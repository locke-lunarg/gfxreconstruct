/*
** Copyright (c) 2021 LunarG, Inc.
**
** Permission is hereby granted, free of charge, to any person obtaining a
** copy of this software and associated documentation files (the "Software"),
** to deal in the Software without restriction, including without limitation
** the rights to use, copy, modify, merge, publish, distribute, sublicense,
** and/or sell copies of the Software, and to permit persons to whom the
** Software is furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be included in
** all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
** FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
** DEALINGS IN THE SOFTWARE.
*/

#include "graphics/dx12_resource_data_util.h"

#include "graphics/dx12_util.h"
#include "util/logging.h"

#include <inttypes.h>
#include <algorithm>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

HRESULT
Dx12ResourceDataUtil::MapSubresourceAndReadData(
    ID3D12Resource* resource, UINT subresource, size_t offset, size_t size, uint8_t* data)
{
    uint8_t* subresource_data;
    HRESULT  result = dx12::MapSubresource(resource, subresource, nullptr, subresource_data);
    if (SUCCEEDED(result))
    {
        subresource_data += offset;
        util::platform::MemoryCopy(data, size, subresource_data, size);
        resource->Unmap(subresource, &dx12::kZeroRange);
    }
    return result;
}

HRESULT Dx12ResourceDataUtil::MapSubresourceAndWriteData(ID3D12Resource* resource,
                                                         UINT            subresource,
                                                         size_t          size,
                                                         const uint8_t*  data)
{
    uint8_t* subresource_data;
    HRESULT  result = dx12::MapSubresource(resource, subresource, &dx12::kZeroRange, subresource_data);
    if (SUCCEEDED(result))
    {
        util::platform::MemoryCopy(subresource_data, size, data, size);
        resource->Unmap(subresource, nullptr);
    }
    return result;
}

// Add a transition barrier to cmd_list. Returns true if cmd_list was modified.
bool AddTransitionBarrier(ID3D12GraphicsCommandList*     cmd_list,
                          ID3D12Resource*                resource,
                          UINT                           subresource,
                          const dx12::ResourceStateInfo& current_state,
                          const dx12::ResourceStateInfo& desired_state)
{
    // It is expected that barrier_flags can have bits set for either D3D12_RESOURCE_BARRIER_FLAG_BEGIN_ONLY or
    // D3D12_RESOURCE_BARRIER_FLAG_END_ONLY, not both.
    GFXRECON_ASSERT((current_state.barrier_flags &
                     (D3D12_RESOURCE_BARRIER_FLAG_BEGIN_ONLY | D3D12_RESOURCE_BARRIER_FLAG_END_ONLY)) !=
                    (D3D12_RESOURCE_BARRIER_FLAG_BEGIN_ONLY | D3D12_RESOURCE_BARRIER_FLAG_END_ONLY));
    GFXRECON_ASSERT((current_state.barrier_flags &
                     (D3D12_RESOURCE_BARRIER_FLAG_BEGIN_ONLY | D3D12_RESOURCE_BARRIER_FLAG_END_ONLY)) !=
                    (D3D12_RESOURCE_BARRIER_FLAG_BEGIN_ONLY | D3D12_RESOURCE_BARRIER_FLAG_END_ONLY));

    // Return early if the resource is already in the desired state
    bool current_barrier_begins_split = ((current_state.barrier_flags & D3D12_RESOURCE_BARRIER_FLAG_BEGIN_ONLY) ==
                                         D3D12_RESOURCE_BARRIER_FLAG_BEGIN_ONLY);
    bool desired_barrier_begins_split = ((desired_state.barrier_flags & D3D12_RESOURCE_BARRIER_FLAG_BEGIN_ONLY) ==
                                         D3D12_RESOURCE_BARRIER_FLAG_BEGIN_ONLY);
    if (current_state.states == desired_state.states)
    {
        if (current_barrier_begins_split == desired_barrier_begins_split)
        {
            return false;
        }
    }

    D3D12_RESOURCE_BARRIER_FLAGS flags =
        desired_barrier_begins_split ? D3D12_RESOURCE_BARRIER_FLAG_BEGIN_ONLY : D3D12_RESOURCE_BARRIER_FLAG_NONE;

    // Handle the cases where the resource is currently in the middle of a split transition barrier.
    if (current_barrier_begins_split)
    {
        // If the previous state started a split transition to the desired state, complete the current split transition.
        if (desired_state.states == current_state.states)
        {
            flags = D3D12_RESOURCE_BARRIER_FLAG_END_ONLY;
        }
        else
        {
            // If the previous state started a split transition to a state other than the desired state, add an
            // additional transition to complete the split transition.
            AddTransitionBarrier(cmd_list,
                                 resource,
                                 subresource,
                                 current_state,
                                 { current_state.states, D3D12_RESOURCE_BARRIER_FLAG_END_ONLY });
        }
    }

    D3D12_RESOURCE_TRANSITION_BARRIER transition;
    transition.pResource   = resource;
    transition.Subresource = subresource;
    transition.StateBefore = current_state.states;
    transition.StateAfter  = desired_state.states;

    D3D12_RESOURCE_BARRIER barrier;
    barrier.Type       = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
    barrier.Flags      = flags;
    barrier.Transition = transition;

    cmd_list->ResourceBarrier(1, &barrier);

    return true;
}

