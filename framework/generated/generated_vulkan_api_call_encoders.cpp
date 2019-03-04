/*
** Copyright (c) 2018-2019 Valve Corporation
** Copyright (c) 2018-2019 LunarG, Inc.
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

/*
** This file is generated from the Khronos Vulkan XML API Registry.
**
*/

#include "generated/generated_vulkan_api_call_encoders.h"

#include "encode/custom_encoder_commands.h"
#include "encode/parameter_encoder.h"
#include "encode/struct_pointer_encoder.h"
#include "encode/trace_manager.h"
#include "format/api_call_id.h"
#include "layer/trace_layer.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)

VKAPI_ATTR VkResult VKAPI_CALL CreateInstance(
    const VkInstanceCreateInfo*                 pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkInstance*                                 pInstance)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateInstance>::Dispatch(encode::TraceManager::Get(), pCreateInfo, pAllocator, pInstance);

    VkResult result = dispatch_CreateInstance(pCreateInfo, pAllocator, pInstance);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateInstance);
    if (encoder)
    {
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pInstance);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateInstance>::Dispatch(encode::TraceManager::Get(), result, pCreateInfo, pAllocator, pInstance);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyInstance(
    VkInstance                                  instance,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyInstance>::Dispatch(encode::TraceManager::Get(), instance, pAllocator);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyInstance);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(instance);
        EncodeStructPtr(encoder, pAllocator);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetInstanceTable(instance)->DestroyInstance(instance, pAllocator);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyInstance>::Dispatch(encode::TraceManager::Get(), instance, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL EnumeratePhysicalDevices(
    VkInstance                                  instance,
    uint32_t*                                   pPhysicalDeviceCount,
    VkPhysicalDevice*                           pPhysicalDevices)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDevices>::Dispatch(encode::TraceManager::Get(), instance, pPhysicalDeviceCount, pPhysicalDevices);

    VkResult result = encode::TraceManager::Get()->GetInstanceTable(instance)->EnumeratePhysicalDevices(instance, pPhysicalDeviceCount, pPhysicalDevices);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkEnumeratePhysicalDevices);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(instance);
        encoder->EncodeUInt32Ptr(pPhysicalDeviceCount);
        encoder->EncodeHandleIdArray(pPhysicalDevices, (pPhysicalDeviceCount != nullptr) ? (*pPhysicalDeviceCount) : 0);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDevices>::Dispatch(encode::TraceManager::Get(), result, instance, pPhysicalDeviceCount, pPhysicalDevices);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFeatures(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceFeatures*                   pFeatures)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures>::Dispatch(encode::TraceManager::Get(), physicalDevice, pFeatures);

    encode::TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceFeatures(physicalDevice, pFeatures);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        EncodeStructPtr(encoder, pFeatures);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures>::Dispatch(encode::TraceManager::Get(), physicalDevice, pFeatures);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFormatProperties(
    VkPhysicalDevice                            physicalDevice,
    VkFormat                                    format,
    VkFormatProperties*                         pFormatProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties>::Dispatch(encode::TraceManager::Get(), physicalDevice, format, pFormatProperties);

    encode::TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceFormatProperties(physicalDevice, format, pFormatProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeEnumValue(format);
        EncodeStructPtr(encoder, pFormatProperties);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties>::Dispatch(encode::TraceManager::Get(), physicalDevice, format, pFormatProperties);
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceImageFormatProperties(
    VkPhysicalDevice                            physicalDevice,
    VkFormat                                    format,
    VkImageType                                 type,
    VkImageTiling                               tiling,
    VkImageUsageFlags                           usage,
    VkImageCreateFlags                          flags,
    VkImageFormatProperties*                    pImageFormatProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties>::Dispatch(encode::TraceManager::Get(), physicalDevice, format, type, tiling, usage, flags, pImageFormatProperties);

    VkResult result = encode::TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceImageFormatProperties(physicalDevice, format, type, tiling, usage, flags, pImageFormatProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeEnumValue(format);
        encoder->EncodeEnumValue(type);
        encoder->EncodeEnumValue(tiling);
        encoder->EncodeFlagsValue(usage);
        encoder->EncodeFlagsValue(flags);
        EncodeStructPtr(encoder, pImageFormatProperties);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, format, type, tiling, usage, flags, pImageFormatProperties);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceProperties(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceProperties*                 pProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties>::Dispatch(encode::TraceManager::Get(), physicalDevice, pProperties);

    encode::TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceProperties(physicalDevice, pProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        EncodeStructPtr(encoder, pProperties);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties>::Dispatch(encode::TraceManager::Get(), physicalDevice, pProperties);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceQueueFamilyProperties(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pQueueFamilyPropertyCount,
    VkQueueFamilyProperties*                    pQueueFamilyProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties>::Dispatch(encode::TraceManager::Get(), physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);

    encode::TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceQueueFamilyProperties(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeUInt32Ptr(pQueueFamilyPropertyCount);
        EncodeStructArray(encoder, pQueueFamilyProperties, (pQueueFamilyPropertyCount != nullptr) ? (*pQueueFamilyPropertyCount) : 0);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties>::Dispatch(encode::TraceManager::Get(), physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceMemoryProperties(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceMemoryProperties*           pMemoryProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties>::Dispatch(encode::TraceManager::Get(), physicalDevice, pMemoryProperties);

    encode::TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceMemoryProperties(physicalDevice, pMemoryProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        EncodeStructPtr(encoder, pMemoryProperties);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties>::Dispatch(encode::TraceManager::Get(), physicalDevice, pMemoryProperties);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDevice(
    VkPhysicalDevice                            physicalDevice,
    const VkDeviceCreateInfo*                   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDevice*                                   pDevice)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDevice>::Dispatch(encode::TraceManager::Get(), physicalDevice, pCreateInfo, pAllocator, pDevice);

    VkResult result = dispatch_CreateDevice(physicalDevice, pCreateInfo, pAllocator, pDevice);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateDevice);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pDevice);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDevice>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, pCreateInfo, pAllocator, pDevice);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyDevice(
    VkDevice                                    device,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDevice>::Dispatch(encode::TraceManager::Get(), device, pAllocator);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyDevice);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pAllocator);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(device)->DestroyDevice(device, pAllocator);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDevice>::Dispatch(encode::TraceManager::Get(), device, pAllocator);
}

VKAPI_ATTR void VKAPI_CALL GetDeviceQueue(
    VkDevice                                    device,
    uint32_t                                    queueFamilyIndex,
    uint32_t                                    queueIndex,
    VkQueue*                                    pQueue)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceQueue>::Dispatch(encode::TraceManager::Get(), device, queueFamilyIndex, queueIndex, pQueue);

    encode::TraceManager::Get()->GetDeviceTable(device)->GetDeviceQueue(device, queueFamilyIndex, queueIndex, pQueue);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetDeviceQueue);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeUInt32Value(queueFamilyIndex);
        encoder->EncodeUInt32Value(queueIndex);
        encoder->EncodeHandleIdPtr(pQueue);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceQueue>::Dispatch(encode::TraceManager::Get(), device, queueFamilyIndex, queueIndex, pQueue);
}

VKAPI_ATTR VkResult VKAPI_CALL QueueSubmit(
    VkQueue                                     queue,
    uint32_t                                    submitCount,
    const VkSubmitInfo*                         pSubmits,
    VkFence                                     fence)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkQueueSubmit>::Dispatch(encode::TraceManager::Get(), queue, submitCount, pSubmits, fence);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(queue)->QueueSubmit(queue, submitCount, pSubmits, fence);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkQueueSubmit);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(queue);
        encoder->EncodeUInt32Value(submitCount);
        EncodeStructArray(encoder, pSubmits, submitCount);
        encoder->EncodeHandleIdValue(fence);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueueSubmit>::Dispatch(encode::TraceManager::Get(), result, queue, submitCount, pSubmits, fence);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL QueueWaitIdle(
    VkQueue                                     queue)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkQueueWaitIdle>::Dispatch(encode::TraceManager::Get(), queue);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(queue)->QueueWaitIdle(queue);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkQueueWaitIdle);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(queue);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueueWaitIdle>::Dispatch(encode::TraceManager::Get(), result, queue);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL DeviceWaitIdle(
    VkDevice                                    device)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDeviceWaitIdle>::Dispatch(encode::TraceManager::Get(), device);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->DeviceWaitIdle(device);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDeviceWaitIdle);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDeviceWaitIdle>::Dispatch(encode::TraceManager::Get(), result, device);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL AllocateMemory(
    VkDevice                                    device,
    const VkMemoryAllocateInfo*                 pAllocateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDeviceMemory*                             pMemory)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkAllocateMemory>::Dispatch(encode::TraceManager::Get(), device, pAllocateInfo, pAllocator, pMemory);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->AllocateMemory(device, pAllocateInfo, pAllocator, pMemory);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkAllocateMemory);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pAllocateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pMemory);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAllocateMemory>::Dispatch(encode::TraceManager::Get(), result, device, pAllocateInfo, pAllocator, pMemory);

    return result;
}

VKAPI_ATTR void VKAPI_CALL FreeMemory(
    VkDevice                                    device,
    VkDeviceMemory                              memory,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkFreeMemory>::Dispatch(encode::TraceManager::Get(), device, memory, pAllocator);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkFreeMemory);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(memory);
        EncodeStructPtr(encoder, pAllocator);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(device)->FreeMemory(device, memory, pAllocator);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkFreeMemory>::Dispatch(encode::TraceManager::Get(), device, memory, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL MapMemory(
    VkDevice                                    device,
    VkDeviceMemory                              memory,
    VkDeviceSize                                offset,
    VkDeviceSize                                size,
    VkMemoryMapFlags                            flags,
    void**                                      ppData)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkMapMemory>::Dispatch(encode::TraceManager::Get(), device, memory, offset, size, flags, ppData);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->MapMemory(device, memory, offset, size, flags, ppData);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkMapMemory);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(memory);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeVkDeviceSizeValue(size);
        encoder->EncodeFlagsValue(flags);
        encoder->EncodeVoidPtrPtr(ppData);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkMapMemory>::Dispatch(encode::TraceManager::Get(), result, device, memory, offset, size, flags, ppData);

    return result;
}

VKAPI_ATTR void VKAPI_CALL UnmapMemory(
    VkDevice                                    device,
    VkDeviceMemory                              memory)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkUnmapMemory>::Dispatch(encode::TraceManager::Get(), device, memory);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkUnmapMemory);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(memory);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(device)->UnmapMemory(device, memory);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkUnmapMemory>::Dispatch(encode::TraceManager::Get(), device, memory);
}

VKAPI_ATTR VkResult VKAPI_CALL FlushMappedMemoryRanges(
    VkDevice                                    device,
    uint32_t                                    memoryRangeCount,
    const VkMappedMemoryRange*                  pMemoryRanges)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkFlushMappedMemoryRanges>::Dispatch(encode::TraceManager::Get(), device, memoryRangeCount, pMemoryRanges);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->FlushMappedMemoryRanges(device, memoryRangeCount, pMemoryRanges);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkFlushMappedMemoryRanges);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeUInt32Value(memoryRangeCount);
        EncodeStructArray(encoder, pMemoryRanges, memoryRangeCount);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkFlushMappedMemoryRanges>::Dispatch(encode::TraceManager::Get(), result, device, memoryRangeCount, pMemoryRanges);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL InvalidateMappedMemoryRanges(
    VkDevice                                    device,
    uint32_t                                    memoryRangeCount,
    const VkMappedMemoryRange*                  pMemoryRanges)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkInvalidateMappedMemoryRanges>::Dispatch(encode::TraceManager::Get(), device, memoryRangeCount, pMemoryRanges);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->InvalidateMappedMemoryRanges(device, memoryRangeCount, pMemoryRanges);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkInvalidateMappedMemoryRanges);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeUInt32Value(memoryRangeCount);
        EncodeStructArray(encoder, pMemoryRanges, memoryRangeCount);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkInvalidateMappedMemoryRanges>::Dispatch(encode::TraceManager::Get(), result, device, memoryRangeCount, pMemoryRanges);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetDeviceMemoryCommitment(
    VkDevice                                    device,
    VkDeviceMemory                              memory,
    VkDeviceSize*                               pCommittedMemoryInBytes)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryCommitment>::Dispatch(encode::TraceManager::Get(), device, memory, pCommittedMemoryInBytes);

    encode::TraceManager::Get()->GetDeviceTable(device)->GetDeviceMemoryCommitment(device, memory, pCommittedMemoryInBytes);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetDeviceMemoryCommitment);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(memory);
        encoder->EncodeVkDeviceSizePtr(pCommittedMemoryInBytes);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceMemoryCommitment>::Dispatch(encode::TraceManager::Get(), device, memory, pCommittedMemoryInBytes);
}

VKAPI_ATTR VkResult VKAPI_CALL BindBufferMemory(
    VkDevice                                    device,
    VkBuffer                                    buffer,
    VkDeviceMemory                              memory,
    VkDeviceSize                                memoryOffset)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBindBufferMemory>::Dispatch(encode::TraceManager::Get(), device, buffer, memory, memoryOffset);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->BindBufferMemory(device, buffer, memory, memoryOffset);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkBindBufferMemory);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(buffer);
        encoder->EncodeHandleIdValue(memory);
        encoder->EncodeVkDeviceSizeValue(memoryOffset);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindBufferMemory>::Dispatch(encode::TraceManager::Get(), result, device, buffer, memory, memoryOffset);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL BindImageMemory(
    VkDevice                                    device,
    VkImage                                     image,
    VkDeviceMemory                              memory,
    VkDeviceSize                                memoryOffset)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBindImageMemory>::Dispatch(encode::TraceManager::Get(), device, image, memory, memoryOffset);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->BindImageMemory(device, image, memory, memoryOffset);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkBindImageMemory);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(image);
        encoder->EncodeHandleIdValue(memory);
        encoder->EncodeVkDeviceSizeValue(memoryOffset);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindImageMemory>::Dispatch(encode::TraceManager::Get(), result, device, image, memory, memoryOffset);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetBufferMemoryRequirements(
    VkDevice                                    device,
    VkBuffer                                    buffer,
    VkMemoryRequirements*                       pMemoryRequirements)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements>::Dispatch(encode::TraceManager::Get(), device, buffer, pMemoryRequirements);

    encode::TraceManager::Get()->GetDeviceTable(device)->GetBufferMemoryRequirements(device, buffer, pMemoryRequirements);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(buffer);
        EncodeStructPtr(encoder, pMemoryRequirements);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements>::Dispatch(encode::TraceManager::Get(), device, buffer, pMemoryRequirements);
}

VKAPI_ATTR void VKAPI_CALL GetImageMemoryRequirements(
    VkDevice                                    device,
    VkImage                                     image,
    VkMemoryRequirements*                       pMemoryRequirements)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements>::Dispatch(encode::TraceManager::Get(), device, image, pMemoryRequirements);

    encode::TraceManager::Get()->GetDeviceTable(device)->GetImageMemoryRequirements(device, image, pMemoryRequirements);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetImageMemoryRequirements);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(image);
        EncodeStructPtr(encoder, pMemoryRequirements);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements>::Dispatch(encode::TraceManager::Get(), device, image, pMemoryRequirements);
}

VKAPI_ATTR void VKAPI_CALL GetImageSparseMemoryRequirements(
    VkDevice                                    device,
    VkImage                                     image,
    uint32_t*                                   pSparseMemoryRequirementCount,
    VkSparseImageMemoryRequirements*            pSparseMemoryRequirements)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements>::Dispatch(encode::TraceManager::Get(), device, image, pSparseMemoryRequirementCount, pSparseMemoryRequirements);

    encode::TraceManager::Get()->GetDeviceTable(device)->GetImageSparseMemoryRequirements(device, image, pSparseMemoryRequirementCount, pSparseMemoryRequirements);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(image);
        encoder->EncodeUInt32Ptr(pSparseMemoryRequirementCount);
        EncodeStructArray(encoder, pSparseMemoryRequirements, (pSparseMemoryRequirementCount != nullptr) ? (*pSparseMemoryRequirementCount) : 0);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements>::Dispatch(encode::TraceManager::Get(), device, image, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSparseImageFormatProperties(
    VkPhysicalDevice                            physicalDevice,
    VkFormat                                    format,
    VkImageType                                 type,
    VkSampleCountFlagBits                       samples,
    VkImageUsageFlags                           usage,
    VkImageTiling                               tiling,
    uint32_t*                                   pPropertyCount,
    VkSparseImageFormatProperties*              pProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties>::Dispatch(encode::TraceManager::Get(), physicalDevice, format, type, samples, usage, tiling, pPropertyCount, pProperties);

    encode::TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceSparseImageFormatProperties(physicalDevice, format, type, samples, usage, tiling, pPropertyCount, pProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeEnumValue(format);
        encoder->EncodeEnumValue(type);
        encoder->EncodeEnumValue(samples);
        encoder->EncodeFlagsValue(usage);
        encoder->EncodeEnumValue(tiling);
        encoder->EncodeUInt32Ptr(pPropertyCount);
        EncodeStructArray(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties>::Dispatch(encode::TraceManager::Get(), physicalDevice, format, type, samples, usage, tiling, pPropertyCount, pProperties);
}

VKAPI_ATTR VkResult VKAPI_CALL QueueBindSparse(
    VkQueue                                     queue,
    uint32_t                                    bindInfoCount,
    const VkBindSparseInfo*                     pBindInfo,
    VkFence                                     fence)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkQueueBindSparse>::Dispatch(encode::TraceManager::Get(), queue, bindInfoCount, pBindInfo, fence);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(queue)->QueueBindSparse(queue, bindInfoCount, pBindInfo, fence);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkQueueBindSparse);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(queue);
        encoder->EncodeUInt32Value(bindInfoCount);
        EncodeStructArray(encoder, pBindInfo, bindInfoCount);
        encoder->EncodeHandleIdValue(fence);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueueBindSparse>::Dispatch(encode::TraceManager::Get(), result, queue, bindInfoCount, pBindInfo, fence);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateFence(
    VkDevice                                    device,
    const VkFenceCreateInfo*                    pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkFence*                                    pFence)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateFence>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pFence);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->CreateFence(device, pCreateInfo, pAllocator, pFence);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateFence);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pFence);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateFence>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pFence);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyFence(
    VkDevice                                    device,
    VkFence                                     fence,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyFence>::Dispatch(encode::TraceManager::Get(), device, fence, pAllocator);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyFence);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(fence);
        EncodeStructPtr(encoder, pAllocator);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(device)->DestroyFence(device, fence, pAllocator);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyFence>::Dispatch(encode::TraceManager::Get(), device, fence, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL ResetFences(
    VkDevice                                    device,
    uint32_t                                    fenceCount,
    const VkFence*                              pFences)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkResetFences>::Dispatch(encode::TraceManager::Get(), device, fenceCount, pFences);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->ResetFences(device, fenceCount, pFences);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkResetFences);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeUInt32Value(fenceCount);
        encoder->EncodeHandleIdArray(pFences, fenceCount);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkResetFences>::Dispatch(encode::TraceManager::Get(), result, device, fenceCount, pFences);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetFenceStatus(
    VkDevice                                    device,
    VkFence                                     fence)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetFenceStatus>::Dispatch(encode::TraceManager::Get(), device, fence);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->GetFenceStatus(device, fence);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetFenceStatus);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(fence);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetFenceStatus>::Dispatch(encode::TraceManager::Get(), result, device, fence);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL WaitForFences(
    VkDevice                                    device,
    uint32_t                                    fenceCount,
    const VkFence*                              pFences,
    VkBool32                                    waitAll,
    uint64_t                                    timeout)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkWaitForFences>::Dispatch(encode::TraceManager::Get(), device, fenceCount, pFences, waitAll, timeout);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->WaitForFences(device, fenceCount, pFences, waitAll, timeout);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkWaitForFences);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeUInt32Value(fenceCount);
        encoder->EncodeHandleIdArray(pFences, fenceCount);
        encoder->EncodeVkBool32Value(waitAll);
        encoder->EncodeUInt64Value(timeout);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkWaitForFences>::Dispatch(encode::TraceManager::Get(), result, device, fenceCount, pFences, waitAll, timeout);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateSemaphore(
    VkDevice                                    device,
    const VkSemaphoreCreateInfo*                pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSemaphore*                                pSemaphore)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateSemaphore>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pSemaphore);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->CreateSemaphore(device, pCreateInfo, pAllocator, pSemaphore);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateSemaphore);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pSemaphore);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSemaphore>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pSemaphore);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroySemaphore(
    VkDevice                                    device,
    VkSemaphore                                 semaphore,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroySemaphore>::Dispatch(encode::TraceManager::Get(), device, semaphore, pAllocator);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroySemaphore);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(semaphore);
        EncodeStructPtr(encoder, pAllocator);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(device)->DestroySemaphore(device, semaphore, pAllocator);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySemaphore>::Dispatch(encode::TraceManager::Get(), device, semaphore, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateEvent(
    VkDevice                                    device,
    const VkEventCreateInfo*                    pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkEvent*                                    pEvent)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateEvent>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pEvent);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->CreateEvent(device, pCreateInfo, pAllocator, pEvent);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateEvent);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pEvent);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateEvent>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pEvent);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyEvent(
    VkDevice                                    device,
    VkEvent                                     event,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyEvent>::Dispatch(encode::TraceManager::Get(), device, event, pAllocator);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyEvent);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(event);
        EncodeStructPtr(encoder, pAllocator);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(device)->DestroyEvent(device, event, pAllocator);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyEvent>::Dispatch(encode::TraceManager::Get(), device, event, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL GetEventStatus(
    VkDevice                                    device,
    VkEvent                                     event)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetEventStatus>::Dispatch(encode::TraceManager::Get(), device, event);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->GetEventStatus(device, event);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetEventStatus);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(event);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetEventStatus>::Dispatch(encode::TraceManager::Get(), result, device, event);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL SetEvent(
    VkDevice                                    device,
    VkEvent                                     event)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkSetEvent>::Dispatch(encode::TraceManager::Get(), device, event);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->SetEvent(device, event);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkSetEvent);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(event);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSetEvent>::Dispatch(encode::TraceManager::Get(), result, device, event);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL ResetEvent(
    VkDevice                                    device,
    VkEvent                                     event)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkResetEvent>::Dispatch(encode::TraceManager::Get(), device, event);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->ResetEvent(device, event);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkResetEvent);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(event);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkResetEvent>::Dispatch(encode::TraceManager::Get(), result, device, event);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateQueryPool(
    VkDevice                                    device,
    const VkQueryPoolCreateInfo*                pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkQueryPool*                                pQueryPool)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateQueryPool>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pQueryPool);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->CreateQueryPool(device, pCreateInfo, pAllocator, pQueryPool);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateQueryPool);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pQueryPool);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateQueryPool>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pQueryPool);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyQueryPool(
    VkDevice                                    device,
    VkQueryPool                                 queryPool,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyQueryPool>::Dispatch(encode::TraceManager::Get(), device, queryPool, pAllocator);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyQueryPool);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(queryPool);
        EncodeStructPtr(encoder, pAllocator);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(device)->DestroyQueryPool(device, queryPool, pAllocator);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyQueryPool>::Dispatch(encode::TraceManager::Get(), device, queryPool, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL GetQueryPoolResults(
    VkDevice                                    device,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount,
    size_t                                      dataSize,
    void*                                       pData,
    VkDeviceSize                                stride,
    VkQueryResultFlags                          flags)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetQueryPoolResults>::Dispatch(encode::TraceManager::Get(), device, queryPool, firstQuery, queryCount, dataSize, pData, stride, flags);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->GetQueryPoolResults(device, queryPool, firstQuery, queryCount, dataSize, pData, stride, flags);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetQueryPoolResults);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(queryPool);
        encoder->EncodeUInt32Value(firstQuery);
        encoder->EncodeUInt32Value(queryCount);
        encoder->EncodeSizeTValue(dataSize);
        encoder->EncodeVoidArray(pData, dataSize);
        encoder->EncodeVkDeviceSizeValue(stride);
        encoder->EncodeFlagsValue(flags);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetQueryPoolResults>::Dispatch(encode::TraceManager::Get(), result, device, queryPool, firstQuery, queryCount, dataSize, pData, stride, flags);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateBuffer(
    VkDevice                                    device,
    const VkBufferCreateInfo*                   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkBuffer*                                   pBuffer)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateBuffer>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pBuffer);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->CreateBuffer(device, pCreateInfo, pAllocator, pBuffer);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateBuffer);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pBuffer);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateBuffer>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pBuffer);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyBuffer(
    VkDevice                                    device,
    VkBuffer                                    buffer,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyBuffer>::Dispatch(encode::TraceManager::Get(), device, buffer, pAllocator);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyBuffer);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(buffer);
        EncodeStructPtr(encoder, pAllocator);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(device)->DestroyBuffer(device, buffer, pAllocator);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyBuffer>::Dispatch(encode::TraceManager::Get(), device, buffer, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateBufferView(
    VkDevice                                    device,
    const VkBufferViewCreateInfo*               pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkBufferView*                               pView)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateBufferView>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pView);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->CreateBufferView(device, pCreateInfo, pAllocator, pView);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateBufferView);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pView);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateBufferView>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pView);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyBufferView(
    VkDevice                                    device,
    VkBufferView                                bufferView,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyBufferView>::Dispatch(encode::TraceManager::Get(), device, bufferView, pAllocator);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyBufferView);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(bufferView);
        EncodeStructPtr(encoder, pAllocator);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(device)->DestroyBufferView(device, bufferView, pAllocator);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyBufferView>::Dispatch(encode::TraceManager::Get(), device, bufferView, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateImage(
    VkDevice                                    device,
    const VkImageCreateInfo*                    pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkImage*                                    pImage)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateImage>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pImage);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->CreateImage(device, pCreateInfo, pAllocator, pImage);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateImage);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pImage);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateImage>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pImage);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyImage(
    VkDevice                                    device,
    VkImage                                     image,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyImage>::Dispatch(encode::TraceManager::Get(), device, image, pAllocator);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyImage);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(image);
        EncodeStructPtr(encoder, pAllocator);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(device)->DestroyImage(device, image, pAllocator);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyImage>::Dispatch(encode::TraceManager::Get(), device, image, pAllocator);
}

