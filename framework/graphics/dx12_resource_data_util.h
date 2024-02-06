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

#ifndef GFXRECON_GRAPHICS_DX12_RESOURCE_DATA_UTIL_H
#define GFXRECON_GRAPHICS_DX12_RESOURCE_DATA_UTIL_H

#include "graphics/dx12_util.h"
#include "util/defines.h"
#include "util/platform.h"

#include <d3d12.h>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

class Dx12ResourceDataUtil
{
  public:
    // If the resource is render target, it requires its swapchain's CommandQueue.
    Dx12ResourceDataUtil(ID3D12Device*                  device,
                         uint64_t                       min_buffer_size,
                         dx12::ID3D12CommandQueueComPtr queue = nullptr);

    virtual ~Dx12ResourceDataUtil() {}

    // Buffer has only one subresource, so this function only read the first subresource.
    // If size is UINT64_MAX, it copys the resource from offset to the end.
    HRESULT ReadFromBufferResource(ID3D12Resource*                target_resource,
                                   bool                           try_map_and_copy,
                                   uint64_t                       offset,
                                   uint64_t                       size,
                                   const dx12::ResourceStateInfo& before_state,
                                   const dx12::ResourceStateInfo& after_state,
                                   std::vector<uint8_t>&          data,
                                   ID3D12Resource*                staging_resource = nullptr);

    HRESULT ReadFromTargetSubresources(ID3D12Resource*                             target_resource,
                                       bool                                        try_map_and_copy,
                                       const std::vector<dx12::ResourceStateInfo>& before_states,
                                       const std::vector<dx12::ResourceStateInfo>& after_states,
                                       std::vector<uint8_t>&                       data,
                                       const std::vector<uint32_t>&                subresource_indices,
                                       std::vector<uint64_t>&                      subresource_offsets,
                                       std::vector<uint64_t>&                      subresource_sizes,
                                       ID3D12Resource*                             staging_resource = nullptr);

    HRESULT ReadFromResource(ID3D12Resource*                             target_resource,
                             bool                                        try_map_and_copy,
                             const std::vector<dx12::ResourceStateInfo>& before_states,
                             const std::vector<dx12::ResourceStateInfo>& after_states,
                             std::vector<uint8_t>&                       data,
                             std::vector<uint64_t>&                      subresource_offsets,
                             std::vector<uint64_t>&                      subresource_sizes,
                             ID3D12Resource*                             staging_resource = nullptr);

    HRESULT WriteToResource(ID3D12Resource*                             target_resource,
                            bool                                        try_map_and_copy,
                            const std::vector<dx12::ResourceStateInfo>& before_states,
                            const std::vector<dx12::ResourceStateInfo>& after_states,
                            const std::vector<uint8_t>&                 data,
                            const std::vector<uint64_t>&                subresource_offsets,
                            const std::vector<uint64_t>&                subresource_sizes,
                            ID3D12Resource*                             staging_resource = nullptr,
                            bool                                        batching         = false);

    enum CopyType : int
    {
        kCopyTypeRead  = 0,
        kCopyTypeWrite = 1
    };

    // Create a mappable buffer used to copy data to or from another resource via a command list.
    dx12::ID3D12ResourceComPtr GetStagingBuffer(CopyType type, uint64_t required_buffer_size);
    dx12::ID3D12ResourceComPtr CreateStagingBuffer(CopyType type, uint64_t required_buffer_size);

    void GetResourceCopyInfo(ID3D12Resource*                                  resource,
                             size_t&                                          subresource_count,
                             std::vector<uint64_t>&                           subresource_offsets,
                             std::vector<uint64_t>&                           subresource_sizes,
                             std::vector<D3D12_PLACED_SUBRESOURCE_FOOTPRINT>& layouts,
                             uint64_t&                                        total_size);

    // For buffer and only CopyTypeRead.
    // Copy data to or from a mappable resource. Also transitions the resource to after_states.
    bool CopyMappableBufferResource(ID3D12Resource*                target_resource,
                                    uint64_t                       offset,
                                    uint64_t                       size,
                                    const dx12::ResourceStateInfo& before_state,
                                    const dx12::ResourceStateInfo& after_state,
                                    std::vector<uint8_t>*          read_data);

    // For texture.
    // Copy data to or from a mappable resource. Also transitions the resource to after_states.
    // TODO: Not sure if it's correct for copying all subresources for kCopyTypeWrite,
    bool CopyMappableResource(ID3D12Resource*                             target_resource,
                              const std::vector<dx12::ResourceStateInfo>& all_before_states,
                              const std::vector<dx12::ResourceStateInfo>& all_after_states,
                              CopyType                                    copy_type,
                              std::vector<uint8_t>*                       read_data,
                              const std::vector<uint8_t>*                 write_data,
                              const std::vector<uint32_t>&                subresource_indices,
                              const std::vector<uint64_t>&                all_subresource_offsets,
                              const std::vector<uint64_t>&                all_subresource_sizes);

    HRESULT ExecuteAndWaitForCommandList();

    // Build and execute a command list that copies data to or from the target_resource.
    HRESULT ResetCommandList();

    HRESULT CloseCommandList();

    // copy_offset is for buffer, subresource_indices is for texture,
    HRESULT
    ExecuteCopyCommandList(ID3D12Resource*                                        target_resource,
                           CopyType                                               copy_type,
                           uint64_t                                               copy_offset,
                           uint64_t                                               copy_size,
                           const std::vector<uint32_t>&                           subresource_indices,
                           const std::vector<D3D12_PLACED_SUBRESOURCE_FOOTPRINT>& all_subresource_layouts,
                           const std::vector<uint64_t>&                           all_subresource_sizes,
                           const std::vector<dx12::ResourceStateInfo>&            all_before_states,
                           const std::vector<dx12::ResourceStateInfo>&            all_after_states,
                           ID3D12Resource*                                        staging_buffer = nullptr,
                           bool                                                   batching       = false);

    // Build and execute a command list to transition the target resource's subresources from before_states to
    // after_states.
    HRESULT
    ExecuteTransitionCommandList(ID3D12Resource*                             target_resource,
                                 const std::vector<dx12::ResourceStateInfo>& before_states,
                                 const std::vector<dx12::ResourceStateInfo>& after_states);

    HRESULT
    MapSubresourceAndReadData(ID3D12Resource* resource, UINT subresource, size_t offset, size_t size, uint8_t* data);

    HRESULT MapSubresourceAndWriteData(ID3D12Resource* resource, UINT subresource, size_t size, const uint8_t* data);

  private:
    ID3D12Device*                         device_;
    dx12::ID3D12CommandQueueComPtr        command_queue_;
    dx12::ID3D12CommandAllocatorComPtr    command_allocator_;
    dx12::ID3D12GraphicsCommandListComPtr command_list_;
    dx12::ID3D12ResourceComPtr            staging_buffers_[2];
    dx12::ID3D12FenceComPtr               command_fence_;
    uint64_t                              staging_buffer_sizes_[2];
    const uint64_t                        min_buffer_size_;
    uint64_t                              fence_value_;

    // Temporary buffers.
    std::vector<D3D12_PLACED_SUBRESOURCE_FOOTPRINT> temp_subresource_layouts_;
    std::vector<UINT>                               temp_subresource_row_counts_;
    std::vector<UINT64>                             temp_subresource_row_size_bytes_;

    // Vector to Resident resources
    std::vector<ID3D12Pageable*> resident_resources;
};

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_GRAPHICS_DX12_RESOURCE_DATA_UTIL_H