void Dx12ResourceDataUtil::GetResourceCopyInfo(ID3D12Resource*                                  resource,
                                               size_t&                                          subresource_count,
                                               std::vector<uint64_t>&                           subresource_offsets,
                                               std::vector<uint64_t>&                           subresource_sizes,
                                               std::vector<D3D12_PLACED_SUBRESOURCE_FOOTPRINT>& layouts,
                                               uint64_t&                                        total_size)
{
    GFXRECON_ASSERT(resource != nullptr);

    subresource_count = dx12::GetSubresourceCount(resource);
    subresource_offsets.clear();
    subresource_sizes.clear();
    layouts.clear();
    total_size = 0;

    auto resource_desc = resource->GetDesc();

    if (resource_desc.Dimension == D3D12_RESOURCE_DIMENSION_BUFFER)
    {
        layouts.resize(subresource_count);
        subresource_sizes.push_back(resource_desc.Width);
        subresource_offsets.push_back(0);

        device_->GetCopyableFootprints(&resource_desc, 0, 1, 0, layouts.data(), nullptr, nullptr, &total_size);

        // Total resource size should be equal to buffer width and should have 0 offset.
        GFXRECON_ASSERT((total_size == resource_desc.Width) && (layouts[0].Offset == 0));
    }
    else
    {
        layouts.resize(subresource_count);
        temp_subresource_row_counts_.clear();
        temp_subresource_row_counts_.resize(subresource_count);
        temp_subresource_row_size_bytes_.clear();
        temp_subresource_row_size_bytes_.resize(subresource_count);

        device_->GetCopyableFootprints(&resource_desc,
                                       0,
                                       subresource_count,
                                       0,
                                       layouts.data(),
                                       temp_subresource_row_counts_.data(),
                                       temp_subresource_row_size_bytes_.data(),
                                       &total_size);

        subresource_sizes.resize(subresource_count);
        subresource_offsets.resize(subresource_count);
        for (size_t i = 0; i < subresource_count; ++i)
        {
            size_t slice_count = 1;
            if (resource_desc.Dimension == D3D12_RESOURCE_DIMENSION_TEXTURE3D)
            {
                slice_count = layouts[i].Footprint.Depth;
            }
            else
            {
                GFXRECON_ASSERT(layouts[i].Footprint.Depth == 1);
            }

            // Compute the size required to copy the subresource. The final row of the subresource does not require
            // padding, so the total size is (row_count - 1) * row_pitch + row_size_bytes.
            size_t row_count = temp_subresource_row_counts_[i] * slice_count;
            subresource_sizes[i] =
                (row_count - 1) * layouts[i].Footprint.RowPitch + temp_subresource_row_size_bytes_[i];

            subresource_offsets[i] = layouts[i].Offset;
        }

        GFXRECON_ASSERT((subresource_offsets.back() + subresource_sizes.back()) == total_size);
    }
}

Dx12ResourceDataUtil::Dx12ResourceDataUtil(ID3D12Device*                  device,
                                           uint64_t                       min_buffer_size,
                                           dx12::ID3D12CommandQueueComPtr queue) :
    device_(device),
    staging_buffers_{ nullptr, nullptr }, staging_buffer_sizes_{ 0, 0 }, min_buffer_size_(min_buffer_size),
    fence_value_(0)
{
    HRESULT result = E_FAIL;

    // Create a command list (and its dependencies) that will be used to run the copy commands.
    D3D12_COMMAND_LIST_TYPE  list_type  = D3D12_COMMAND_LIST_TYPE_DIRECT;
    D3D12_COMMAND_QUEUE_DESC queue_desc = {};
    queue_desc.Flags                    = D3D12_COMMAND_QUEUE_FLAG_NONE;
    queue_desc.Type                     = list_type;

    if (queue != nullptr)
    {
        command_queue_ = queue;
        result         = S_OK;
    }
    else
    {
        result = device_->CreateCommandQueue(&queue_desc, IID_PPV_ARGS(&command_queue_));
    }
    if (SUCCEEDED(result))
    {
        result = device_->CreateCommandAllocator(list_type, IID_PPV_ARGS(&command_allocator_));
        if (SUCCEEDED(result))
        {
            result =
                device_->CreateCommandList(0, list_type, command_allocator_, nullptr, IID_PPV_ARGS(&command_list_));
            if (SUCCEEDED(result))
            {
                result = command_list_->Close();
                if (SUCCEEDED(result))
                {
                    result = device_->CreateFence(fence_value_, D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(&command_fence_));
                }
            }
        }
    }

    if (FAILED(result))
    {
        GFXRECON_LOG_ERROR(
            "Failed to initialize DX12 command list and command queue for Dx12ResourceDataUtil. (error = %lx)", result);
    }
}

