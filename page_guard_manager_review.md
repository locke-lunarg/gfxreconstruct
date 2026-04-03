# PageGuardManager Code Review — commit `fd0628c99`

## Background

The change adds `page_to_memory_infos_` (a `void* → vector<MemoryInfo*>` map) to propagate
dirty state across `MemoryInfo` entries that share a boundary page.

The problem being solved is specific to the Windows **write-watch** mode:
`GetWriteWatch(WRITE_WATCH_FLAG_RESET, ...)` atomically resets dirty bits for the entire
queried range. If two `MemoryInfo` entries overlap at a page boundary (e.g., two adjacent
DX12 subresources on the same heap), processing one entry resets the shared page's dirty bit
before the other entry can query it. The change propagates the dirty state to all other
`MemoryInfo` entries registered for that page.

---

## Bug 1 (High) — Dangling pointers in `page_to_memory_infos_` on re-mapped memory

**Location:** `AddTrackedMemory` lines 1261–1268; `RemoveTrackedMemory` lines 1303–1315.

### Problem

The `page_to_memory_infos_` population loop uses **local variables** `aligned_address` and
`total_pages`, computed from the *current call's* arguments:

```cpp
// local aligned_address and total_pages used here:
for (uint32_t i = 0; i < total_pages; ++i)
{
    auto page_address = reinterpret_cast<void*>(...aligned_address... + (i << ...));
    page_to_memory_infos_[page_address].emplace_back(&entry.first->second);
}
```

This loop runs whether `entry.second` is `true` (new insert) **or** `false` (duplicate —
same `memory_id` already in map, only `ref_count` incremented). For the duplicate case,
`emplace` does not update the stored `MemoryInfo`; its `aligned_address` and `total_pages`
still reflect the **original** registration.

`RemoveTrackedMemory` cleans up using `info.aligned_address` and `info.total_pages` from the
**stored** `MemoryInfo`:

```cpp
auto& info = entry->second;
for (uint32_t i = 0; i < info.total_pages; ++i)   // ← uses stored MemoryInfo values
{
    auto page_address = ...info.aligned_address... + (i << ...);
    std::erase(page_to_memory_infos_[page_address], &info);
    ...
}
```

If the second `AddTrackedMemory` call used different parameters (e.g., a DX12 resource
re-mapped with a different subresource pointer or size), any pages the second call added that
fall outside the stored MemoryInfo's range will **never be cleaned up**. After
`memory_info_.erase(entry)`, those map slots hold a dangling `MemoryInfo*` pointer,
leading to undefined behaviour in subsequent `LoadActiveWriteStates` calls.

### When does this occur?

The DX12 capture path calls `AddTrackedMemory` only on the **first** Map (`map_count == 1`)
and guards against duplicate adds with its own counter. However, the PageGuardManager's
`ref_count` mechanism was designed to handle the general case of the same `memory_id` being
added more than once. The specific scenario that triggers this today is two DX12 placed
resources at the **same heap offset** — both Map calls return the same CPU pointer, which
becomes the `memory_id`. See the **Triggering Example** section below.

### Fix

Move the `page_to_memory_infos_` population loop inside `if (entry.second)` so it only
executes on genuinely new inserts:

```cpp
if (entry.second)
{
    for (uint32_t i = 0; i < total_pages; ++i)
    {
        auto page_address = ...;
        page_to_memory_infos_[page_address].emplace_back(&entry.first->second);
    }
}
```

### Triggering Example — DX12 placed resource aliasing

Two placed resources at the same heap offset produce the same CPU pointer from `Map`, and
therefore the same `memory_id` in PageGuardManager. The following sequence creates dangling
pointers and then dereferences them:

