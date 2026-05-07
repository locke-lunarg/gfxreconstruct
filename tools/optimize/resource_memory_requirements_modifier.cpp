/*
** Copyright (c) 2026 LunarG, Inc.
** Copyright (c) 2026 Arm Limited and/or its affiliates <open-source-office@arm.com>
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

#include "resource_memory_requirements_modifier.h"

#include <algorithm>
#include <cstdint>
#include <limits>
#include <map>
#include <numeric>
#include <utility>
#include <vulkan/vulkan_core.h>

#include "encode/parameter_encoder.h"
#include "format/format.h"
#include "format/format_util.h"
#include "encode/struct_pointer_encoder.h"
#include "encode/parameter_buffer.h"
#include "generated/generated_vulkan_struct_encoders.h"
#include "util/logging.h"
GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

bool ResourceMemoryRequirementsModifier::CanOptimize()
{
    for (auto& entry : resources_memory_requirements_by_device_)
    {
        GenerateAliasingGroups(&entry.second);

        if (std::any_of(entry.second.begin(), entry.second.end(), [](const ResourceMemoryRequirementsInfo& resource) {
                return resource.aliasing_group != 0;
            }))
        {
            return true;
        }
    }

    return false;
}

void ResourceMemoryRequirementsModifier::Process_vkCreateDevice(
    const ApiCallInfo&                                   call_info,
    VkResult                                             returnValue,
    format::HandleId                                     physicalDevice,
    StructPointerDecoder<Decoded_VkDeviceCreateInfo>*    pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDevice>*                      pDevice)
{
    if (!IsModificationPass() || (returnValue != VK_SUCCESS))
    {
        return;
    }

    if ((pDevice == nullptr) || (pDevice->GetPointer() == nullptr))
    {
        return;
    }

    GFXRECON_UNREFERENCED_PARAMETER(call_info);
    GFXRECON_UNREFERENCED_PARAMETER(physicalDevice);
    GFXRECON_UNREFERENCED_PARAMETER(pCreateInfo);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);

    format::arm::ResourceMemoryRequirementsCommandHeader header{};
    header.meta_header.block_header.type = format::BlockType::kMetaDataBlock;
    header.meta_header.meta_data_id      = format::MakeMetaDataId(format::ApiFamilyId::ApiFamily_Vulkan,
                                                             format::arm::MetaDataType::kMemoryRequirementsCommand);
    header.device_id                     = *pDevice->GetPointer();

    auto resources_iter = resources_memory_requirements_by_device_.find(header.device_id);
    if (resources_iter == resources_memory_requirements_by_device_.end())
    {
        return;
    }

    const auto&              device_resources = resources_iter->second;
    encode::ParameterBuffer  parameter_buffer;
    encode::ParameterEncoder encoder(&parameter_buffer);

    uint32_t resources_count = 0;

    for (const auto& resource : device_resources)
    {
        if (resource.aliasing_group == 0)
        {
            continue;
        }
        resources_count++;
        using namespace format::arm;
        encoder.EncodeEnumValue<ResourceMemoryRequirementsPropertiesResourceType>(resource.resource_type);

        uint32_t property_count = 3;
        encoder.EncodeUInt32Value(property_count);

        encoder.EncodeEnumValue<ResourceMemoryRequirementsProperties>(
            ResourceMemoryRequirementsProperties::kResourceHandle);
        encoder.EncodeSizeTValue(sizeof(resource.resource_handle));
        encoder.EncodeHandleIdValue(resource.resource_handle);

        encoder.EncodeEnumValue<ResourceMemoryRequirementsProperties>(
            ResourceMemoryRequirementsProperties::kAliasingGroup);
        encoder.EncodeSizeTValue(sizeof(uint8_t));
        encoder.EncodeUInt8Value(resource.aliasing_group);

        encoder.EncodeEnumValue<ResourceMemoryRequirementsProperties>(
            ResourceMemoryRequirementsProperties::kCreateInfo);
        encoder.EncodeSizeTValue(resource.encoded_create_info.GetDataSize());
        parameter_buffer.Write(resource.encoded_create_info.GetData(), resource.encoded_create_info.GetDataSize());
    }
    header.resources_count = resources_count;

    if (resources_count == 0)
    {
        return;
    }

    auto new_call       = CreatePostCall();
    new_call->type      = util::CallModifierBase::NewCallDataType::MetaDataCall;
    new_call->call_id   = gfxrecon::format::ApiCallId::ApiCall_Unknown;
    new_call->thread_id = 0;

    header.meta_header.block_header.size = format::GetMetaDataBlockBaseSize(header) + parameter_buffer.GetDataSize();

    new_call->parameter_buffer.Write(&header, sizeof(header));
    new_call->parameter_buffer.Write(parameter_buffer.GetData(), parameter_buffer.GetDataSize());
}

ResourceMemoryRequirementsModifier::ResourceMemoryRequirementsInfo*
ResourceMemoryRequirementsModifier::FindResourceInfo(format::HandleId device_id, format::HandleId resource_id)
{
    auto device_resources_iter = resources_memory_requirements_by_device_.find(device_id);
    auto device_index_iter     = resource_index_by_device_.find(device_id);
    if ((device_resources_iter == resources_memory_requirements_by_device_.end()) ||
        (device_index_iter == resource_index_by_device_.end()))
    {
        return nullptr;
    }

    auto& device_resources = device_resources_iter->second;
    auto& device_index     = device_index_iter->second;
    auto  index_iter       = device_index.find(resource_id);
    if (index_iter == device_index.end())
    {
        return nullptr;
    }

    const size_t index = index_iter->second;
    if ((index >= device_resources.size()) || (device_resources[index].resource_handle != resource_id))
    {
        return nullptr;
    }

    return &device_resources[index];
}

void ResourceMemoryRequirementsModifier::TrackBind(format::HandleId device_id,
                                                   format::HandleId resource_id,
                                                   format::HandleId memory_id,
                                                   VkDeviceSize     memory_offset,
                                                   uint64_t         bind_index,
                                                   const char*      resource_name)
{
    auto* resource = FindResourceInfo(device_id, resource_id);
    if (resource == nullptr)
    {
        GFXRECON_LOG_ERROR("AliasingMeta: failed to find %s handle %" PRIu64 " on device %" PRIu64,
                           resource_name,
                           resource_id,
                           device_id);
        return;
    }

    resource->bind_index    = bind_index;
    resource->bind_offset   = memory_offset;
    resource->memory_handle = memory_id;
}

void ResourceMemoryRequirementsModifier::GenerateAliasingGroups(std::vector<ResourceMemoryRequirementsInfo>* resources)
{
    if ((resources == nullptr) || resources->empty())
    {
        return;
    }

    for (auto& resource : *resources)
    {
        resource.aliasing_group = 0;
    }

    // Union-find over resources with matching memory+offset and overlapping lifetimes.
    const size_t        resource_count = resources->size();
    std::vector<size_t> parents(resource_count);
    std::iota(parents.begin(), parents.end(), 0);

    auto find_root = [&parents](size_t index) {
        while (parents[index] != index)
        {
            parents[index] = parents[parents[index]];
            index          = parents[index];
        }
        return index;
    };

    auto union_roots = [&find_root, &parents](size_t lhs, size_t rhs) {
        const size_t lhs_root = find_root(lhs);
        const size_t rhs_root = find_root(rhs);
        if (lhs_root != rhs_root)
        {
            parents[rhs_root] = lhs_root;
        }
    };

    const auto is_lifetime_overlapping = [](const ResourceMemoryRequirementsInfo& lhs,
                                            const ResourceMemoryRequirementsInfo& rhs) {
        if ((lhs.bind_index == 0) || (rhs.bind_index == 0))
        {
            return false;
        }

        const uint64_t start = std::max(lhs.bind_index, rhs.bind_index);
        const uint64_t end   = std::min(lhs.destroy_index, rhs.destroy_index);
        return (start < end);
    };

    using MemoryOffsetBucket = std::pair<format::HandleId, uint64_t>;
    struct MemoryOffsetBucketHash
    {
        size_t operator()(const MemoryOffsetBucket& bucket) const
        {
            const size_t handle_hash = std::hash<format::HandleId>{}(bucket.first);
            const size_t offset_hash = std::hash<uint64_t>{}(bucket.second);
            return handle_hash ^ (offset_hash + 0x9e3779b9 + (handle_hash << 6) + (handle_hash >> 2));
        }
    };

    std::unordered_map<MemoryOffsetBucket, std::vector<size_t>, MemoryOffsetBucketHash> bucketed_resources;
    bucketed_resources.reserve(resource_count);

    for (size_t i = 0; i < resource_count; ++i)
    {
        const ResourceMemoryRequirementsInfo& lhs = (*resources)[i];
        if ((lhs.memory_handle == format::kNullHandleId) || (lhs.bind_index == 0))
        {
            continue;
        }

        bucketed_resources[{ lhs.memory_handle, lhs.bind_offset }].push_back(i);
    }

    for (const auto& bucket_entry : bucketed_resources)
    {
        const auto&  bucket_indices = bucket_entry.second;
        const size_t bucket_size    = bucket_indices.size();
        for (size_t i = 0; i < bucket_size; ++i)
        {
            for (size_t j = i + 1; j < bucket_size; ++j)
            {
                const size_t lhs_index = bucket_indices[i];
                const size_t rhs_index = bucket_indices[j];

                const ResourceMemoryRequirementsInfo& lhs = (*resources)[lhs_index];
                const ResourceMemoryRequirementsInfo& rhs = (*resources)[rhs_index];

                if (is_lifetime_overlapping(lhs, rhs))
                {
                    union_roots(lhs_index, rhs_index);
                }
            }
        }
    }

    // Materialize connected components and assign compact group IDs starting at 1.
    std::map<size_t, std::vector<size_t>> component_members;
    for (size_t i = 0; i < resource_count; ++i)
    {
        const size_t root = find_root(i);
        component_members[root].push_back(i);
    }

    uint32_t next_group = 1;
    for (const auto& entry : component_members)
    {
        const auto& members = entry.second;
        if (members.size() < 2)
        {
            continue;
        }

        if (next_group > std::numeric_limits<uint8_t>::max())
        {
            GFXRECON_LOG_WARNING("AliasingMeta: too many aliasing groups, truncating at %" PRIu8,
                                 std::numeric_limits<uint8_t>::max());
            break;
        }

        for (size_t index : members)
        {
            (*resources)[index].aliasing_group = static_cast<uint8_t>(next_group);
        }
        ++next_group;
    }
}

void ResourceMemoryRequirementsModifier::Process_vkCreateBuffer(
    const ApiCallInfo&                                   call_info,
    VkResult                                             returnValue,
    format::HandleId                                     device,
    StructPointerDecoder<Decoded_VkBufferCreateInfo>*    pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkBuffer>*                      handle)
{
    if (IsModificationPass() || returnValue != VK_SUCCESS)
    {
        return;
    }

    auto& device_resources                                     = resources_memory_requirements_by_device_[device];
    auto& resource_memory_requirements                         = device_resources.emplace_back();
    auto& device_index                                         = resource_index_by_device_[device];
    resource_memory_requirements.resource_handle               = *handle->GetPointer();
    device_index[resource_memory_requirements.resource_handle] = device_resources.size() - 1;
    resource_memory_requirements.resource_type =
        format::arm::ResourceMemoryRequirementsPropertiesResourceType::kResourceTypeVkBuffer;
    encode::ParameterEncoder encoder(&resource_memory_requirements.encoded_create_info);
    encode::EncodeStruct(&encoder, *pCreateInfo->GetPointer());

    GFXRECON_UNREFERENCED_PARAMETER(call_info);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);
}

void ResourceMemoryRequirementsModifier::Process_vkCreateImage(
    const ApiCallInfo&                                   call_info,
    VkResult                                             returnValue,
    format::HandleId                                     device,
    StructPointerDecoder<Decoded_VkImageCreateInfo>*     pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkImage>*                       handle)
{
    if (IsModificationPass() || returnValue != VK_SUCCESS)
    {
        return;
    }

    auto& device_resources                                     = resources_memory_requirements_by_device_[device];
    auto& resource_memory_requirements                         = device_resources.emplace_back();
    auto& device_index                                         = resource_index_by_device_[device];
    resource_memory_requirements.resource_handle               = *handle->GetPointer();
    device_index[resource_memory_requirements.resource_handle] = device_resources.size() - 1;
    resource_memory_requirements.resource_type =
        format::arm::ResourceMemoryRequirementsPropertiesResourceType::kResourceTypeVkImage;
    encode::ParameterEncoder encoder(&resource_memory_requirements.encoded_create_info);
    encode::EncodeStruct(&encoder, *pCreateInfo->GetPointer());

    GFXRECON_UNREFERENCED_PARAMETER(call_info);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);
}

void ResourceMemoryRequirementsModifier::Process_vkCreateTensorARM(
    const ApiCallInfo&                                   call_info,
    VkResult                                             returnValue,
    format::HandleId                                     device,
    StructPointerDecoder<Decoded_VkTensorCreateInfoARM>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkTensorARM>*                   handle)

{
    if (IsModificationPass() || (returnValue != VK_SUCCESS))
    {
        return;
    }

    auto& device_resources                                     = resources_memory_requirements_by_device_[device];
    auto& resource_memory_requirements                         = device_resources.emplace_back();
    auto& device_index                                         = resource_index_by_device_[device];
    resource_memory_requirements.resource_handle               = *handle->GetPointer();
    device_index[resource_memory_requirements.resource_handle] = device_resources.size() - 1;
    resource_memory_requirements.resource_type =
        format::arm::ResourceMemoryRequirementsPropertiesResourceType::kResourceTypeVkTensor;

    encode::ParameterEncoder encoder(&resource_memory_requirements.encoded_create_info);
    encode::EncodeStruct(&encoder, *pCreateInfo->GetPointer());

    GFXRECON_UNREFERENCED_PARAMETER(call_info);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);
}

void ResourceMemoryRequirementsModifier::Process_vkBindBufferMemory(const ApiCallInfo& call_info,
                                                                    VkResult           returnValue,
                                                                    format::HandleId   device,
                                                                    format::HandleId   buffer,
                                                                    format::HandleId   memory,
                                                                    VkDeviceSize       memory_offset)
{
    if (IsModificationPass())
    {
        return;
    }

    if (returnValue != VK_SUCCESS)
    {
        return;
    }

    TrackBind(device, buffer, memory, memory_offset, call_info.index, "buffer");
}

void ResourceMemoryRequirementsModifier::Process_vkBindImageMemory(const ApiCallInfo& call_info,
                                                                   VkResult           returnValue,
                                                                   format::HandleId   device,
                                                                   format::HandleId   image,
                                                                   format::HandleId   memory,
                                                                   VkDeviceSize       memory_offset)
{
    if (IsModificationPass() || returnValue != VK_SUCCESS)
    {
        return;
    }

    TrackBind(device, image, memory, memory_offset, call_info.index, "image");
}

void ResourceMemoryRequirementsModifier::Process_vkBindBufferMemory2(
    const ApiCallInfo&                                    call_info,
    VkResult                                              returnValue,
    format::HandleId                                      device,
    uint32_t                                              bindInfoCount,
    StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>* pBindInfos)
{
    if (IsModificationPass() || returnValue != VK_SUCCESS)
    {
        return;
    }

    if ((pBindInfos == nullptr) || (pBindInfos->GetPointer() == nullptr) ||
        (pBindInfos->GetMetaStructPointer() == nullptr))
    {
        return;
    }

    const VkBindBufferMemoryInfo*         bind_infos      = pBindInfos->GetPointer();
    const Decoded_VkBindBufferMemoryInfo* bind_meta_infos = pBindInfos->GetMetaStructPointer();

    for (uint32_t i = 0; i < bindInfoCount; ++i)
    {
        TrackBind(device,
                  bind_meta_infos[i].buffer,
                  bind_meta_infos[i].memory,
                  bind_infos[i].memoryOffset,
                  call_info.index,
                  "buffer");
    }
}

void ResourceMemoryRequirementsModifier::Process_vkBindBufferMemory2KHR(
    const ApiCallInfo&                                    call_info,
    VkResult                                              returnValue,
    format::HandleId                                      device,
    uint32_t                                              bindInfoCount,
    StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>* pBindInfos)
{
    Process_vkBindBufferMemory2(call_info, returnValue, device, bindInfoCount, pBindInfos);
}

void ResourceMemoryRequirementsModifier::Process_vkBindImageMemory2(
    const ApiCallInfo&                                   call_info,
    VkResult                                             returnValue,
    format::HandleId                                     device,
    uint32_t                                             bindInfoCount,
    StructPointerDecoder<Decoded_VkBindImageMemoryInfo>* pBindInfos)
{
    if (IsModificationPass())
    {
        return;
    }

    if (returnValue != VK_SUCCESS)
    {
        return;
    }

    if ((pBindInfos == nullptr) || (pBindInfos->GetPointer() == nullptr) ||
        (pBindInfos->GetMetaStructPointer() == nullptr))
    {
        return;
    }

    const VkBindImageMemoryInfo*         bind_infos      = pBindInfos->GetPointer();
    const Decoded_VkBindImageMemoryInfo* bind_meta_infos = pBindInfos->GetMetaStructPointer();

    for (uint32_t i = 0; i < bindInfoCount; ++i)
    {
        TrackBind(device,
                  bind_meta_infos[i].image,
                  bind_meta_infos[i].memory,
                  bind_infos[i].memoryOffset,
                  call_info.index,
                  "image");
    }
}

void ResourceMemoryRequirementsModifier::Process_vkBindImageMemory2KHR(
    const ApiCallInfo&                                   call_info,
    VkResult                                             returnValue,
    format::HandleId                                     device,
    uint32_t                                             bindInfoCount,
    StructPointerDecoder<Decoded_VkBindImageMemoryInfo>* pBindInfos)
{
    Process_vkBindImageMemory2(call_info, returnValue, device, bindInfoCount, pBindInfos);
}

void ResourceMemoryRequirementsModifier::Process_vkBindTensorMemoryARM(
    const ApiCallInfo&                                       call_info,
    VkResult                                                 returnValue,
    format::HandleId                                         device,
    uint32_t                                                 bindInfoCount,
    StructPointerDecoder<Decoded_VkBindTensorMemoryInfoARM>* pBindInfos)
{
    if (IsModificationPass() || returnValue != VK_SUCCESS)
    {
        return;
    }

    if ((pBindInfos == nullptr) || (pBindInfos->GetPointer() == nullptr) ||
        (pBindInfos->GetMetaStructPointer() == nullptr))
    {
        return;
    }

    const VkBindTensorMemoryInfoARM*         bind_infos      = pBindInfos->GetPointer();
    const Decoded_VkBindTensorMemoryInfoARM* bind_meta_infos = pBindInfos->GetMetaStructPointer();

    for (uint32_t i = 0; i < bindInfoCount; ++i)
    {
        TrackBind(device,
                  bind_meta_infos[i].tensor,
                  bind_meta_infos[i].memory,
                  bind_infos[i].memoryOffset,
                  call_info.index,
                  "tensor");
    }
}

void ResourceMemoryRequirementsModifier::Process_vkDestroyBuffer(
    const ApiCallInfo&                                   call_info,
    format::HandleId                                     device,
    format::HandleId                                     buffer,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    if (IsModificationPass())
    {
        return;
    }

    OnResourceDestroyCall(device, buffer, call_info.index);

    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);
}

void ResourceMemoryRequirementsModifier::Process_vkDestroyImage(
    const ApiCallInfo&                                   call_info,
    format::HandleId                                     device,
    format::HandleId                                     image,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    if (IsModificationPass())
    {
        return;
    }

    OnResourceDestroyCall(device, image, call_info.index);

    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);
}

void ResourceMemoryRequirementsModifier::Process_vkDestroyTensorARM(
    const ApiCallInfo&                                   call_info,
    format::HandleId                                     device,
    format::HandleId                                     tensor,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    if (IsModificationPass())
    {
        return;
    }

    OnResourceDestroyCall(device, tensor, call_info.index);

    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);
}

void ResourceMemoryRequirementsModifier::OnResourceDestroyCall(format::HandleId device_id,
                                                               format::HandleId resource_id,
                                                               uint64_t         call_index)
{
    auto* resource = FindResourceInfo(device_id, resource_id);
    if (resource == nullptr)
    {
        return;
    }

    resource->destroy_index = call_index;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