dx12::ID3D12ResourceComPtr Dx12ResourceDataUtil::GetStagingBuffer(CopyType type, uint64_t required_buffer_size)
{
    if (required_buffer_size == 0)
    {
        return E_INVALIDARG;
    }

    // If the buffer was already initialized with a size >= required_buffer_size, use the existing buffer.
    if ((staging_buffers_[type] != nullptr) && (required_buffer_size <= staging_buffer_sizes_[type]))
    {
        return staging_buffers_[type];
    }

    uint64_t buffer_size = std::max(required_buffer_size, min_buffer_size_);

    // Release existing buffer.
    staging_buffers_[type]      = nullptr;
    staging_buffer_sizes_[type] = 0;

    // Create the staging resource.
    D3D12_HEAP_PROPERTIES heap_properties = {};
    if (type == kCopyTypeRead)
    {
        heap_properties.Type = D3D12_HEAP_TYPE_READBACK;
    }
    else
    {
        heap_properties.Type = D3D12_HEAP_TYPE_UPLOAD;
    }

    D3D12_RESOURCE_DESC staging_resource_desc = {};
    staging_resource_desc.Dimension           = D3D12_RESOURCE_DIMENSION_BUFFER;
    staging_resource_desc.Alignment           = 0;
    staging_resource_desc.Width               = buffer_size;
    staging_resource_desc.Height              = 1;
    staging_resource_desc.DepthOrArraySize    = 1;
    staging_resource_desc.MipLevels           = 1;
    staging_resource_desc.Format              = DXGI_FORMAT_UNKNOWN;
    staging_resource_desc.SampleDesc.Count    = 1;
    staging_resource_desc.Layout              = D3D12_TEXTURE_LAYOUT_ROW_MAJOR;
    staging_resource_desc.Flags               = D3D12_RESOURCE_FLAG_NONE;

    D3D12_RESOURCE_STATES staging_resource_state;
    if (type == kCopyTypeRead)
    {
        staging_resource_state = D3D12_RESOURCE_STATE_COPY_DEST;
    }
    else
    {
        staging_resource_state = D3D12_RESOURCE_STATE_GENERIC_READ;
    }
    HRESULT result = device_->CreateCommittedResource(&heap_properties,
                                                      D3D12_HEAP_FLAG_NONE,
                                                      &staging_resource_desc,
                                                      staging_resource_state,
                                                      nullptr,
                                                      IID_PPV_ARGS(&staging_buffers_[type]));

    if (FAILED(result))
    {
        GFXRECON_LOG_FATAL("Failed to create a staging buffer of size %" PRIu64 " for copying resource data.",
                           buffer_size);

        staging_buffers_[type]      = nullptr;
        staging_buffer_sizes_[type] = 0;
    }
    else
    {
        staging_buffer_sizes_[type] = buffer_size;
    }

    return staging_buffers_[type];
}

dx12::ID3D12ResourceComPtr Dx12ResourceDataUtil::CreateStagingBuffer(CopyType type, uint64_t required_buffer_size)
{
    if (required_buffer_size == 0)
    {
        return nullptr;
    }

    // Create the staging resource.
    D3D12_HEAP_TYPE       staging_resource_type  = D3D12_HEAP_TYPE_READBACK;
    D3D12_RESOURCE_STATES staging_resource_state = D3D12_RESOURCE_STATE_COPY_DEST;
    if (type == kCopyTypeWrite)
    {
        staging_resource_type  = D3D12_HEAP_TYPE_UPLOAD;
        staging_resource_state = D3D12_RESOURCE_STATE_GENERIC_READ;
    }
    return graphics::dx12::CreateBufferResource(
        device_, required_buffer_size, staging_resource_type, staging_resource_state, D3D12_RESOURCE_FLAG_NONE);
}

