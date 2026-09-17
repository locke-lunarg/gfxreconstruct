#include <gtest/gtest.h>

#include "verify-gfxr.h"

TEST(ExternalMemoryFD, CorrectGFXR)
{
    run_in_background("external-memory-fd-export");

    // Wait for the exporter to be ready
    sleep(1);
    verify_gfxr("external-memory-fd-import");
}

// Replays the same capture with -m rebind, where memory is managed by VMA rather than by the captured
// vkAllocateMemory calls. The external create-info structs have to survive that translation, and the resources
// have to end up bound to exportable allocations. See
// https://github.com/LunarG/gfxreconstruct/issues/2813.
TEST(ExternalMemoryFD, RebindReplay)
{
    run_in_background("external-memory-fd-export");

    // Wait for the exporter to be ready
    sleep(1);
    capture_and_replay("external-memory-fd-import", { "-m", "rebind" });
}