```
// Setup: two placed resources at the same heap offset
heap      = CreateHeap(size = M pages)
resourceA = CreatePlacedResource(heap, offset=0, size=N pages)   // smaller
resourceB = CreatePlacedResource(heap, offset=0, size=M pages)   // larger, M > N

// Map both resources
resourceA.Map()
  // GFXR: map_count_A 0→1, CPU ptr = P
  // AddTrackedMemory(id=P, ptr=P, size=N)
  //   entry.second == TRUE  (new insert)
  //   MemoryInfo_A stored: total_pages=N
  //   page_to_memory_infos_[pages 0..N-1] = { &MemoryInfo_A }

resourceB.Map()
  // GFXR: map_count_B 0→1, CPU ptr = P  (same — same heap offset)
  // AddTrackedMemory(id=P, ptr=P, size=M)
  //   entry.second == FALSE  (duplicate)
  //   ref_count: 1 → 2
  //   BUG 1: loop runs with local total_pages=M
  //     page_to_memory_infos_[pages 0..N-1] += &MemoryInfo_A  (now duplicated)
  //     page_to_memory_infos_[pages N..M-1]  = { &MemoryInfo_A }  ← extra entries

// Unmap both resources (either order produces the same result)
resourceA.Unmap()
  // GFXR: map_count_A 1→0 → RemoveTrackedMemory(P)
  //   ref_count: 2 → 1  →  no cleanup

resourceB.Unmap()
  // GFXR: map_count_B 1→0 → RemoveTrackedMemory(P)
  //   ref_count: 1 → 0  →  enters cleanup block
  //   cleanup iterates info.total_pages = N  (original stored value)
  //   pages [0..N-1]: std::erase removes all copies of &MemoryInfo_A ✓
  //   pages [N..M-1]: NOT iterated — &MemoryInfo_A still in map ← LEAK
  //   memory_info_.erase() → MemoryInfo_A DESTROYED
  //
  //   page_to_memory_infos_[pages N..M-1] now holds DANGLING &MemoryInfo_A

// Map a new resource whose boundary page falls within the leaked range
resourceC = CreatePlacedResource(heap, offset = N*page_size, size = K pages)
resourceC.Map()
  // CPU ptr = P + N*page_size  (starts exactly at leaked page N)
  // AddTrackedMemory(id=P+N*page_size, ...)
  //   new insert, MemoryInfo_C stored
  //   page_to_memory_infos_[page N] = { &MemoryInfo_A (dangling!), &MemoryInfo_C }

// Next queue submit
ExecuteCommandLists(...)
  // ProcessMemoryEntries → LoadActiveWriteStates(MemoryInfo_C)
  //   GetWriteWatch reports page N as dirty (C's first/boundary page)
  //   page_to_memory_infos_.find(page N) → { &MemoryInfo_A, &MemoryInfo_C }
  //   other_mem_info = &MemoryInfo_A  →  USE-AFTER-FREE  ← CRASH / silent corruption
```

**Three conditions must align to trigger the dereference:**
1. Two placed resources at the same heap offset with different sizes (same `memory_id`)
2. Both mapped then unmapped — driving `ref_count` to 0 and triggering partial cleanup
3. A subsequent resource mapped such that its first or last page coincides with one of the
   leaked entries — the `LoadActiveWriteStates` boundary check is what gates the
   `page_to_memory_infos_` lookup

---

## Bug 2 (Medium) — `page_to_memory_infos_` populated for non-write-watch and non-WIN32 MemoryInfos

**Location:** `AddTrackedMemory` lines 1261–1268.

### Problem

`LoadActiveWriteStates` — the only function that consults `page_to_memory_infos_` — is:

- Compiled for **WIN32 only** (`#if defined(WIN32)`)
- Called only when `memory_info->use_write_watch == true`

Yet the map is populated **unconditionally** for every `MemoryInfo`, including:

- Shadow-memory MemoryInfos (mprotect / uffd) on Windows
- All MemoryInfos on Linux / Android (where `use_write_watch` is always forced `false` at
  line 1091)