HRESULT Dx12ResourceDataUtil::ReadFromBufferResource(ID3D12Resource*                target_resource,
                                                     bool                           try_map_and_copy,
                                                     uint64_t                       offset,
                                                     uint64_t                       size,
                                                     const dx12::ResourceStateInfo& before_state,
                                                     const dx12::ResourceStateInfo& after_state,
                                                     std::vector<uint8_t>&          data,
                                                     ID3D12Resource*                staging_resource)
{
    HRESULT result = E_FAIL;

    // Get the layout information for copying resource data.
    size_t                subresource_count;
    std::vector<uint64_t> subresource_offsets;
    std::vector<uint64_t> subresource_sizes;
    uint64_t              required_data_size;
    temp_subresource_layouts_.clear();
    GetResourceCopyInfo(target_resource,
                        subresource_count,
                        subresource_offsets,
                        subresource_sizes,
                        temp_subresource_layouts_,
                        required_data_size);
    if (subresource_count > 1)
    {
        GFXRECON_LOG_FATAL("ReadFromBufferResource: The buffer resource's subresource_count(%" PRIu64
                           ") is larger than 1. This resource mightn't be buffer.",
                           subresource_count);
    }
    if (offset > subresource_sizes[0])
    {
        GFXRECON_LOG_FATAL("ReadFromBufferResource: offset(%" PRIu64 ") is larger than "
                           "subresource_sizes[0](%" PRIu64 ").",
                           offset,
                           subresource_sizes[0]);
    }
    if (size == UINT64_MAX)
    {
        size = subresource_sizes[0] - offset;
    }
    else if ((offset + size) > subresource_sizes[0])
    {
        GFXRECON_LOG_FATAL("ReadFromBufferResource: offset(%" PRIu64 ") + size(%" PRIu64 ") is larger than "
                           "subresource_sizes[0](%" PRIu64 ").",
                           offset,
                           size,
                           subresource_sizes[0]);
    }
    GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, required_data_size);

    data.clear();
    data.resize(static_cast<size_t>(size));

    // If the resource can be mapped, map it, copy the data, and return success.
    if (try_map_and_copy && CopyMappableBufferResource(target_resource, offset, size, before_state, after_state, &data))
    {
        return S_OK;
    }

    std::vector<uint32_t>                subresource_indices{ 0 };
    std::vector<dx12::ResourceStateInfo> before_states{ before_state };
    std::vector<dx12::ResourceStateInfo> after_states{ after_state };
    // Get or create the staging buffer for copying the resource on device.
    if (staging_resource != nullptr)
    {
        result = ExecuteCopyCommandList(target_resource,
                                        kCopyTypeRead,
                                        offset,
                                        size,
                                        subresource_indices,
                                        temp_subresource_layouts_,
                                        subresource_sizes,
                                        before_states,
                                        after_states,
                                        staging_resource);
    }
    else
    {
        auto staging_resource_temp = GetStagingBuffer(kCopyTypeRead, size);
        staging_resource           = staging_resource_temp.GetInterfacePtr();
        // Build and execute commands to copy data to the resource.
        result = ExecuteCopyCommandList(target_resource,
                                        kCopyTypeRead,
                                        offset,
                                        size,
                                        subresource_indices,
                                        temp_subresource_layouts_,
                                        subresource_sizes,
                                        before_states,
                                        after_states);
    }
    // After the command list has completed, map the copy resource and read its data.
    if (SUCCEEDED(result))
    {
        result = MapSubresourceAndReadData(staging_resource, 0, 0, static_cast<size_t>(size), data.data());
    }

    return result;
}

HRESULT Dx12ResourceDataUtil::ReadFromTargetSubresources(ID3D12Resource*                             target_resource,
                                                         bool                                        try_map_and_copy,
                                                         const std::vector<dx12::ResourceStateInfo>& before_states,
                                                         const std::vector<dx12::ResourceStateInfo>& after_states,
                                                         std::vector<uint8_t>&                       data,
                                                         const std::vector<uint32_t>& subresource_indices,
                                                         std::vector<uint64_t>&       subresource_offsets,
                                                         std::vector<uint64_t>&       subresource_sizes,
                                                         ID3D12Resource*              staging_resource)
{
    HRESULT result = E_FAIL;

    // Get the layout information for copying resource data.
    size_t                all_subresource_count;
    std::vector<uint64_t> all_subresource_offsets;
    std::vector<uint64_t> all_subresource_sizes;
    uint64_t              total_size;
    temp_subresource_layouts_.clear();
    GetResourceCopyInfo(target_resource,
                        all_subresource_count,
                        all_subresource_offsets,
                        all_subresource_sizes,
                        temp_subresource_layouts_,
                        total_size);

    GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, total_size);

    subresource_offsets.clear();
    subresource_sizes.clear();

    uint32_t i            = 0;
    uint64_t end_sub_size = 0;
    for (const auto sub_index : subresource_indices)
    {
        subresource_offsets.emplace_back(all_subresource_offsets[i]);
        subresource_sizes.emplace_back(all_subresource_sizes[i]);
        end_sub_size = all_subresource_sizes[i];
        ++i;
    }

    data.clear();
    auto size = end_sub_size - subresource_offsets[0];
    data.resize(static_cast<size_t>(size));

    // If the resource can be mapped, map it, copy the data, and return success.
    if (try_map_and_copy && CopyMappableResource(target_resource,
                                                 before_states,
                                                 after_states,
                                                 kCopyTypeRead,
                                                 &data,
                                                 nullptr,
                                                 subresource_indices,
                                                 all_subresource_offsets,
                                                 all_subresource_sizes))
    {
        return S_OK;
    }

    // Get or create the staging buffer for copying the resource on device.
    if (staging_resource != nullptr)
    {
        result = ExecuteCopyCommandList(target_resource,
                                        kCopyTypeRead,
                                        0,
                                        size,
                                        subresource_indices,
                                        temp_subresource_layouts_,
                                        all_subresource_sizes,
                                        before_states,
                                        after_states,
                                        staging_resource);
    }
    else
    {
        auto staging_resource_temp = GetStagingBuffer(kCopyTypeRead, size);
        staging_resource           = staging_resource_temp.GetInterfacePtr();
        // Build and execute commands to copy data to the resource.
        result = ExecuteCopyCommandList(target_resource,
                                        kCopyTypeRead,
                                        0,
                                        size,
                                        subresource_indices,
                                        temp_subresource_layouts_,
                                        all_subresource_sizes,
                                        before_states,
                                        after_states);
    }
    // After the command list has completed, map the copy resource and read its data.
    if (SUCCEEDED(result))
    {
        result = MapSubresourceAndReadData(staging_resource, 0, 0, static_cast<size_t>(size), data.data());
    }

    return result;
}