VKAPI_ATTR void VKAPI_CALL GetImageSubresourceLayout(
    VkDevice                                    device,
    VkImage                                     image,
    const VkImageSubresource*                   pSubresource,
    VkSubresourceLayout*                        pLayout)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageSubresourceLayout>::Dispatch(encode::TraceManager::Get(), device, image, pSubresource, pLayout);

    encode::TraceManager::Get()->GetDeviceTable(device)->GetImageSubresourceLayout(device, image, pSubresource, pLayout);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetImageSubresourceLayout);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(image);
        EncodeStructPtr(encoder, pSubresource);
        EncodeStructPtr(encoder, pLayout);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSubresourceLayout>::Dispatch(encode::TraceManager::Get(), device, image, pSubresource, pLayout);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateImageView(
    VkDevice                                    device,
    const VkImageViewCreateInfo*                pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkImageView*                                pView)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateImageView>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pView);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->CreateImageView(device, pCreateInfo, pAllocator, pView);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateImageView);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pView);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateImageView>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pView);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyImageView(
    VkDevice                                    device,
    VkImageView                                 imageView,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyImageView>::Dispatch(encode::TraceManager::Get(), device, imageView, pAllocator);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyImageView);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(imageView);
        EncodeStructPtr(encoder, pAllocator);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(device)->DestroyImageView(device, imageView, pAllocator);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyImageView>::Dispatch(encode::TraceManager::Get(), device, imageView, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateShaderModule(
    VkDevice                                    device,
    const VkShaderModuleCreateInfo*             pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkShaderModule*                             pShaderModule)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateShaderModule>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pShaderModule);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->CreateShaderModule(device, pCreateInfo, pAllocator, pShaderModule);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateShaderModule);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pShaderModule);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateShaderModule>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pShaderModule);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyShaderModule(
    VkDevice                                    device,
    VkShaderModule                              shaderModule,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyShaderModule>::Dispatch(encode::TraceManager::Get(), device, shaderModule, pAllocator);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyShaderModule);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(shaderModule);
        EncodeStructPtr(encoder, pAllocator);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(device)->DestroyShaderModule(device, shaderModule, pAllocator);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyShaderModule>::Dispatch(encode::TraceManager::Get(), device, shaderModule, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL CreatePipelineCache(
    VkDevice                                    device,
    const VkPipelineCacheCreateInfo*            pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkPipelineCache*                            pPipelineCache)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreatePipelineCache>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pPipelineCache);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->CreatePipelineCache(device, pCreateInfo, pAllocator, pPipelineCache);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreatePipelineCache);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pPipelineCache);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreatePipelineCache>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pPipelineCache);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyPipelineCache(
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyPipelineCache>::Dispatch(encode::TraceManager::Get(), device, pipelineCache, pAllocator);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyPipelineCache);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(pipelineCache);
        EncodeStructPtr(encoder, pAllocator);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(device)->DestroyPipelineCache(device, pipelineCache, pAllocator);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPipelineCache>::Dispatch(encode::TraceManager::Get(), device, pipelineCache, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL GetPipelineCacheData(
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache,
    size_t*                                     pDataSize,
    void*                                       pData)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPipelineCacheData>::Dispatch(encode::TraceManager::Get(), device, pipelineCache, pDataSize, pData);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->GetPipelineCacheData(device, pipelineCache, pDataSize, pData);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPipelineCacheData);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(pipelineCache);
        encoder->EncodeSizeTPtr(pDataSize);
        encoder->EncodeVoidArray(pData, (pDataSize != nullptr) ? (*pDataSize) : 0);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPipelineCacheData>::Dispatch(encode::TraceManager::Get(), result, device, pipelineCache, pDataSize, pData);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL MergePipelineCaches(
    VkDevice                                    device,
    VkPipelineCache                             dstCache,
    uint32_t                                    srcCacheCount,
    const VkPipelineCache*                      pSrcCaches)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkMergePipelineCaches>::Dispatch(encode::TraceManager::Get(), device, dstCache, srcCacheCount, pSrcCaches);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->MergePipelineCaches(device, dstCache, srcCacheCount, pSrcCaches);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkMergePipelineCaches);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(dstCache);
        encoder->EncodeUInt32Value(srcCacheCount);
        encoder->EncodeHandleIdArray(pSrcCaches, srcCacheCount);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkMergePipelineCaches>::Dispatch(encode::TraceManager::Get(), result, device, dstCache, srcCacheCount, pSrcCaches);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateGraphicsPipelines(
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache,
    uint32_t                                    createInfoCount,
    const VkGraphicsPipelineCreateInfo*         pCreateInfos,
    const VkAllocationCallbacks*                pAllocator,
    VkPipeline*                                 pPipelines)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateGraphicsPipelines>::Dispatch(encode::TraceManager::Get(), device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->CreateGraphicsPipelines(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateGraphicsPipelines);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(pipelineCache);
        encoder->EncodeUInt32Value(createInfoCount);
        EncodeStructArray(encoder, pCreateInfos, createInfoCount);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdArray(pPipelines, createInfoCount);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateGraphicsPipelines>::Dispatch(encode::TraceManager::Get(), result, device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateComputePipelines(
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache,
    uint32_t                                    createInfoCount,
    const VkComputePipelineCreateInfo*          pCreateInfos,
    const VkAllocationCallbacks*                pAllocator,
    VkPipeline*                                 pPipelines)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateComputePipelines>::Dispatch(encode::TraceManager::Get(), device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->CreateComputePipelines(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateComputePipelines);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(pipelineCache);
        encoder->EncodeUInt32Value(createInfoCount);
        EncodeStructArray(encoder, pCreateInfos, createInfoCount);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdArray(pPipelines, createInfoCount);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateComputePipelines>::Dispatch(encode::TraceManager::Get(), result, device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyPipeline(
    VkDevice                                    device,
    VkPipeline                                  pipeline,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyPipeline>::Dispatch(encode::TraceManager::Get(), device, pipeline, pAllocator);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyPipeline);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(pipeline);
        EncodeStructPtr(encoder, pAllocator);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(device)->DestroyPipeline(device, pipeline, pAllocator);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPipeline>::Dispatch(encode::TraceManager::Get(), device, pipeline, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL CreatePipelineLayout(
    VkDevice                                    device,
    const VkPipelineLayoutCreateInfo*           pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkPipelineLayout*                           pPipelineLayout)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreatePipelineLayout>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pPipelineLayout);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->CreatePipelineLayout(device, pCreateInfo, pAllocator, pPipelineLayout);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreatePipelineLayout);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pPipelineLayout);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreatePipelineLayout>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pPipelineLayout);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyPipelineLayout(
    VkDevice                                    device,
    VkPipelineLayout                            pipelineLayout,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyPipelineLayout>::Dispatch(encode::TraceManager::Get(), device, pipelineLayout, pAllocator);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyPipelineLayout);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(pipelineLayout);
        EncodeStructPtr(encoder, pAllocator);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(device)->DestroyPipelineLayout(device, pipelineLayout, pAllocator);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyPipelineLayout>::Dispatch(encode::TraceManager::Get(), device, pipelineLayout, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateSampler(
    VkDevice                                    device,
    const VkSamplerCreateInfo*                  pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSampler*                                  pSampler)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateSampler>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pSampler);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->CreateSampler(device, pCreateInfo, pAllocator, pSampler);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateSampler);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pSampler);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSampler>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pSampler);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroySampler(
    VkDevice                                    device,
    VkSampler                                   sampler,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroySampler>::Dispatch(encode::TraceManager::Get(), device, sampler, pAllocator);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroySampler);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(sampler);
        EncodeStructPtr(encoder, pAllocator);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(device)->DestroySampler(device, sampler, pAllocator);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySampler>::Dispatch(encode::TraceManager::Get(), device, sampler, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDescriptorSetLayout(
    VkDevice                                    device,
    const VkDescriptorSetLayoutCreateInfo*      pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDescriptorSetLayout*                      pSetLayout)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDescriptorSetLayout>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pSetLayout);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->CreateDescriptorSetLayout(device, pCreateInfo, pAllocator, pSetLayout);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateDescriptorSetLayout);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pSetLayout);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDescriptorSetLayout>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pSetLayout);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyDescriptorSetLayout(
    VkDevice                                    device,
    VkDescriptorSetLayout                       descriptorSetLayout,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDescriptorSetLayout>::Dispatch(encode::TraceManager::Get(), device, descriptorSetLayout, pAllocator);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyDescriptorSetLayout);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(descriptorSetLayout);
        EncodeStructPtr(encoder, pAllocator);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(device)->DestroyDescriptorSetLayout(device, descriptorSetLayout, pAllocator);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDescriptorSetLayout>::Dispatch(encode::TraceManager::Get(), device, descriptorSetLayout, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDescriptorPool(
    VkDevice                                    device,
    const VkDescriptorPoolCreateInfo*           pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDescriptorPool*                           pDescriptorPool)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDescriptorPool>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pDescriptorPool);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->CreateDescriptorPool(device, pCreateInfo, pAllocator, pDescriptorPool);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateDescriptorPool);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pDescriptorPool);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDescriptorPool>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pDescriptorPool);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyDescriptorPool(
    VkDevice                                    device,
    VkDescriptorPool                            descriptorPool,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDescriptorPool>::Dispatch(encode::TraceManager::Get(), device, descriptorPool, pAllocator);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyDescriptorPool);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(descriptorPool);
        EncodeStructPtr(encoder, pAllocator);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(device)->DestroyDescriptorPool(device, descriptorPool, pAllocator);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDescriptorPool>::Dispatch(encode::TraceManager::Get(), device, descriptorPool, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL ResetDescriptorPool(
    VkDevice                                    device,
    VkDescriptorPool                            descriptorPool,
    VkDescriptorPoolResetFlags                  flags)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkResetDescriptorPool>::Dispatch(encode::TraceManager::Get(), device, descriptorPool, flags);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->ResetDescriptorPool(device, descriptorPool, flags);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkResetDescriptorPool);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(descriptorPool);
        encoder->EncodeFlagsValue(flags);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkResetDescriptorPool>::Dispatch(encode::TraceManager::Get(), result, device, descriptorPool, flags);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL AllocateDescriptorSets(
    VkDevice                                    device,
    const VkDescriptorSetAllocateInfo*          pAllocateInfo,
    VkDescriptorSet*                            pDescriptorSets)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkAllocateDescriptorSets>::Dispatch(encode::TraceManager::Get(), device, pAllocateInfo, pDescriptorSets);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->AllocateDescriptorSets(device, pAllocateInfo, pDescriptorSets);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkAllocateDescriptorSets);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pAllocateInfo);
        encoder->EncodeHandleIdArray(pDescriptorSets, pAllocateInfo->descriptorSetCount);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAllocateDescriptorSets>::Dispatch(encode::TraceManager::Get(), result, device, pAllocateInfo, pDescriptorSets);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL FreeDescriptorSets(
    VkDevice                                    device,
    VkDescriptorPool                            descriptorPool,
    uint32_t                                    descriptorSetCount,
    const VkDescriptorSet*                      pDescriptorSets)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkFreeDescriptorSets>::Dispatch(encode::TraceManager::Get(), device, descriptorPool, descriptorSetCount, pDescriptorSets);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->FreeDescriptorSets(device, descriptorPool, descriptorSetCount, pDescriptorSets);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkFreeDescriptorSets);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(descriptorPool);
        encoder->EncodeUInt32Value(descriptorSetCount);
        encoder->EncodeHandleIdArray(pDescriptorSets, descriptorSetCount);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkFreeDescriptorSets>::Dispatch(encode::TraceManager::Get(), result, device, descriptorPool, descriptorSetCount, pDescriptorSets);

    return result;
}

VKAPI_ATTR void VKAPI_CALL UpdateDescriptorSets(
    VkDevice                                    device,
    uint32_t                                    descriptorWriteCount,
    const VkWriteDescriptorSet*                 pDescriptorWrites,
    uint32_t                                    descriptorCopyCount,
    const VkCopyDescriptorSet*                  pDescriptorCopies)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSets>::Dispatch(encode::TraceManager::Get(), device, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount, pDescriptorCopies);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkUpdateDescriptorSets);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeUInt32Value(descriptorWriteCount);
        EncodeStructArray(encoder, pDescriptorWrites, descriptorWriteCount);
        encoder->EncodeUInt32Value(descriptorCopyCount);
        EncodeStructArray(encoder, pDescriptorCopies, descriptorCopyCount);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(device)->UpdateDescriptorSets(device, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount, pDescriptorCopies);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkUpdateDescriptorSets>::Dispatch(encode::TraceManager::Get(), device, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount, pDescriptorCopies);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateFramebuffer(
    VkDevice                                    device,
    const VkFramebufferCreateInfo*              pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkFramebuffer*                              pFramebuffer)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateFramebuffer>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pFramebuffer);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->CreateFramebuffer(device, pCreateInfo, pAllocator, pFramebuffer);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateFramebuffer);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pFramebuffer);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateFramebuffer>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pFramebuffer);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyFramebuffer(
    VkDevice                                    device,
    VkFramebuffer                               framebuffer,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyFramebuffer>::Dispatch(encode::TraceManager::Get(), device, framebuffer, pAllocator);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyFramebuffer);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(framebuffer);
        EncodeStructPtr(encoder, pAllocator);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(device)->DestroyFramebuffer(device, framebuffer, pAllocator);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyFramebuffer>::Dispatch(encode::TraceManager::Get(), device, framebuffer, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateRenderPass(
    VkDevice                                    device,
    const VkRenderPassCreateInfo*               pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkRenderPass*                               pRenderPass)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateRenderPass>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pRenderPass);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->CreateRenderPass(device, pCreateInfo, pAllocator, pRenderPass);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateRenderPass);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pRenderPass);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateRenderPass>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pRenderPass);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyRenderPass(
    VkDevice                                    device,
    VkRenderPass                                renderPass,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyRenderPass>::Dispatch(encode::TraceManager::Get(), device, renderPass, pAllocator);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyRenderPass);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(renderPass);
        EncodeStructPtr(encoder, pAllocator);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(device)->DestroyRenderPass(device, renderPass, pAllocator);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyRenderPass>::Dispatch(encode::TraceManager::Get(), device, renderPass, pAllocator);
}

VKAPI_ATTR void VKAPI_CALL GetRenderAreaGranularity(
    VkDevice                                    device,
    VkRenderPass                                renderPass,
    VkExtent2D*                                 pGranularity)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetRenderAreaGranularity>::Dispatch(encode::TraceManager::Get(), device, renderPass, pGranularity);

    encode::TraceManager::Get()->GetDeviceTable(device)->GetRenderAreaGranularity(device, renderPass, pGranularity);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetRenderAreaGranularity);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(renderPass);
        EncodeStructPtr(encoder, pGranularity);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetRenderAreaGranularity>::Dispatch(encode::TraceManager::Get(), device, renderPass, pGranularity);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateCommandPool(
    VkDevice                                    device,
    const VkCommandPoolCreateInfo*              pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkCommandPool*                              pCommandPool)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateCommandPool>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pCommandPool);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->CreateCommandPool(device, pCreateInfo, pAllocator, pCommandPool);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateCommandPool);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pCommandPool);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateCommandPool>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pCommandPool);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyCommandPool(
    VkDevice                                    device,
    VkCommandPool                               commandPool,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyCommandPool>::Dispatch(encode::TraceManager::Get(), device, commandPool, pAllocator);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyCommandPool);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(commandPool);
        EncodeStructPtr(encoder, pAllocator);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(device)->DestroyCommandPool(device, commandPool, pAllocator);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyCommandPool>::Dispatch(encode::TraceManager::Get(), device, commandPool, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL ResetCommandPool(
    VkDevice                                    device,
    VkCommandPool                               commandPool,
    VkCommandPoolResetFlags                     flags)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkResetCommandPool>::Dispatch(encode::TraceManager::Get(), device, commandPool, flags);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->ResetCommandPool(device, commandPool, flags);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkResetCommandPool);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(commandPool);
        encoder->EncodeFlagsValue(flags);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkResetCommandPool>::Dispatch(encode::TraceManager::Get(), result, device, commandPool, flags);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL AllocateCommandBuffers(
    VkDevice                                    device,
    const VkCommandBufferAllocateInfo*          pAllocateInfo,
    VkCommandBuffer*                            pCommandBuffers)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkAllocateCommandBuffers>::Dispatch(encode::TraceManager::Get(), device, pAllocateInfo, pCommandBuffers);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->AllocateCommandBuffers(device, pAllocateInfo, pCommandBuffers);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkAllocateCommandBuffers);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pAllocateInfo);
        encoder->EncodeHandleIdArray(pCommandBuffers, pAllocateInfo->commandBufferCount);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAllocateCommandBuffers>::Dispatch(encode::TraceManager::Get(), result, device, pAllocateInfo, pCommandBuffers);

    return result;
}

VKAPI_ATTR void VKAPI_CALL FreeCommandBuffers(
    VkDevice                                    device,
    VkCommandPool                               commandPool,
    uint32_t                                    commandBufferCount,
    const VkCommandBuffer*                      pCommandBuffers)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkFreeCommandBuffers>::Dispatch(encode::TraceManager::Get(), device, commandPool, commandBufferCount, pCommandBuffers);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkFreeCommandBuffers);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(commandPool);
        encoder->EncodeUInt32Value(commandBufferCount);
        encoder->EncodeHandleIdArray(pCommandBuffers, commandBufferCount);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(device)->FreeCommandBuffers(device, commandPool, commandBufferCount, pCommandBuffers);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkFreeCommandBuffers>::Dispatch(encode::TraceManager::Get(), device, commandPool, commandBufferCount, pCommandBuffers);
}

VKAPI_ATTR VkResult VKAPI_CALL BeginCommandBuffer(
    VkCommandBuffer                             commandBuffer,
    const VkCommandBufferBeginInfo*             pBeginInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBeginCommandBuffer>::Dispatch(encode::TraceManager::Get(), commandBuffer, pBeginInfo);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->BeginCommandBuffer(commandBuffer, pBeginInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkBeginCommandBuffer);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        EncodeStructPtr(encoder, pBeginInfo);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBeginCommandBuffer>::Dispatch(encode::TraceManager::Get(), result, commandBuffer, pBeginInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL EndCommandBuffer(
    VkCommandBuffer                             commandBuffer)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkEndCommandBuffer>::Dispatch(encode::TraceManager::Get(), commandBuffer);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->EndCommandBuffer(commandBuffer);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkEndCommandBuffer);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkEndCommandBuffer>::Dispatch(encode::TraceManager::Get(), result, commandBuffer);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL ResetCommandBuffer(
    VkCommandBuffer                             commandBuffer,
    VkCommandBufferResetFlags                   flags)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkResetCommandBuffer>::Dispatch(encode::TraceManager::Get(), commandBuffer, flags);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->ResetCommandBuffer(commandBuffer, flags);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkResetCommandBuffer);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeFlagsValue(flags);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkResetCommandBuffer>::Dispatch(encode::TraceManager::Get(), result, commandBuffer, flags);

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdBindPipeline(
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipeline                                  pipeline)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindPipeline>::Dispatch(encode::TraceManager::Get(), commandBuffer, pipelineBindPoint, pipeline);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdBindPipeline);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeEnumValue(pipelineBindPoint);
        encoder->EncodeHandleIdValue(pipeline);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdBindPipeline(commandBuffer, pipelineBindPoint, pipeline);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindPipeline>::Dispatch(encode::TraceManager::Get(), commandBuffer, pipelineBindPoint, pipeline);
}

VKAPI_ATTR void VKAPI_CALL CmdSetViewport(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    const VkViewport*                           pViewports)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewport>::Dispatch(encode::TraceManager::Get(), commandBuffer, firstViewport, viewportCount, pViewports);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetViewport);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(firstViewport);
        encoder->EncodeUInt32Value(viewportCount);
        EncodeStructArray(encoder, pViewports, viewportCount);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdSetViewport(commandBuffer, firstViewport, viewportCount, pViewports);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewport>::Dispatch(encode::TraceManager::Get(), commandBuffer, firstViewport, viewportCount, pViewports);
}

VKAPI_ATTR void VKAPI_CALL CmdSetScissor(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstScissor,
    uint32_t                                    scissorCount,
    const VkRect2D*                             pScissors)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetScissor>::Dispatch(encode::TraceManager::Get(), commandBuffer, firstScissor, scissorCount, pScissors);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetScissor);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(firstScissor);
        encoder->EncodeUInt32Value(scissorCount);
        EncodeStructArray(encoder, pScissors, scissorCount);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdSetScissor(commandBuffer, firstScissor, scissorCount, pScissors);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetScissor>::Dispatch(encode::TraceManager::Get(), commandBuffer, firstScissor, scissorCount, pScissors);
}

VKAPI_ATTR void VKAPI_CALL CmdSetLineWidth(
    VkCommandBuffer                             commandBuffer,
    float                                       lineWidth)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetLineWidth>::Dispatch(encode::TraceManager::Get(), commandBuffer, lineWidth);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetLineWidth);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeFloatValue(lineWidth);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdSetLineWidth(commandBuffer, lineWidth);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetLineWidth>::Dispatch(encode::TraceManager::Get(), commandBuffer, lineWidth);
}

VKAPI_ATTR void VKAPI_CALL CmdSetDepthBias(
    VkCommandBuffer                             commandBuffer,
    float                                       depthBiasConstantFactor,
    float                                       depthBiasClamp,
    float                                       depthBiasSlopeFactor)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBias>::Dispatch(encode::TraceManager::Get(), commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetDepthBias);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeFloatValue(depthBiasConstantFactor);
        encoder->EncodeFloatValue(depthBiasClamp);
        encoder->EncodeFloatValue(depthBiasSlopeFactor);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdSetDepthBias(commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBias>::Dispatch(encode::TraceManager::Get(), commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);
}

VKAPI_ATTR void VKAPI_CALL CmdSetBlendConstants(
    VkCommandBuffer                             commandBuffer,
    const float                                 blendConstants[4])
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetBlendConstants>::Dispatch(encode::TraceManager::Get(), commandBuffer, blendConstants);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetBlendConstants);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeFloatArray(blendConstants, 4);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdSetBlendConstants(commandBuffer, blendConstants);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetBlendConstants>::Dispatch(encode::TraceManager::Get(), commandBuffer, blendConstants);
}

VKAPI_ATTR void VKAPI_CALL CmdSetDepthBounds(
    VkCommandBuffer                             commandBuffer,
    float                                       minDepthBounds,
    float                                       maxDepthBounds)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDepthBounds>::Dispatch(encode::TraceManager::Get(), commandBuffer, minDepthBounds, maxDepthBounds);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetDepthBounds);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeFloatValue(minDepthBounds);
        encoder->EncodeFloatValue(maxDepthBounds);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdSetDepthBounds(commandBuffer, minDepthBounds, maxDepthBounds);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDepthBounds>::Dispatch(encode::TraceManager::Get(), commandBuffer, minDepthBounds, maxDepthBounds);
}

VKAPI_ATTR void VKAPI_CALL CmdSetStencilCompareMask(
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    compareMask)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilCompareMask>::Dispatch(encode::TraceManager::Get(), commandBuffer, faceMask, compareMask);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetStencilCompareMask);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeFlagsValue(faceMask);
        encoder->EncodeUInt32Value(compareMask);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdSetStencilCompareMask(commandBuffer, faceMask, compareMask);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilCompareMask>::Dispatch(encode::TraceManager::Get(), commandBuffer, faceMask, compareMask);
}

VKAPI_ATTR void VKAPI_CALL CmdSetStencilWriteMask(
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    writeMask)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilWriteMask>::Dispatch(encode::TraceManager::Get(), commandBuffer, faceMask, writeMask);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetStencilWriteMask);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeFlagsValue(faceMask);
        encoder->EncodeUInt32Value(writeMask);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdSetStencilWriteMask(commandBuffer, faceMask, writeMask);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilWriteMask>::Dispatch(encode::TraceManager::Get(), commandBuffer, faceMask, writeMask);
}