For shadow MemoryInfos, `aligned_address` points into GFXR-allocated shadow memory — a
completely different virtual address range from write-watch MemoryInfos. If the OS reuses a
virtual address (a shadow allocation landing at the same VA as an active write-watch mapping),
`LoadActiveWriteStates` would find the shadow `MemoryInfo` via the page map and compute:

```cpp
// other_mem_info->aligned_address is in shadow space;
// modified_page_address is in write-watch space
size_t other_start_offset = static_cast<uint8_t*>(modified_page_address) -
                            static_cast<uint8_t*>(other_mem_info->aligned_address);
size_t other_page_index = other_start_offset >> system_page_pot_shift_;
// other_page_index is garbage → out-of-bounds SetActiveWriteBlock
other_mem_info->status_tracker.SetActiveWriteBlock(other_page_index, true);
```

This silently corrupts the shadow MemoryInfo's `status_tracker`, potentially causing spurious
or missed dirty-page reports during capture.

On Linux/Android the map is simply wasted memory and CPU time (built every map, never read).

### Fix

Gate both the population in `AddTrackedMemory` and the cleanup in `RemoveTrackedMemory` with
the `use_write_watch` flag:

```cpp
// AddTrackedMemory — inside if (entry.second):
if (use_write_watch)
{
    for (uint32_t i = 0; i < total_pages; ++i) { ... }
}

// RemoveTrackedMemory:
if (info.use_write_watch)
{
    for (uint32_t i = 0; i < info.total_pages; ++i) { ... }
}
```

This also covers Linux/Android at no extra cost (since `use_write_watch` is always `false`
there).

---

## Bug 3 (Medium) — `other_page_index` not bounds-checked before `SetActiveWriteBlock`

**Location:** `LoadActiveWriteStates` lines 821–825.

### Problem

```cpp
size_t other_start_offset = static_cast<uint8_t*>(modified_page_address) -
                            static_cast<uint8_t*>(other_mem_info->aligned_address);
size_t other_page_index = other_start_offset >> system_page_pot_shift_;
other_mem_info->status_tracker.SetActiveWriteBlock(other_page_index, true);
```

`other_start_offset` is `size_t` (unsigned). If `modified_page_address <
other_mem_info->aligned_address` — which should not occur under normal operation but can
happen given the stale-entry (Bug 1) or mixed-mode-entry (Bug 2) issues — the subtraction
**silently underflows** to a huge value. `other_page_index` then far exceeds
`other_mem_info->total_pages`, and `SetActiveWriteBlock` writes out of bounds.

### Fix

Add a defensive assert (and ideally a runtime guard) before the call:

```cpp
assert(static_cast<uint8_t*>(modified_page_address) >=
       static_cast<uint8_t*>(other_mem_info->aligned_address));
assert(other_page_index < other_mem_info->total_pages);
other_mem_info->status_tracker.SetActiveWriteBlock(other_page_index, true);
```

---

## Summary

| # | Severity | Mode / API affected | Description |
|---|----------|---------------------|-------------|
| 1 | **High** | All (particularly DX12 write-watch) | Dangling `MemoryInfo*` in `page_to_memory_infos_` when `AddTrackedMemory` is called twice for the same `memory_id` with different parameters |
| 2 | **Medium** | All modes; Linux/Android | Map populated for non-write-watch MemoryInfos; potential `status_tracker` corruption on VA reuse; wasteful no-op on Linux/Android |
| 3 | **Medium** | WIN32 write-watch | `other_page_index` not bounds-checked before `SetActiveWriteBlock`; silent UB on underflow |

### Minimal combined fix

1. Move `page_to_memory_infos_` population inside `if (entry.second)` in `AddTrackedMemory`.
2. Gate both population and cleanup with `if (use_write_watch)` / `if (info.use_write_watch)`.
3. Add `assert(other_page_index < other_mem_info->total_pages)` in `LoadActiveWriteStates`.