HRESULT Dx12ResourceDataUtil::ReadFromResource(ID3D12Resource*                             target_resource,
                                               bool                                        try_map_and_copy,
                                               const std::vector<dx12::ResourceStateInfo>& before_states,
                                               const std::vector<dx12::ResourceStateInfo>& after_states,
                                               std::vector<uint8_t>&                       data,
                                               std::vector<uint64_t>&                      subresource_offsets,
                                               std::vector<uint64_t>&                      subresource_sizes,
                                               ID3D12Resource*                             staging_resource)
{
    HRESULT result = E_FAIL;

    // Get the layout information for copying resource data.
    size_t   subresource_count;
    uint64_t required_data_size;
    temp_subresource_layouts_.clear();
    GetResourceCopyInfo(target_resource,
                        subresource_count,
                        subresource_offsets,
                        subresource_sizes,
                        temp_subresource_layouts_,
                        required_data_size);

    GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, required_data_size);

    std::vector<uint32_t> subresource_indices;
    for (uint32_t i = 0; i < subresource_count; ++i)
    {
        subresource_indices.emplace_back(i);
    }

    data.clear();
    data.resize(static_cast<size_t>(required_data_size));

    // If the resource can be mapped, map it, copy the data, and return success.
    if (try_map_and_copy && CopyMappableResource(target_resource,
                                                 before_states,
                                                 after_states,
                                                 kCopyTypeRead,
                                                 &data,
                                                 nullptr,
                                                 subresource_indices,
                                                 subresource_offsets,
                                                 subresource_sizes))
    {
        return S_OK;
    }

    // Get or create the staging buffer for copying the resource on device.
    if (staging_resource != nullptr)
    {
        result = ExecuteCopyCommandList(target_resource,
                                        kCopyTypeRead,
                                        0,
                                        required_data_size,
                                        subresource_indices,
                                        temp_subresource_layouts_,
                                        subresource_sizes,
                                        before_states,
                                        after_states,
                                        staging_resource);
    }
    else
    {
        auto staging_resource_temp = GetStagingBuffer(kCopyTypeRead, required_data_size);
        staging_resource           = staging_resource_temp.GetInterfacePtr();
        // Build and execute commands to copy data to the resource.
        result = ExecuteCopyCommandList(target_resource,
                                        kCopyTypeRead,
                                        0,
                                        required_data_size,
                                        subresource_indices,
                                        temp_subresource_layouts_,
                                        subresource_sizes,
                                        before_states,
                                        after_states);
    }
    // After the command list has completed, map the copy resource and read its data.
    if (SUCCEEDED(result))
    {
        result =
            MapSubresourceAndReadData(staging_resource, 0, 0, static_cast<size_t>(required_data_size), data.data());
    }

    return result;
}