VKAPI_ATTR void VKAPI_CALL CmdSetStencilReference(
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    reference)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetStencilReference>::Dispatch(encode::TraceManager::Get(), commandBuffer, faceMask, reference);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetStencilReference);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeFlagsValue(faceMask);
        encoder->EncodeUInt32Value(reference);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdSetStencilReference(commandBuffer, faceMask, reference);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetStencilReference>::Dispatch(encode::TraceManager::Get(), commandBuffer, faceMask, reference);
}

VKAPI_ATTR void VKAPI_CALL CmdBindDescriptorSets(
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipelineLayout                            layout,
    uint32_t                                    firstSet,
    uint32_t                                    descriptorSetCount,
    const VkDescriptorSet*                      pDescriptorSets,
    uint32_t                                    dynamicOffsetCount,
    const uint32_t*                             pDynamicOffsets)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindDescriptorSets>::Dispatch(encode::TraceManager::Get(), commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount, pDescriptorSets, dynamicOffsetCount, pDynamicOffsets);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdBindDescriptorSets);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeEnumValue(pipelineBindPoint);
        encoder->EncodeHandleIdValue(layout);
        encoder->EncodeUInt32Value(firstSet);
        encoder->EncodeUInt32Value(descriptorSetCount);
        encoder->EncodeHandleIdArray(pDescriptorSets, descriptorSetCount);
        encoder->EncodeUInt32Value(dynamicOffsetCount);
        encoder->EncodeUInt32Array(pDynamicOffsets, dynamicOffsetCount);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdBindDescriptorSets(commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount, pDescriptorSets, dynamicOffsetCount, pDynamicOffsets);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindDescriptorSets>::Dispatch(encode::TraceManager::Get(), commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount, pDescriptorSets, dynamicOffsetCount, pDynamicOffsets);
}

VKAPI_ATTR void VKAPI_CALL CmdBindIndexBuffer(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkIndexType                                 indexType)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindIndexBuffer>::Dispatch(encode::TraceManager::Get(), commandBuffer, buffer, offset, indexType);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdBindIndexBuffer);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeEnumValue(indexType);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdBindIndexBuffer(commandBuffer, buffer, offset, indexType);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindIndexBuffer>::Dispatch(encode::TraceManager::Get(), commandBuffer, buffer, offset, indexType);
}

VKAPI_ATTR void VKAPI_CALL CmdBindVertexBuffers(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    const VkBuffer*                             pBuffers,
    const VkDeviceSize*                         pOffsets)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers>::Dispatch(encode::TraceManager::Get(), commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdBindVertexBuffers);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(firstBinding);
        encoder->EncodeUInt32Value(bindingCount);
        encoder->EncodeHandleIdArray(pBuffers, bindingCount);
        encoder->EncodeVkDeviceSizeArray(pOffsets, bindingCount);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdBindVertexBuffers(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindVertexBuffers>::Dispatch(encode::TraceManager::Get(), commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);
}

VKAPI_ATTR void VKAPI_CALL CmdDraw(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    vertexCount,
    uint32_t                                    instanceCount,
    uint32_t                                    firstVertex,
    uint32_t                                    firstInstance)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDraw>::Dispatch(encode::TraceManager::Get(), commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdDraw);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(vertexCount);
        encoder->EncodeUInt32Value(instanceCount);
        encoder->EncodeUInt32Value(firstVertex);
        encoder->EncodeUInt32Value(firstInstance);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdDraw(commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDraw>::Dispatch(encode::TraceManager::Get(), commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);
}

VKAPI_ATTR void VKAPI_CALL CmdDrawIndexed(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    indexCount,
    uint32_t                                    instanceCount,
    uint32_t                                    firstIndex,
    int32_t                                     vertexOffset,
    uint32_t                                    firstInstance)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndexed>::Dispatch(encode::TraceManager::Get(), commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdDrawIndexed);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(indexCount);
        encoder->EncodeUInt32Value(instanceCount);
        encoder->EncodeUInt32Value(firstIndex);
        encoder->EncodeInt32Value(vertexOffset);
        encoder->EncodeUInt32Value(firstInstance);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdDrawIndexed(commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexed>::Dispatch(encode::TraceManager::Get(), commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
}

VKAPI_ATTR void VKAPI_CALL CmdDrawIndirect(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndirect>::Dispatch(encode::TraceManager::Get(), commandBuffer, buffer, offset, drawCount, stride);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdDrawIndirect);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeUInt32Value(drawCount);
        encoder->EncodeUInt32Value(stride);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdDrawIndirect(commandBuffer, buffer, offset, drawCount, stride);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirect>::Dispatch(encode::TraceManager::Get(), commandBuffer, buffer, offset, drawCount, stride);
}

VKAPI_ATTR void VKAPI_CALL CmdDrawIndexedIndirect(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirect>::Dispatch(encode::TraceManager::Get(), commandBuffer, buffer, offset, drawCount, stride);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirect);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeUInt32Value(drawCount);
        encoder->EncodeUInt32Value(stride);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdDrawIndexedIndirect(commandBuffer, buffer, offset, drawCount, stride);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirect>::Dispatch(encode::TraceManager::Get(), commandBuffer, buffer, offset, drawCount, stride);
}

VKAPI_ATTR void VKAPI_CALL CmdDispatch(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDispatch>::Dispatch(encode::TraceManager::Get(), commandBuffer, groupCountX, groupCountY, groupCountZ);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdDispatch);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(groupCountX);
        encoder->EncodeUInt32Value(groupCountY);
        encoder->EncodeUInt32Value(groupCountZ);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdDispatch(commandBuffer, groupCountX, groupCountY, groupCountZ);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDispatch>::Dispatch(encode::TraceManager::Get(), commandBuffer, groupCountX, groupCountY, groupCountZ);
}

VKAPI_ATTR void VKAPI_CALL CmdDispatchIndirect(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDispatchIndirect>::Dispatch(encode::TraceManager::Get(), commandBuffer, buffer, offset);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdDispatchIndirect);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdDispatchIndirect(commandBuffer, buffer, offset);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDispatchIndirect>::Dispatch(encode::TraceManager::Get(), commandBuffer, buffer, offset);
}

VKAPI_ATTR void VKAPI_CALL CmdCopyBuffer(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    srcBuffer,
    VkBuffer                                    dstBuffer,
    uint32_t                                    regionCount,
    const VkBufferCopy*                         pRegions)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer>::Dispatch(encode::TraceManager::Get(), commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdCopyBuffer);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(srcBuffer);
        encoder->EncodeHandleIdValue(dstBuffer);
        encoder->EncodeUInt32Value(regionCount);
        EncodeStructArray(encoder, pRegions, regionCount);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdCopyBuffer(commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBuffer>::Dispatch(encode::TraceManager::Get(), commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);
}

VKAPI_ATTR void VKAPI_CALL CmdCopyImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const VkImageCopy*                          pRegions)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyImage>::Dispatch(encode::TraceManager::Get(), commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdCopyImage);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(srcImage);
        encoder->EncodeEnumValue(srcImageLayout);
        encoder->EncodeHandleIdValue(dstImage);
        encoder->EncodeEnumValue(dstImageLayout);
        encoder->EncodeUInt32Value(regionCount);
        EncodeStructArray(encoder, pRegions, regionCount);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdCopyImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImage>::Dispatch(encode::TraceManager::Get(), commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
}

VKAPI_ATTR void VKAPI_CALL CmdBlitImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const VkImageBlit*                          pRegions,
    VkFilter                                    filter)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBlitImage>::Dispatch(encode::TraceManager::Get(), commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, filter);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdBlitImage);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(srcImage);
        encoder->EncodeEnumValue(srcImageLayout);
        encoder->EncodeHandleIdValue(dstImage);
        encoder->EncodeEnumValue(dstImageLayout);
        encoder->EncodeUInt32Value(regionCount);
        EncodeStructArray(encoder, pRegions, regionCount);
        encoder->EncodeEnumValue(filter);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdBlitImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, filter);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBlitImage>::Dispatch(encode::TraceManager::Get(), commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, filter);
}

VKAPI_ATTR void VKAPI_CALL CmdCopyBufferToImage(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    srcBuffer,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const VkBufferImageCopy*                    pRegions)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage>::Dispatch(encode::TraceManager::Get(), commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdCopyBufferToImage);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(srcBuffer);
        encoder->EncodeHandleIdValue(dstImage);
        encoder->EncodeEnumValue(dstImageLayout);
        encoder->EncodeUInt32Value(regionCount);
        EncodeStructArray(encoder, pRegions, regionCount);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdCopyBufferToImage(commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyBufferToImage>::Dispatch(encode::TraceManager::Get(), commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);
}

VKAPI_ATTR void VKAPI_CALL CmdCopyImageToBuffer(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkBuffer                                    dstBuffer,
    uint32_t                                    regionCount,
    const VkBufferImageCopy*                    pRegions)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer>::Dispatch(encode::TraceManager::Get(), commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(srcImage);
        encoder->EncodeEnumValue(srcImageLayout);
        encoder->EncodeHandleIdValue(dstBuffer);
        encoder->EncodeUInt32Value(regionCount);
        EncodeStructArray(encoder, pRegions, regionCount);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdCopyImageToBuffer(commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer>::Dispatch(encode::TraceManager::Get(), commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);
}

VKAPI_ATTR void VKAPI_CALL CmdUpdateBuffer(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                dataSize,
    const void*                                 pData)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdUpdateBuffer>::Dispatch(encode::TraceManager::Get(), commandBuffer, dstBuffer, dstOffset, dataSize, pData);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdUpdateBuffer);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(dstBuffer);
        encoder->EncodeVkDeviceSizeValue(dstOffset);
        encoder->EncodeVkDeviceSizeValue(dataSize);
        encoder->EncodeVoidArray(pData, dataSize);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdUpdateBuffer(commandBuffer, dstBuffer, dstOffset, dataSize, pData);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdUpdateBuffer>::Dispatch(encode::TraceManager::Get(), commandBuffer, dstBuffer, dstOffset, dataSize, pData);
}

VKAPI_ATTR void VKAPI_CALL CmdFillBuffer(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                size,
    uint32_t                                    data)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdFillBuffer>::Dispatch(encode::TraceManager::Get(), commandBuffer, dstBuffer, dstOffset, size, data);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdFillBuffer);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(dstBuffer);
        encoder->EncodeVkDeviceSizeValue(dstOffset);
        encoder->EncodeVkDeviceSizeValue(size);
        encoder->EncodeUInt32Value(data);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdFillBuffer(commandBuffer, dstBuffer, dstOffset, size, data);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdFillBuffer>::Dispatch(encode::TraceManager::Get(), commandBuffer, dstBuffer, dstOffset, size, data);
}

VKAPI_ATTR void VKAPI_CALL CmdClearColorImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     image,
    VkImageLayout                               imageLayout,
    const VkClearColorValue*                    pColor,
    uint32_t                                    rangeCount,
    const VkImageSubresourceRange*              pRanges)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdClearColorImage>::Dispatch(encode::TraceManager::Get(), commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdClearColorImage);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(image);
        encoder->EncodeEnumValue(imageLayout);
        EncodeStructPtr(encoder, pColor);
        encoder->EncodeUInt32Value(rangeCount);
        EncodeStructArray(encoder, pRanges, rangeCount);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdClearColorImage(commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdClearColorImage>::Dispatch(encode::TraceManager::Get(), commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);
}

VKAPI_ATTR void VKAPI_CALL CmdClearDepthStencilImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     image,
    VkImageLayout                               imageLayout,
    const VkClearDepthStencilValue*             pDepthStencil,
    uint32_t                                    rangeCount,
    const VkImageSubresourceRange*              pRanges)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdClearDepthStencilImage>::Dispatch(encode::TraceManager::Get(), commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdClearDepthStencilImage);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(image);
        encoder->EncodeEnumValue(imageLayout);
        EncodeStructPtr(encoder, pDepthStencil);
        encoder->EncodeUInt32Value(rangeCount);
        EncodeStructArray(encoder, pRanges, rangeCount);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdClearDepthStencilImage(commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdClearDepthStencilImage>::Dispatch(encode::TraceManager::Get(), commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges);
}

VKAPI_ATTR void VKAPI_CALL CmdClearAttachments(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    attachmentCount,
    const VkClearAttachment*                    pAttachments,
    uint32_t                                    rectCount,
    const VkClearRect*                          pRects)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdClearAttachments>::Dispatch(encode::TraceManager::Get(), commandBuffer, attachmentCount, pAttachments, rectCount, pRects);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdClearAttachments);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(attachmentCount);
        EncodeStructArray(encoder, pAttachments, attachmentCount);
        encoder->EncodeUInt32Value(rectCount);
        EncodeStructArray(encoder, pRects, rectCount);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdClearAttachments(commandBuffer, attachmentCount, pAttachments, rectCount, pRects);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdClearAttachments>::Dispatch(encode::TraceManager::Get(), commandBuffer, attachmentCount, pAttachments, rectCount, pRects);
}

VKAPI_ATTR void VKAPI_CALL CmdResolveImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const VkImageResolve*                       pRegions)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdResolveImage>::Dispatch(encode::TraceManager::Get(), commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdResolveImage);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(srcImage);
        encoder->EncodeEnumValue(srcImageLayout);
        encoder->EncodeHandleIdValue(dstImage);
        encoder->EncodeEnumValue(dstImageLayout);
        encoder->EncodeUInt32Value(regionCount);
        EncodeStructArray(encoder, pRegions, regionCount);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdResolveImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResolveImage>::Dispatch(encode::TraceManager::Get(), commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
}

VKAPI_ATTR void VKAPI_CALL CmdSetEvent(
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    VkPipelineStageFlags                        stageMask)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetEvent>::Dispatch(encode::TraceManager::Get(), commandBuffer, event, stageMask);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetEvent);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(event);
        encoder->EncodeFlagsValue(stageMask);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdSetEvent(commandBuffer, event, stageMask);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetEvent>::Dispatch(encode::TraceManager::Get(), commandBuffer, event, stageMask);
}

VKAPI_ATTR void VKAPI_CALL CmdResetEvent(
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    VkPipelineStageFlags                        stageMask)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdResetEvent>::Dispatch(encode::TraceManager::Get(), commandBuffer, event, stageMask);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdResetEvent);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(event);
        encoder->EncodeFlagsValue(stageMask);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdResetEvent(commandBuffer, event, stageMask);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResetEvent>::Dispatch(encode::TraceManager::Get(), commandBuffer, event, stageMask);
}

VKAPI_ATTR void VKAPI_CALL CmdWaitEvents(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    eventCount,
    const VkEvent*                              pEvents,
    VkPipelineStageFlags                        srcStageMask,
    VkPipelineStageFlags                        dstStageMask,
    uint32_t                                    memoryBarrierCount,
    const VkMemoryBarrier*                      pMemoryBarriers,
    uint32_t                                    bufferMemoryBarrierCount,
    const VkBufferMemoryBarrier*                pBufferMemoryBarriers,
    uint32_t                                    imageMemoryBarrierCount,
    const VkImageMemoryBarrier*                 pImageMemoryBarriers)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWaitEvents>::Dispatch(encode::TraceManager::Get(), commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdWaitEvents);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(eventCount);
        encoder->EncodeHandleIdArray(pEvents, eventCount);
        encoder->EncodeFlagsValue(srcStageMask);
        encoder->EncodeFlagsValue(dstStageMask);
        encoder->EncodeUInt32Value(memoryBarrierCount);
        EncodeStructArray(encoder, pMemoryBarriers, memoryBarrierCount);
        encoder->EncodeUInt32Value(bufferMemoryBarrierCount);
        EncodeStructArray(encoder, pBufferMemoryBarriers, bufferMemoryBarrierCount);
        encoder->EncodeUInt32Value(imageMemoryBarrierCount);
        EncodeStructArray(encoder, pImageMemoryBarriers, imageMemoryBarrierCount);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdWaitEvents(commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWaitEvents>::Dispatch(encode::TraceManager::Get(), commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
}

VKAPI_ATTR void VKAPI_CALL CmdPipelineBarrier(
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlags                        srcStageMask,
    VkPipelineStageFlags                        dstStageMask,
    VkDependencyFlags                           dependencyFlags,
    uint32_t                                    memoryBarrierCount,
    const VkMemoryBarrier*                      pMemoryBarriers,
    uint32_t                                    bufferMemoryBarrierCount,
    const VkBufferMemoryBarrier*                pBufferMemoryBarriers,
    uint32_t                                    imageMemoryBarrierCount,
    const VkImageMemoryBarrier*                 pImageMemoryBarriers)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier>::Dispatch(encode::TraceManager::Get(), commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdPipelineBarrier);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeFlagsValue(srcStageMask);
        encoder->EncodeFlagsValue(dstStageMask);
        encoder->EncodeFlagsValue(dependencyFlags);
        encoder->EncodeUInt32Value(memoryBarrierCount);
        EncodeStructArray(encoder, pMemoryBarriers, memoryBarrierCount);
        encoder->EncodeUInt32Value(bufferMemoryBarrierCount);
        EncodeStructArray(encoder, pBufferMemoryBarriers, bufferMemoryBarrierCount);
        encoder->EncodeUInt32Value(imageMemoryBarrierCount);
        EncodeStructArray(encoder, pImageMemoryBarriers, imageMemoryBarrierCount);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdPipelineBarrier(commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPipelineBarrier>::Dispatch(encode::TraceManager::Get(), commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
}

VKAPI_ATTR void VKAPI_CALL CmdBeginQuery(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    query,
    VkQueryControlFlags                         flags)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginQuery>::Dispatch(encode::TraceManager::Get(), commandBuffer, queryPool, query, flags);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdBeginQuery);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(queryPool);
        encoder->EncodeUInt32Value(query);
        encoder->EncodeFlagsValue(flags);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdBeginQuery(commandBuffer, queryPool, query, flags);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginQuery>::Dispatch(encode::TraceManager::Get(), commandBuffer, queryPool, query, flags);
}

VKAPI_ATTR void VKAPI_CALL CmdEndQuery(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    query)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndQuery>::Dispatch(encode::TraceManager::Get(), commandBuffer, queryPool, query);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdEndQuery);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(queryPool);
        encoder->EncodeUInt32Value(query);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdEndQuery(commandBuffer, queryPool, query);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndQuery>::Dispatch(encode::TraceManager::Get(), commandBuffer, queryPool, query);
}

VKAPI_ATTR void VKAPI_CALL CmdResetQueryPool(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdResetQueryPool>::Dispatch(encode::TraceManager::Get(), commandBuffer, queryPool, firstQuery, queryCount);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdResetQueryPool);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(queryPool);
        encoder->EncodeUInt32Value(firstQuery);
        encoder->EncodeUInt32Value(queryCount);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdResetQueryPool(commandBuffer, queryPool, firstQuery, queryCount);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdResetQueryPool>::Dispatch(encode::TraceManager::Get(), commandBuffer, queryPool, firstQuery, queryCount);
}

VKAPI_ATTR void VKAPI_CALL CmdWriteTimestamp(
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlagBits                     pipelineStage,
    VkQueryPool                                 queryPool,
    uint32_t                                    query)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp>::Dispatch(encode::TraceManager::Get(), commandBuffer, pipelineStage, queryPool, query);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdWriteTimestamp);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeEnumValue(pipelineStage);
        encoder->EncodeHandleIdValue(queryPool);
        encoder->EncodeUInt32Value(query);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdWriteTimestamp(commandBuffer, pipelineStage, queryPool, query);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteTimestamp>::Dispatch(encode::TraceManager::Get(), commandBuffer, pipelineStage, queryPool, query);
}

VKAPI_ATTR void VKAPI_CALL CmdCopyQueryPoolResults(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                stride,
    VkQueryResultFlags                          flags)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyQueryPoolResults>::Dispatch(encode::TraceManager::Get(), commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdCopyQueryPoolResults);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(queryPool);
        encoder->EncodeUInt32Value(firstQuery);
        encoder->EncodeUInt32Value(queryCount);
        encoder->EncodeHandleIdValue(dstBuffer);
        encoder->EncodeVkDeviceSizeValue(dstOffset);
        encoder->EncodeVkDeviceSizeValue(stride);
        encoder->EncodeFlagsValue(flags);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdCopyQueryPoolResults(commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyQueryPoolResults>::Dispatch(encode::TraceManager::Get(), commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags);
}

VKAPI_ATTR void VKAPI_CALL CmdPushConstants(
    VkCommandBuffer                             commandBuffer,
    VkPipelineLayout                            layout,
    VkShaderStageFlags                          stageFlags,
    uint32_t                                    offset,
    uint32_t                                    size,
    const void*                                 pValues)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdPushConstants>::Dispatch(encode::TraceManager::Get(), commandBuffer, layout, stageFlags, offset, size, pValues);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdPushConstants);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(layout);
        encoder->EncodeFlagsValue(stageFlags);
        encoder->EncodeUInt32Value(offset);
        encoder->EncodeUInt32Value(size);
        encoder->EncodeVoidArray(pValues, size);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdPushConstants(commandBuffer, layout, stageFlags, offset, size, pValues);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPushConstants>::Dispatch(encode::TraceManager::Get(), commandBuffer, layout, stageFlags, offset, size, pValues);
}

VKAPI_ATTR void VKAPI_CALL CmdBeginRenderPass(
    VkCommandBuffer                             commandBuffer,
    const VkRenderPassBeginInfo*                pRenderPassBegin,
    VkSubpassContents                           contents)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass>::Dispatch(encode::TraceManager::Get(), commandBuffer, pRenderPassBegin, contents);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdBeginRenderPass);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        EncodeStructPtr(encoder, pRenderPassBegin);
        encoder->EncodeEnumValue(contents);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdBeginRenderPass(commandBuffer, pRenderPassBegin, contents);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass>::Dispatch(encode::TraceManager::Get(), commandBuffer, pRenderPassBegin, contents);
}

VKAPI_ATTR void VKAPI_CALL CmdNextSubpass(
    VkCommandBuffer                             commandBuffer,
    VkSubpassContents                           contents)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdNextSubpass>::Dispatch(encode::TraceManager::Get(), commandBuffer, contents);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdNextSubpass);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeEnumValue(contents);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdNextSubpass(commandBuffer, contents);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdNextSubpass>::Dispatch(encode::TraceManager::Get(), commandBuffer, contents);
}

VKAPI_ATTR void VKAPI_CALL CmdEndRenderPass(
    VkCommandBuffer                             commandBuffer)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass>::Dispatch(encode::TraceManager::Get(), commandBuffer);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdEndRenderPass);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdEndRenderPass(commandBuffer);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass>::Dispatch(encode::TraceManager::Get(), commandBuffer);
}

VKAPI_ATTR void VKAPI_CALL CmdExecuteCommands(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    commandBufferCount,
    const VkCommandBuffer*                      pCommandBuffers)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdExecuteCommands>::Dispatch(encode::TraceManager::Get(), commandBuffer, commandBufferCount, pCommandBuffers);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdExecuteCommands);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(commandBufferCount);
        encoder->EncodeHandleIdArray(pCommandBuffers, commandBufferCount);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdExecuteCommands(commandBuffer, commandBufferCount, pCommandBuffers);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdExecuteCommands>::Dispatch(encode::TraceManager::Get(), commandBuffer, commandBufferCount, pCommandBuffers);
}

VKAPI_ATTR VkResult VKAPI_CALL BindBufferMemory2(
    VkDevice                                    device,
    uint32_t                                    bindInfoCount,
    const VkBindBufferMemoryInfo*               pBindInfos)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBindBufferMemory2>::Dispatch(encode::TraceManager::Get(), device, bindInfoCount, pBindInfos);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->BindBufferMemory2(device, bindInfoCount, pBindInfos);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkBindBufferMemory2);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeUInt32Value(bindInfoCount);
        EncodeStructArray(encoder, pBindInfos, bindInfoCount);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindBufferMemory2>::Dispatch(encode::TraceManager::Get(), result, device, bindInfoCount, pBindInfos);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL BindImageMemory2(
    VkDevice                                    device,
    uint32_t                                    bindInfoCount,
    const VkBindImageMemoryInfo*                pBindInfos)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBindImageMemory2>::Dispatch(encode::TraceManager::Get(), device, bindInfoCount, pBindInfos);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->BindImageMemory2(device, bindInfoCount, pBindInfos);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkBindImageMemory2);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeUInt32Value(bindInfoCount);
        EncodeStructArray(encoder, pBindInfos, bindInfoCount);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindImageMemory2>::Dispatch(encode::TraceManager::Get(), result, device, bindInfoCount, pBindInfos);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetDeviceGroupPeerMemoryFeatures(
    VkDevice                                    device,
    uint32_t                                    heapIndex,
    uint32_t                                    localDeviceIndex,
    uint32_t                                    remoteDeviceIndex,
    VkPeerMemoryFeatureFlags*                   pPeerMemoryFeatures)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeatures>::Dispatch(encode::TraceManager::Get(), device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);

    encode::TraceManager::Get()->GetDeviceTable(device)->GetDeviceGroupPeerMemoryFeatures(device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeatures);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeUInt32Value(heapIndex);
        encoder->EncodeUInt32Value(localDeviceIndex);
        encoder->EncodeUInt32Value(remoteDeviceIndex);
        encoder->EncodeFlagsPtr(pPeerMemoryFeatures);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeatures>::Dispatch(encode::TraceManager::Get(), device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);
}

