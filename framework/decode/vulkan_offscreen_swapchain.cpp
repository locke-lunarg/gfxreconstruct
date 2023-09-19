/*
** Copyright (c) 2021-2022 LunarG, Inc.
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

#include "decode/vulkan_offscreen_swapchain.h"
#include "encode/vulkan_handle_wrapper_util.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)


VkResult VulkanOffscreenSwapchain::CreateSurface(InstanceInfo*                       instance_info,
                                                 const std::string&                  wsi_extension,
                                                 VkFlags                             flags,
                                                 HandlePointerDecoder<VkSurfaceKHR>* surface,
                                                 const encode::InstanceTable*        instance_table,
                                                 application::Application*           application,
                                                 int32_t                             options_surface_index)
{
    instance_table_        = instance_table;
    application_           = application;
    options_surface_index_ = options_surface_index;

    const format::HandleId* id             = surface->GetPointer();
    VkSurfaceKHR*           replay_surface = surface->GetHandlePointer();

    // Give surface a fake handle. It's handle id.
    *replay_surface = UINT64_TO_VK_HANDLE(VkSurfaceKHR, *id);
    return VK_SUCCESS;
}

void VulkanOffscreenSwapchain::DestroySurface(PFN_vkDestroySurfaceKHR      func,
                                              const InstanceInfo*          instance_info,
                                              const SurfaceKHRInfo*        surface_info,
                                              const VkAllocationCallbacks* allocator)
{}

VkResult VulkanOffscreenSwapchain::CreateSwapchainKHR(PFN_vkCreateSwapchainKHR              func,
                                                      const DeviceInfo*                     device_info,
                                                      const VkSwapchainCreateInfoKHR*       create_info,
                                                      const VkAllocationCallbacks*          allocator,
                                                      HandlePointerDecoder<VkSwapchainKHR>* swapchain,
                                                      const encode::DeviceTable*            device_table)
{
    GFXRECON_ASSERT(device_info);
    device_table_       = device_table;

    const format::HandleId* id               = swapchain->GetPointer();
    VkSwapchainKHR*         replay_swapchain = swapchain->GetHandlePointer();

    // Give swapchain a fake handle. It's handle id.
    *replay_swapchain = UINT64_TO_VK_HANDLE(VkSwapchainKHR, *id);
    if (!AddSwapchainResourceData(*replay_swapchain))
    {
        return VK_ERROR_OUT_OF_HOST_MEMORY;
    }

    VkDevice device = device = device_info->handle;
    device_table_->GetDeviceQueue(device, default_queue_family_index_, 0, &default_queue_);

    return VK_SUCCESS;
}

void VulkanOffscreenSwapchain::DestroySwapchainKHR(PFN_vkDestroySwapchainKHR    func,
                                                   const DeviceInfo*            device_info,
                                                   const SwapchainKHRInfo*      swapchain_info,
                                                   const VkAllocationCallbacks* allocator)
{
    if ((device_info != nullptr) && (swapchain_info != nullptr))
    {
        CleanSwapchainResourceData(device_info, swapchain_info);
    }
}

VkResult VulkanOffscreenSwapchain::GetSwapchainImagesKHR(PFN_vkGetSwapchainImagesKHR func,
                                                         const DeviceInfo*           device_info,
                                                         SwapchainKHRInfo*           swapchain_info,
                                                         uint32_t                    capture_image_count,
                                                         uint32_t*                   image_count,
                                                         VkImage*                    images)
{
    GFXRECON_ASSERT(swapchain_info);
    uint32_t* replay_image_count = &swapchain_info->replay_image_count;

    if (images == nullptr)
    {
        (*image_count)        = capture_image_count;
        (*replay_image_count) = capture_image_count;
        return VK_SUCCESS;
    }

    return CreateSwapchainResourceData(
        device_info, swapchain_info, capture_image_count, replay_image_count, images, true);
}

VkResult VulkanOffscreenSwapchain::AcquireNextImageKHR(PFN_vkAcquireNextImageKHR func,
                                                       const DeviceInfo*         device_info,
                                                       SwapchainKHRInfo*         swapchain_info,
                                                       uint64_t                  timeout,
                                                       VkSemaphore               semaphore,
                                                       VkFence                   fence,
                                                       uint32_t                  capture_image_index,
                                                       uint32_t*                 image_index)
{
    *image_index = capture_image_index;
    if (semaphore != VK_NULL_HANDLE || fence != VK_NULL_HANDLE)
    {
        uint32_t           signal_semaphore_count = 0;
        const VkSemaphore* signal_semaphores      = nullptr;

        if (semaphore != VK_NULL_HANDLE)
        {
            signal_semaphore_count = 1;
            signal_semaphores      = &semaphore;
        }
        return SingalSemaphoresFence(
            swapchain_info, capture_image_index, nullptr, 0, nullptr, signal_semaphore_count, signal_semaphores, fence);
    }
    return VK_SUCCESS;
}

VkResult VulkanOffscreenSwapchain::AcquireNextImage2KHR(PFN_vkAcquireNextImage2KHR       func,
                                                        const DeviceInfo*                device_info,
                                                        SwapchainKHRInfo*                swapchain_info,
                                                        const VkAcquireNextImageInfoKHR* acquire_info,
                                                        uint32_t                         capture_image_index,
                                                        uint32_t*                        image_index)
{
    *image_index = capture_image_index;
    if (acquire_info->semaphore != VK_NULL_HANDLE || acquire_info->fence != VK_NULL_HANDLE)
    {
        uint32_t           signal_semaphore_count = 0;
        const VkSemaphore* signal_semaphores      = nullptr;

        if (acquire_info->semaphore != VK_NULL_HANDLE)
        {
            signal_semaphore_count = 1;
            signal_semaphores      = &acquire_info->semaphore;
        }

        return SingalSemaphoresFence(swapchain_info,
                                     capture_image_index,
                                     nullptr,
                                     0,
                                     nullptr,
                                     signal_semaphore_count,
                                     signal_semaphores,
                                     acquire_info->fence);
    }
    return VK_SUCCESS;
}

VkResult VulkanOffscreenSwapchain::QueuePresentKHR(PFN_vkQueuePresentKHR                 func,
                                                   const std::vector<uint32_t>&          capture_image_indices,
                                                   const std::vector<SwapchainKHRInfo*>& swapchain_infos,
                                                   const QueueInfo*                      queue_info,
                                                   const VkPresentInfoKHR*               present_info)
{
    if (present_info->waitSemaphoreCount > 0)
    {
        auto length = present_info->swapchainCount;
        for (uint32_t i = 0; i < length; ++i)
        {
            return SingalSemaphoresFence(swapchain_infos[i],
                                         capture_image_indices[i],
                                         queue_info,
                                         present_info->waitSemaphoreCount,
                                         present_info->pWaitSemaphores,
                                         0,
                                         nullptr,
                                         VK_NULL_HANDLE);
        }
    }
    return VK_SUCCESS;
}

// queue_info could be nullptr. It means it doesn't specify a VkQueue and use default_queue. Its purpose is to singal
// semaphores or fence. All VkQueue should work.
VkResult VulkanOffscreenSwapchain::SingalSemaphoresFence(SwapchainKHRInfo*  swapchain_info,
                                                         uint32_t           capture_image_index,
                                                         const QueueInfo*   queue_info,
                                                         uint32_t           wait_semaphore_count,
                                                         const VkSemaphore* wait_semaphores,
                                                         uint32_t           signal_semaphore_count,
                                                         const VkSemaphore* signal_semaphores,
                                                         VkFence            fence)
{
    // Get the per swapchain resource data so we have access to the swapchain-specific information.
    if (swapchain_resources_.find(swapchain_info->handle) == swapchain_resources_.end())
    {
        GFXRECON_LOG_ERROR("VulkanOffscreenSwapchain::SingalSemaphoresFence missing swapchain resource data for "
                           "swapchain (ID = %" PRIu64 ")",
                           swapchain_info->capture_id);
        return VK_ERROR_UNKNOWN;
    }

    auto& swapchain_resources = swapchain_resources_[swapchain_info->handle];
    assert(swapchain_resources != nullptr);

    uint32_t queue_family_index = default_queue_family_index_;
    if (queue_info)
    {
        queue_family_index = queue_info->family_index;
    }
    // Find the appropriate CommandCopyData struct for this queue family
    if (swapchain_resources->copy_cmd_data.find(queue_family_index) == swapchain_resources->copy_cmd_data.end())
    {
        GFXRECON_LOG_ERROR(
            "VulkanOffscreenSwapchain::SingalSemaphoresFence missing swapchain resource copy command data for "
            "queue_family_index: %d in swapchain (ID = %" PRIu64 ")",
            queue_family_index,
            swapchain_info->capture_id);
        return VK_ERROR_UNKNOWN;
    }
    auto& copy_cmd_data  = swapchain_resources->copy_cmd_data[queue_family_index];
    auto  command_buffer = copy_cmd_data.command_buffers[capture_image_index];

    VkCommandBufferBeginInfo begin_info = { VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO };
    begin_info.pNext                    = nullptr;
    begin_info.flags                    = 0;
    begin_info.pInheritanceInfo         = nullptr;

    VkResult result = device_table_->ResetCommandBuffer(command_buffer, 0);
    if (result != VK_SUCCESS)
    {
        return result;
    }
    result = device_table_->BeginCommandBuffer(command_buffer, &begin_info);
    if (result != VK_SUCCESS)
    {
        return result;
    }
    result = device_table_->EndCommandBuffer(command_buffer);
    if (result != VK_SUCCESS)
    {
        return result;
    }

    VkPipelineStageFlags wait_stage  = VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT;
    VkSubmitInfo         submit_info = { VK_STRUCTURE_TYPE_SUBMIT_INFO };
    submit_info.commandBufferCount   = 1;
    submit_info.pCommandBuffers      = &command_buffer;

    if (wait_semaphore_count > 0)
    {
        submit_info.waitSemaphoreCount = wait_semaphore_count;
        submit_info.pWaitSemaphores    = wait_semaphores;
        submit_info.pWaitDstStageMask  = &wait_stage;
    }
    if (signal_semaphore_count > 0)
    {
        submit_info.signalSemaphoreCount = signal_semaphore_count;
        submit_info.pSignalSemaphores    = signal_semaphores;
    }

    VkQueue queue = VK_NULL_HANDLE;
    if (queue_info)
    {
        queue = queue_info->handle;
    }
    else
    {
        queue = default_queue_;
    }
    result = device_table_->QueueSubmit(queue, 1, &submit_info, fence);
    if (result != VK_SUCCESS)
    {
        return result;
    }
    return device_table_->QueueWaitIdle(queue);
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