HRESULT Dx12ResourceDataUtil::WriteToResource(ID3D12Resource*                             target_resource,
                                              bool                                        try_map_and_copy,
                                              const std::vector<dx12::ResourceStateInfo>& before_states,
                                              const std::vector<dx12::ResourceStateInfo>& after_states,
                                              const std::vector<uint8_t>&                 data,
                                              const std::vector<uint64_t>&                subresource_offsets,
                                              const std::vector<uint64_t>&                subresource_sizes,
                                              ID3D12Resource*                             staging_resource,
                                              bool                                        batching)
{
    HRESULT result = E_FAIL;

    size_t   subresource_count;
    uint64_t required_data_size;

    // Get the layout information for copying resource data.
    std::vector<uint64_t> layout_offsets;
    std::vector<uint64_t> layout_sizes;
    temp_subresource_layouts_.clear();
    GetResourceCopyInfo(target_resource,
                        subresource_count,
                        layout_offsets,
                        layout_sizes,
                        temp_subresource_layouts_,
                        required_data_size);

    std::vector<uint32_t> subresource_indices;
    for (uint32_t i = 0; i < subresource_count; ++i)
    {
        subresource_indices.emplace_back(i);
    }

    // If the resource can be mapped, map it, copy the data, and return success.
    if (try_map_and_copy && CopyMappableResource(target_resource,
                                                 before_states,
                                                 after_states,
                                                 kCopyTypeWrite,
                                                 nullptr,
                                                 &data,
                                                 subresource_indices,
                                                 subresource_offsets,
                                                 subresource_sizes))
    {
        return S_OK;
    }

    // Get or create the staging buffer for copying the resource on device.
    if (staging_resource == nullptr)
    {
        auto staging_buffer = GetStagingBuffer(kCopyTypeWrite, required_data_size);
        staging_resource    = staging_buffer;
    }

    // When writing and before running the command list, map the copy resource and write its data.
    uint8_t* subresource_data;
    result = dx12::MapSubresource(staging_resource, 0, &dx12::kZeroRange, subresource_data);
    if (SUCCEEDED(result))
    {
        for (UINT i = 0; i < subresource_count; ++i)
        {
            GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, subresource_sizes[i]);
            size_t subresource_size = static_cast<size_t>(std::min(subresource_sizes[i], layout_sizes[i]));

            if (layout_sizes[i] != subresource_sizes[i])
            {
                GFXRECON_LOG_ERROR("The size of the data to be copied to the subresource does not match the size "
                                   "required by the subresource's copyable footprint (data size = %" PRIu64
                                   ", footprint size = %" PRIu64 ", subresouce index = %" PRIu32 ").",
                                   subresource_sizes[i],
                                   layout_sizes[i],
                                   i);
            }

            size_t layout_offset = static_cast<size_t>(layout_offsets[i]);
            size_t layout_size   = static_cast<size_t>(layout_sizes[i]);
            util::platform::MemoryCopy(
                subresource_data + layout_offset, layout_size, data.data() + subresource_offsets[i], subresource_size);
        }
        staging_resource->Unmap(0, nullptr);
    }
    else
    {
        GFXRECON_LOG_ERROR("Failed to map staging buffer for writing data to resource.");
    }

    // Build and execute commands to copy data to the resource.
    if (batching == false)
    {
        result = ExecuteCopyCommandList(target_resource,
                                        kCopyTypeWrite,
                                        0,
                                        required_data_size,
                                        subresource_indices,
                                        temp_subresource_layouts_,
                                        subresource_sizes,
                                        before_states,
                                        after_states);
    }
    else
    {
        result = ExecuteCopyCommandList(target_resource,
                                        kCopyTypeWrite,
                                        0,
                                        required_data_size,
                                        subresource_indices,
                                        temp_subresource_layouts_,
                                        subresource_sizes,
                                        before_states,
                                        after_states,
                                        staging_resource,
                                        batching);
    }

    return result;
}

bool Dx12ResourceDataUtil::CopyMappableBufferResource(ID3D12Resource*                target_resource,
                                                      uint64_t                       offset,
                                                      uint64_t                       size,
                                                      const dx12::ResourceStateInfo& before_state,
                                                      const dx12::ResourceStateInfo& after_state,
                                                      std::vector<uint8_t>*          read_data)
{
    // Map the resource and copy the data if the resource has the correct heap type.
    D3D12_HEAP_PROPERTIES target_heap_properties;
    D3D12_HEAP_FLAGS      target_heap_flags;
    HRESULT               result = target_resource->GetHeapProperties(&target_heap_properties, &target_heap_flags);
    if (SUCCEEDED(result))
    {
        bool is_cpu_accessible = (target_heap_properties.Type == D3D12_HEAP_TYPE_READBACK) ||
                                 ((target_heap_properties.Type == D3D12_HEAP_TYPE_CUSTOM) &&
                                  (target_heap_properties.CPUPageProperty != D3D12_CPU_PAGE_PROPERTY_UNKNOWN) &&
                                  (target_heap_properties.CPUPageProperty != D3D12_CPU_PAGE_PROPERTY_NOT_AVAILABLE));

        if (is_cpu_accessible)
        {
            GFXRECON_ASSERT(read_data != nullptr);
            result = MapSubresourceAndReadData(target_resource, 0, offset, size, read_data->data());

            if (before_state.states != after_state.states)
            {
                GFXRECON_LOG_ERROR_ONCE("CPU buffer state not match");
            }
            return SUCCEEDED(result);
        }
    }
    return false;
}

bool Dx12ResourceDataUtil::CopyMappableResource(ID3D12Resource*                             target_resource,
                                                const std::vector<dx12::ResourceStateInfo>& all_before_states,
                                                const std::vector<dx12::ResourceStateInfo>& all_after_states,
                                                CopyType                                    copy_type,
                                                std::vector<uint8_t>*                       read_data,
                                                const std::vector<uint8_t>*                 write_data,
                                                const std::vector<uint32_t>&                subresource_indices,
                                                const std::vector<uint64_t>&                all_subresource_offsets,
                                                const std::vector<uint64_t>&                all_subresource_sizes)
{
    // Map the resource and copy the data if the resource has the correct heap type.
    D3D12_HEAP_PROPERTIES target_heap_properties;
    D3D12_HEAP_FLAGS      target_heap_flags;
    HRESULT               result = target_resource->GetHeapProperties(&target_heap_properties, &target_heap_flags);
    if (SUCCEEDED(result))
    {
        bool is_cpu_accessible =
            ((target_heap_properties.Type == D3D12_HEAP_TYPE_UPLOAD) && (copy_type == kCopyTypeWrite)) ||
            ((target_heap_properties.Type == D3D12_HEAP_TYPE_READBACK) && (copy_type == kCopyTypeRead)) ||
            ((target_heap_properties.Type == D3D12_HEAP_TYPE_CUSTOM) &&
             (target_heap_properties.CPUPageProperty != D3D12_CPU_PAGE_PROPERTY_UNKNOWN) &&
             (target_heap_properties.CPUPageProperty != D3D12_CPU_PAGE_PROPERTY_NOT_AVAILABLE));

        if (is_cpu_accessible)
        {
            uint64_t read_data_index = 0;
            for (auto sub_index : subresource_indices)
            {
                GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, all_subresource_sizes[sub_index]);
                size_t subresource_size = static_cast<size_t>(all_subresource_sizes[sub_index]);

                if (copy_type == kCopyTypeRead)
                {
                    GFXRECON_ASSERT(read_data != nullptr);
                    result = MapSubresourceAndReadData(
                        target_resource, sub_index, 0, subresource_size, read_data->data() + read_data_index);
                }
                else
                {
                    GFXRECON_ASSERT(write_data != nullptr);
                    result = MapSubresourceAndWriteData(
                        target_resource, sub_index, subresource_size, write_data->data() + read_data_index);
                }
                if (all_before_states[sub_index].states != all_after_states[sub_index].states)
                {
                    GFXRECON_LOG_ERROR_ONCE("CPU buffer state not match");
                }
                read_data_index += subresource_size;
                return SUCCEEDED(result);
            }
        }
    }

    return false;
}