VKAPI_ATTR void VKAPI_CALL CmdSetDeviceMask(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    deviceMask)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDeviceMask>::Dispatch(encode::TraceManager::Get(), commandBuffer, deviceMask);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetDeviceMask);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(deviceMask);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdSetDeviceMask(commandBuffer, deviceMask);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDeviceMask>::Dispatch(encode::TraceManager::Get(), commandBuffer, deviceMask);
}

VKAPI_ATTR void VKAPI_CALL CmdDispatchBase(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    baseGroupX,
    uint32_t                                    baseGroupY,
    uint32_t                                    baseGroupZ,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDispatchBase>::Dispatch(encode::TraceManager::Get(), commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdDispatchBase);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(baseGroupX);
        encoder->EncodeUInt32Value(baseGroupY);
        encoder->EncodeUInt32Value(baseGroupZ);
        encoder->EncodeUInt32Value(groupCountX);
        encoder->EncodeUInt32Value(groupCountY);
        encoder->EncodeUInt32Value(groupCountZ);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdDispatchBase(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDispatchBase>::Dispatch(encode::TraceManager::Get(), commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
}

VKAPI_ATTR VkResult VKAPI_CALL EnumeratePhysicalDeviceGroups(
    VkInstance                                  instance,
    uint32_t*                                   pPhysicalDeviceGroupCount,
    VkPhysicalDeviceGroupProperties*            pPhysicalDeviceGroupProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroups>::Dispatch(encode::TraceManager::Get(), instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);

    VkResult result = encode::TraceManager::Get()->GetInstanceTable(instance)->EnumeratePhysicalDeviceGroups(instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroups);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(instance);
        encoder->EncodeUInt32Ptr(pPhysicalDeviceGroupCount);
        EncodeStructArray(encoder, pPhysicalDeviceGroupProperties, (pPhysicalDeviceGroupCount != nullptr) ? (*pPhysicalDeviceGroupCount) : 0);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroups>::Dispatch(encode::TraceManager::Get(), result, instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetImageMemoryRequirements2(
    VkDevice                                    device,
    const VkImageMemoryRequirementsInfo2*       pInfo,
    VkMemoryRequirements2*                      pMemoryRequirements)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2>::Dispatch(encode::TraceManager::Get(), device, pInfo, pMemoryRequirements);

    encode::TraceManager::Get()->GetDeviceTable(device)->GetImageMemoryRequirements2(device, pInfo, pMemoryRequirements);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pInfo);
        EncodeStructPtr(encoder, pMemoryRequirements);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2>::Dispatch(encode::TraceManager::Get(), device, pInfo, pMemoryRequirements);
}

VKAPI_ATTR void VKAPI_CALL GetBufferMemoryRequirements2(
    VkDevice                                    device,
    const VkBufferMemoryRequirementsInfo2*      pInfo,
    VkMemoryRequirements2*                      pMemoryRequirements)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2>::Dispatch(encode::TraceManager::Get(), device, pInfo, pMemoryRequirements);

    encode::TraceManager::Get()->GetDeviceTable(device)->GetBufferMemoryRequirements2(device, pInfo, pMemoryRequirements);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pInfo);
        EncodeStructPtr(encoder, pMemoryRequirements);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2>::Dispatch(encode::TraceManager::Get(), device, pInfo, pMemoryRequirements);
}

VKAPI_ATTR void VKAPI_CALL GetImageSparseMemoryRequirements2(
    VkDevice                                    device,
    const VkImageSparseMemoryRequirementsInfo2* pInfo,
    uint32_t*                                   pSparseMemoryRequirementCount,
    VkSparseImageMemoryRequirements2*           pSparseMemoryRequirements)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2>::Dispatch(encode::TraceManager::Get(), device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);

    encode::TraceManager::Get()->GetDeviceTable(device)->GetImageSparseMemoryRequirements2(device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pInfo);
        encoder->EncodeUInt32Ptr(pSparseMemoryRequirementCount);
        EncodeStructArray(encoder, pSparseMemoryRequirements, (pSparseMemoryRequirementCount != nullptr) ? (*pSparseMemoryRequirementCount) : 0);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2>::Dispatch(encode::TraceManager::Get(), device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFeatures2(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceFeatures2*                  pFeatures)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2>::Dispatch(encode::TraceManager::Get(), physicalDevice, pFeatures);

    encode::TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceFeatures2(physicalDevice, pFeatures);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        EncodeStructPtr(encoder, pFeatures);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2>::Dispatch(encode::TraceManager::Get(), physicalDevice, pFeatures);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceProperties2(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceProperties2*                pProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2>::Dispatch(encode::TraceManager::Get(), physicalDevice, pProperties);

    encode::TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceProperties2(physicalDevice, pProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        EncodeStructPtr(encoder, pProperties);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2>::Dispatch(encode::TraceManager::Get(), physicalDevice, pProperties);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFormatProperties2(
    VkPhysicalDevice                            physicalDevice,
    VkFormat                                    format,
    VkFormatProperties2*                        pFormatProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2>::Dispatch(encode::TraceManager::Get(), physicalDevice, format, pFormatProperties);

    encode::TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceFormatProperties2(physicalDevice, format, pFormatProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeEnumValue(format);
        EncodeStructPtr(encoder, pFormatProperties);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2>::Dispatch(encode::TraceManager::Get(), physicalDevice, format, pFormatProperties);
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceImageFormatProperties2(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceImageFormatInfo2*     pImageFormatInfo,
    VkImageFormatProperties2*                   pImageFormatProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2>::Dispatch(encode::TraceManager::Get(), physicalDevice, pImageFormatInfo, pImageFormatProperties);

    VkResult result = encode::TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceImageFormatProperties2(physicalDevice, pImageFormatInfo, pImageFormatProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        EncodeStructPtr(encoder, pImageFormatInfo);
        EncodeStructPtr(encoder, pImageFormatProperties);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, pImageFormatInfo, pImageFormatProperties);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceQueueFamilyProperties2(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pQueueFamilyPropertyCount,
    VkQueueFamilyProperties2*                   pQueueFamilyProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2>::Dispatch(encode::TraceManager::Get(), physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);

    encode::TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceQueueFamilyProperties2(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeUInt32Ptr(pQueueFamilyPropertyCount);
        EncodeStructArray(encoder, pQueueFamilyProperties, (pQueueFamilyPropertyCount != nullptr) ? (*pQueueFamilyPropertyCount) : 0);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2>::Dispatch(encode::TraceManager::Get(), physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceMemoryProperties2(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceMemoryProperties2*          pMemoryProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2>::Dispatch(encode::TraceManager::Get(), physicalDevice, pMemoryProperties);

    encode::TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceMemoryProperties2(physicalDevice, pMemoryProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        EncodeStructPtr(encoder, pMemoryProperties);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2>::Dispatch(encode::TraceManager::Get(), physicalDevice, pMemoryProperties);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSparseImageFormatProperties2(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo,
    uint32_t*                                   pPropertyCount,
    VkSparseImageFormatProperties2*             pProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2>::Dispatch(encode::TraceManager::Get(), physicalDevice, pFormatInfo, pPropertyCount, pProperties);

    encode::TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceSparseImageFormatProperties2(physicalDevice, pFormatInfo, pPropertyCount, pProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        EncodeStructPtr(encoder, pFormatInfo);
        encoder->EncodeUInt32Ptr(pPropertyCount);
        EncodeStructArray(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2>::Dispatch(encode::TraceManager::Get(), physicalDevice, pFormatInfo, pPropertyCount, pProperties);
}

VKAPI_ATTR void VKAPI_CALL TrimCommandPool(
    VkDevice                                    device,
    VkCommandPool                               commandPool,
    VkCommandPoolTrimFlags                      flags)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkTrimCommandPool>::Dispatch(encode::TraceManager::Get(), device, commandPool, flags);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkTrimCommandPool);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(commandPool);
        encoder->EncodeFlagsValue(flags);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(device)->TrimCommandPool(device, commandPool, flags);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkTrimCommandPool>::Dispatch(encode::TraceManager::Get(), device, commandPool, flags);
}

VKAPI_ATTR void VKAPI_CALL GetDeviceQueue2(
    VkDevice                                    device,
    const VkDeviceQueueInfo2*                   pQueueInfo,
    VkQueue*                                    pQueue)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceQueue2>::Dispatch(encode::TraceManager::Get(), device, pQueueInfo, pQueue);

    encode::TraceManager::Get()->GetDeviceTable(device)->GetDeviceQueue2(device, pQueueInfo, pQueue);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetDeviceQueue2);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pQueueInfo);
        encoder->EncodeHandleIdPtr(pQueue);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceQueue2>::Dispatch(encode::TraceManager::Get(), device, pQueueInfo, pQueue);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateSamplerYcbcrConversion(
    VkDevice                                    device,
    const VkSamplerYcbcrConversionCreateInfo*   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSamplerYcbcrConversion*                   pYcbcrConversion)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversion>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pYcbcrConversion);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->CreateSamplerYcbcrConversion(device, pCreateInfo, pAllocator, pYcbcrConversion);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversion);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pYcbcrConversion);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversion>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pYcbcrConversion);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroySamplerYcbcrConversion(
    VkDevice                                    device,
    VkSamplerYcbcrConversion                    ycbcrConversion,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversion>::Dispatch(encode::TraceManager::Get(), device, ycbcrConversion, pAllocator);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversion);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(ycbcrConversion);
        EncodeStructPtr(encoder, pAllocator);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(device)->DestroySamplerYcbcrConversion(device, ycbcrConversion, pAllocator);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversion>::Dispatch(encode::TraceManager::Get(), device, ycbcrConversion, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDescriptorUpdateTemplate(
    VkDevice                                    device,
    const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDescriptorUpdateTemplate*                 pDescriptorUpdateTemplate)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplate>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->CreateDescriptorUpdateTemplate(device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplate);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pDescriptorUpdateTemplate);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplate>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyDescriptorUpdateTemplate(
    VkDevice                                    device,
    VkDescriptorUpdateTemplate                  descriptorUpdateTemplate,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplate>::Dispatch(encode::TraceManager::Get(), device, descriptorUpdateTemplate, pAllocator);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplate);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(descriptorUpdateTemplate);
        EncodeStructPtr(encoder, pAllocator);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(device)->DestroyDescriptorUpdateTemplate(device, descriptorUpdateTemplate, pAllocator);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplate>::Dispatch(encode::TraceManager::Get(), device, descriptorUpdateTemplate, pAllocator);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalBufferProperties(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceExternalBufferInfo*   pExternalBufferInfo,
    VkExternalBufferProperties*                 pExternalBufferProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferProperties>::Dispatch(encode::TraceManager::Get(), physicalDevice, pExternalBufferInfo, pExternalBufferProperties);

    encode::TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceExternalBufferProperties(physicalDevice, pExternalBufferInfo, pExternalBufferProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferProperties);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        EncodeStructPtr(encoder, pExternalBufferInfo);
        EncodeStructPtr(encoder, pExternalBufferProperties);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferProperties>::Dispatch(encode::TraceManager::Get(), physicalDevice, pExternalBufferInfo, pExternalBufferProperties);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalFenceProperties(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceExternalFenceInfo*    pExternalFenceInfo,
    VkExternalFenceProperties*                  pExternalFenceProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFenceProperties>::Dispatch(encode::TraceManager::Get(), physicalDevice, pExternalFenceInfo, pExternalFenceProperties);

    encode::TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceExternalFenceProperties(physicalDevice, pExternalFenceInfo, pExternalFenceProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFenceProperties);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        EncodeStructPtr(encoder, pExternalFenceInfo);
        EncodeStructPtr(encoder, pExternalFenceProperties);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFenceProperties>::Dispatch(encode::TraceManager::Get(), physicalDevice, pExternalFenceInfo, pExternalFenceProperties);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalSemaphoreProperties(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo,
    VkExternalSemaphoreProperties*              pExternalSemaphoreProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphoreProperties>::Dispatch(encode::TraceManager::Get(), physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);

    encode::TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceExternalSemaphoreProperties(physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphoreProperties);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        EncodeStructPtr(encoder, pExternalSemaphoreInfo);
        EncodeStructPtr(encoder, pExternalSemaphoreProperties);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphoreProperties>::Dispatch(encode::TraceManager::Get(), physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);
}

VKAPI_ATTR void VKAPI_CALL GetDescriptorSetLayoutSupport(
    VkDevice                                    device,
    const VkDescriptorSetLayoutCreateInfo*      pCreateInfo,
    VkDescriptorSetLayoutSupport*               pSupport)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupport>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pSupport);

    encode::TraceManager::Get()->GetDeviceTable(device)->GetDescriptorSetLayoutSupport(device, pCreateInfo, pSupport);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupport);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pSupport);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupport>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pSupport);
}

VKAPI_ATTR void VKAPI_CALL DestroySurfaceKHR(
    VkInstance                                  instance,
    VkSurfaceKHR                                surface,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroySurfaceKHR>::Dispatch(encode::TraceManager::Get(), instance, surface, pAllocator);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroySurfaceKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(instance);
        encoder->EncodeHandleIdValue(surface);
        EncodeStructPtr(encoder, pAllocator);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetInstanceTable(instance)->DestroySurfaceKHR(instance, surface, pAllocator);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySurfaceKHR>::Dispatch(encode::TraceManager::Get(), instance, surface, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceSupportKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    VkSurfaceKHR                                surface,
    VkBool32*                                   pSupported)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceSupportKHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, queueFamilyIndex, surface, pSupported);

    VkResult result = encode::TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceSurfaceSupportKHR(physicalDevice, queueFamilyIndex, surface, pSupported);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceSupportKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeUInt32Value(queueFamilyIndex);
        encoder->EncodeHandleIdValue(surface);
        encoder->EncodeVkBool32Ptr(pSupported);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceSupportKHR>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, queueFamilyIndex, surface, pSupported);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceCapabilitiesKHR(
    VkPhysicalDevice                            physicalDevice,
    VkSurfaceKHR                                surface,
    VkSurfaceCapabilitiesKHR*                   pSurfaceCapabilities)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilitiesKHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, surface, pSurfaceCapabilities);

    VkResult result = encode::TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceSurfaceCapabilitiesKHR(physicalDevice, surface, pSurfaceCapabilities);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilitiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeHandleIdValue(surface);
        EncodeStructPtr(encoder, pSurfaceCapabilities);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilitiesKHR>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, surface, pSurfaceCapabilities);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceFormatsKHR(
    VkPhysicalDevice                            physicalDevice,
    VkSurfaceKHR                                surface,
    uint32_t*                                   pSurfaceFormatCount,
    VkSurfaceFormatKHR*                         pSurfaceFormats)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormatsKHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, surface, pSurfaceFormatCount, pSurfaceFormats);

    VkResult result = encode::TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceSurfaceFormatsKHR(physicalDevice, surface, pSurfaceFormatCount, pSurfaceFormats);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormatsKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeHandleIdValue(surface);
        encoder->EncodeUInt32Ptr(pSurfaceFormatCount);
        EncodeStructArray(encoder, pSurfaceFormats, (pSurfaceFormatCount != nullptr) ? (*pSurfaceFormatCount) : 0);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormatsKHR>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, surface, pSurfaceFormatCount, pSurfaceFormats);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfacePresentModesKHR(
    VkPhysicalDevice                            physicalDevice,
    VkSurfaceKHR                                surface,
    uint32_t*                                   pPresentModeCount,
    VkPresentModeKHR*                           pPresentModes)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModesKHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, surface, pPresentModeCount, pPresentModes);

    VkResult result = encode::TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceSurfacePresentModesKHR(physicalDevice, surface, pPresentModeCount, pPresentModes);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModesKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeHandleIdValue(surface);
        encoder->EncodeUInt32Ptr(pPresentModeCount);
        encoder->EncodeEnumArray(pPresentModes, (pPresentModeCount != nullptr) ? (*pPresentModeCount) : 0);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModesKHR>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, surface, pPresentModeCount, pPresentModes);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateSwapchainKHR(
    VkDevice                                    device,
    const VkSwapchainCreateInfoKHR*             pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSwapchainKHR*                             pSwapchain)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateSwapchainKHR>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pSwapchain);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->CreateSwapchainKHR(device, pCreateInfo, pAllocator, pSwapchain);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateSwapchainKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pSwapchain);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSwapchainKHR>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pSwapchain);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroySwapchainKHR(
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroySwapchainKHR>::Dispatch(encode::TraceManager::Get(), device, swapchain, pAllocator);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroySwapchainKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(swapchain);
        EncodeStructPtr(encoder, pAllocator);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(device)->DestroySwapchainKHR(device, swapchain, pAllocator);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySwapchainKHR>::Dispatch(encode::TraceManager::Get(), device, swapchain, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL GetSwapchainImagesKHR(
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain,
    uint32_t*                                   pSwapchainImageCount,
    VkImage*                                    pSwapchainImages)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetSwapchainImagesKHR>::Dispatch(encode::TraceManager::Get(), device, swapchain, pSwapchainImageCount, pSwapchainImages);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->GetSwapchainImagesKHR(device, swapchain, pSwapchainImageCount, pSwapchainImages);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetSwapchainImagesKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(swapchain);
        encoder->EncodeUInt32Ptr(pSwapchainImageCount);
        encoder->EncodeHandleIdArray(pSwapchainImages, (pSwapchainImageCount != nullptr) ? (*pSwapchainImageCount) : 0);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetSwapchainImagesKHR>::Dispatch(encode::TraceManager::Get(), result, device, swapchain, pSwapchainImageCount, pSwapchainImages);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL AcquireNextImageKHR(
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain,
    uint64_t                                    timeout,
    VkSemaphore                                 semaphore,
    VkFence                                     fence,
    uint32_t*                                   pImageIndex)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkAcquireNextImageKHR>::Dispatch(encode::TraceManager::Get(), device, swapchain, timeout, semaphore, fence, pImageIndex);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->AcquireNextImageKHR(device, swapchain, timeout, semaphore, fence, pImageIndex);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkAcquireNextImageKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(swapchain);
        encoder->EncodeUInt64Value(timeout);
        encoder->EncodeHandleIdValue(semaphore);
        encoder->EncodeHandleIdValue(fence);
        encoder->EncodeUInt32Ptr(pImageIndex);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireNextImageKHR>::Dispatch(encode::TraceManager::Get(), result, device, swapchain, timeout, semaphore, fence, pImageIndex);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL QueuePresentKHR(
    VkQueue                                     queue,
    const VkPresentInfoKHR*                     pPresentInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkQueuePresentKHR>::Dispatch(encode::TraceManager::Get(), queue, pPresentInfo);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(queue)->QueuePresentKHR(queue, pPresentInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkQueuePresentKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(queue);
        EncodeStructPtr(encoder, pPresentInfo);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueuePresentKHR>::Dispatch(encode::TraceManager::Get(), result, queue, pPresentInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDeviceGroupPresentCapabilitiesKHR(
    VkDevice                                    device,
    VkDeviceGroupPresentCapabilitiesKHR*        pDeviceGroupPresentCapabilities)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPresentCapabilitiesKHR>::Dispatch(encode::TraceManager::Get(), device, pDeviceGroupPresentCapabilities);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->GetDeviceGroupPresentCapabilitiesKHR(device, pDeviceGroupPresentCapabilities);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetDeviceGroupPresentCapabilitiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pDeviceGroupPresentCapabilities);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPresentCapabilitiesKHR>::Dispatch(encode::TraceManager::Get(), result, device, pDeviceGroupPresentCapabilities);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDeviceGroupSurfacePresentModesKHR(
    VkDevice                                    device,
    VkSurfaceKHR                                surface,
    VkDeviceGroupPresentModeFlagsKHR*           pModes)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModesKHR>::Dispatch(encode::TraceManager::Get(), device, surface, pModes);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->GetDeviceGroupSurfacePresentModesKHR(device, surface, pModes);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModesKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(surface);
        encoder->EncodeFlagsPtr(pModes);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModesKHR>::Dispatch(encode::TraceManager::Get(), result, device, surface, pModes);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDevicePresentRectanglesKHR(
    VkPhysicalDevice                            physicalDevice,
    VkSurfaceKHR                                surface,
    uint32_t*                                   pRectCount,
    VkRect2D*                                   pRects)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDevicePresentRectanglesKHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, surface, pRectCount, pRects);

    VkResult result = encode::TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDevicePresentRectanglesKHR(physicalDevice, surface, pRectCount, pRects);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDevicePresentRectanglesKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeHandleIdValue(surface);
        encoder->EncodeUInt32Ptr(pRectCount);
        EncodeStructArray(encoder, pRects, (pRectCount != nullptr) ? (*pRectCount) : 0);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDevicePresentRectanglesKHR>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, surface, pRectCount, pRects);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL AcquireNextImage2KHR(
    VkDevice                                    device,
    const VkAcquireNextImageInfoKHR*            pAcquireInfo,
    uint32_t*                                   pImageIndex)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkAcquireNextImage2KHR>::Dispatch(encode::TraceManager::Get(), device, pAcquireInfo, pImageIndex);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->AcquireNextImage2KHR(device, pAcquireInfo, pImageIndex);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkAcquireNextImage2KHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pAcquireInfo);
        encoder->EncodeUInt32Ptr(pImageIndex);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireNextImage2KHR>::Dispatch(encode::TraceManager::Get(), result, device, pAcquireInfo, pImageIndex);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceDisplayPropertiesKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pPropertyCount,
    VkDisplayPropertiesKHR*                     pProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPropertiesKHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pPropertyCount, pProperties);

    VkResult result = encode::TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceDisplayPropertiesKHR(physicalDevice, pPropertyCount, pProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPropertiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeUInt32Ptr(pPropertyCount);
        EncodeStructArray(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPropertiesKHR>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, pPropertyCount, pProperties);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceDisplayPlanePropertiesKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pPropertyCount,
    VkDisplayPlanePropertiesKHR*                pProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlanePropertiesKHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pPropertyCount, pProperties);

    VkResult result = encode::TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceDisplayPlanePropertiesKHR(physicalDevice, pPropertyCount, pProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlanePropertiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeUInt32Ptr(pPropertyCount);
        EncodeStructArray(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlanePropertiesKHR>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, pPropertyCount, pProperties);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDisplayPlaneSupportedDisplaysKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    planeIndex,
    uint32_t*                                   pDisplayCount,
    VkDisplayKHR*                               pDisplays)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneSupportedDisplaysKHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, planeIndex, pDisplayCount, pDisplays);

    VkResult result = encode::TraceManager::Get()->GetInstanceTable(physicalDevice)->GetDisplayPlaneSupportedDisplaysKHR(physicalDevice, planeIndex, pDisplayCount, pDisplays);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetDisplayPlaneSupportedDisplaysKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeUInt32Value(planeIndex);
        encoder->EncodeUInt32Ptr(pDisplayCount);
        encoder->EncodeHandleIdArray(pDisplays, (pDisplayCount != nullptr) ? (*pDisplayCount) : 0);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneSupportedDisplaysKHR>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, planeIndex, pDisplayCount, pDisplays);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDisplayModePropertiesKHR(
    VkPhysicalDevice                            physicalDevice,
    VkDisplayKHR                                display,
    uint32_t*                                   pPropertyCount,
    VkDisplayModePropertiesKHR*                 pProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDisplayModePropertiesKHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, display, pPropertyCount, pProperties);

    VkResult result = encode::TraceManager::Get()->GetInstanceTable(physicalDevice)->GetDisplayModePropertiesKHR(physicalDevice, display, pPropertyCount, pProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetDisplayModePropertiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeHandleIdValue(display);
        encoder->EncodeUInt32Ptr(pPropertyCount);
        EncodeStructArray(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayModePropertiesKHR>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, display, pPropertyCount, pProperties);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDisplayModeKHR(
    VkPhysicalDevice                            physicalDevice,
    VkDisplayKHR                                display,
    const VkDisplayModeCreateInfoKHR*           pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDisplayModeKHR*                           pMode)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDisplayModeKHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, display, pCreateInfo, pAllocator, pMode);

    VkResult result = encode::TraceManager::Get()->GetInstanceTable(physicalDevice)->CreateDisplayModeKHR(physicalDevice, display, pCreateInfo, pAllocator, pMode);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateDisplayModeKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeHandleIdValue(display);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pMode);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDisplayModeKHR>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, display, pCreateInfo, pAllocator, pMode);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDisplayPlaneCapabilitiesKHR(
    VkPhysicalDevice                            physicalDevice,
    VkDisplayModeKHR                            mode,
    uint32_t                                    planeIndex,
    VkDisplayPlaneCapabilitiesKHR*              pCapabilities)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilitiesKHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, mode, planeIndex, pCapabilities);

    VkResult result = encode::TraceManager::Get()->GetInstanceTable(physicalDevice)->GetDisplayPlaneCapabilitiesKHR(physicalDevice, mode, planeIndex, pCapabilities);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilitiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeHandleIdValue(mode);
        encoder->EncodeUInt32Value(planeIndex);
        EncodeStructPtr(encoder, pCapabilities);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilitiesKHR>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, mode, planeIndex, pCapabilities);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDisplayPlaneSurfaceKHR(
    VkInstance                                  instance,
    const VkDisplaySurfaceCreateInfoKHR*        pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDisplayPlaneSurfaceKHR>::Dispatch(encode::TraceManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    VkResult result = encode::TraceManager::Get()->GetInstanceTable(instance)->CreateDisplayPlaneSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateDisplayPlaneSurfaceKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(instance);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pSurface);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDisplayPlaneSurfaceKHR>::Dispatch(encode::TraceManager::Get(), result, instance, pCreateInfo, pAllocator, pSurface);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateSharedSwapchainsKHR(
    VkDevice                                    device,
    uint32_t                                    swapchainCount,
    const VkSwapchainCreateInfoKHR*             pCreateInfos,
    const VkAllocationCallbacks*                pAllocator,
    VkSwapchainKHR*                             pSwapchains)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateSharedSwapchainsKHR>::Dispatch(encode::TraceManager::Get(), device, swapchainCount, pCreateInfos, pAllocator, pSwapchains);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->CreateSharedSwapchainsKHR(device, swapchainCount, pCreateInfos, pAllocator, pSwapchains);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateSharedSwapchainsKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeUInt32Value(swapchainCount);
        EncodeStructArray(encoder, pCreateInfos, swapchainCount);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdArray(pSwapchains, swapchainCount);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSharedSwapchainsKHR>::Dispatch(encode::TraceManager::Get(), result, device, swapchainCount, pCreateInfos, pAllocator, pSwapchains);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateXlibSurfaceKHR(
    VkInstance                                  instance,
    const VkXlibSurfaceCreateInfoKHR*           pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateXlibSurfaceKHR>::Dispatch(encode::TraceManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    VkResult result = encode::TraceManager::Get()->GetInstanceTable(instance)->CreateXlibSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateXlibSurfaceKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(instance);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pSurface);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateXlibSurfaceKHR>::Dispatch(encode::TraceManager::Get(), result, instance, pCreateInfo, pAllocator, pSurface);

    return result;
}

VKAPI_ATTR VkBool32 VKAPI_CALL GetPhysicalDeviceXlibPresentationSupportKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    Display*                                    dpy,
    VisualID                                    visualID)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceXlibPresentationSupportKHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, queueFamilyIndex, dpy, visualID);

    VkBool32 result = encode::TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceXlibPresentationSupportKHR(physicalDevice, queueFamilyIndex, dpy, visualID);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceXlibPresentationSupportKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeUInt32Value(queueFamilyIndex);
        encoder->EncodeVoidPtr(dpy);
        encoder->EncodeSizeTValue(visualID);
        encoder->EncodeVkBool32Value(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceXlibPresentationSupportKHR>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, queueFamilyIndex, dpy, visualID);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateXcbSurfaceKHR(
    VkInstance                                  instance,
    const VkXcbSurfaceCreateInfoKHR*            pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateXcbSurfaceKHR>::Dispatch(encode::TraceManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    VkResult result = encode::TraceManager::Get()->GetInstanceTable(instance)->CreateXcbSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateXcbSurfaceKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(instance);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pSurface);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateXcbSurfaceKHR>::Dispatch(encode::TraceManager::Get(), result, instance, pCreateInfo, pAllocator, pSurface);

    return result;
}

