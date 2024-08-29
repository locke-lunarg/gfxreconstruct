/*
** Copyright (c) 2022 Advanced Micro Devices, Inc. All rights reserved.
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

#ifndef GFXRECON_DECODE_DX12_OBJECT_SCANNING_CONSUMER_BASE_H
#define GFXRECON_DECODE_DX12_OBJECT_SCANNING_CONSUMER_BASE_H

#include "decode/referenced_object_table.h"
#include "decode/referenced_resource_table.h"
#include "generated/generated_dx12_consumer.h"
#include "util/to_string.h"

#include <cctype>

#include <functional>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class DescriptorUpdateTemplateDecoder;
class Dx12ObjectScanningConsumerBase : public Dx12Consumer
{
  public:
    Dx12ObjectScanningConsumerBase(){}; // No implementation file yet...
    virtual ~Dx12ObjectScanningConsumerBase(){};

    void AddObjectWithCreator(format::HandleId object_id, uint64_t block_index, format::ApiCallId call_id)
    {
        referenced_objects_.AddObjectWithCreator(object_id, block_index, call_id);
    }

    void AddObjectStoreBlock(format::HandleId object_id, uint64_t store_block_index)
    {
        referenced_objects_.AddObjectStoreBlock(object_id, store_block_index);
    }

    void MarkObjectReferenced(format::HandleId object_id) { referenced_objects_.MarkObjectReferenced(object_id); }

    void GetUnreferencedObjectCreationBlocks(std::unordered_set<uint64_t>*         unreferenced_blocks,
                                             decode::UnreferencedPsoCreationCalls* calls_info) const
    {
        referenced_objects_.GetUnreferencedObjectCreationBlocks(unreferenced_blocks, calls_info);
    }

    void GetReferencedResourceIds(std::unordered_set<format::HandleId>* referenced_ids,
                                  std::unordered_set<format::HandleId>* unreferenced_ids) const
    {
        table_.GetReferencedResourceIds(referenced_ids, unreferenced_ids);
    }

  private:
    uint32_t GetBindingCount(format::HandleId container_id, uint32_t binding) const;

    void AddDescriptorToContainer(format::HandleId                                 container_id,
                                  int32_t                                          binding,
                                  uint32_t                                         element,
                                  uint32_t                                         count,
                                  std::function<void(uint32_t, int32_t, uint32_t)> add_descriptor);

    void AddImagesToContainer(format::HandleId                     container_id,
                              int32_t                              binding,
                              uint32_t                             element,
                              uint32_t                             count,
                              const Decoded_VkDescriptorImageInfo* image_infos);

    void AddBuffersToContainer(format::HandleId                      container_id,
                               int32_t                               binding,
                               uint32_t                              element,
                               uint32_t                              count,
                               const Decoded_VkDescriptorBufferInfo* buffer_infos);

    void AddResourcesToContainer(format::HandleId        container_id,
                                 int32_t                 binding,
                                 uint32_t                element,
                                 uint32_t                count,
                                 const format::HandleId* resource_ids);

    void AddImagesToUser(format::HandleId user_id, size_t count, const Decoded_VkDescriptorImageInfo* image_info);

    void AddBuffersToUser(format::HandleId user_id, size_t count, const Decoded_VkDescriptorBufferInfo* buffer_info);

    void AddTexelBufferViewsToUser(format::HandleId user_id, size_t count, const format::HandleId* view_ids);

    void CreateDescriptorUpdateTemplate(
        const StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>* pCreateInfo,
        const HandlePointerDecoder<VkDescriptorUpdateTemplate>*                   pDescriptorUpdateTemplate);

    void UpdateDescriptorSetWithTemplate(format::HandleId                       container_id,
                                         format::HandleId                       template_id,
                                         const DescriptorUpdateTemplateDecoder* decoder);

    void PushDescriptorSetWithTemplate(format::HandleId                       user_id,
                                       format::HandleId                       template_id,
                                       const DescriptorUpdateTemplateDecoder* decoder);

  private:
    ReferencedObjectTable referenced_objects_;

    bool                    loading_state_;
    bool                    loaded_state_;
    ReferencedResourceTable table_;
    LayoutBindingCounts     layout_binding_counts_;
    SetLayouts              set_layouts_;
    UpdateTemplateInfos     template_infos_;
    bool                    not_optimizable_;

    std::unordered_map<format::HandleId, VkDeviceAddress> dev_address_to_resource_map;
    std::unordered_map<VkDeviceAddress, format::HandleId> dev_address_to_buffers_map;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_DX12_OBJECT_SCANNING_CONSUMER_BASE_H