HRESULT Dx12ResourceDataUtil::ExecuteAndWaitForCommandList()
{
    // Execute the command list and wait for completion.
    ID3D12CommandList* cmd_lists[] = { command_list_ };
    command_queue_->ExecuteCommandLists(1, cmd_lists);
    return dx12::WaitForQueue(command_queue_, command_fence_, ++fence_value_);

    // MakeResident and Evict are ref-counted. Remove the ref count added by MakeResident.
    for (auto resource : resident_resources)
    {
        if (!SUCCEEDED(device_->Evict(1, &resource)))
        {
            GFXRECON_LOG_WARNING("Failed to evict resource after copying resource data.");
        }
    }
}

HRESULT Dx12ResourceDataUtil::CloseCommandList()
{
    return command_list_->Close();
}

HRESULT
Dx12ResourceDataUtil::ResetCommandList()
{
    HRESULT result = command_allocator_->Reset();
    if (SUCCEEDED(result))
    {
        result = command_list_->Reset(command_allocator_, nullptr);
        if (FAILED(result))
        {
            GFXRECON_LOG_ERROR("Could not reset command list to copy resource data. (error = %lx)", result);
        }
    }
    else
    {
        GFXRECON_LOG_ERROR("Could not reset command allocator to copy resource data.. (error = %lx)", result);
    }
    return result;
}