VKAPI_ATTR VkBool32 VKAPI_CALL GetPhysicalDeviceXcbPresentationSupportKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    xcb_connection_t*                           connection,
    xcb_visualid_t                              visual_id)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceXcbPresentationSupportKHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, queueFamilyIndex, connection, visual_id);

    VkBool32 result = encode::TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceXcbPresentationSupportKHR(physicalDevice, queueFamilyIndex, connection, visual_id);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceXcbPresentationSupportKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeUInt32Value(queueFamilyIndex);
        encoder->EncodeVoidPtr(connection);
        encoder->EncodeUInt32Value(visual_id);
        encoder->EncodeVkBool32Value(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceXcbPresentationSupportKHR>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, queueFamilyIndex, connection, visual_id);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateWaylandSurfaceKHR(
    VkInstance                                  instance,
    const VkWaylandSurfaceCreateInfoKHR*        pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateWaylandSurfaceKHR>::Dispatch(encode::TraceManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    VkResult result = encode::TraceManager::Get()->GetInstanceTable(instance)->CreateWaylandSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateWaylandSurfaceKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(instance);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pSurface);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateWaylandSurfaceKHR>::Dispatch(encode::TraceManager::Get(), result, instance, pCreateInfo, pAllocator, pSurface);

    return result;
}

VKAPI_ATTR VkBool32 VKAPI_CALL GetPhysicalDeviceWaylandPresentationSupportKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    struct wl_display*                          display)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceWaylandPresentationSupportKHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, queueFamilyIndex, display);

    VkBool32 result = encode::TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceWaylandPresentationSupportKHR(physicalDevice, queueFamilyIndex, display);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceWaylandPresentationSupportKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeUInt32Value(queueFamilyIndex);
        encoder->EncodeVoidPtr(display);
        encoder->EncodeVkBool32Value(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceWaylandPresentationSupportKHR>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, queueFamilyIndex, display);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateAndroidSurfaceKHR(
    VkInstance                                  instance,
    const VkAndroidSurfaceCreateInfoKHR*        pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateAndroidSurfaceKHR>::Dispatch(encode::TraceManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    VkResult result = encode::TraceManager::Get()->GetInstanceTable(instance)->CreateAndroidSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateAndroidSurfaceKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(instance);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pSurface);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateAndroidSurfaceKHR>::Dispatch(encode::TraceManager::Get(), result, instance, pCreateInfo, pAllocator, pSurface);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateWin32SurfaceKHR(
    VkInstance                                  instance,
    const VkWin32SurfaceCreateInfoKHR*          pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateWin32SurfaceKHR>::Dispatch(encode::TraceManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    VkResult result = encode::TraceManager::Get()->GetInstanceTable(instance)->CreateWin32SurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateWin32SurfaceKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(instance);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pSurface);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateWin32SurfaceKHR>::Dispatch(encode::TraceManager::Get(), result, instance, pCreateInfo, pAllocator, pSurface);

    return result;
}

VKAPI_ATTR VkBool32 VKAPI_CALL GetPhysicalDeviceWin32PresentationSupportKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceWin32PresentationSupportKHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, queueFamilyIndex);

    VkBool32 result = encode::TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceWin32PresentationSupportKHR(physicalDevice, queueFamilyIndex);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceWin32PresentationSupportKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeUInt32Value(queueFamilyIndex);
        encoder->EncodeVkBool32Value(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceWin32PresentationSupportKHR>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, queueFamilyIndex);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFeatures2KHR(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceFeatures2*                  pFeatures)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2KHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pFeatures);

    encode::TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceFeatures2KHR(physicalDevice, pFeatures);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2KHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        EncodeStructPtr(encoder, pFeatures);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2KHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pFeatures);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceProperties2*                pProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2KHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pProperties);

    encode::TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceProperties2KHR(physicalDevice, pProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2KHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        EncodeStructPtr(encoder, pProperties);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2KHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pProperties);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFormatProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    VkFormat                                    format,
    VkFormatProperties2*                        pFormatProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2KHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, format, pFormatProperties);

    encode::TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceFormatProperties2KHR(physicalDevice, format, pFormatProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2KHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeEnumValue(format);
        EncodeStructPtr(encoder, pFormatProperties);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2KHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, format, pFormatProperties);
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceImageFormatProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceImageFormatInfo2*     pImageFormatInfo,
    VkImageFormatProperties2*                   pImageFormatProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2KHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pImageFormatInfo, pImageFormatProperties);

    VkResult result = encode::TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceImageFormatProperties2KHR(physicalDevice, pImageFormatInfo, pImageFormatProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2KHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        EncodeStructPtr(encoder, pImageFormatInfo);
        EncodeStructPtr(encoder, pImageFormatProperties);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2KHR>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, pImageFormatInfo, pImageFormatProperties);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceQueueFamilyProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pQueueFamilyPropertyCount,
    VkQueueFamilyProperties2*                   pQueueFamilyProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2KHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);

    encode::TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceQueueFamilyProperties2KHR(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2KHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeUInt32Ptr(pQueueFamilyPropertyCount);
        EncodeStructArray(encoder, pQueueFamilyProperties, (pQueueFamilyPropertyCount != nullptr) ? (*pQueueFamilyPropertyCount) : 0);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2KHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceMemoryProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceMemoryProperties2*          pMemoryProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2KHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pMemoryProperties);

    encode::TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceMemoryProperties2KHR(physicalDevice, pMemoryProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2KHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        EncodeStructPtr(encoder, pMemoryProperties);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2KHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pMemoryProperties);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSparseImageFormatProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo,
    uint32_t*                                   pPropertyCount,
    VkSparseImageFormatProperties2*             pProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2KHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pFormatInfo, pPropertyCount, pProperties);

    encode::TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceSparseImageFormatProperties2KHR(physicalDevice, pFormatInfo, pPropertyCount, pProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2KHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        EncodeStructPtr(encoder, pFormatInfo);
        encoder->EncodeUInt32Ptr(pPropertyCount);
        EncodeStructArray(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2KHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pFormatInfo, pPropertyCount, pProperties);
}

VKAPI_ATTR void VKAPI_CALL GetDeviceGroupPeerMemoryFeaturesKHR(
    VkDevice                                    device,
    uint32_t                                    heapIndex,
    uint32_t                                    localDeviceIndex,
    uint32_t                                    remoteDeviceIndex,
    VkPeerMemoryFeatureFlags*                   pPeerMemoryFeatures)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeaturesKHR>::Dispatch(encode::TraceManager::Get(), device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);

    encode::TraceManager::Get()->GetDeviceTable(device)->GetDeviceGroupPeerMemoryFeaturesKHR(device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeaturesKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeUInt32Value(heapIndex);
        encoder->EncodeUInt32Value(localDeviceIndex);
        encoder->EncodeUInt32Value(remoteDeviceIndex);
        encoder->EncodeFlagsPtr(pPeerMemoryFeatures);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeaturesKHR>::Dispatch(encode::TraceManager::Get(), device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);
}

VKAPI_ATTR void VKAPI_CALL CmdSetDeviceMaskKHR(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    deviceMask)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDeviceMaskKHR>::Dispatch(encode::TraceManager::Get(), commandBuffer, deviceMask);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetDeviceMaskKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(deviceMask);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdSetDeviceMaskKHR(commandBuffer, deviceMask);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDeviceMaskKHR>::Dispatch(encode::TraceManager::Get(), commandBuffer, deviceMask);
}

