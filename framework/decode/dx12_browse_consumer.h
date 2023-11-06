/*
** Copyright (c) 2023 LunarG, Inc.
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

#ifndef GFXRECON_DECODE_DX12_BROWSE_CONSUMER_H
#define GFXRECON_DECODE_DX12_BROWSE_CONSUMER_H

#include "decode/api_decoder.h"
#include "decode/struct_pointer_decoder.h"
#include "decode/file_processor.h"
#if defined(WIN32)
#include "generated/generated_dx12_decoder.h"
#endif
#include "decode/stat_consumer_base.h"
#include "graphics/dx12_dump_resources.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

struct TrackDumpCommandList
{
    format::HandleId commandlist_id{ format::kNullHandleId };
    uint64_t         commandlist_reset_code_index{ 0 };
    uint64_t         begin_renderpass_code_index{ 0 };
    uint64_t         drawcall_code_index{ 0 };

    // vertex
    std::vector<D3D12_GPU_VIRTUAL_ADDRESS> captured_vertex_buffer_view_gvas;

    // index
    D3D12_GPU_VIRTUAL_ADDRESS captured_index_buffer_view_gva{ decode::kNullGpuAddress };

    // descriptor
    std::vector<format::HandleId> descriptor_heap_ids;

    // render target
    std::vector<format::HandleId> render_target_heap_ids;
    std::vector<size_t>           captured_render_target_cpu_handles;
    format::HandleId              depth_stencil_heap_id{ format::kNullHandleId };
    size_t                        captured_depth_stencil_cpu_handle{ decode::kNullCpuAddress };

    void Clear()
    {
        commandlist_reset_code_index = 0;
        begin_renderpass_code_index  = 0;
        drawcall_code_index          = 0;
        captured_vertex_buffer_view_gvas.clear();
        captured_index_buffer_view_gva = decode::kNullGpuAddress;
        descriptor_heap_ids.clear();
        render_target_heap_ids.clear();
        captured_render_target_cpu_handles.clear();
        depth_stencil_heap_id             = format::kNullHandleId;
        captured_depth_stencil_cpu_handle = decode::kNullCpuAddress;
    }
};

class Dx12BrowseConsumer : public Dx12Consumer
{
  public:
    Dx12BrowseConsumer() {}

    void SetTrackDumpTarget(uint64_t target_drawcall_index) { target_drawcall_index_ = target_drawcall_index; }
    TrackDumpCommandList* GetTrackDumpTarget()
    {
        auto it = track_commandlist_infos_.find(target_command_list_);
        if (it != track_commandlist_infos_.end())
        {
            return &(it->second);
        }
        return nullptr;
    }

    virtual void Process_ID3D12GraphicsCommandList_Reset(const ApiCallInfo& call_info,
                                                         format::HandleId   object_id,
                                                         HRESULT            return_value,
                                                         format::HandleId   pAllocator,
                                                         format::HandleId   pInitialState)
    {
        if (!IsTrackDumpComplete())
        {
            auto it = track_commandlist_infos_.find(object_id);
            if (it != track_commandlist_infos_.end())
            {
                it->second.Clear();
                it->second.commandlist_reset_code_index = call_info.index;
            }
            else
            {
                TrackDumpCommandList info         = {};
                info.commandlist_id               = object_id;
                info.commandlist_reset_code_index = call_info.index;
                track_commandlist_infos_.insert({ object_id, std::move(info) });
            }
        }
    }

    virtual void Process_ID3D12GraphicsCommandList4_BeginRenderPass(
        const ApiCallInfo&                                                  call_info,
        format::HandleId                                                    object_id,
        UINT                                                                NumRenderTargets,
        StructPointerDecoder<Decoded_D3D12_RENDER_PASS_RENDER_TARGET_DESC>* pRenderTargets,
        StructPointerDecoder<Decoded_D3D12_RENDER_PASS_DEPTH_STENCIL_DESC>* pDepthStencil,
        D3D12_RENDER_PASS_FLAGS                                             Flags)
    {
        if (!IsTrackDumpComplete())
        {
            auto it = track_commandlist_infos_.find(object_id);
            if (it != track_commandlist_infos_.end())
            {
                it->second.begin_renderpass_code_index = call_info.index;
                if (NumRenderTargets > 0)
                {
                    auto rt_descriptors = pRenderTargets->GetMetaStructPointer();
                    it->second.render_target_heap_ids.resize(NumRenderTargets);
                    it->second.captured_render_target_cpu_handles.resize(NumRenderTargets);
                    for (uint32_t i = 0; i < NumRenderTargets; ++i)
                    {
                        it->second.render_target_heap_ids[i] = rt_descriptors[i].cpuDescriptor->heap_id;
                        it->second.captured_render_target_cpu_handles[i] =
                            rt_descriptors[i].cpuDescriptor->decoded_value->ptr;
                    }
                }

                if (pDepthStencil)
                {
                    auto ds_descriptor = pDepthStencil->GetMetaStructPointer();
                    if (ds_descriptor)
                    {
                        it->second.depth_stencil_heap_id             = ds_descriptor->cpuDescriptor->heap_id;
                        it->second.captured_depth_stencil_cpu_handle = ds_descriptor->cpuDescriptor->decoded_value->ptr;
                    }
                }
            }
        }
    }

    virtual void Process_ID3D12GraphicsCommandList_OMSetRenderTargets(
        const ApiCallInfo&                                         call_info,
        format::HandleId                                           object_id,
        UINT                                                       NumRenderTargetDescriptors,
        StructPointerDecoder<Decoded_D3D12_CPU_DESCRIPTOR_HANDLE>* pRenderTargetDescriptors,
        BOOL                                                       RTsSingleHandleToDescriptorRange,
        StructPointerDecoder<Decoded_D3D12_CPU_DESCRIPTOR_HANDLE>* pDepthStencilDescriptor)
    {
        if (!IsTrackDumpComplete())
        {
            auto it = track_commandlist_infos_.find(object_id);
            if (it != track_commandlist_infos_.end())
            {
                if (NumRenderTargetDescriptors > 0)
                {
                    auto rt_descriptors = pRenderTargetDescriptors->GetMetaStructPointer();
                    it->second.render_target_heap_ids.resize(NumRenderTargetDescriptors);
                    it->second.captured_render_target_cpu_handles.resize(NumRenderTargetDescriptors);
                    for (uint32_t i = 0; i < NumRenderTargetDescriptors; ++i)
                    {
                        it->second.render_target_heap_ids[i]             = rt_descriptors[i].heap_id;
                        it->second.captured_render_target_cpu_handles[i] = rt_descriptors[i].decoded_value->ptr;
                    }
                }

                if (pDepthStencilDescriptor)
                {
                    auto ds_descriptor = pDepthStencilDescriptor->GetMetaStructPointer();
                    if (ds_descriptor)
                    {
                        it->second.depth_stencil_heap_id             = ds_descriptor->heap_id;
                        it->second.captured_depth_stencil_cpu_handle = ds_descriptor->decoded_value->ptr;
                    }
                }
            }
        }
    }

    virtual void
    Process_ID3D12GraphicsCommandList_IASetVertexBuffers(const ApiCallInfo& call_info,
                                                         format::HandleId   object_id,
                                                         UINT               StartSlot,
                                                         UINT               NumViews,
                                                         StructPointerDecoder<Decoded_D3D12_VERTEX_BUFFER_VIEW>* pViews)
    {
        if (!IsTrackDumpComplete())
        {
            auto it = track_commandlist_infos_.find(object_id);
            if (it != track_commandlist_infos_.end())
            {
                it->second.captured_vertex_buffer_view_gvas.resize(NumViews);
                auto views = pViews->GetMetaStructPointer();
                for (uint32_t i = 0; i < NumViews; ++i)
                {
                    it->second.captured_vertex_buffer_view_gvas[i] = views[i].decoded_value->BufferLocation;
                }
            }
        }
    }

    virtual void
    Process_ID3D12GraphicsCommandList_IASetIndexBuffer(const ApiCallInfo&                                     call_info,
                                                       format::HandleId                                       object_id,
                                                       StructPointerDecoder<Decoded_D3D12_INDEX_BUFFER_VIEW>* pView)
    {
        if (!IsTrackDumpComplete())
        {
            auto it = track_commandlist_infos_.find(object_id);
            if (it != track_commandlist_infos_.end())
            {
                auto view                                 = pView->GetMetaStructPointer();
                it->second.captured_index_buffer_view_gva = view->decoded_value->BufferLocation;
            }
        }
    }

    virtual void
    Process_ID3D12GraphicsCommandList_SetDescriptorHeaps(const ApiCallInfo& call_info,
                                                         format::HandleId   object_id,
                                                         UINT               NumDescriptorHeaps,
                                                         HandlePointerDecoder<ID3D12DescriptorHeap*>* ppDescriptorHeaps)
    {
        if (!IsTrackDumpComplete())
        {
            auto it = track_commandlist_infos_.find(object_id);
            if (it != track_commandlist_infos_.end())
            {
                it->second.descriptor_heap_ids.resize(NumDescriptorHeaps);
                auto heap_ids = ppDescriptorHeaps->GetPointer();
                for (uint32_t i = 0; i < NumDescriptorHeaps; ++i)
                {
                    it->second.descriptor_heap_ids[i] = heap_ids[i];
                }
            }
        }
    }

    virtual void Process_ID3D12GraphicsCommandList_DrawInstanced(const ApiCallInfo& call_info,
                                                                 format::HandleId   object_id,
                                                                 UINT               VertexCountPerInstance,
                                                                 UINT               InstanceCount,
                                                                 UINT               StartVertexLocation,
                                                                 UINT               StartInstanceLocation)
    {
        auto it = track_commandlist_infos_.find(object_id);
        if (it != track_commandlist_infos_.end())
        {
            it->second.drawcall_code_index = call_info.index;
            if (track_drawcall_index_ == target_drawcall_index_)
            {
                target_command_list_ = object_id;
            }
        }
        ++track_drawcall_index_;
    }

    virtual bool IsComplete(uint64_t block_index) override
    {
        return (block_index > kMaxDX12BlockLimit) || IsTrackDumpComplete();
    }

  private:
    bool IsTrackDumpComplete() { return (track_drawcall_index_ > target_drawcall_index_); }

    static int const kMaxDX12BlockLimit = 1000;
    uint64_t         target_drawcall_index_{ 0 };
    uint64_t         track_drawcall_index_{ 0 };
    format::HandleId target_command_list_{ 0 };

    // Key is commandlist_id. We need to know the commandlist of the info because in a commandlist block
    // between reset and close, it might have the other commandlist's commands.
    std::map<format::HandleId, TrackDumpCommandList> track_commandlist_infos_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_DX12_BROWSE_CONSUMER_H