HRESULT
Dx12ResourceDataUtil::ExecuteCopyCommandList(
    ID3D12Resource*                                        target_resource,
    CopyType                                               copy_type,
    uint64_t                                               copy_offset,
    uint64_t                                               copy_size,
    const std::vector<uint32_t>&                           subresource_indices,
    const std::vector<D3D12_PLACED_SUBRESOURCE_FOOTPRINT>& all_subresource_layouts,
    const std::vector<uint64_t>&                           all_subresource_sizes,
    const std::vector<dx12::ResourceStateInfo>&            all_before_states,
    const std::vector<dx12::ResourceStateInfo>&            all_after_states,
    ID3D12Resource*                                        staging_buffer,
    bool                                                   batching)
{
    // The resource state required to copy data to the target resource.
    const dx12::ResourceStateInfo before_copy_state = { D3D12_RESOURCE_STATE_COMMON, D3D12_RESOURCE_BARRIER_FLAG_NONE };

    const dx12::ResourceStateInfo after_copy_state = { (copy_type == kCopyTypeRead) ? D3D12_RESOURCE_STATE_COPY_SOURCE
                                                                                    : D3D12_RESOURCE_STATE_COPY_DEST,
                                                       D3D12_RESOURCE_BARRIER_FLAG_NONE };

    uint64_t subresource_count = subresource_indices.back();
    // The number of incoming subresource states should match the number of subresource layouts.
    if ((subresource_count >= all_before_states.size()) || (subresource_count >= all_after_states.size()))
    {
        GFXRECON_LOG_ERROR("Unexpected number of subresource states for copying resource data.");
        return E_INVALIDARG;
    }
    if (subresource_count >= all_subresource_layouts.size())
    {
        GFXRECON_LOG_ERROR("Unexpected number of subresource layouts for copying resource data.");
        return E_INVALIDARG;
    }
    if (subresource_count >= all_subresource_sizes.size())
    {
        GFXRECON_LOG_ERROR("Unexpected number of subresource sizes for copying resource data.");
        return E_INVALIDARG;
    }
    // Make sure the target resource is resident.
    ID3D12Pageable* const pageable = target_resource;
    if (!SUCCEEDED(device_->MakeResident(1, &pageable)))
    {
        GFXRECON_LOG_ERROR("Failed to make resource resident for copying resource data.");
        return E_FAIL;
    }
    if (staging_buffer == nullptr)
    {
        auto staging_resource = GetStagingBuffer(copy_type, copy_size);
        staging_buffer        = staging_resource;
    }
    resident_resources.push_back(pageable);
    // Transition the resource, copy the data, and transition it back.
    auto resource_desc = target_resource->GetDesc();

    if (resource_desc.SampleDesc.Count > 1)
    {
        GFXRECON_LOG_ERROR("Dx12ResourceDataUtil: Multi-sampled resources are not supported.");
        return E_INVALIDARG;
    }

    HRESULT result = S_OK;
    if (batching == false)
    {
        result = command_allocator_->Reset();
    }
    if (SUCCEEDED(result))
    {
        if (batching == false)
        {
            result = command_list_->Reset(command_allocator_, nullptr);
        }
        if (SUCCEEDED(result))
        {
            uint64_t dest_res_index = 0;
            for (auto sub_index : subresource_indices)
            {
                if ((all_before_states[sub_index].states & D3D12_RESOURCE_STATE_RAYTRACING_ACCELERATION_STRUCTURE) ==
                    D3D12_RESOURCE_STATE_RAYTRACING_ACCELERATION_STRUCTURE)
                {
                    command_list_->Close();
                    GFXRECON_LOG_ERROR(
                        "Dx12ResourceDataUtil: Ray tracing acceleration structure resources are not supported.");
                    return E_INVALIDARG;
                }

                // Prepare resource state.
                AddTransitionBarrier(
                    command_list_, target_resource, sub_index, all_before_states[sub_index], before_copy_state);

                // Copy data.
                if (resource_desc.Dimension == D3D12_RESOURCE_DIMENSION_BUFFER)
                {
                    // There is only 1 subresource for buffers.
                    GFXRECON_ASSERT(sub_index == 0);

                    if (copy_type == kCopyTypeRead)
                    {
                        // Copy from buffer.
                        command_list_->CopyBufferRegion(staging_buffer, 0, target_resource, copy_offset, copy_size);
                    }
                    else
                    {
                        // Copy to buffer.
                        command_list_->CopyBufferRegion(target_resource, 0, staging_buffer, copy_offset, copy_size);
                    }
                }
                else
                {
                    D3D12_TEXTURE_COPY_LOCATION texture_location = {};
                    texture_location.pResource                   = target_resource;
                    texture_location.Type                        = D3D12_TEXTURE_COPY_TYPE_SUBRESOURCE_INDEX;
                    texture_location.SubresourceIndex            = sub_index;

                    D3D12_TEXTURE_COPY_LOCATION copy_location = {};
                    copy_location.pResource                   = staging_buffer;
                    copy_location.Type                        = D3D12_TEXTURE_COPY_TYPE_PLACED_FOOTPRINT;
                    copy_location.PlacedFootprint             = all_subresource_layouts[sub_index];
                    copy_location.PlacedFootprint.Offset      = dest_res_index;

                    if (copy_type == kCopyTypeRead)
                    {
                        // Copy from texture.
                        command_list_->CopyTextureRegion(&copy_location, 0, 0, 0, &texture_location, nullptr);
                    }
                    else
                    {
                        // Copy to texture.
                        command_list_->CopyTextureRegion(&texture_location, 0, 0, 0, &copy_location, nullptr);
                    }
                    dest_res_index += all_subresource_sizes[sub_index];
                }

                // Restore resource state.
                AddTransitionBarrier(
                    command_list_, target_resource, sub_index, after_copy_state, all_after_states[sub_index]);
            }

            // Close and execute the command list.
            if (batching == false)
            {
                result = command_list_->Close();
                if (SUCCEEDED(result))
                {
                    result = ExecuteAndWaitForCommandList();
                }
            }
        }
    }

    if (FAILED(result))
    {
        GFXRECON_LOG_ERROR("Error executing command list to copy resource data. (error = %lx)", result);
    }

    return result;
}

HRESULT
Dx12ResourceDataUtil::ExecuteTransitionCommandList(ID3D12Resource*                             target_resource,
                                                   const std::vector<dx12::ResourceStateInfo>& before_states,
                                                   const std::vector<dx12::ResourceStateInfo>& after_states)
{
    GFXRECON_ASSERT(before_states.size() == after_states.size());
    uint64_t subresource_count = before_states.size();

    // Transition the subresources.
    bool    cmd_list_empty = true;
    auto    resource_desc  = target_resource->GetDesc();
    HRESULT result         = command_allocator_->Reset();
    if (SUCCEEDED(result))
    {
        result = command_list_->Reset(command_allocator_, nullptr);
        if (SUCCEEDED(result))
        {
            for (UINT i = 0; i < subresource_count; ++i)
            {
                if (AddTransitionBarrier(command_list_, target_resource, i, before_states[i], after_states[i]))
                {
                    cmd_list_empty = false;
                }
            }

            // Close and execute the command list.
            result = command_list_->Close();
            if (SUCCEEDED(result) && !cmd_list_empty)
            {
                result = ExecuteAndWaitForCommandList();
            }
        }
    }

    if (FAILED(result))
    {
        GFXRECON_LOG_ERROR("Error executing command list to transition resource state. (error = %lx)", result);
    }

    return result;
}

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)