VKAPI_ATTR void VKAPI_CALL CmdDispatchBaseKHR(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    baseGroupX,
    uint32_t                                    baseGroupY,
    uint32_t                                    baseGroupZ,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDispatchBaseKHR>::Dispatch(encode::TraceManager::Get(), commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdDispatchBaseKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(baseGroupX);
        encoder->EncodeUInt32Value(baseGroupY);
        encoder->EncodeUInt32Value(baseGroupZ);
        encoder->EncodeUInt32Value(groupCountX);
        encoder->EncodeUInt32Value(groupCountY);
        encoder->EncodeUInt32Value(groupCountZ);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdDispatchBaseKHR(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDispatchBaseKHR>::Dispatch(encode::TraceManager::Get(), commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
}

VKAPI_ATTR void VKAPI_CALL TrimCommandPoolKHR(
    VkDevice                                    device,
    VkCommandPool                               commandPool,
    VkCommandPoolTrimFlags                      flags)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkTrimCommandPoolKHR>::Dispatch(encode::TraceManager::Get(), device, commandPool, flags);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkTrimCommandPoolKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(commandPool);
        encoder->EncodeFlagsValue(flags);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(device)->TrimCommandPoolKHR(device, commandPool, flags);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkTrimCommandPoolKHR>::Dispatch(encode::TraceManager::Get(), device, commandPool, flags);
}

VKAPI_ATTR VkResult VKAPI_CALL EnumeratePhysicalDeviceGroupsKHR(
    VkInstance                                  instance,
    uint32_t*                                   pPhysicalDeviceGroupCount,
    VkPhysicalDeviceGroupProperties*            pPhysicalDeviceGroupProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroupsKHR>::Dispatch(encode::TraceManager::Get(), instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);

    VkResult result = encode::TraceManager::Get()->GetInstanceTable(instance)->EnumeratePhysicalDeviceGroupsKHR(instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroupsKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(instance);
        encoder->EncodeUInt32Ptr(pPhysicalDeviceGroupCount);
        EncodeStructArray(encoder, pPhysicalDeviceGroupProperties, (pPhysicalDeviceGroupCount != nullptr) ? (*pPhysicalDeviceGroupCount) : 0);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroupsKHR>::Dispatch(encode::TraceManager::Get(), result, instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalBufferPropertiesKHR(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceExternalBufferInfo*   pExternalBufferInfo,
    VkExternalBufferProperties*                 pExternalBufferProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferPropertiesKHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pExternalBufferInfo, pExternalBufferProperties);

    encode::TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceExternalBufferPropertiesKHR(physicalDevice, pExternalBufferInfo, pExternalBufferProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferPropertiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        EncodeStructPtr(encoder, pExternalBufferInfo);
        EncodeStructPtr(encoder, pExternalBufferProperties);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferPropertiesKHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pExternalBufferInfo, pExternalBufferProperties);
}

VKAPI_ATTR VkResult VKAPI_CALL GetMemoryWin32HandleKHR(
    VkDevice                                    device,
    const VkMemoryGetWin32HandleInfoKHR*        pGetWin32HandleInfo,
    HANDLE*                                     pHandle)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandleKHR>::Dispatch(encode::TraceManager::Get(), device, pGetWin32HandleInfo, pHandle);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->GetMemoryWin32HandleKHR(device, pGetWin32HandleInfo, pHandle);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetMemoryWin32HandleKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pGetWin32HandleInfo);
        encoder->EncodeVoidPtrPtr(pHandle);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandleKHR>::Dispatch(encode::TraceManager::Get(), result, device, pGetWin32HandleInfo, pHandle);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetMemoryWin32HandlePropertiesKHR(
    VkDevice                                    device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    HANDLE                                      handle,
    VkMemoryWin32HandlePropertiesKHR*           pMemoryWin32HandleProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandlePropertiesKHR>::Dispatch(encode::TraceManager::Get(), device, handleType, handle, pMemoryWin32HandleProperties);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->GetMemoryWin32HandlePropertiesKHR(device, handleType, handle, pMemoryWin32HandleProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetMemoryWin32HandlePropertiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeEnumValue(handleType);
        encoder->EncodeVoidPtr(handle);
        EncodeStructPtr(encoder, pMemoryWin32HandleProperties);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandlePropertiesKHR>::Dispatch(encode::TraceManager::Get(), result, device, handleType, handle, pMemoryWin32HandleProperties);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetMemoryFdKHR(
    VkDevice                                    device,
    const VkMemoryGetFdInfoKHR*                 pGetFdInfo,
    int*                                        pFd)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryFdKHR>::Dispatch(encode::TraceManager::Get(), device, pGetFdInfo, pFd);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->GetMemoryFdKHR(device, pGetFdInfo, pFd);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetMemoryFdKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pGetFdInfo);
        encoder->EncodeInt32Ptr(pFd);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryFdKHR>::Dispatch(encode::TraceManager::Get(), result, device, pGetFdInfo, pFd);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetMemoryFdPropertiesKHR(
    VkDevice                                    device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    int                                         fd,
    VkMemoryFdPropertiesKHR*                    pMemoryFdProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryFdPropertiesKHR>::Dispatch(encode::TraceManager::Get(), device, handleType, fd, pMemoryFdProperties);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->GetMemoryFdPropertiesKHR(device, handleType, fd, pMemoryFdProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetMemoryFdPropertiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeEnumValue(handleType);
        encoder->EncodeInt32Value(fd);
        EncodeStructPtr(encoder, pMemoryFdProperties);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryFdPropertiesKHR>::Dispatch(encode::TraceManager::Get(), result, device, handleType, fd, pMemoryFdProperties);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalSemaphorePropertiesKHR(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo,
    VkExternalSemaphoreProperties*              pExternalSemaphoreProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);

    encode::TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceExternalSemaphorePropertiesKHR(physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        EncodeStructPtr(encoder, pExternalSemaphoreInfo);
        EncodeStructPtr(encoder, pExternalSemaphoreProperties);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);
}

VKAPI_ATTR VkResult VKAPI_CALL ImportSemaphoreWin32HandleKHR(
    VkDevice                                    device,
    const VkImportSemaphoreWin32HandleInfoKHR*  pImportSemaphoreWin32HandleInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkImportSemaphoreWin32HandleKHR>::Dispatch(encode::TraceManager::Get(), device, pImportSemaphoreWin32HandleInfo);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->ImportSemaphoreWin32HandleKHR(device, pImportSemaphoreWin32HandleInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkImportSemaphoreWin32HandleKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pImportSemaphoreWin32HandleInfo);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkImportSemaphoreWin32HandleKHR>::Dispatch(encode::TraceManager::Get(), result, device, pImportSemaphoreWin32HandleInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetSemaphoreWin32HandleKHR(
    VkDevice                                    device,
    const VkSemaphoreGetWin32HandleInfoKHR*     pGetWin32HandleInfo,
    HANDLE*                                     pHandle)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetSemaphoreWin32HandleKHR>::Dispatch(encode::TraceManager::Get(), device, pGetWin32HandleInfo, pHandle);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->GetSemaphoreWin32HandleKHR(device, pGetWin32HandleInfo, pHandle);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetSemaphoreWin32HandleKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pGetWin32HandleInfo);
        encoder->EncodeVoidPtrPtr(pHandle);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreWin32HandleKHR>::Dispatch(encode::TraceManager::Get(), result, device, pGetWin32HandleInfo, pHandle);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL ImportSemaphoreFdKHR(
    VkDevice                                    device,
    const VkImportSemaphoreFdInfoKHR*           pImportSemaphoreFdInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkImportSemaphoreFdKHR>::Dispatch(encode::TraceManager::Get(), device, pImportSemaphoreFdInfo);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->ImportSemaphoreFdKHR(device, pImportSemaphoreFdInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkImportSemaphoreFdKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pImportSemaphoreFdInfo);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkImportSemaphoreFdKHR>::Dispatch(encode::TraceManager::Get(), result, device, pImportSemaphoreFdInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetSemaphoreFdKHR(
    VkDevice                                    device,
    const VkSemaphoreGetFdInfoKHR*              pGetFdInfo,
    int*                                        pFd)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetSemaphoreFdKHR>::Dispatch(encode::TraceManager::Get(), device, pGetFdInfo, pFd);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->GetSemaphoreFdKHR(device, pGetFdInfo, pFd);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetSemaphoreFdKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pGetFdInfo);
        encoder->EncodeInt32Ptr(pFd);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetSemaphoreFdKHR>::Dispatch(encode::TraceManager::Get(), result, device, pGetFdInfo, pFd);

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdPushDescriptorSetKHR(
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipelineLayout                            layout,
    uint32_t                                    set,
    uint32_t                                    descriptorWriteCount,
    const VkWriteDescriptorSet*                 pDescriptorWrites)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdPushDescriptorSetKHR>::Dispatch(encode::TraceManager::Get(), commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdPushDescriptorSetKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeEnumValue(pipelineBindPoint);
        encoder->EncodeHandleIdValue(layout);
        encoder->EncodeUInt32Value(set);
        encoder->EncodeUInt32Value(descriptorWriteCount);
        EncodeStructArray(encoder, pDescriptorWrites, descriptorWriteCount);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdPushDescriptorSetKHR(commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdPushDescriptorSetKHR>::Dispatch(encode::TraceManager::Get(), commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDescriptorUpdateTemplateKHR(
    VkDevice                                    device,
    const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDescriptorUpdateTemplate*                 pDescriptorUpdateTemplate)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplateKHR>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->CreateDescriptorUpdateTemplateKHR(device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplateKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pDescriptorUpdateTemplate);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplateKHR>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyDescriptorUpdateTemplateKHR(
    VkDevice                                    device,
    VkDescriptorUpdateTemplate                  descriptorUpdateTemplate,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplateKHR>::Dispatch(encode::TraceManager::Get(), device, descriptorUpdateTemplate, pAllocator);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplateKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(descriptorUpdateTemplate);
        EncodeStructPtr(encoder, pAllocator);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(device)->DestroyDescriptorUpdateTemplateKHR(device, descriptorUpdateTemplate, pAllocator);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplateKHR>::Dispatch(encode::TraceManager::Get(), device, descriptorUpdateTemplate, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateRenderPass2KHR(
    VkDevice                                    device,
    const VkRenderPassCreateInfo2KHR*           pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkRenderPass*                               pRenderPass)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateRenderPass2KHR>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pRenderPass);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->CreateRenderPass2KHR(device, pCreateInfo, pAllocator, pRenderPass);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateRenderPass2KHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pRenderPass);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateRenderPass2KHR>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pRenderPass);

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdBeginRenderPass2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkRenderPassBeginInfo*                pRenderPassBegin,
    const VkSubpassBeginInfoKHR*                pSubpassBeginInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass2KHR>::Dispatch(encode::TraceManager::Get(), commandBuffer, pRenderPassBegin, pSubpassBeginInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdBeginRenderPass2KHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        EncodeStructPtr(encoder, pRenderPassBegin);
        EncodeStructPtr(encoder, pSubpassBeginInfo);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdBeginRenderPass2KHR(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginRenderPass2KHR>::Dispatch(encode::TraceManager::Get(), commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdNextSubpass2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkSubpassBeginInfoKHR*                pSubpassBeginInfo,
    const VkSubpassEndInfoKHR*                  pSubpassEndInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdNextSubpass2KHR>::Dispatch(encode::TraceManager::Get(), commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdNextSubpass2KHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        EncodeStructPtr(encoder, pSubpassBeginInfo);
        EncodeStructPtr(encoder, pSubpassEndInfo);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdNextSubpass2KHR(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdNextSubpass2KHR>::Dispatch(encode::TraceManager::Get(), commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdEndRenderPass2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkSubpassEndInfoKHR*                  pSubpassEndInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass2KHR>::Dispatch(encode::TraceManager::Get(), commandBuffer, pSubpassEndInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdEndRenderPass2KHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        EncodeStructPtr(encoder, pSubpassEndInfo);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdEndRenderPass2KHR(commandBuffer, pSubpassEndInfo);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndRenderPass2KHR>::Dispatch(encode::TraceManager::Get(), commandBuffer, pSubpassEndInfo);
}

VKAPI_ATTR VkResult VKAPI_CALL GetSwapchainStatusKHR(
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetSwapchainStatusKHR>::Dispatch(encode::TraceManager::Get(), device, swapchain);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->GetSwapchainStatusKHR(device, swapchain);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetSwapchainStatusKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(swapchain);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetSwapchainStatusKHR>::Dispatch(encode::TraceManager::Get(), result, device, swapchain);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalFencePropertiesKHR(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceExternalFenceInfo*    pExternalFenceInfo,
    VkExternalFenceProperties*                  pExternalFenceProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFencePropertiesKHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pExternalFenceInfo, pExternalFenceProperties);

    encode::TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceExternalFencePropertiesKHR(physicalDevice, pExternalFenceInfo, pExternalFenceProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFencePropertiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        EncodeStructPtr(encoder, pExternalFenceInfo);
        EncodeStructPtr(encoder, pExternalFenceProperties);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFencePropertiesKHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pExternalFenceInfo, pExternalFenceProperties);
}

VKAPI_ATTR VkResult VKAPI_CALL ImportFenceWin32HandleKHR(
    VkDevice                                    device,
    const VkImportFenceWin32HandleInfoKHR*      pImportFenceWin32HandleInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkImportFenceWin32HandleKHR>::Dispatch(encode::TraceManager::Get(), device, pImportFenceWin32HandleInfo);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->ImportFenceWin32HandleKHR(device, pImportFenceWin32HandleInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkImportFenceWin32HandleKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pImportFenceWin32HandleInfo);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkImportFenceWin32HandleKHR>::Dispatch(encode::TraceManager::Get(), result, device, pImportFenceWin32HandleInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetFenceWin32HandleKHR(
    VkDevice                                    device,
    const VkFenceGetWin32HandleInfoKHR*         pGetWin32HandleInfo,
    HANDLE*                                     pHandle)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetFenceWin32HandleKHR>::Dispatch(encode::TraceManager::Get(), device, pGetWin32HandleInfo, pHandle);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->GetFenceWin32HandleKHR(device, pGetWin32HandleInfo, pHandle);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetFenceWin32HandleKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pGetWin32HandleInfo);
        encoder->EncodeVoidPtrPtr(pHandle);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetFenceWin32HandleKHR>::Dispatch(encode::TraceManager::Get(), result, device, pGetWin32HandleInfo, pHandle);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL ImportFenceFdKHR(
    VkDevice                                    device,
    const VkImportFenceFdInfoKHR*               pImportFenceFdInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkImportFenceFdKHR>::Dispatch(encode::TraceManager::Get(), device, pImportFenceFdInfo);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->ImportFenceFdKHR(device, pImportFenceFdInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkImportFenceFdKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pImportFenceFdInfo);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkImportFenceFdKHR>::Dispatch(encode::TraceManager::Get(), result, device, pImportFenceFdInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetFenceFdKHR(
    VkDevice                                    device,
    const VkFenceGetFdInfoKHR*                  pGetFdInfo,
    int*                                        pFd)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetFenceFdKHR>::Dispatch(encode::TraceManager::Get(), device, pGetFdInfo, pFd);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->GetFenceFdKHR(device, pGetFdInfo, pFd);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetFenceFdKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pGetFdInfo);
        encoder->EncodeInt32Ptr(pFd);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetFenceFdKHR>::Dispatch(encode::TraceManager::Get(), result, device, pGetFdInfo, pFd);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceCapabilities2KHR(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceSurfaceInfo2KHR*      pSurfaceInfo,
    VkSurfaceCapabilities2KHR*                  pSurfaceCapabilities)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2KHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pSurfaceInfo, pSurfaceCapabilities);

    VkResult result = encode::TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceSurfaceCapabilities2KHR(physicalDevice, pSurfaceInfo, pSurfaceCapabilities);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2KHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        EncodeStructPtr(encoder, pSurfaceInfo);
        EncodeStructPtr(encoder, pSurfaceCapabilities);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2KHR>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, pSurfaceInfo, pSurfaceCapabilities);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceFormats2KHR(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceSurfaceInfo2KHR*      pSurfaceInfo,
    uint32_t*                                   pSurfaceFormatCount,
    VkSurfaceFormat2KHR*                        pSurfaceFormats)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormats2KHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pSurfaceInfo, pSurfaceFormatCount, pSurfaceFormats);

    VkResult result = encode::TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceSurfaceFormats2KHR(physicalDevice, pSurfaceInfo, pSurfaceFormatCount, pSurfaceFormats);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormats2KHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        EncodeStructPtr(encoder, pSurfaceInfo);
        encoder->EncodeUInt32Ptr(pSurfaceFormatCount);
        EncodeStructArray(encoder, pSurfaceFormats, (pSurfaceFormatCount != nullptr) ? (*pSurfaceFormatCount) : 0);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormats2KHR>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, pSurfaceInfo, pSurfaceFormatCount, pSurfaceFormats);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceDisplayProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pPropertyCount,
    VkDisplayProperties2KHR*                    pProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayProperties2KHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pPropertyCount, pProperties);

    VkResult result = encode::TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceDisplayProperties2KHR(physicalDevice, pPropertyCount, pProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayProperties2KHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeUInt32Ptr(pPropertyCount);
        EncodeStructArray(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayProperties2KHR>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, pPropertyCount, pProperties);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceDisplayPlaneProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pPropertyCount,
    VkDisplayPlaneProperties2KHR*               pProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlaneProperties2KHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pPropertyCount, pProperties);

    VkResult result = encode::TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceDisplayPlaneProperties2KHR(physicalDevice, pPropertyCount, pProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlaneProperties2KHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeUInt32Ptr(pPropertyCount);
        EncodeStructArray(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlaneProperties2KHR>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, pPropertyCount, pProperties);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDisplayModeProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    VkDisplayKHR                                display,
    uint32_t*                                   pPropertyCount,
    VkDisplayModeProperties2KHR*                pProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDisplayModeProperties2KHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, display, pPropertyCount, pProperties);

    VkResult result = encode::TraceManager::Get()->GetInstanceTable(physicalDevice)->GetDisplayModeProperties2KHR(physicalDevice, display, pPropertyCount, pProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetDisplayModeProperties2KHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeHandleIdValue(display);
        encoder->EncodeUInt32Ptr(pPropertyCount);
        EncodeStructArray(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayModeProperties2KHR>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, display, pPropertyCount, pProperties);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDisplayPlaneCapabilities2KHR(
    VkPhysicalDevice                            physicalDevice,
    const VkDisplayPlaneInfo2KHR*               pDisplayPlaneInfo,
    VkDisplayPlaneCapabilities2KHR*             pCapabilities)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilities2KHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pDisplayPlaneInfo, pCapabilities);

    VkResult result = encode::TraceManager::Get()->GetInstanceTable(physicalDevice)->GetDisplayPlaneCapabilities2KHR(physicalDevice, pDisplayPlaneInfo, pCapabilities);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilities2KHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        EncodeStructPtr(encoder, pDisplayPlaneInfo);
        EncodeStructPtr(encoder, pCapabilities);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilities2KHR>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, pDisplayPlaneInfo, pCapabilities);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetImageMemoryRequirements2KHR(
    VkDevice                                    device,
    const VkImageMemoryRequirementsInfo2*       pInfo,
    VkMemoryRequirements2*                      pMemoryRequirements)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2KHR>::Dispatch(encode::TraceManager::Get(), device, pInfo, pMemoryRequirements);

    encode::TraceManager::Get()->GetDeviceTable(device)->GetImageMemoryRequirements2KHR(device, pInfo, pMemoryRequirements);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2KHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pInfo);
        EncodeStructPtr(encoder, pMemoryRequirements);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2KHR>::Dispatch(encode::TraceManager::Get(), device, pInfo, pMemoryRequirements);
}

VKAPI_ATTR void VKAPI_CALL GetBufferMemoryRequirements2KHR(
    VkDevice                                    device,
    const VkBufferMemoryRequirementsInfo2*      pInfo,
    VkMemoryRequirements2*                      pMemoryRequirements)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2KHR>::Dispatch(encode::TraceManager::Get(), device, pInfo, pMemoryRequirements);

    encode::TraceManager::Get()->GetDeviceTable(device)->GetBufferMemoryRequirements2KHR(device, pInfo, pMemoryRequirements);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2KHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pInfo);
        EncodeStructPtr(encoder, pMemoryRequirements);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2KHR>::Dispatch(encode::TraceManager::Get(), device, pInfo, pMemoryRequirements);
}

VKAPI_ATTR void VKAPI_CALL GetImageSparseMemoryRequirements2KHR(
    VkDevice                                    device,
    const VkImageSparseMemoryRequirementsInfo2* pInfo,
    uint32_t*                                   pSparseMemoryRequirementCount,
    VkSparseImageMemoryRequirements2*           pSparseMemoryRequirements)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2KHR>::Dispatch(encode::TraceManager::Get(), device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);

    encode::TraceManager::Get()->GetDeviceTable(device)->GetImageSparseMemoryRequirements2KHR(device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2KHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pInfo);
        encoder->EncodeUInt32Ptr(pSparseMemoryRequirementCount);
        EncodeStructArray(encoder, pSparseMemoryRequirements, (pSparseMemoryRequirementCount != nullptr) ? (*pSparseMemoryRequirementCount) : 0);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2KHR>::Dispatch(encode::TraceManager::Get(), device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateSamplerYcbcrConversionKHR(
    VkDevice                                    device,
    const VkSamplerYcbcrConversionCreateInfo*   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSamplerYcbcrConversion*                   pYcbcrConversion)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversionKHR>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pYcbcrConversion);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->CreateSamplerYcbcrConversionKHR(device, pCreateInfo, pAllocator, pYcbcrConversion);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversionKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pYcbcrConversion);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversionKHR>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pYcbcrConversion);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroySamplerYcbcrConversionKHR(
    VkDevice                                    device,
    VkSamplerYcbcrConversion                    ycbcrConversion,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversionKHR>::Dispatch(encode::TraceManager::Get(), device, ycbcrConversion, pAllocator);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversionKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(ycbcrConversion);
        EncodeStructPtr(encoder, pAllocator);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(device)->DestroySamplerYcbcrConversionKHR(device, ycbcrConversion, pAllocator);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversionKHR>::Dispatch(encode::TraceManager::Get(), device, ycbcrConversion, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL BindBufferMemory2KHR(
    VkDevice                                    device,
    uint32_t                                    bindInfoCount,
    const VkBindBufferMemoryInfo*               pBindInfos)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBindBufferMemory2KHR>::Dispatch(encode::TraceManager::Get(), device, bindInfoCount, pBindInfos);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->BindBufferMemory2KHR(device, bindInfoCount, pBindInfos);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkBindBufferMemory2KHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeUInt32Value(bindInfoCount);
        EncodeStructArray(encoder, pBindInfos, bindInfoCount);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindBufferMemory2KHR>::Dispatch(encode::TraceManager::Get(), result, device, bindInfoCount, pBindInfos);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL BindImageMemory2KHR(
    VkDevice                                    device,
    uint32_t                                    bindInfoCount,
    const VkBindImageMemoryInfo*                pBindInfos)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBindImageMemory2KHR>::Dispatch(encode::TraceManager::Get(), device, bindInfoCount, pBindInfos);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->BindImageMemory2KHR(device, bindInfoCount, pBindInfos);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkBindImageMemory2KHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeUInt32Value(bindInfoCount);
        EncodeStructArray(encoder, pBindInfos, bindInfoCount);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindImageMemory2KHR>::Dispatch(encode::TraceManager::Get(), result, device, bindInfoCount, pBindInfos);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetDescriptorSetLayoutSupportKHR(
    VkDevice                                    device,
    const VkDescriptorSetLayoutCreateInfo*      pCreateInfo,
    VkDescriptorSetLayoutSupport*               pSupport)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupportKHR>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pSupport);

    encode::TraceManager::Get()->GetDeviceTable(device)->GetDescriptorSetLayoutSupportKHR(device, pCreateInfo, pSupport);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupportKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pSupport);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupportKHR>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pSupport);
}

VKAPI_ATTR void VKAPI_CALL CmdDrawIndirectCountKHR(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCountKHR>::Dispatch(encode::TraceManager::Get(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdDrawIndirectCountKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeHandleIdValue(countBuffer);
        encoder->EncodeVkDeviceSizeValue(countBufferOffset);
        encoder->EncodeUInt32Value(maxDrawCount);
        encoder->EncodeUInt32Value(stride);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdDrawIndirectCountKHR(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCountKHR>::Dispatch(encode::TraceManager::Get(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

VKAPI_ATTR void VKAPI_CALL CmdDrawIndexedIndirectCountKHR(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountKHR>::Dispatch(encode::TraceManager::Get(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeHandleIdValue(countBuffer);
        encoder->EncodeVkDeviceSizeValue(countBufferOffset);
        encoder->EncodeUInt32Value(maxDrawCount);
        encoder->EncodeUInt32Value(stride);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdDrawIndexedIndirectCountKHR(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountKHR>::Dispatch(encode::TraceManager::Get(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDebugReportCallbackEXT(
    VkInstance                                  instance,
    const VkDebugReportCallbackCreateInfoEXT*   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDebugReportCallbackEXT*                   pCallback)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDebugReportCallbackEXT>::Dispatch(encode::TraceManager::Get(), instance, pCreateInfo, pAllocator, pCallback);

    VkResult result = encode::TraceManager::Get()->GetInstanceTable(instance)->CreateDebugReportCallbackEXT(instance, pCreateInfo, pAllocator, pCallback);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateDebugReportCallbackEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(instance);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pCallback);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDebugReportCallbackEXT>::Dispatch(encode::TraceManager::Get(), result, instance, pCreateInfo, pAllocator, pCallback);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyDebugReportCallbackEXT(
    VkInstance                                  instance,
    VkDebugReportCallbackEXT                    callback,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDebugReportCallbackEXT>::Dispatch(encode::TraceManager::Get(), instance, callback, pAllocator);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyDebugReportCallbackEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(instance);
        encoder->EncodeHandleIdValue(callback);
        EncodeStructPtr(encoder, pAllocator);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetInstanceTable(instance)->DestroyDebugReportCallbackEXT(instance, callback, pAllocator);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDebugReportCallbackEXT>::Dispatch(encode::TraceManager::Get(), instance, callback, pAllocator);
}

VKAPI_ATTR void VKAPI_CALL DebugReportMessageEXT(
    VkInstance                                  instance,
    VkDebugReportFlagsEXT                       flags,
    VkDebugReportObjectTypeEXT                  objectType,
    uint64_t                                    object,
    size_t                                      location,
    int32_t                                     messageCode,
    const char*                                 pLayerPrefix,
    const char*                                 pMessage)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDebugReportMessageEXT>::Dispatch(encode::TraceManager::Get(), instance, flags, objectType, object, location, messageCode, pLayerPrefix, pMessage);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDebugReportMessageEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(instance);
        encoder->EncodeFlagsValue(flags);
        encoder->EncodeEnumValue(objectType);
        encoder->EncodeUInt64Value(object);
        encoder->EncodeSizeTValue(location);
        encoder->EncodeInt32Value(messageCode);
        encoder->EncodeString(pLayerPrefix);
        encoder->EncodeString(pMessage);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetInstanceTable(instance)->DebugReportMessageEXT(instance, flags, objectType, object, location, messageCode, pLayerPrefix, pMessage);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDebugReportMessageEXT>::Dispatch(encode::TraceManager::Get(), instance, flags, objectType, object, location, messageCode, pLayerPrefix, pMessage);
}

VKAPI_ATTR VkResult VKAPI_CALL DebugMarkerSetObjectTagEXT(
    VkDevice                                    device,
    const VkDebugMarkerObjectTagInfoEXT*        pTagInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDebugMarkerSetObjectTagEXT>::Dispatch(encode::TraceManager::Get(), device, pTagInfo);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->DebugMarkerSetObjectTagEXT(device, pTagInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDebugMarkerSetObjectTagEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pTagInfo);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDebugMarkerSetObjectTagEXT>::Dispatch(encode::TraceManager::Get(), result, device, pTagInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL DebugMarkerSetObjectNameEXT(
    VkDevice                                    device,
    const VkDebugMarkerObjectNameInfoEXT*       pNameInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDebugMarkerSetObjectNameEXT>::Dispatch(encode::TraceManager::Get(), device, pNameInfo);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->DebugMarkerSetObjectNameEXT(device, pNameInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDebugMarkerSetObjectNameEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pNameInfo);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDebugMarkerSetObjectNameEXT>::Dispatch(encode::TraceManager::Get(), result, device, pNameInfo);

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdDebugMarkerBeginEXT(
    VkCommandBuffer                             commandBuffer,
    const VkDebugMarkerMarkerInfoEXT*           pMarkerInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerBeginEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer, pMarkerInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdDebugMarkerBeginEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        EncodeStructPtr(encoder, pMarkerInfo);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdDebugMarkerBeginEXT(commandBuffer, pMarkerInfo);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerBeginEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer, pMarkerInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdDebugMarkerEndEXT(
    VkCommandBuffer                             commandBuffer)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerEndEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdDebugMarkerEndEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdDebugMarkerEndEXT(commandBuffer);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerEndEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer);
}

VKAPI_ATTR void VKAPI_CALL CmdDebugMarkerInsertEXT(
    VkCommandBuffer                             commandBuffer,
    const VkDebugMarkerMarkerInfoEXT*           pMarkerInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerInsertEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer, pMarkerInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdDebugMarkerInsertEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        EncodeStructPtr(encoder, pMarkerInfo);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdDebugMarkerInsertEXT(commandBuffer, pMarkerInfo);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDebugMarkerInsertEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer, pMarkerInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdBindTransformFeedbackBuffersEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    const VkBuffer*                             pBuffers,
    const VkDeviceSize*                         pOffsets,
    const VkDeviceSize*                         pSizes)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindTransformFeedbackBuffersEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdBindTransformFeedbackBuffersEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(firstBinding);
        encoder->EncodeUInt32Value(bindingCount);
        encoder->EncodeHandleIdArray(pBuffers, bindingCount);
        encoder->EncodeVkDeviceSizeArray(pOffsets, bindingCount);
        encoder->EncodeVkDeviceSizeArray(pSizes, bindingCount);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdBindTransformFeedbackBuffersEXT(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindTransformFeedbackBuffersEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes);
}

VKAPI_ATTR void VKAPI_CALL CmdBeginTransformFeedbackEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstCounterBuffer,
    uint32_t                                    counterBufferCount,
    const VkBuffer*                             pCounterBuffers,
    const VkDeviceSize*                         pCounterBufferOffsets)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginTransformFeedbackEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdBeginTransformFeedbackEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(firstCounterBuffer);
        encoder->EncodeUInt32Value(counterBufferCount);
        encoder->EncodeHandleIdArray(pCounterBuffers, counterBufferCount);
        encoder->EncodeVkDeviceSizeArray(pCounterBufferOffsets, counterBufferCount);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdBeginTransformFeedbackEXT(commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginTransformFeedbackEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
}

VKAPI_ATTR void VKAPI_CALL CmdEndTransformFeedbackEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstCounterBuffer,
    uint32_t                                    counterBufferCount,
    const VkBuffer*                             pCounterBuffers,
    const VkDeviceSize*                         pCounterBufferOffsets)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndTransformFeedbackEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdEndTransformFeedbackEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(firstCounterBuffer);
        encoder->EncodeUInt32Value(counterBufferCount);
        encoder->EncodeHandleIdArray(pCounterBuffers, counterBufferCount);
        encoder->EncodeVkDeviceSizeArray(pCounterBufferOffsets, counterBufferCount);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdEndTransformFeedbackEXT(commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndTransformFeedbackEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
}

VKAPI_ATTR void VKAPI_CALL CmdBeginQueryIndexedEXT(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    query,
    VkQueryControlFlags                         flags,
    uint32_t                                    index)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginQueryIndexedEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer, queryPool, query, flags, index);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdBeginQueryIndexedEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(queryPool);
        encoder->EncodeUInt32Value(query);
        encoder->EncodeFlagsValue(flags);
        encoder->EncodeUInt32Value(index);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdBeginQueryIndexedEXT(commandBuffer, queryPool, query, flags, index);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginQueryIndexedEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer, queryPool, query, flags, index);
}

VKAPI_ATTR void VKAPI_CALL CmdEndQueryIndexedEXT(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    query,
    uint32_t                                    index)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndQueryIndexedEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer, queryPool, query, index);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdEndQueryIndexedEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(queryPool);
        encoder->EncodeUInt32Value(query);
        encoder->EncodeUInt32Value(index);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdEndQueryIndexedEXT(commandBuffer, queryPool, query, index);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndQueryIndexedEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer, queryPool, query, index);
}

VKAPI_ATTR void VKAPI_CALL CmdDrawIndirectByteCountEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    instanceCount,
    uint32_t                                    firstInstance,
    VkBuffer                                    counterBuffer,
    VkDeviceSize                                counterBufferOffset,
    uint32_t                                    counterOffset,
    uint32_t                                    vertexStride)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectByteCountEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer, instanceCount, firstInstance, counterBuffer, counterBufferOffset, counterOffset, vertexStride);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdDrawIndirectByteCountEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(instanceCount);
        encoder->EncodeUInt32Value(firstInstance);
        encoder->EncodeHandleIdValue(counterBuffer);
        encoder->EncodeVkDeviceSizeValue(counterBufferOffset);
        encoder->EncodeUInt32Value(counterOffset);
        encoder->EncodeUInt32Value(vertexStride);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdDrawIndirectByteCountEXT(commandBuffer, instanceCount, firstInstance, counterBuffer, counterBufferOffset, counterOffset, vertexStride);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectByteCountEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer, instanceCount, firstInstance, counterBuffer, counterBufferOffset, counterOffset, vertexStride);
}

VKAPI_ATTR void VKAPI_CALL CmdDrawIndirectCountAMD(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCountAMD>::Dispatch(encode::TraceManager::Get(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdDrawIndirectCountAMD);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeHandleIdValue(countBuffer);
        encoder->EncodeVkDeviceSizeValue(countBufferOffset);
        encoder->EncodeUInt32Value(maxDrawCount);
        encoder->EncodeUInt32Value(stride);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdDrawIndirectCountAMD(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndirectCountAMD>::Dispatch(encode::TraceManager::Get(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

VKAPI_ATTR void VKAPI_CALL CmdDrawIndexedIndirectCountAMD(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountAMD>::Dispatch(encode::TraceManager::Get(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountAMD);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeHandleIdValue(countBuffer);
        encoder->EncodeVkDeviceSizeValue(countBufferOffset);
        encoder->EncodeUInt32Value(maxDrawCount);
        encoder->EncodeUInt32Value(stride);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdDrawIndexedIndirectCountAMD(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountAMD>::Dispatch(encode::TraceManager::Get(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

VKAPI_ATTR VkResult VKAPI_CALL GetShaderInfoAMD(
    VkDevice                                    device,
    VkPipeline                                  pipeline,
    VkShaderStageFlagBits                       shaderStage,
    VkShaderInfoTypeAMD                         infoType,
    size_t*                                     pInfoSize,
    void*                                       pInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetShaderInfoAMD>::Dispatch(encode::TraceManager::Get(), device, pipeline, shaderStage, infoType, pInfoSize, pInfo);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->GetShaderInfoAMD(device, pipeline, shaderStage, infoType, pInfoSize, pInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetShaderInfoAMD);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(pipeline);
        encoder->EncodeEnumValue(shaderStage);
        encoder->EncodeEnumValue(infoType);
        encoder->EncodeSizeTPtr(pInfoSize);
        encoder->EncodeVoidArray(pInfo, (pInfoSize != nullptr) ? (*pInfoSize) : 0);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetShaderInfoAMD>::Dispatch(encode::TraceManager::Get(), result, device, pipeline, shaderStage, infoType, pInfoSize, pInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceExternalImageFormatPropertiesNV(
    VkPhysicalDevice                            physicalDevice,
    VkFormat                                    format,
    VkImageType                                 type,
    VkImageTiling                               tiling,
    VkImageUsageFlags                           usage,
    VkImageCreateFlags                          flags,
    VkExternalMemoryHandleTypeFlagsNV           externalHandleType,
    VkExternalImageFormatPropertiesNV*          pExternalImageFormatProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalImageFormatPropertiesNV>::Dispatch(encode::TraceManager::Get(), physicalDevice, format, type, tiling, usage, flags, externalHandleType, pExternalImageFormatProperties);

    VkResult result = encode::TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceExternalImageFormatPropertiesNV(physicalDevice, format, type, tiling, usage, flags, externalHandleType, pExternalImageFormatProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalImageFormatPropertiesNV);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeEnumValue(format);
        encoder->EncodeEnumValue(type);
        encoder->EncodeEnumValue(tiling);
        encoder->EncodeFlagsValue(usage);
        encoder->EncodeFlagsValue(flags);
        encoder->EncodeFlagsValue(externalHandleType);
        EncodeStructPtr(encoder, pExternalImageFormatProperties);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalImageFormatPropertiesNV>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, format, type, tiling, usage, flags, externalHandleType, pExternalImageFormatProperties);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetMemoryWin32HandleNV(
    VkDevice                                    device,
    VkDeviceMemory                              memory,
    VkExternalMemoryHandleTypeFlagsNV           handleType,
    HANDLE*                                     pHandle)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandleNV>::Dispatch(encode::TraceManager::Get(), device, memory, handleType, pHandle);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->GetMemoryWin32HandleNV(device, memory, handleType, pHandle);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetMemoryWin32HandleNV);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(memory);
        encoder->EncodeFlagsValue(handleType);
        encoder->EncodeVoidPtrPtr(pHandle);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryWin32HandleNV>::Dispatch(encode::TraceManager::Get(), result, device, memory, handleType, pHandle);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateViSurfaceNN(
    VkInstance                                  instance,
    const VkViSurfaceCreateInfoNN*              pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateViSurfaceNN>::Dispatch(encode::TraceManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    VkResult result = encode::TraceManager::Get()->GetInstanceTable(instance)->CreateViSurfaceNN(instance, pCreateInfo, pAllocator, pSurface);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateViSurfaceNN);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(instance);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pSurface);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateViSurfaceNN>::Dispatch(encode::TraceManager::Get(), result, instance, pCreateInfo, pAllocator, pSurface);

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdBeginConditionalRenderingEXT(
    VkCommandBuffer                             commandBuffer,
    const VkConditionalRenderingBeginInfoEXT*   pConditionalRenderingBegin)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginConditionalRenderingEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer, pConditionalRenderingBegin);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdBeginConditionalRenderingEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        EncodeStructPtr(encoder, pConditionalRenderingBegin);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdBeginConditionalRenderingEXT(commandBuffer, pConditionalRenderingBegin);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginConditionalRenderingEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer, pConditionalRenderingBegin);
}

VKAPI_ATTR void VKAPI_CALL CmdEndConditionalRenderingEXT(
    VkCommandBuffer                             commandBuffer)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndConditionalRenderingEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdEndConditionalRenderingEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdEndConditionalRenderingEXT(commandBuffer);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndConditionalRenderingEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer);
}

VKAPI_ATTR void VKAPI_CALL CmdProcessCommandsNVX(
    VkCommandBuffer                             commandBuffer,
    const VkCmdProcessCommandsInfoNVX*          pProcessCommandsInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdProcessCommandsNVX>::Dispatch(encode::TraceManager::Get(), commandBuffer, pProcessCommandsInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdProcessCommandsNVX);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        EncodeStructPtr(encoder, pProcessCommandsInfo);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdProcessCommandsNVX(commandBuffer, pProcessCommandsInfo);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdProcessCommandsNVX>::Dispatch(encode::TraceManager::Get(), commandBuffer, pProcessCommandsInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdReserveSpaceForCommandsNVX(
    VkCommandBuffer                             commandBuffer,
    const VkCmdReserveSpaceForCommandsInfoNVX*  pReserveSpaceInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdReserveSpaceForCommandsNVX>::Dispatch(encode::TraceManager::Get(), commandBuffer, pReserveSpaceInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdReserveSpaceForCommandsNVX);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        EncodeStructPtr(encoder, pReserveSpaceInfo);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdReserveSpaceForCommandsNVX(commandBuffer, pReserveSpaceInfo);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdReserveSpaceForCommandsNVX>::Dispatch(encode::TraceManager::Get(), commandBuffer, pReserveSpaceInfo);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateIndirectCommandsLayoutNVX(
    VkDevice                                    device,
    const VkIndirectCommandsLayoutCreateInfoNVX* pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkIndirectCommandsLayoutNVX*                pIndirectCommandsLayout)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateIndirectCommandsLayoutNVX>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pIndirectCommandsLayout);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->CreateIndirectCommandsLayoutNVX(device, pCreateInfo, pAllocator, pIndirectCommandsLayout);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateIndirectCommandsLayoutNVX);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pIndirectCommandsLayout);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateIndirectCommandsLayoutNVX>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pIndirectCommandsLayout);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyIndirectCommandsLayoutNVX(
    VkDevice                                    device,
    VkIndirectCommandsLayoutNVX                 indirectCommandsLayout,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyIndirectCommandsLayoutNVX>::Dispatch(encode::TraceManager::Get(), device, indirectCommandsLayout, pAllocator);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyIndirectCommandsLayoutNVX);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(indirectCommandsLayout);
        EncodeStructPtr(encoder, pAllocator);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(device)->DestroyIndirectCommandsLayoutNVX(device, indirectCommandsLayout, pAllocator);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyIndirectCommandsLayoutNVX>::Dispatch(encode::TraceManager::Get(), device, indirectCommandsLayout, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateObjectTableNVX(
    VkDevice                                    device,
    const VkObjectTableCreateInfoNVX*           pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkObjectTableNVX*                           pObjectTable)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateObjectTableNVX>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pObjectTable);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->CreateObjectTableNVX(device, pCreateInfo, pAllocator, pObjectTable);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateObjectTableNVX);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pObjectTable);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateObjectTableNVX>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pObjectTable);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyObjectTableNVX(
    VkDevice                                    device,
    VkObjectTableNVX                            objectTable,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyObjectTableNVX>::Dispatch(encode::TraceManager::Get(), device, objectTable, pAllocator);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyObjectTableNVX);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(objectTable);
        EncodeStructPtr(encoder, pAllocator);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(device)->DestroyObjectTableNVX(device, objectTable, pAllocator);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyObjectTableNVX>::Dispatch(encode::TraceManager::Get(), device, objectTable, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL UnregisterObjectsNVX(
    VkDevice                                    device,
    VkObjectTableNVX                            objectTable,
    uint32_t                                    objectCount,
    const VkObjectEntryTypeNVX*                 pObjectEntryTypes,
    const uint32_t*                             pObjectIndices)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkUnregisterObjectsNVX>::Dispatch(encode::TraceManager::Get(), device, objectTable, objectCount, pObjectEntryTypes, pObjectIndices);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->UnregisterObjectsNVX(device, objectTable, objectCount, pObjectEntryTypes, pObjectIndices);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkUnregisterObjectsNVX);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(objectTable);
        encoder->EncodeUInt32Value(objectCount);
        encoder->EncodeEnumArray(pObjectEntryTypes, objectCount);
        encoder->EncodeUInt32Array(pObjectIndices, objectCount);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkUnregisterObjectsNVX>::Dispatch(encode::TraceManager::Get(), result, device, objectTable, objectCount, pObjectEntryTypes, pObjectIndices);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceGeneratedCommandsPropertiesNVX(
    VkPhysicalDevice                            physicalDevice,
    VkDeviceGeneratedCommandsFeaturesNVX*       pFeatures,
    VkDeviceGeneratedCommandsLimitsNVX*         pLimits)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX>::Dispatch(encode::TraceManager::Get(), physicalDevice, pFeatures, pLimits);

    encode::TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceGeneratedCommandsPropertiesNVX(physicalDevice, pFeatures, pLimits);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        EncodeStructPtr(encoder, pFeatures);
        EncodeStructPtr(encoder, pLimits);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX>::Dispatch(encode::TraceManager::Get(), physicalDevice, pFeatures, pLimits);
}

VKAPI_ATTR void VKAPI_CALL CmdSetViewportWScalingNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    const VkViewportWScalingNV*                 pViewportWScalings)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportWScalingNV>::Dispatch(encode::TraceManager::Get(), commandBuffer, firstViewport, viewportCount, pViewportWScalings);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetViewportWScalingNV);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(firstViewport);
        encoder->EncodeUInt32Value(viewportCount);
        EncodeStructArray(encoder, pViewportWScalings, viewportCount);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdSetViewportWScalingNV(commandBuffer, firstViewport, viewportCount, pViewportWScalings);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportWScalingNV>::Dispatch(encode::TraceManager::Get(), commandBuffer, firstViewport, viewportCount, pViewportWScalings);
}

