/*
** Copyright (c) 2025 LunarG, Inc.
** Copyright (c) 2025 Arm Limited and/or its affiliates <open-source-office@arm.com>
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

#include "generated/generated_vulkan_skiavk_modifier.h"

#include "graphics/vulkan_struct_get_pnext.h"
#include "graphics/vulkan_util.h"
#include "util/logging.h"

#include <cassert>
#include <cstring>
#include <stdexcept>

#include "generated/generated_vulkan_api_call_encoders.h"

#include "encode/custom_vulkan_encoder_commands.h"
#include "encode/custom_vulkan_array_size_2d.h"
#include "encode/parameter_encoder.h"
#include "encode/struct_pointer_encoder.h"
#include "encode/vulkan_capture_manager.h"
#include "encode/vulkan_handle_wrapper_util.h"
#include "encode/vulkan_handle_wrappers.h"
#include "format/api_call_id.h"
#include "generated/generated_vulkan_command_buffer_util.h"
#include "generated/generated_vulkan_struct_handle_wrappers.h"
#include "util/defines.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

std::vector<std::string> VulkanSkiaModifier::app_name_array = {};

bool VulkanSkiaModifier::SubmitHasFrameEndMarker(uint32_t                                    submit_count,
                                                 StructPointerDecoder<Decoded_VkSubmitInfo>* pSubmits) const
{
    if ((submit_count == 0) || (pSubmits == nullptr))
    {
        return false;
    }

    const VkSubmitInfo*         submits      = pSubmits->GetPointer();
    const Decoded_VkSubmitInfo* submit_metas = pSubmits->GetMetaStructPointer();
    if ((submits == nullptr) || (submit_metas == nullptr))
    {
        return false;
    }

    for (uint32_t i = 0; i < submit_count; ++i)
    {
        auto* frame_boundary = graphics::vulkan_struct_get_pnext<VkFrameBoundaryEXT>(
            reinterpret_cast<const VkBaseInStructure*>(submits + i));
        if ((frame_boundary != nullptr) && ((frame_boundary->flags & VK_FRAME_BOUNDARY_FRAME_END_BIT_EXT) != 0))
        {
            return true;
        }

        auto* command_buffers = submit_metas[i].pCommandBuffers.GetPointer();
        for (uint32_t j = 0; j < submits[i].commandBufferCount; ++j)
        {
            if ((command_buffers != nullptr) && frame_boundary_command_buffers_.contains(command_buffers[j]))
            {
                return true;
            }
        }
    }

    return false;
}

bool VulkanSkiaModifier::Submit2HasFrameEndMarker(uint32_t                                     submit_count,
                                                  StructPointerDecoder<Decoded_VkSubmitInfo2>* pSubmits) const
{
    if ((submit_count == 0) || (pSubmits == nullptr))
    {
        return false;
    }

    const VkSubmitInfo2*         submits      = pSubmits->GetPointer();
    const Decoded_VkSubmitInfo2* submit_metas = pSubmits->GetMetaStructPointer();
    if ((submits == nullptr) || (submit_metas == nullptr))
    {
        return false;
    }

    for (uint32_t i = 0; i < submit_count; ++i)
    {
        auto* frame_boundary = graphics::vulkan_struct_get_pnext<VkFrameBoundaryEXT>(
            reinterpret_cast<const VkBaseInStructure*>(submits + i));
        if ((frame_boundary != nullptr) && ((frame_boundary->flags & VK_FRAME_BOUNDARY_FRAME_END_BIT_EXT) != 0))
        {
            return true;
        }

        if (submit_metas[i].pCommandBufferInfos == nullptr)
        {
            continue;
        }

        auto* command_buffer_infos = submit_metas[i].pCommandBufferInfos->GetMetaStructPointer();
        for (uint32_t j = 0; j < submits[i].commandBufferInfoCount; ++j)
        {
            if ((command_buffer_infos != nullptr) &&
                frame_boundary_command_buffers_.contains(command_buffer_infos[j].commandBuffer))
            {
                return true;
            }
        }
    }

    return false;
}

bool VulkanSkiaModifier::ContainsVrFrameDelimiter(const char* label) const
{
    return (label != nullptr) && (std::strstr(label, graphics::kVulkanVrFrameDelimiterString) != nullptr);
}

void VulkanSkiaModifier::AppendFrameEndMarkerForCurrentBlock()
{
    if (!frame_end_marker_blocks_to_insert_.contains(block_index_))
    {
        return;
    }

    auto* frame_marker         = CreatePostCall();
    frame_marker->type         = util::CallModifierBase::NewCallDataType::FrameMarkerCall;
    frame_marker->frame_number = next_output_frame_number_++;

    frame_end_marker_blocks_to_insert_.erase(block_index_);
}

void VulkanSkiaModifier::ProcessFrameEndMarker(uint64_t frame_number)
{
    GFXRECON_UNREFERENCED_PARAMETER(frame_number);
    SetDeleteCurrentCall();
}

void VulkanSkiaModifier::Process_vkQueuePresentKHR(const ApiCallInfo&                              call_info,
                                                   VkResult                                        returnValue,
                                                   format::HandleId                                queue,
                                                   StructPointerDecoder<Decoded_VkPresentInfoKHR>* pPresentInfo)
{
    if (IsModificationPass())
    {
        AppendFrameEndMarkerForCurrentBlock();
        return;
    }

    frame_end_marker_blocks_to_insert_.insert(block_index_);
}

void VulkanSkiaModifier::Process_vkQueueSubmit(const ApiCallInfo&                          call_info,
                                               VkResult                                    returnValue,
                                               format::HandleId                            queue,
                                               uint32_t                                    submitCount,
                                               StructPointerDecoder<Decoded_VkSubmitInfo>* pSubmits,
                                               format::HandleId                            fence)
{
    if (IsModificationPass())
    {
        AppendFrameEndMarkerForCurrentBlock();
        return;
    }

    const bool delete_call = IsSkiaBlock(queue);
    const bool has_marker  = SubmitHasFrameEndMarker(submitCount, pSubmits);

    if (delete_call)
    {
        SetDeleteCurrentCall();
    }
    else if (has_marker)
    {
        frame_end_marker_blocks_to_insert_.insert(block_index_);
    }
}

void VulkanSkiaModifier::Process_vkQueueSubmit2(const ApiCallInfo&                           call_info,
                                                VkResult                                     returnValue,
                                                format::HandleId                             queue,
                                                uint32_t                                     submitCount,
                                                StructPointerDecoder<Decoded_VkSubmitInfo2>* pSubmits,
                                                format::HandleId                             fence)
{
    if (IsModificationPass())
    {
        AppendFrameEndMarkerForCurrentBlock();
        return;
    }

    const bool delete_call = IsSkiaBlock(queue);
    const bool has_marker  = Submit2HasFrameEndMarker(submitCount, pSubmits);

    if (delete_call)
    {
        SetDeleteCurrentCall();
    }
    else if (has_marker)
    {
        frame_end_marker_blocks_to_insert_.insert(block_index_);
    }
}

void VulkanSkiaModifier::Process_vkQueueSubmit2KHR(const ApiCallInfo&                           call_info,
                                                   VkResult                                     returnValue,
                                                   format::HandleId                             queue,
                                                   uint32_t                                     submitCount,
                                                   StructPointerDecoder<Decoded_VkSubmitInfo2>* pSubmits,
                                                   format::HandleId                             fence)
{
    Process_vkQueueSubmit2(call_info, returnValue, queue, submitCount, pSubmits, fence);
}

void VulkanSkiaModifier::Process_vkFrameBoundaryANDROID(const ApiCallInfo& call_info,
                                                        format::HandleId   device,
                                                        format::HandleId   semaphore,
                                                        format::HandleId   image)
{
    if (IsModificationPass())
    {
        AppendFrameEndMarkerForCurrentBlock();
        return;
    }

    const bool delete_call = IsSkiaBlock(device);

    if (delete_call)
    {
        SetDeleteCurrentCall();
    }
    else
    {
        frame_end_marker_blocks_to_insert_.insert(block_index_);
    }
}

void VulkanSkiaModifier::Process_vkBeginCommandBuffer(
    const ApiCallInfo&                                      call_info,
    VkResult                                                returnValue,
    format::HandleId                                        commandBuffer,
    StructPointerDecoder<Decoded_VkCommandBufferBeginInfo>* pBeginInfo)
{
    if (IsModificationPass())
    {
        return;
    }

    frame_boundary_command_buffers_.erase(commandBuffer);
    if (IsSkiaBlock(commandBuffer))
    {
        SetDeleteCurrentCall();
    }
}

void VulkanSkiaModifier::Process_vkResetCommandBuffer(const ApiCallInfo&        call_info,
                                                      VkResult                  returnValue,
                                                      format::HandleId          commandBuffer,
                                                      VkCommandBufferResetFlags flags)
{
    if (IsModificationPass())
    {
        return;
    }

    frame_boundary_command_buffers_.erase(commandBuffer);
    if (IsSkiaBlock(commandBuffer))
    {
        SetDeleteCurrentCall();
    }
}

void VulkanSkiaModifier::Process_vkCmdDebugMarkerInsertEXT(
    const ApiCallInfo&                                        call_info,
    format::HandleId                                          commandBuffer,
    StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT>* pMarkerInfo)
{
    if (IsModificationPass())
    {
        return;
    }

    const VkDebugMarkerMarkerInfoEXT* marker_info = pMarkerInfo->GetPointer();
    if ((marker_info != nullptr) && ContainsVrFrameDelimiter(marker_info->pMarkerName))
    {
        frame_boundary_command_buffers_.insert(commandBuffer);
    }

    if (IsSkiaBlock(commandBuffer))
    {
        SetDeleteCurrentCall();
    }
}

void VulkanSkiaModifier::Process_vkCmdInsertDebugUtilsLabelEXT(
    const ApiCallInfo&                                  call_info,
    format::HandleId                                    commandBuffer,
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo)
{
    if (IsModificationPass())
    {
        return;
    }

    const VkDebugUtilsLabelEXT* label_info = pLabelInfo->GetPointer();
    if ((label_info != nullptr) && ContainsVrFrameDelimiter(label_info->pLabelName))
    {
        frame_boundary_command_buffers_.insert(commandBuffer);
    }

    if (IsSkiaBlock(commandBuffer))
    {
        SetDeleteCurrentCall();
    }
}

bool VulkanSkiaModifier::CanOptimize()
{
    bool skivkOptimize = true;
    if (!not_skiavk_instance) // only include skiavk instance
        skivkOptimize = false;
    if (!skiavk_instance) // no skiavk instance
        skivkOptimize = false;
    GFXRECON_WRITE_CONSOLE("skiavk optimization is %s, remove block count: %u",
                           skivkOptimize ? "true" : "false",
                           skiavkindex2remove.size());

    return skivkOptimize;
}

bool VulkanSkiaModifier::IsSkiaBlock(format::HandleId handle)
{
    auto it0 = skia_device2queue.find(handle);
    if (it0 != skia_device2queue.end())
    {
        return true;
    }

    for (auto& e : skia_command_pool2command_buffer)
    {
        auto it1 = std::find(e.second.begin(), e.second.end(), handle);
        if (it1 != e.second.end())
        {
            return true;
        }
    }

    auto it3 = skiavk_instance2physical_device.find(handle);
    if (it3 != skiavk_instance2physical_device.end())
    {
        return true;
    }

    for (auto& e : skiavk_instance2physical_device)
    {
        auto it = std::find(e.second.begin(), e.second.end(), handle);
        if (it != e.second.end())
        {
            return true;
        }
    }

    for (auto& e : skiavk_physical_device2device)
    {
        auto it = std::find(e.second.begin(), e.second.end(), handle);
        if (it != e.second.end())
        {
            return true;
        }
    }

    for (auto& e : skia_device2queue)
    {
        auto it5 = std::find(e.second.begin(), e.second.end(), handle);
        if (it5 != e.second.end())
        {
            return true;
        }
    }
    return false;
}

void VulkanSkiaModifier::Process_vkCreateInstance(const ApiCallInfo&                                   call_info,
                                                  VkResult                                             returnValue,
                                                  StructPointerDecoder<Decoded_VkInstanceCreateInfo>*  pCreateInfo,
                                                  StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
                                                  HandlePointerDecoder<VkInstance>*                    pInstance)
{
    if (IsModificationPass())
        return;

    const VkInstanceCreateInfo* pVkInstanceCreateInfo = pCreateInfo->GetPointer();

    if (pVkInstanceCreateInfo == nullptr)
    {
        return;
    }

    bool name_match = false;

    if (pVkInstanceCreateInfo->pApplicationInfo != nullptr)
    {
        for (const auto& app_name : VulkanSkiaModifier::app_name_array)
        {
            if (pVkInstanceCreateInfo->pApplicationInfo->pApplicationName != nullptr &&
                strcmp(pVkInstanceCreateInfo->pApplicationInfo->pApplicationName, app_name.c_str()) == 0)
            {
                name_match = true;
            }
            else if (pVkInstanceCreateInfo->pApplicationInfo->pEngineName != nullptr &&
                     strcmp(pVkInstanceCreateInfo->pApplicationInfo->pEngineName, app_name.c_str()) == 0)
            {
                name_match = true;
            }

            if (name_match)
            {
                break;
            }
        }
    }

    bool remove = name_match;
    if (keep_device_instance_mode_)
    {
        remove = !name_match;
    }

    if (remove)
    {
        std::vector<format::HandleId> pyhsical_device;
        skiavk_instance2physical_device[*(pInstance->GetPointer())] = pyhsical_device;
        SetDeleteCurrentCall();
        skiavk_instance = true;
        return;
    }

    not_skiavk_instance = true;
}

void VulkanSkiaModifier::Process_vkDestroyInstance(const ApiCallInfo&                                   call_info,
                                                   format::HandleId                                     instance,
                                                   StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    if (IsModificationPass())
        return;
    auto                          it0 = skiavk_instance2physical_device.find(instance);
    std::vector<format::HandleId> physical_devices;
    if (it0 != skiavk_instance2physical_device.end())
    {
        SetDeleteCurrentCall();
        physical_devices = it0->second;
        skiavk_instance2physical_device.erase(it0);
    }
    for (auto& e : physical_devices)
    {
        std::vector<format::HandleId> devices;
        auto                          it1 = skiavk_physical_device2device.find(e);
        if (it1 != skiavk_physical_device2device.end())
        {
            devices = it1->second;
            skiavk_physical_device2device.erase(it1);
        }

        for (auto& e : devices)
        {
            auto it2 = skia_device2queue.find(e);
            if (it2 != skia_device2queue.end())
            {
                skia_device2queue.erase(it2);
            }
            std::vector<format::HandleId> command_pool;
            auto                          it3 = skia_device2command_pool.find(e);
            if (it3 != skia_device2command_pool.end())
            {
                command_pool = it3->second;
                skia_device2command_pool.erase(it3);
            }
            for (auto& cp : command_pool)
            {
                auto it4 = skia_command_pool2command_buffer.find(cp);
                if (it4 != skia_command_pool2command_buffer.end())
                {
                    skia_command_pool2command_buffer.erase(it4);
                }
            }
            auto it5 = skia_device2memory.find(e);
            if (it5 != skia_device2memory.end())
            {
                skia_device2memory.erase(it5);
            }
            auto it6 = skia_device2buffer.find(e);
            if (it6 != skia_device2buffer.end())
            {
                skia_device2buffer.erase(it6);
            }
        }
    }
}

void VulkanSkiaModifier::Process_vkEnumeratePhysicalDevices(const ApiCallInfo&        call_info,
                                                            VkResult                  returnValue,
                                                            format::HandleId          instance,
                                                            PointerDecoder<uint32_t>* pPhysicalDeviceCount,
                                                            HandlePointerDecoder<VkPhysicalDevice>* pPhysicalDevices)
{
    if (IsModificationPass())
        return;
    auto it = skiavk_instance2physical_device.find(instance);
    if (it != skiavk_instance2physical_device.end())
    {
        SetDeleteCurrentCall();
        if (!pPhysicalDevices->IsNull())
        {
            for (int i = 0; i < *pPhysicalDeviceCount->GetPointer(); i++)
            {
                it->second.push_back(((pPhysicalDevices->GetPointer()))[i]);
            }
        }
    }
}

void VulkanSkiaModifier::Process_vkCreateDevice(const ApiCallInfo&                                   call_info,
                                                VkResult                                             returnValue,
                                                format::HandleId                                     physicalDevice,
                                                StructPointerDecoder<Decoded_VkDeviceCreateInfo>*    pCreateInfo,
                                                StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
                                                HandlePointerDecoder<VkDevice>*                      pDevice)
{
    if (IsModificationPass())
        return;
    for (auto& e : skiavk_instance2physical_device)
    {
        auto it = std::find(e.second.begin(), e.second.end(), physicalDevice);
        if (it != e.second.end())
        {
            SetDeleteCurrentCall();
            skiavk_physical_device2device[physicalDevice].push_back(*pDevice->GetPointer());
            break;
        }
    }
}

void VulkanSkiaModifier::Process_vkDestroyDevice(const ApiCallInfo&                                   call_info,
                                                 format::HandleId                                     device,
                                                 StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    if (IsModificationPass())
        return;
    for (auto& e : skiavk_physical_device2device)
    {
        auto it = std::find(e.second.begin(), e.second.end(), device);
        if (it != e.second.end())
        {
            SetDeleteCurrentCall();
            e.second.erase(it);
            break;
        }
    }
    auto it2 = skia_device2queue.find(device);
    if (it2 != skia_device2queue.end())
    {
        skia_device2queue.erase(it2);
    }
    std::vector<format::HandleId> command_pool;
    auto                          it3 = skia_device2command_pool.find(device);
    if (it3 != skia_device2command_pool.end())
    {
        command_pool = it3->second;
        skia_device2command_pool.erase(it3);
    }
    for (auto& cp : command_pool)
    {
        auto it4 = skia_command_pool2command_buffer.find(cp);
        if (it4 != skia_command_pool2command_buffer.end())
        {
            skia_command_pool2command_buffer.erase(it4);
        }
    }
    auto it5 = skia_device2memory.find(device);
    if (it5 != skia_device2memory.end())
    {
        skia_device2memory.erase(it5);
    }
    auto it6 = skia_device2buffer.find(device);
    if (it6 != skia_device2buffer.end())
    {
        skia_device2buffer.erase(it6);
    }
}

void VulkanSkiaModifier::Process_vkGetDeviceQueue(const ApiCallInfo&             call_info,
                                                  format::HandleId               device,
                                                  uint32_t                       queueFamilyIndex,
                                                  uint32_t                       queueIndex,
                                                  HandlePointerDecoder<VkQueue>* pQueue)
{
    if (IsModificationPass())
        return;
    for (auto& e : skiavk_physical_device2device)
    {
        auto it = std::find(e.second.begin(), e.second.end(), device);
        if (it != e.second.end())
        {
            SetDeleteCurrentCall();
            skia_device2queue[device].push_back((*pQueue->GetPointer()));
            break;
        }
    }
}

void VulkanSkiaModifier::Process_vkGetDeviceQueue2(const ApiCallInfo&                                call_info,
                                                   format::HandleId                                  device,
                                                   StructPointerDecoder<Decoded_VkDeviceQueueInfo2>* pQueueInfo,
                                                   HandlePointerDecoder<VkQueue>*                    pQueue)
{
    if (IsModificationPass())
        return;
    for (auto& e : skiavk_physical_device2device)
    {
        auto it = std::find(e.second.begin(), e.second.end(), device);
        if (it != e.second.end())
        {
            SetDeleteCurrentCall();
            skia_device2queue[device].push_back((*pQueue->GetPointer()));
            break;
        }
    }
}

void VulkanSkiaModifier::Process_vkCreateCommandPool(const ApiCallInfo&                                     call_info,
                                                     VkResult                                               returnValue,
                                                     format::HandleId                                       device,
                                                     StructPointerDecoder<Decoded_VkCommandPoolCreateInfo>* pCreateInfo,
                                                     StructPointerDecoder<Decoded_VkAllocationCallbacks>*   pAllocator,
                                                     HandlePointerDecoder<VkCommandPool>* pCommandPool)
{
    if (IsModificationPass())
        return;
    for (auto& e : skiavk_physical_device2device)
    {
        auto it = std::find(e.second.begin(), e.second.end(), device);
        if (it != e.second.end())
        {
            SetDeleteCurrentCall();
            skia_device2command_pool[device].push_back((*pCommandPool->GetPointer()));
            break;
        }
    }
}

void VulkanSkiaModifier::Process_vkDestroyCommandPool(const ApiCallInfo&                                   call_info,
                                                      format::HandleId                                     device,
                                                      format::HandleId                                     commandPool,
                                                      StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    if (IsModificationPass())
        return;
    auto it = skia_device2command_pool.find(device);
    if (it != skia_device2command_pool.end())
    {
        SetDeleteCurrentCall();
        auto it1 = std::find(it->second.begin(), it->second.end(), commandPool);
        if (it1 != it->second.end())
        {
            it->second.erase(it1);
            auto it2 = skia_command_pool2command_buffer.find(commandPool);
            if (it2 != skia_command_pool2command_buffer.end())
            {
                skia_command_pool2command_buffer.erase(it2);
            }
        }
    }
}

void VulkanSkiaModifier::Process_vkAllocateCommandBuffers(
    const ApiCallInfo&                                         call_info,
    VkResult                                                   returnValue,
    format::HandleId                                           device,
    StructPointerDecoder<Decoded_VkCommandBufferAllocateInfo>* pAllocateInfo,
    HandlePointerDecoder<VkCommandBuffer>*                     pCommandBuffers)
{
    if (IsModificationPass())
        return;
    auto it = skia_device2queue.find(device);
    if (it != skia_device2queue.end())
    {
        SetDeleteCurrentCall();
        VkCommandBufferAllocateInfo* pVkCommandBufferAllocateInfo =
            (VkCommandBufferAllocateInfo*)pAllocateInfo->GetPointer();
        for (int i = 0; i < pVkCommandBufferAllocateInfo->commandBufferCount; i++)
        {
            skia_command_pool2command_buffer[(pAllocateInfo->GetMetaStructPointer()->commandPool)].push_back(
                (pCommandBuffers->GetPointer())[i]);
        }
    }
}

void VulkanSkiaModifier::Process_vkFreeCommandBuffers(const ApiCallInfo&                     call_info,
                                                      format::HandleId                       device,
                                                      format::HandleId                       commandPool,
                                                      uint32_t                               commandBufferCount,
                                                      HandlePointerDecoder<VkCommandBuffer>* pCommandBuffers)
{
    if (IsModificationPass())
        return;
    auto it = skia_command_pool2command_buffer.find(commandPool);
    if (it != skia_command_pool2command_buffer.end())
    {
        SetDeleteCurrentCall();
        for (int i = 0; i < commandBufferCount; i++)
        {
            auto it1 = std::find(it->second.begin(), it->second.end(), ((pCommandBuffers->GetPointer()))[i]);
            if (it1 != it->second.end())
            {
                it->second.erase(it1);
            }
        }
    }
}

void VulkanSkiaModifier::Process_vkAllocateMemory(const ApiCallInfo&                                   call_info,
                                                  VkResult                                             returnValue,
                                                  format::HandleId                                     device,
                                                  StructPointerDecoder<Decoded_VkMemoryAllocateInfo>*  pAllocateInfo,
                                                  StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
                                                  HandlePointerDecoder<VkDeviceMemory>*                pMemory)
{
    if (IsModificationPass())
        return;

    if (IsSkiaBlock(device))
    {
        SetDeleteCurrentCall();
        skia_device2memory[device].push_back(*pMemory->GetPointer());
    }
}

void VulkanSkiaModifier::Process_vkFreeMemory(const ApiCallInfo&                                   call_info,
                                              format::HandleId                                     device,
                                              format::HandleId                                     memory,
                                              StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    if (IsModificationPass())
        return;

    if (IsSkiaBlock(device))
    {
        SetDeleteCurrentCall();
    }

    auto it = skia_device2memory.find(device);
    if (it != skia_device2memory.end())
    {
        auto it1 = std::find(it->second.begin(), it->second.end(), memory);
        if (it1 != it->second.end())
        {
            it->second.erase(it1);
        }
    }
}

void VulkanSkiaModifier::Process_vkCreateAndroidSurfaceKHR(
    const ApiCallInfo&                                           call_info,
    VkResult                                                     returnValue,
    format::HandleId                                             instance,
    StructPointerDecoder<Decoded_VkAndroidSurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*         pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*                          pSurface)
{
    if (IsModificationPass())
        return;
    auto it = skiavk_instance2physical_device.find(instance);
    if (it != skiavk_instance2physical_device.end())
    {
        SetDeleteCurrentCall();
        skia_instance2surface[instance].push_back(*pSurface->GetPointer());
    }
}

void VulkanSkiaModifier::Process_vkCreateBuffer(const ApiCallInfo&                                   call_info,
                                                VkResult                                             returnValue,
                                                format::HandleId                                     device,
                                                StructPointerDecoder<Decoded_VkBufferCreateInfo>*    pCreateInfo,
                                                StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
                                                HandlePointerDecoder<VkBuffer>*                      pBuffer)
{
    if (IsModificationPass())
        return;
    auto it = skia_device2queue.find(device);
    if (it != skia_device2queue.end())
    {
        SetDeleteCurrentCall();
        skia_device2buffer[device].push_back(*pBuffer->GetPointer());
    }
}

void VulkanSkiaModifier::Process_vkDestroyBuffer(const ApiCallInfo&                                   call_info,
                                                 format::HandleId                                     device,
                                                 format::HandleId                                     buffer,
                                                 StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    if (IsModificationPass())
        return;
    auto it = skia_device2buffer.find(device);
    if (it != skia_device2buffer.end())
    {
        SetDeleteCurrentCall();
        auto it1 = std::find(it->second.begin(), it->second.end(), buffer);
        if (it1 != it->second.end())
        {
            it->second.erase(it1);
        }
    }
}

void VulkanSkiaModifier::ProcessSetDevicePropertiesCommand(format::HandleId   physical_device_id,
                                                           uint32_t           api_version,
                                                           uint32_t           driver_version,
                                                           uint32_t           vendor_id,
                                                           uint32_t           device_id,
                                                           uint32_t           device_type,
                                                           const uint8_t      pipeline_cache_uuid[format::kUuidSize],
                                                           const std::string& device_name)
{
    if (IsModificationPass())
        return;
    for (auto& e : skiavk_instance2physical_device)
    {
        auto it = std::find(e.second.begin(), e.second.end(), physical_device_id);
        if (it != e.second.end())
        {
            skiavkindex2remove[block_index_] = true;
            break;
        }
    }
}

void VulkanSkiaModifier::ProcessFillMemoryCommand(uint64_t       memory_id,
                                                  uint64_t       offset,
                                                  uint64_t       size,
                                                  const uint8_t* data)
{
    if (IsModificationPass())
        return;
    for (auto& e : skia_device2memory)
    {
        auto it = std::find(e.second.begin(), e.second.end(), memory_id);
        if (it != e.second.end())
        {
            skiavkindex2remove[block_index_] = true;
            break;
        }
    }
}

void VulkanSkiaModifier::ProcessCreateHardwareBufferCommand(
    format::HandleId                                    device_id,
    format::HandleId                                    memory_id,
    uint64_t                                            buffer_id,
    uint32_t                                            format,
    uint32_t                                            width,
    uint32_t                                            height,
    uint32_t                                            stride,
    uint64_t                                            usage,
    uint32_t                                            layers,
    const std::vector<format::HardwareBufferPlaneInfo>& plane_info)
{
    if (IsModificationPass())
        return;
    auto it2 = skia_device2queue.find(device_id);
    if (it2 != skia_device2queue.end())
    {
        skia_device2buffer[device_id].push_back(buffer_id);
        skiavkindex2remove[block_index_] = true;
        return;
    }
    for (auto& e : skia_device2memory)
    {
        auto it = std::find(e.second.begin(), e.second.end(), memory_id);
        if (it != e.second.end())
        {
            skia_device2buffer[device_id].push_back(buffer_id);
            skiavkindex2remove[block_index_] = true;
            return;
        }
    }
}

void VulkanSkiaModifier::ProcessFixDeviceAddressCommand(const format::FixDeviceAddressCommandHeader&    header,
                                                        const std::vector<format::AddressLocationInfo>& infos)
{
    if (IsModificationPass())
        return;
    auto it = skia_device2queue.find(header.relation_id);
    if (it != skia_device2queue.end())
    {
        skiavkindex2remove[block_index_] = true;
    }
    else
    {
        for (auto& e : skia_device2memory)
        {
            auto it1 = std::find(e.second.begin(), e.second.end(), header.relation_id);
            if (it1 != e.second.end())
            {
                skiavkindex2remove[block_index_] = true;
                break;
            }
        }
    }
}

void VulkanSkiaModifier::ProcessFixShaderGroupHandleCommand(const format::FixShaderGroupHandleCommandHeader&     header,
                                                            const std::vector<format::ShaderHandleLocationInfo>& infos)
{
    if (IsModificationPass())
        return;
    auto it = skia_device2queue.find(header.relation_id);
    if (it != skia_device2queue.end())
    {
        skiavkindex2remove[block_index_] = true;
    }
    else
    {
        for (auto& e : skia_device2memory)
        {
            auto it1 = std::find(e.second.begin(), e.second.end(), header.relation_id);
            if (it1 != e.second.end())
            {
                skiavkindex2remove[block_index_] = true;
                break;
            }
        }
    }
}

void VulkanSkiaModifier::ProcessResizeWindowCommand(format::HandleId surface_id, uint32_t width, uint32_t height)
{
    if (IsModificationPass())
        return;
    for (auto& e : skia_instance2surface)
    {
        auto it = std::find(e.second.begin(), e.second.end(), surface_id);
        if (it != e.second.end())
        {
            skiavkindex2remove[block_index_] = true;
            break;
        }
    }
}

void VulkanSkiaModifier::ProcessResizeWindowCommand2(format::HandleId surface_id,
                                                     uint32_t         width,
                                                     uint32_t         height,
                                                     uint32_t         pre_transform)
{
    if (IsModificationPass())
        return;
    for (auto& e : skia_instance2surface)
    {
        auto it = std::find(e.second.begin(), e.second.end(), surface_id);
        if (it != e.second.end())
        {
            skiavkindex2remove[block_index_] = true;
            break;
        }
    }
}

void VulkanSkiaModifier::ProcessDestroyHardwareBufferCommand(uint64_t buffer_id)
{
    if (IsModificationPass())
        return;
    for (auto& e : skia_device2buffer)
    {
        auto it = std::find(e.second.begin(), e.second.end(), buffer_id);
        if (it != e.second.end())
        {
            e.second.erase(it);
            skiavkindex2remove[block_index_] = true;
            break;
        }
    }
}

void VulkanSkiaModifier::ProcessSetDeviceMemoryPropertiesCommand(
    format::HandleId                             physical_device_id,
    const std::vector<format::DeviceMemoryType>& memory_types,
    const std::vector<format::DeviceMemoryHeap>& memory_heaps)
{
    if (IsModificationPass())
        return;
    for (auto& e : skiavk_instance2physical_device)
    {
        auto it = std::find(e.second.begin(), e.second.end(), physical_device_id);
        if (it != e.second.end())
        {
            skiavkindex2remove[block_index_] = true;
            break;
        }
    }
}

void VulkanSkiaModifier::ProcessSetOpaqueAddressCommand(format::HandleId device_id,
                                                        format::HandleId object_id,
                                                        uint64_t         address)
{
    if (IsModificationPass())
        return;
    auto it = skia_device2queue.find(device_id);
    if (it != skia_device2queue.end())
    {
        skiavkindex2remove[block_index_] = true;
    }
}

void VulkanSkiaModifier::ProcessSetRayTracingShaderGroupHandlesCommand(format::HandleId device_id,
                                                                       format::HandleId pipeline_id,
                                                                       size_t           data_size,
                                                                       const uint8_t*   data)
{
    if (IsModificationPass())
        return;
    auto it = skia_device2queue.find(device_id);
    if (it != skia_device2queue.end())
    {
        skiavkindex2remove[block_index_] = true;
    }
}

void VulkanSkiaModifier::ProcessSetSwapchainImageStateCommand(
    format::HandleId                                    device_id,
    format::HandleId                                    swapchain_id,
    uint32_t                                            last_presented_image,
    const std::vector<format::SwapchainImageStateInfo>& image_state)
{
    if (IsModificationPass())
        return;
    auto it = skia_device2queue.find(device_id);
    if (it != skia_device2queue.end())
    {
        skiavkindex2remove[block_index_] = true;
    }
}

void VulkanSkiaModifier::ProcessBeginResourceInitCommand(format::HandleId device_id,
                                                         uint64_t         max_resource_size,
                                                         uint64_t         max_copy_size)
{
    if (IsModificationPass())
        return;
    auto it = skia_device2queue.find(device_id);
    if (it != skia_device2queue.end())
    {
        skiavkindex2remove[block_index_] = true;
    }
}

void VulkanSkiaModifier::ProcessEndResourceInitCommand(format::HandleId device_id)
{
    if (IsModificationPass())
        return;
    auto it = skia_device2queue.find(device_id);
    if (it != skia_device2queue.end())
    {
        skiavkindex2remove[block_index_] = true;
    }
}

void VulkanSkiaModifier::ProcessInitBufferCommand(format::HandleId device_id,
                                                  format::HandleId buffer_id,
                                                  uint64_t         data_size,
                                                  const uint8_t*   data)
{
    if (IsModificationPass())
        return;
    auto it = skia_device2queue.find(device_id);
    if (it != skia_device2queue.end())
    {
        skiavkindex2remove[block_index_] = true;
    }
}

void VulkanSkiaModifier::ProcessInitImageCommand(format::HandleId             device_id,
                                                 format::HandleId             image_id,
                                                 uint64_t                     data_size,
                                                 uint32_t                     aspect,
                                                 uint32_t                     layout,
                                                 const std::vector<uint64_t>& level_sizes,
                                                 const uint8_t*               data)
{
    if (IsModificationPass())
        return;
    auto it = skia_device2queue.find(device_id);
    if (it != skia_device2queue.end())
    {
        skiavkindex2remove[block_index_] = true;
    }
}

void VulkanSkiaModifier::ProcessInitSubresourceCommand(const format::InitSubresourceCommandHeader& command_header,
                                                       const uint8_t*                              data)
{
    if (IsModificationPass())
        return;
    auto it = skia_device2queue.find(command_header.device_id);
    if (it != skia_device2queue.end())
    {
        skiavkindex2remove[block_index_] = true;
    }
}

void VulkanSkiaModifier::ProcessVulkanBuildAccelerationStructuresCommand(
    format::HandleId                                                           device_id,
    uint32_t                                                                   info_count,
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR>* geometry_infos,
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildRangeInfoKHR*>*   range_infos,
    std::vector<std::vector<VkAccelerationStructureInstanceKHR>>&              instance_buffers_data)
{
    if (IsModificationPass())
        return;
    auto it = skia_device2queue.find(device_id);
    if (it != skia_device2queue.end())
    {
        skiavkindex2remove[block_index_] = true;
    }
}

void VulkanSkiaModifier::ProcessVulkanCopyAccelerationStructuresCommand(
    format::HandleId device_id, StructPointerDecoder<Decoded_VkCopyAccelerationStructureInfoKHR>* copy_infos)
{
    if (IsModificationPass())
        return;
    auto it = skia_device2queue.find(device_id);
    if (it != skia_device2queue.end())
    {
        skiavkindex2remove[block_index_] = true;
    }
}

void VulkanSkiaModifier::ProcessVulkanWriteAccelerationStructuresPropertiesCommand(
    format::HandleId device_id, VkQueryType query_type, format::HandleId acceleration_structure_id)
{
    if (IsModificationPass())
        return;
    auto it = skia_device2queue.find(device_id);
    if (it != skia_device2queue.end())
    {
        skiavkindex2remove[block_index_] = true;
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