VKAPI_ATTR VkResult VKAPI_CALL ReleaseDisplayEXT(
    VkPhysicalDevice                            physicalDevice,
    VkDisplayKHR                                display)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkReleaseDisplayEXT>::Dispatch(encode::TraceManager::Get(), physicalDevice, display);

    VkResult result = encode::TraceManager::Get()->GetInstanceTable(physicalDevice)->ReleaseDisplayEXT(physicalDevice, display);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkReleaseDisplayEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeHandleIdValue(display);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkReleaseDisplayEXT>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, display);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL AcquireXlibDisplayEXT(
    VkPhysicalDevice                            physicalDevice,
    Display*                                    dpy,
    VkDisplayKHR                                display)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkAcquireXlibDisplayEXT>::Dispatch(encode::TraceManager::Get(), physicalDevice, dpy, display);

    VkResult result = encode::TraceManager::Get()->GetInstanceTable(physicalDevice)->AcquireXlibDisplayEXT(physicalDevice, dpy, display);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkAcquireXlibDisplayEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeVoidPtr(dpy);
        encoder->EncodeHandleIdValue(display);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkAcquireXlibDisplayEXT>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, dpy, display);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetRandROutputDisplayEXT(
    VkPhysicalDevice                            physicalDevice,
    Display*                                    dpy,
    RROutput                                    rrOutput,
    VkDisplayKHR*                               pDisplay)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetRandROutputDisplayEXT>::Dispatch(encode::TraceManager::Get(), physicalDevice, dpy, rrOutput, pDisplay);

    VkResult result = encode::TraceManager::Get()->GetInstanceTable(physicalDevice)->GetRandROutputDisplayEXT(physicalDevice, dpy, rrOutput, pDisplay);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetRandROutputDisplayEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeVoidPtr(dpy);
        encoder->EncodeSizeTValue(rrOutput);
        encoder->EncodeHandleIdPtr(pDisplay);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetRandROutputDisplayEXT>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, dpy, rrOutput, pDisplay);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceCapabilities2EXT(
    VkPhysicalDevice                            physicalDevice,
    VkSurfaceKHR                                surface,
    VkSurfaceCapabilities2EXT*                  pSurfaceCapabilities)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2EXT>::Dispatch(encode::TraceManager::Get(), physicalDevice, surface, pSurfaceCapabilities);

    VkResult result = encode::TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceSurfaceCapabilities2EXT(physicalDevice, surface, pSurfaceCapabilities);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2EXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeHandleIdValue(surface);
        EncodeStructPtr(encoder, pSurfaceCapabilities);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2EXT>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, surface, pSurfaceCapabilities);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL DisplayPowerControlEXT(
    VkDevice                                    device,
    VkDisplayKHR                                display,
    const VkDisplayPowerInfoEXT*                pDisplayPowerInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDisplayPowerControlEXT>::Dispatch(encode::TraceManager::Get(), device, display, pDisplayPowerInfo);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->DisplayPowerControlEXT(device, display, pDisplayPowerInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDisplayPowerControlEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(display);
        EncodeStructPtr(encoder, pDisplayPowerInfo);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDisplayPowerControlEXT>::Dispatch(encode::TraceManager::Get(), result, device, display, pDisplayPowerInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL RegisterDeviceEventEXT(
    VkDevice                                    device,
    const VkDeviceEventInfoEXT*                 pDeviceEventInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkFence*                                    pFence)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkRegisterDeviceEventEXT>::Dispatch(encode::TraceManager::Get(), device, pDeviceEventInfo, pAllocator, pFence);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->RegisterDeviceEventEXT(device, pDeviceEventInfo, pAllocator, pFence);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkRegisterDeviceEventEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pDeviceEventInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pFence);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkRegisterDeviceEventEXT>::Dispatch(encode::TraceManager::Get(), result, device, pDeviceEventInfo, pAllocator, pFence);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL RegisterDisplayEventEXT(
    VkDevice                                    device,
    VkDisplayKHR                                display,
    const VkDisplayEventInfoEXT*                pDisplayEventInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkFence*                                    pFence)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkRegisterDisplayEventEXT>::Dispatch(encode::TraceManager::Get(), device, display, pDisplayEventInfo, pAllocator, pFence);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->RegisterDisplayEventEXT(device, display, pDisplayEventInfo, pAllocator, pFence);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkRegisterDisplayEventEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(display);
        EncodeStructPtr(encoder, pDisplayEventInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pFence);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkRegisterDisplayEventEXT>::Dispatch(encode::TraceManager::Get(), result, device, display, pDisplayEventInfo, pAllocator, pFence);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetSwapchainCounterEXT(
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain,
    VkSurfaceCounterFlagBitsEXT                 counter,
    uint64_t*                                   pCounterValue)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetSwapchainCounterEXT>::Dispatch(encode::TraceManager::Get(), device, swapchain, counter, pCounterValue);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->GetSwapchainCounterEXT(device, swapchain, counter, pCounterValue);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetSwapchainCounterEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(swapchain);
        encoder->EncodeEnumValue(counter);
        encoder->EncodeUInt64Ptr(pCounterValue);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetSwapchainCounterEXT>::Dispatch(encode::TraceManager::Get(), result, device, swapchain, counter, pCounterValue);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetRefreshCycleDurationGOOGLE(
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain,
    VkRefreshCycleDurationGOOGLE*               pDisplayTimingProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetRefreshCycleDurationGOOGLE>::Dispatch(encode::TraceManager::Get(), device, swapchain, pDisplayTimingProperties);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->GetRefreshCycleDurationGOOGLE(device, swapchain, pDisplayTimingProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetRefreshCycleDurationGOOGLE);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(swapchain);
        EncodeStructPtr(encoder, pDisplayTimingProperties);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetRefreshCycleDurationGOOGLE>::Dispatch(encode::TraceManager::Get(), result, device, swapchain, pDisplayTimingProperties);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPastPresentationTimingGOOGLE(
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain,
    uint32_t*                                   pPresentationTimingCount,
    VkPastPresentationTimingGOOGLE*             pPresentationTimings)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPastPresentationTimingGOOGLE>::Dispatch(encode::TraceManager::Get(), device, swapchain, pPresentationTimingCount, pPresentationTimings);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->GetPastPresentationTimingGOOGLE(device, swapchain, pPresentationTimingCount, pPresentationTimings);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPastPresentationTimingGOOGLE);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(swapchain);
        encoder->EncodeUInt32Ptr(pPresentationTimingCount);
        EncodeStructArray(encoder, pPresentationTimings, (pPresentationTimingCount != nullptr) ? (*pPresentationTimingCount) : 0);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPastPresentationTimingGOOGLE>::Dispatch(encode::TraceManager::Get(), result, device, swapchain, pPresentationTimingCount, pPresentationTimings);

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdSetDiscardRectangleEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstDiscardRectangle,
    uint32_t                                    discardRectangleCount,
    const VkRect2D*                             pDiscardRectangles)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer, firstDiscardRectangle, discardRectangleCount, pDiscardRectangles);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(firstDiscardRectangle);
        encoder->EncodeUInt32Value(discardRectangleCount);
        EncodeStructArray(encoder, pDiscardRectangles, discardRectangleCount);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdSetDiscardRectangleEXT(commandBuffer, firstDiscardRectangle, discardRectangleCount, pDiscardRectangles);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer, firstDiscardRectangle, discardRectangleCount, pDiscardRectangles);
}

VKAPI_ATTR void VKAPI_CALL SetHdrMetadataEXT(
    VkDevice                                    device,
    uint32_t                                    swapchainCount,
    const VkSwapchainKHR*                       pSwapchains,
    const VkHdrMetadataEXT*                     pMetadata)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkSetHdrMetadataEXT>::Dispatch(encode::TraceManager::Get(), device, swapchainCount, pSwapchains, pMetadata);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkSetHdrMetadataEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeUInt32Value(swapchainCount);
        encoder->EncodeHandleIdArray(pSwapchains, swapchainCount);
        EncodeStructArray(encoder, pMetadata, swapchainCount);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(device)->SetHdrMetadataEXT(device, swapchainCount, pSwapchains, pMetadata);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSetHdrMetadataEXT>::Dispatch(encode::TraceManager::Get(), device, swapchainCount, pSwapchains, pMetadata);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateIOSSurfaceMVK(
    VkInstance                                  instance,
    const VkIOSSurfaceCreateInfoMVK*            pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateIOSSurfaceMVK>::Dispatch(encode::TraceManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    VkResult result = encode::TraceManager::Get()->GetInstanceTable(instance)->CreateIOSSurfaceMVK(instance, pCreateInfo, pAllocator, pSurface);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateIOSSurfaceMVK);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(instance);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pSurface);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateIOSSurfaceMVK>::Dispatch(encode::TraceManager::Get(), result, instance, pCreateInfo, pAllocator, pSurface);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateMacOSSurfaceMVK(
    VkInstance                                  instance,
    const VkMacOSSurfaceCreateInfoMVK*          pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateMacOSSurfaceMVK>::Dispatch(encode::TraceManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    VkResult result = encode::TraceManager::Get()->GetInstanceTable(instance)->CreateMacOSSurfaceMVK(instance, pCreateInfo, pAllocator, pSurface);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateMacOSSurfaceMVK);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(instance);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pSurface);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateMacOSSurfaceMVK>::Dispatch(encode::TraceManager::Get(), result, instance, pCreateInfo, pAllocator, pSurface);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL SetDebugUtilsObjectNameEXT(
    VkDevice                                    device,
    const VkDebugUtilsObjectNameInfoEXT*        pNameInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkSetDebugUtilsObjectNameEXT>::Dispatch(encode::TraceManager::Get(), device, pNameInfo);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->SetDebugUtilsObjectNameEXT(device, pNameInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkSetDebugUtilsObjectNameEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pNameInfo);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSetDebugUtilsObjectNameEXT>::Dispatch(encode::TraceManager::Get(), result, device, pNameInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL SetDebugUtilsObjectTagEXT(
    VkDevice                                    device,
    const VkDebugUtilsObjectTagInfoEXT*         pTagInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkSetDebugUtilsObjectTagEXT>::Dispatch(encode::TraceManager::Get(), device, pTagInfo);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->SetDebugUtilsObjectTagEXT(device, pTagInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkSetDebugUtilsObjectTagEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pTagInfo);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSetDebugUtilsObjectTagEXT>::Dispatch(encode::TraceManager::Get(), result, device, pTagInfo);

    return result;
}

VKAPI_ATTR void VKAPI_CALL QueueBeginDebugUtilsLabelEXT(
    VkQueue                                     queue,
    const VkDebugUtilsLabelEXT*                 pLabelInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkQueueBeginDebugUtilsLabelEXT>::Dispatch(encode::TraceManager::Get(), queue, pLabelInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkQueueBeginDebugUtilsLabelEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(queue);
        EncodeStructPtr(encoder, pLabelInfo);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(queue)->QueueBeginDebugUtilsLabelEXT(queue, pLabelInfo);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueueBeginDebugUtilsLabelEXT>::Dispatch(encode::TraceManager::Get(), queue, pLabelInfo);
}

VKAPI_ATTR void VKAPI_CALL QueueEndDebugUtilsLabelEXT(
    VkQueue                                     queue)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkQueueEndDebugUtilsLabelEXT>::Dispatch(encode::TraceManager::Get(), queue);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkQueueEndDebugUtilsLabelEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(queue);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(queue)->QueueEndDebugUtilsLabelEXT(queue);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueueEndDebugUtilsLabelEXT>::Dispatch(encode::TraceManager::Get(), queue);
}

VKAPI_ATTR void VKAPI_CALL QueueInsertDebugUtilsLabelEXT(
    VkQueue                                     queue,
    const VkDebugUtilsLabelEXT*                 pLabelInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkQueueInsertDebugUtilsLabelEXT>::Dispatch(encode::TraceManager::Get(), queue, pLabelInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkQueueInsertDebugUtilsLabelEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(queue);
        EncodeStructPtr(encoder, pLabelInfo);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(queue)->QueueInsertDebugUtilsLabelEXT(queue, pLabelInfo);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkQueueInsertDebugUtilsLabelEXT>::Dispatch(encode::TraceManager::Get(), queue, pLabelInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdBeginDebugUtilsLabelEXT(
    VkCommandBuffer                             commandBuffer,
    const VkDebugUtilsLabelEXT*                 pLabelInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBeginDebugUtilsLabelEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer, pLabelInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdBeginDebugUtilsLabelEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        EncodeStructPtr(encoder, pLabelInfo);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdBeginDebugUtilsLabelEXT(commandBuffer, pLabelInfo);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBeginDebugUtilsLabelEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer, pLabelInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdEndDebugUtilsLabelEXT(
    VkCommandBuffer                             commandBuffer)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdEndDebugUtilsLabelEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdEndDebugUtilsLabelEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdEndDebugUtilsLabelEXT(commandBuffer);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdEndDebugUtilsLabelEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer);
}

VKAPI_ATTR void VKAPI_CALL CmdInsertDebugUtilsLabelEXT(
    VkCommandBuffer                             commandBuffer,
    const VkDebugUtilsLabelEXT*                 pLabelInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdInsertDebugUtilsLabelEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer, pLabelInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdInsertDebugUtilsLabelEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        EncodeStructPtr(encoder, pLabelInfo);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdInsertDebugUtilsLabelEXT(commandBuffer, pLabelInfo);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdInsertDebugUtilsLabelEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer, pLabelInfo);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDebugUtilsMessengerEXT(
    VkInstance                                  instance,
    const VkDebugUtilsMessengerCreateInfoEXT*   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDebugUtilsMessengerEXT*                   pMessenger)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateDebugUtilsMessengerEXT>::Dispatch(encode::TraceManager::Get(), instance, pCreateInfo, pAllocator, pMessenger);

    VkResult result = encode::TraceManager::Get()->GetInstanceTable(instance)->CreateDebugUtilsMessengerEXT(instance, pCreateInfo, pAllocator, pMessenger);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateDebugUtilsMessengerEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(instance);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pMessenger);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateDebugUtilsMessengerEXT>::Dispatch(encode::TraceManager::Get(), result, instance, pCreateInfo, pAllocator, pMessenger);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyDebugUtilsMessengerEXT(
    VkInstance                                  instance,
    VkDebugUtilsMessengerEXT                    messenger,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyDebugUtilsMessengerEXT>::Dispatch(encode::TraceManager::Get(), instance, messenger, pAllocator);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyDebugUtilsMessengerEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(instance);
        encoder->EncodeHandleIdValue(messenger);
        EncodeStructPtr(encoder, pAllocator);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetInstanceTable(instance)->DestroyDebugUtilsMessengerEXT(instance, messenger, pAllocator);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyDebugUtilsMessengerEXT>::Dispatch(encode::TraceManager::Get(), instance, messenger, pAllocator);
}

VKAPI_ATTR void VKAPI_CALL SubmitDebugUtilsMessageEXT(
    VkInstance                                  instance,
    VkDebugUtilsMessageSeverityFlagBitsEXT      messageSeverity,
    VkDebugUtilsMessageTypeFlagsEXT             messageTypes,
    const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkSubmitDebugUtilsMessageEXT>::Dispatch(encode::TraceManager::Get(), instance, messageSeverity, messageTypes, pCallbackData);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkSubmitDebugUtilsMessageEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(instance);
        encoder->EncodeEnumValue(messageSeverity);
        encoder->EncodeFlagsValue(messageTypes);
        EncodeStructPtr(encoder, pCallbackData);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetInstanceTable(instance)->SubmitDebugUtilsMessageEXT(instance, messageSeverity, messageTypes, pCallbackData);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkSubmitDebugUtilsMessageEXT>::Dispatch(encode::TraceManager::Get(), instance, messageSeverity, messageTypes, pCallbackData);
}

VKAPI_ATTR VkResult VKAPI_CALL GetAndroidHardwareBufferPropertiesANDROID(
    VkDevice                                    device,
    const struct AHardwareBuffer*               buffer,
    VkAndroidHardwareBufferPropertiesANDROID*   pProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetAndroidHardwareBufferPropertiesANDROID>::Dispatch(encode::TraceManager::Get(), device, buffer, pProperties);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->GetAndroidHardwareBufferPropertiesANDROID(device, buffer, pProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetAndroidHardwareBufferPropertiesANDROID);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeVoidPtr(buffer);
        EncodeStructPtr(encoder, pProperties);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetAndroidHardwareBufferPropertiesANDROID>::Dispatch(encode::TraceManager::Get(), result, device, buffer, pProperties);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetMemoryAndroidHardwareBufferANDROID(
    VkDevice                                    device,
    const VkMemoryGetAndroidHardwareBufferInfoANDROID* pInfo,
    struct AHardwareBuffer**                    pBuffer)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryAndroidHardwareBufferANDROID>::Dispatch(encode::TraceManager::Get(), device, pInfo, pBuffer);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->GetMemoryAndroidHardwareBufferANDROID(device, pInfo, pBuffer);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetMemoryAndroidHardwareBufferANDROID);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pInfo);
        encoder->EncodeVoidPtrPtr(pBuffer);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryAndroidHardwareBufferANDROID>::Dispatch(encode::TraceManager::Get(), result, device, pInfo, pBuffer);

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdSetSampleLocationsEXT(
    VkCommandBuffer                             commandBuffer,
    const VkSampleLocationsInfoEXT*             pSampleLocationsInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer, pSampleLocationsInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        EncodeStructPtr(encoder, pSampleLocationsInfo);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdSetSampleLocationsEXT(commandBuffer, pSampleLocationsInfo);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer, pSampleLocationsInfo);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceMultisamplePropertiesEXT(
    VkPhysicalDevice                            physicalDevice,
    VkSampleCountFlagBits                       samples,
    VkMultisamplePropertiesEXT*                 pMultisampleProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMultisamplePropertiesEXT>::Dispatch(encode::TraceManager::Get(), physicalDevice, samples, pMultisampleProperties);

    encode::TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceMultisamplePropertiesEXT(physicalDevice, samples, pMultisampleProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceMultisamplePropertiesEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeEnumValue(samples);
        EncodeStructPtr(encoder, pMultisampleProperties);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceMultisamplePropertiesEXT>::Dispatch(encode::TraceManager::Get(), physicalDevice, samples, pMultisampleProperties);
}

VKAPI_ATTR VkResult VKAPI_CALL GetImageDrmFormatModifierPropertiesEXT(
    VkDevice                                    device,
    VkImage                                     image,
    VkImageDrmFormatModifierPropertiesEXT*      pProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetImageDrmFormatModifierPropertiesEXT>::Dispatch(encode::TraceManager::Get(), device, image, pProperties);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->GetImageDrmFormatModifierPropertiesEXT(device, image, pProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetImageDrmFormatModifierPropertiesEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(image);
        EncodeStructPtr(encoder, pProperties);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetImageDrmFormatModifierPropertiesEXT>::Dispatch(encode::TraceManager::Get(), result, device, image, pProperties);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateValidationCacheEXT(
    VkDevice                                    device,
    const VkValidationCacheCreateInfoEXT*       pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkValidationCacheEXT*                       pValidationCache)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateValidationCacheEXT>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pValidationCache);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->CreateValidationCacheEXT(device, pCreateInfo, pAllocator, pValidationCache);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateValidationCacheEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pValidationCache);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateValidationCacheEXT>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pValidationCache);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyValidationCacheEXT(
    VkDevice                                    device,
    VkValidationCacheEXT                        validationCache,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyValidationCacheEXT>::Dispatch(encode::TraceManager::Get(), device, validationCache, pAllocator);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyValidationCacheEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(validationCache);
        EncodeStructPtr(encoder, pAllocator);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(device)->DestroyValidationCacheEXT(device, validationCache, pAllocator);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyValidationCacheEXT>::Dispatch(encode::TraceManager::Get(), device, validationCache, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL MergeValidationCachesEXT(
    VkDevice                                    device,
    VkValidationCacheEXT                        dstCache,
    uint32_t                                    srcCacheCount,
    const VkValidationCacheEXT*                 pSrcCaches)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkMergeValidationCachesEXT>::Dispatch(encode::TraceManager::Get(), device, dstCache, srcCacheCount, pSrcCaches);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->MergeValidationCachesEXT(device, dstCache, srcCacheCount, pSrcCaches);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkMergeValidationCachesEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(dstCache);
        encoder->EncodeUInt32Value(srcCacheCount);
        encoder->EncodeHandleIdArray(pSrcCaches, srcCacheCount);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkMergeValidationCachesEXT>::Dispatch(encode::TraceManager::Get(), result, device, dstCache, srcCacheCount, pSrcCaches);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetValidationCacheDataEXT(
    VkDevice                                    device,
    VkValidationCacheEXT                        validationCache,
    size_t*                                     pDataSize,
    void*                                       pData)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetValidationCacheDataEXT>::Dispatch(encode::TraceManager::Get(), device, validationCache, pDataSize, pData);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->GetValidationCacheDataEXT(device, validationCache, pDataSize, pData);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetValidationCacheDataEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(validationCache);
        encoder->EncodeSizeTPtr(pDataSize);
        encoder->EncodeVoidArray(pData, (pDataSize != nullptr) ? (*pDataSize) : 0);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetValidationCacheDataEXT>::Dispatch(encode::TraceManager::Get(), result, device, validationCache, pDataSize, pData);

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdBindShadingRateImageNV(
    VkCommandBuffer                             commandBuffer,
    VkImageView                                 imageView,
    VkImageLayout                               imageLayout)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBindShadingRateImageNV>::Dispatch(encode::TraceManager::Get(), commandBuffer, imageView, imageLayout);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdBindShadingRateImageNV);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(imageView);
        encoder->EncodeEnumValue(imageLayout);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdBindShadingRateImageNV(commandBuffer, imageView, imageLayout);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBindShadingRateImageNV>::Dispatch(encode::TraceManager::Get(), commandBuffer, imageView, imageLayout);
}

VKAPI_ATTR void VKAPI_CALL CmdSetViewportShadingRatePaletteNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    const VkShadingRatePaletteNV*               pShadingRatePalettes)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetViewportShadingRatePaletteNV>::Dispatch(encode::TraceManager::Get(), commandBuffer, firstViewport, viewportCount, pShadingRatePalettes);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetViewportShadingRatePaletteNV);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(firstViewport);
        encoder->EncodeUInt32Value(viewportCount);
        EncodeStructArray(encoder, pShadingRatePalettes, viewportCount);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdSetViewportShadingRatePaletteNV(commandBuffer, firstViewport, viewportCount, pShadingRatePalettes);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetViewportShadingRatePaletteNV>::Dispatch(encode::TraceManager::Get(), commandBuffer, firstViewport, viewportCount, pShadingRatePalettes);
}

VKAPI_ATTR void VKAPI_CALL CmdSetCoarseSampleOrderNV(
    VkCommandBuffer                             commandBuffer,
    VkCoarseSampleOrderTypeNV                   sampleOrderType,
    uint32_t                                    customSampleOrderCount,
    const VkCoarseSampleOrderCustomNV*          pCustomSampleOrders)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCoarseSampleOrderNV>::Dispatch(encode::TraceManager::Get(), commandBuffer, sampleOrderType, customSampleOrderCount, pCustomSampleOrders);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetCoarseSampleOrderNV);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeEnumValue(sampleOrderType);
        encoder->EncodeUInt32Value(customSampleOrderCount);
        EncodeStructArray(encoder, pCustomSampleOrders, customSampleOrderCount);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdSetCoarseSampleOrderNV(commandBuffer, sampleOrderType, customSampleOrderCount, pCustomSampleOrders);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCoarseSampleOrderNV>::Dispatch(encode::TraceManager::Get(), commandBuffer, sampleOrderType, customSampleOrderCount, pCustomSampleOrders);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateAccelerationStructureNV(
    VkDevice                                    device,
    const VkAccelerationStructureCreateInfoNV*  pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkAccelerationStructureNV*                  pAccelerationStructure)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateAccelerationStructureNV>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pAccelerationStructure);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->CreateAccelerationStructureNV(device, pCreateInfo, pAllocator, pAccelerationStructure);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateAccelerationStructureNV);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pAccelerationStructure);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateAccelerationStructureNV>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pAccelerationStructure);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyAccelerationStructureNV(
    VkDevice                                    device,
    VkAccelerationStructureNV                   accelerationStructure,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkDestroyAccelerationStructureNV>::Dispatch(encode::TraceManager::Get(), device, accelerationStructure, pAllocator);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkDestroyAccelerationStructureNV);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(accelerationStructure);
        EncodeStructPtr(encoder, pAllocator);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(device)->DestroyAccelerationStructureNV(device, accelerationStructure, pAllocator);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkDestroyAccelerationStructureNV>::Dispatch(encode::TraceManager::Get(), device, accelerationStructure, pAllocator);
}

VKAPI_ATTR void VKAPI_CALL GetAccelerationStructureMemoryRequirementsNV(
    VkDevice                                    device,
    const VkAccelerationStructureMemoryRequirementsInfoNV* pInfo,
    VkMemoryRequirements2KHR*                   pMemoryRequirements)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureMemoryRequirementsNV>::Dispatch(encode::TraceManager::Get(), device, pInfo, pMemoryRequirements);

    encode::TraceManager::Get()->GetDeviceTable(device)->GetAccelerationStructureMemoryRequirementsNV(device, pInfo, pMemoryRequirements);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetAccelerationStructureMemoryRequirementsNV);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pInfo);
        EncodeStructPtr(encoder, pMemoryRequirements);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureMemoryRequirementsNV>::Dispatch(encode::TraceManager::Get(), device, pInfo, pMemoryRequirements);
}

VKAPI_ATTR VkResult VKAPI_CALL BindAccelerationStructureMemoryNV(
    VkDevice                                    device,
    uint32_t                                    bindInfoCount,
    const VkBindAccelerationStructureMemoryInfoNV* pBindInfos)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkBindAccelerationStructureMemoryNV>::Dispatch(encode::TraceManager::Get(), device, bindInfoCount, pBindInfos);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->BindAccelerationStructureMemoryNV(device, bindInfoCount, pBindInfos);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkBindAccelerationStructureMemoryNV);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeUInt32Value(bindInfoCount);
        EncodeStructArray(encoder, pBindInfos, bindInfoCount);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkBindAccelerationStructureMemoryNV>::Dispatch(encode::TraceManager::Get(), result, device, bindInfoCount, pBindInfos);

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdBuildAccelerationStructureNV(
    VkCommandBuffer                             commandBuffer,
    const VkAccelerationStructureInfoNV*        pInfo,
    VkBuffer                                    instanceData,
    VkDeviceSize                                instanceOffset,
    VkBool32                                    update,
    VkAccelerationStructureNV                   dst,
    VkAccelerationStructureNV                   src,
    VkBuffer                                    scratch,
    VkDeviceSize                                scratchOffset)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructureNV>::Dispatch(encode::TraceManager::Get(), commandBuffer, pInfo, instanceData, instanceOffset, update, dst, src, scratch, scratchOffset);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructureNV);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        EncodeStructPtr(encoder, pInfo);
        encoder->EncodeHandleIdValue(instanceData);
        encoder->EncodeVkDeviceSizeValue(instanceOffset);
        encoder->EncodeVkBool32Value(update);
        encoder->EncodeHandleIdValue(dst);
        encoder->EncodeHandleIdValue(src);
        encoder->EncodeHandleIdValue(scratch);
        encoder->EncodeVkDeviceSizeValue(scratchOffset);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdBuildAccelerationStructureNV(commandBuffer, pInfo, instanceData, instanceOffset, update, dst, src, scratch, scratchOffset);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructureNV>::Dispatch(encode::TraceManager::Get(), commandBuffer, pInfo, instanceData, instanceOffset, update, dst, src, scratch, scratchOffset);
}

VKAPI_ATTR void VKAPI_CALL CmdCopyAccelerationStructureNV(
    VkCommandBuffer                             commandBuffer,
    VkAccelerationStructureNV                   dst,
    VkAccelerationStructureNV                   src,
    VkCopyAccelerationStructureModeNV           mode)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureNV>::Dispatch(encode::TraceManager::Get(), commandBuffer, dst, src, mode);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureNV);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(dst);
        encoder->EncodeHandleIdValue(src);
        encoder->EncodeEnumValue(mode);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdCopyAccelerationStructureNV(commandBuffer, dst, src, mode);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureNV>::Dispatch(encode::TraceManager::Get(), commandBuffer, dst, src, mode);
}

VKAPI_ATTR void VKAPI_CALL CmdTraceRaysNV(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    raygenShaderBindingTableBuffer,
    VkDeviceSize                                raygenShaderBindingOffset,
    VkBuffer                                    missShaderBindingTableBuffer,
    VkDeviceSize                                missShaderBindingOffset,
    VkDeviceSize                                missShaderBindingStride,
    VkBuffer                                    hitShaderBindingTableBuffer,
    VkDeviceSize                                hitShaderBindingOffset,
    VkDeviceSize                                hitShaderBindingStride,
    VkBuffer                                    callableShaderBindingTableBuffer,
    VkDeviceSize                                callableShaderBindingOffset,
    VkDeviceSize                                callableShaderBindingStride,
    uint32_t                                    width,
    uint32_t                                    height,
    uint32_t                                    depth)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdTraceRaysNV>::Dispatch(encode::TraceManager::Get(), commandBuffer, raygenShaderBindingTableBuffer, raygenShaderBindingOffset, missShaderBindingTableBuffer, missShaderBindingOffset, missShaderBindingStride, hitShaderBindingTableBuffer, hitShaderBindingOffset, hitShaderBindingStride, callableShaderBindingTableBuffer, callableShaderBindingOffset, callableShaderBindingStride, width, height, depth);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdTraceRaysNV);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(raygenShaderBindingTableBuffer);
        encoder->EncodeVkDeviceSizeValue(raygenShaderBindingOffset);
        encoder->EncodeHandleIdValue(missShaderBindingTableBuffer);
        encoder->EncodeVkDeviceSizeValue(missShaderBindingOffset);
        encoder->EncodeVkDeviceSizeValue(missShaderBindingStride);
        encoder->EncodeHandleIdValue(hitShaderBindingTableBuffer);
        encoder->EncodeVkDeviceSizeValue(hitShaderBindingOffset);
        encoder->EncodeVkDeviceSizeValue(hitShaderBindingStride);
        encoder->EncodeHandleIdValue(callableShaderBindingTableBuffer);
        encoder->EncodeVkDeviceSizeValue(callableShaderBindingOffset);
        encoder->EncodeVkDeviceSizeValue(callableShaderBindingStride);
        encoder->EncodeUInt32Value(width);
        encoder->EncodeUInt32Value(height);
        encoder->EncodeUInt32Value(depth);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdTraceRaysNV(commandBuffer, raygenShaderBindingTableBuffer, raygenShaderBindingOffset, missShaderBindingTableBuffer, missShaderBindingOffset, missShaderBindingStride, hitShaderBindingTableBuffer, hitShaderBindingOffset, hitShaderBindingStride, callableShaderBindingTableBuffer, callableShaderBindingOffset, callableShaderBindingStride, width, height, depth);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdTraceRaysNV>::Dispatch(encode::TraceManager::Get(), commandBuffer, raygenShaderBindingTableBuffer, raygenShaderBindingOffset, missShaderBindingTableBuffer, missShaderBindingOffset, missShaderBindingStride, hitShaderBindingTableBuffer, hitShaderBindingOffset, hitShaderBindingStride, callableShaderBindingTableBuffer, callableShaderBindingOffset, callableShaderBindingStride, width, height, depth);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateRayTracingPipelinesNV(
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache,
    uint32_t                                    createInfoCount,
    const VkRayTracingPipelineCreateInfoNV*     pCreateInfos,
    const VkAllocationCallbacks*                pAllocator,
    VkPipeline*                                 pPipelines)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesNV>::Dispatch(encode::TraceManager::Get(), device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->CreateRayTracingPipelinesNV(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesNV);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(pipelineCache);
        encoder->EncodeUInt32Value(createInfoCount);
        EncodeStructArray(encoder, pCreateInfos, createInfoCount);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdArray(pPipelines, createInfoCount);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesNV>::Dispatch(encode::TraceManager::Get(), result, device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetRayTracingShaderGroupHandlesNV(
    VkDevice                                    device,
    VkPipeline                                  pipeline,
    uint32_t                                    firstGroup,
    uint32_t                                    groupCount,
    size_t                                      dataSize,
    void*                                       pData)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesNV>::Dispatch(encode::TraceManager::Get(), device, pipeline, firstGroup, groupCount, dataSize, pData);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->GetRayTracingShaderGroupHandlesNV(device, pipeline, firstGroup, groupCount, dataSize, pData);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesNV);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(pipeline);
        encoder->EncodeUInt32Value(firstGroup);
        encoder->EncodeUInt32Value(groupCount);
        encoder->EncodeSizeTValue(dataSize);
        encoder->EncodeVoidArray(pData, dataSize);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesNV>::Dispatch(encode::TraceManager::Get(), result, device, pipeline, firstGroup, groupCount, dataSize, pData);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetAccelerationStructureHandleNV(
    VkDevice                                    device,
    VkAccelerationStructureNV                   accelerationStructure,
    size_t                                      dataSize,
    void*                                       pData)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureHandleNV>::Dispatch(encode::TraceManager::Get(), device, accelerationStructure, dataSize, pData);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->GetAccelerationStructureHandleNV(device, accelerationStructure, dataSize, pData);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetAccelerationStructureHandleNV);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(accelerationStructure);
        encoder->EncodeSizeTValue(dataSize);
        encoder->EncodeVoidArray(pData, dataSize);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetAccelerationStructureHandleNV>::Dispatch(encode::TraceManager::Get(), result, device, accelerationStructure, dataSize, pData);

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdWriteAccelerationStructuresPropertiesNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    accelerationStructureCount,
    const VkAccelerationStructureNV*            pAccelerationStructures,
    VkQueryType                                 queryType,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesNV>::Dispatch(encode::TraceManager::Get(), commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesNV);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(accelerationStructureCount);
        encoder->EncodeHandleIdArray(pAccelerationStructures, accelerationStructureCount);
        encoder->EncodeEnumValue(queryType);
        encoder->EncodeHandleIdValue(queryPool);
        encoder->EncodeUInt32Value(firstQuery);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdWriteAccelerationStructuresPropertiesNV(commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesNV>::Dispatch(encode::TraceManager::Get(), commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
}

VKAPI_ATTR VkResult VKAPI_CALL CompileDeferredNV(
    VkDevice                                    device,
    VkPipeline                                  pipeline,
    uint32_t                                    shader)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCompileDeferredNV>::Dispatch(encode::TraceManager::Get(), device, pipeline, shader);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->CompileDeferredNV(device, pipeline, shader);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCompileDeferredNV);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(pipeline);
        encoder->EncodeUInt32Value(shader);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCompileDeferredNV>::Dispatch(encode::TraceManager::Get(), result, device, pipeline, shader);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetMemoryHostPointerPropertiesEXT(
    VkDevice                                    device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    const void*                                 pHostPointer,
    VkMemoryHostPointerPropertiesEXT*           pMemoryHostPointerProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetMemoryHostPointerPropertiesEXT>::Dispatch(encode::TraceManager::Get(), device, handleType, pHostPointer, pMemoryHostPointerProperties);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->GetMemoryHostPointerPropertiesEXT(device, handleType, pHostPointer, pMemoryHostPointerProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetMemoryHostPointerPropertiesEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeEnumValue(handleType);
        encoder->EncodeVoidPtr(pHostPointer);
        EncodeStructPtr(encoder, pMemoryHostPointerProperties);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetMemoryHostPointerPropertiesEXT>::Dispatch(encode::TraceManager::Get(), result, device, handleType, pHostPointer, pMemoryHostPointerProperties);

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdWriteBufferMarkerAMD(
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlagBits                     pipelineStage,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    uint32_t                                    marker)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdWriteBufferMarkerAMD>::Dispatch(encode::TraceManager::Get(), commandBuffer, pipelineStage, dstBuffer, dstOffset, marker);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdWriteBufferMarkerAMD);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeEnumValue(pipelineStage);
        encoder->EncodeHandleIdValue(dstBuffer);
        encoder->EncodeVkDeviceSizeValue(dstOffset);
        encoder->EncodeUInt32Value(marker);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdWriteBufferMarkerAMD(commandBuffer, pipelineStage, dstBuffer, dstOffset, marker);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdWriteBufferMarkerAMD>::Dispatch(encode::TraceManager::Get(), commandBuffer, pipelineStage, dstBuffer, dstOffset, marker);
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceCalibrateableTimeDomainsEXT(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pTimeDomainCount,
    VkTimeDomainEXT*                            pTimeDomains)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT>::Dispatch(encode::TraceManager::Get(), physicalDevice, pTimeDomainCount, pTimeDomains);

    VkResult result = encode::TraceManager::Get()->GetInstanceTable(physicalDevice)->GetPhysicalDeviceCalibrateableTimeDomainsEXT(physicalDevice, pTimeDomainCount, pTimeDomains);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeUInt32Ptr(pTimeDomainCount);
        encoder->EncodeEnumArray(pTimeDomains, (pTimeDomainCount != nullptr) ? (*pTimeDomainCount) : 0);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, pTimeDomainCount, pTimeDomains);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetCalibratedTimestampsEXT(
    VkDevice                                    device,
    uint32_t                                    timestampCount,
    const VkCalibratedTimestampInfoEXT*         pTimestampInfos,
    uint64_t*                                   pTimestamps,
    uint64_t*                                   pMaxDeviation)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetCalibratedTimestampsEXT>::Dispatch(encode::TraceManager::Get(), device, timestampCount, pTimestampInfos, pTimestamps, pMaxDeviation);

    VkResult result = encode::TraceManager::Get()->GetDeviceTable(device)->GetCalibratedTimestampsEXT(device, timestampCount, pTimestampInfos, pTimestamps, pMaxDeviation);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetCalibratedTimestampsEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeUInt32Value(timestampCount);
        EncodeStructArray(encoder, pTimestampInfos, timestampCount);
        encoder->EncodeUInt64Array(pTimestamps, timestampCount);
        encoder->EncodeUInt64Ptr(pMaxDeviation);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetCalibratedTimestampsEXT>::Dispatch(encode::TraceManager::Get(), result, device, timestampCount, pTimestampInfos, pTimestamps, pMaxDeviation);

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdDrawMeshTasksNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    taskCount,
    uint32_t                                    firstTask)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksNV>::Dispatch(encode::TraceManager::Get(), commandBuffer, taskCount, firstTask);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdDrawMeshTasksNV);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(taskCount);
        encoder->EncodeUInt32Value(firstTask);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdDrawMeshTasksNV(commandBuffer, taskCount, firstTask);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksNV>::Dispatch(encode::TraceManager::Get(), commandBuffer, taskCount, firstTask);
}

VKAPI_ATTR void VKAPI_CALL CmdDrawMeshTasksIndirectNV(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectNV>::Dispatch(encode::TraceManager::Get(), commandBuffer, buffer, offset, drawCount, stride);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectNV);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeUInt32Value(drawCount);
        encoder->EncodeUInt32Value(stride);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdDrawMeshTasksIndirectNV(commandBuffer, buffer, offset, drawCount, stride);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectNV>::Dispatch(encode::TraceManager::Get(), commandBuffer, buffer, offset, drawCount, stride);
}

VKAPI_ATTR void VKAPI_CALL CmdDrawMeshTasksIndirectCountNV(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountNV>::Dispatch(encode::TraceManager::Get(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountNV);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeHandleIdValue(countBuffer);
        encoder->EncodeVkDeviceSizeValue(countBufferOffset);
        encoder->EncodeUInt32Value(maxDrawCount);
        encoder->EncodeUInt32Value(stride);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdDrawMeshTasksIndirectCountNV(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountNV>::Dispatch(encode::TraceManager::Get(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

VKAPI_ATTR void VKAPI_CALL CmdSetExclusiveScissorNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstExclusiveScissor,
    uint32_t                                    exclusiveScissorCount,
    const VkRect2D*                             pExclusiveScissors)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetExclusiveScissorNV>::Dispatch(encode::TraceManager::Get(), commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissors);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetExclusiveScissorNV);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(firstExclusiveScissor);
        encoder->EncodeUInt32Value(exclusiveScissorCount);
        EncodeStructArray(encoder, pExclusiveScissors, exclusiveScissorCount);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdSetExclusiveScissorNV(commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissors);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetExclusiveScissorNV>::Dispatch(encode::TraceManager::Get(), commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissors);
}

VKAPI_ATTR void VKAPI_CALL CmdSetCheckpointNV(
    VkCommandBuffer                             commandBuffer,
    const void*                                 pCheckpointMarker)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCmdSetCheckpointNV>::Dispatch(encode::TraceManager::Get(), commandBuffer, pCheckpointMarker);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCmdSetCheckpointNV);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeVoidPtr(pCheckpointMarker);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::TraceManager::Get()->GetDeviceTable(commandBuffer)->CmdSetCheckpointNV(commandBuffer, pCheckpointMarker);

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCmdSetCheckpointNV>::Dispatch(encode::TraceManager::Get(), commandBuffer, pCheckpointMarker);
}

VKAPI_ATTR void VKAPI_CALL GetQueueCheckpointDataNV(
    VkQueue                                     queue,
    uint32_t*                                   pCheckpointDataCount,
    VkCheckpointDataNV*                         pCheckpointData)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetQueueCheckpointDataNV>::Dispatch(encode::TraceManager::Get(), queue, pCheckpointDataCount, pCheckpointData);

    encode::TraceManager::Get()->GetDeviceTable(queue)->GetQueueCheckpointDataNV(queue, pCheckpointDataCount, pCheckpointData);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetQueueCheckpointDataNV);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(queue);
        encoder->EncodeUInt32Ptr(pCheckpointDataCount);
        EncodeStructArray(encoder, pCheckpointData, (pCheckpointDataCount != nullptr) ? (*pCheckpointDataCount) : 0);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetQueueCheckpointDataNV>::Dispatch(encode::TraceManager::Get(), queue, pCheckpointDataCount, pCheckpointData);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateImagePipeSurfaceFUCHSIA(
    VkInstance                                  instance,
    const VkImagePipeSurfaceCreateInfoFUCHSIA*  pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkCreateImagePipeSurfaceFUCHSIA>::Dispatch(encode::TraceManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    VkResult result = encode::TraceManager::Get()->GetInstanceTable(instance)->CreateImagePipeSurfaceFUCHSIA(instance, pCreateInfo, pAllocator, pSurface);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkCreateImagePipeSurfaceFUCHSIA);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(instance);
        EncodeStructPtr(encoder, pCreateInfo);
        EncodeStructPtr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pSurface);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkCreateImagePipeSurfaceFUCHSIA>::Dispatch(encode::TraceManager::Get(), result, instance, pCreateInfo, pAllocator, pSurface);

    return result;
}

VKAPI_ATTR VkDeviceAddress VKAPI_CALL GetBufferDeviceAddressEXT(
    VkDevice                                    device,
    const VkBufferDeviceAddressInfoEXT*         pInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddressEXT>::Dispatch(encode::TraceManager::Get(), device, pInfo);

    VkDeviceAddress result = encode::TraceManager::Get()->GetDeviceTable(device)->GetBufferDeviceAddressEXT(device, pInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_vkGetBufferDeviceAddressEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        EncodeStructPtr(encoder, pInfo);
        encoder->EncodeVkDeviceAddressValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId::ApiCall_vkGetBufferDeviceAddressEXT>::Dispatch(encode::TraceManager::Get(), result, device, pInfo);

    return result;
}

GFXRECON_END_NAMESPACE(gfxrecon)
