/*
** Copyright (c) 2018-2021 Valve Corporation
** Copyright (c) 2018-2022 LunarG, Inc.
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

/*
** This file is generated from the Khronos Vulkan XML API Registry.
**
*/

#ifndef  GFXRECON_GENERATED_VULKAN_STATE_TABLE_H
#define  GFXRECON_GENERATED_VULKAN_STATE_TABLE_H

#include "encode/vulkan_state_table_base.h"


GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

class VulkanStateTable : VulkanStateTableBase
{
  public:
    VulkanStateTable() {}
    ~VulkanStateTable() {}

    bool InsertWrapper(AccelerationStructureKHRWrapper* wrapper) { return InsertEntry(wrapper->handle_id, wrapper, accelerationStructureKHR_map_); }
    bool InsertWrapper(AccelerationStructureNVWrapper* wrapper) { return InsertEntry(wrapper->handle_id, wrapper, accelerationStructureNV_map_); }
    bool InsertWrapper(BufferWrapper* wrapper) { return InsertEntry(wrapper->handle_id, wrapper, buffer_map_); }
    bool InsertWrapper(BufferViewWrapper* wrapper) { return InsertEntry(wrapper->handle_id, wrapper, bufferView_map_); }
    bool InsertWrapper(CommandBufferWrapper* wrapper) { return InsertEntry(wrapper->handle_id, wrapper, commandBuffer_map_); }
    bool InsertWrapper(CommandPoolWrapper* wrapper) { return InsertEntry(wrapper->handle_id, wrapper, commandPool_map_); }
    bool InsertWrapper(DebugReportCallbackEXTWrapper* wrapper) { return InsertEntry(wrapper->handle_id, wrapper, debugReportCallbackEXT_map_); }
    bool InsertWrapper(DebugUtilsMessengerEXTWrapper* wrapper) { return InsertEntry(wrapper->handle_id, wrapper, debugUtilsMessengerEXT_map_); }
    bool InsertWrapper(DeferredOperationKHRWrapper* wrapper) { return InsertEntry(wrapper->handle_id, wrapper, deferredOperationKHR_map_); }
    bool InsertWrapper(DescriptorPoolWrapper* wrapper) { return InsertEntry(wrapper->handle_id, wrapper, descriptorPool_map_); }
    bool InsertWrapper(DescriptorSetWrapper* wrapper) { return InsertEntry(wrapper->handle_id, wrapper, descriptorSet_map_); }
    bool InsertWrapper(DescriptorSetLayoutWrapper* wrapper) { return InsertEntry(wrapper->handle_id, wrapper, descriptorSetLayout_map_); }
    bool InsertWrapper(DescriptorUpdateTemplateWrapper* wrapper) { return InsertEntry(wrapper->handle_id, wrapper, descriptorUpdateTemplate_map_); }
    bool InsertWrapper(DeviceWrapper* wrapper) { return InsertEntry(wrapper->handle_id, wrapper, device_map_); }
    bool InsertWrapper(DeviceMemoryWrapper* wrapper) { return InsertEntry(wrapper->handle_id, wrapper, deviceMemory_map_); }
    bool InsertWrapper(DisplayKHRWrapper* wrapper) { return InsertEntry(wrapper->handle_id, wrapper, displayKHR_map_); }
    bool InsertWrapper(DisplayModeKHRWrapper* wrapper) { return InsertEntry(wrapper->handle_id, wrapper, displayModeKHR_map_); }
    bool InsertWrapper(EventWrapper* wrapper) { return InsertEntry(wrapper->handle_id, wrapper, event_map_); }
    bool InsertWrapper(FenceWrapper* wrapper) { return InsertEntry(wrapper->handle_id, wrapper, fence_map_); }
    bool InsertWrapper(FramebufferWrapper* wrapper) { return InsertEntry(wrapper->handle_id, wrapper, framebuffer_map_); }
    bool InsertWrapper(ImageWrapper* wrapper) { return InsertEntry(wrapper->handle_id, wrapper, image_map_); }
    bool InsertWrapper(ImageViewWrapper* wrapper) { return InsertEntry(wrapper->handle_id, wrapper, imageView_map_); }
    bool InsertWrapper(IndirectCommandsLayoutNVWrapper* wrapper) { return InsertEntry(wrapper->handle_id, wrapper, indirectCommandsLayoutNV_map_); }
    bool InsertWrapper(InstanceWrapper* wrapper) { return InsertEntry(wrapper->handle_id, wrapper, instance_map_); }
    bool InsertWrapper(MicromapEXTWrapper* wrapper) { return InsertEntry(wrapper->handle_id, wrapper, micromapEXT_map_); }
    bool InsertWrapper(OpticalFlowSessionNVWrapper* wrapper) { return InsertEntry(wrapper->handle_id, wrapper, opticalFlowSessionNV_map_); }
    bool InsertWrapper(PerformanceConfigurationINTELWrapper* wrapper) { return InsertEntry(wrapper->handle_id, wrapper, performanceConfigurationINTEL_map_); }
    bool InsertWrapper(PhysicalDeviceWrapper* wrapper) { return InsertEntry(wrapper->handle_id, wrapper, physicalDevice_map_); }
    bool InsertWrapper(PipelineWrapper* wrapper) { return InsertEntry(wrapper->handle_id, wrapper, pipeline_map_); }
    bool InsertWrapper(PipelineCacheWrapper* wrapper) { return InsertEntry(wrapper->handle_id, wrapper, pipelineCache_map_); }
    bool InsertWrapper(PipelineLayoutWrapper* wrapper) { return InsertEntry(wrapper->handle_id, wrapper, pipelineLayout_map_); }
    bool InsertWrapper(PrivateDataSlotWrapper* wrapper) { return InsertEntry(wrapper->handle_id, wrapper, privateDataSlot_map_); }
    bool InsertWrapper(QueryPoolWrapper* wrapper) { return InsertEntry(wrapper->handle_id, wrapper, queryPool_map_); }
    bool InsertWrapper(QueueWrapper* wrapper) { return InsertEntry(wrapper->handle_id, wrapper, queue_map_); }
    bool InsertWrapper(RenderPassWrapper* wrapper) { return InsertEntry(wrapper->handle_id, wrapper, renderPass_map_); }
    bool InsertWrapper(SamplerWrapper* wrapper) { return InsertEntry(wrapper->handle_id, wrapper, sampler_map_); }
    bool InsertWrapper(SamplerYcbcrConversionWrapper* wrapper) { return InsertEntry(wrapper->handle_id, wrapper, samplerYcbcrConversion_map_); }
    bool InsertWrapper(SemaphoreWrapper* wrapper) { return InsertEntry(wrapper->handle_id, wrapper, semaphore_map_); }
    bool InsertWrapper(ShaderModuleWrapper* wrapper) { return InsertEntry(wrapper->handle_id, wrapper, shaderModule_map_); }
    bool InsertWrapper(SurfaceKHRWrapper* wrapper) { return InsertEntry(wrapper->handle_id, wrapper, surfaceKHR_map_); }
    bool InsertWrapper(SwapchainKHRWrapper* wrapper) { return InsertEntry(wrapper->handle_id, wrapper, swapchainKHR_map_); }
    bool InsertWrapper(ValidationCacheEXTWrapper* wrapper) { return InsertEntry(wrapper->handle_id, wrapper, validationCacheEXT_map_); }

    bool RemoveWrapper(const AccelerationStructureKHRWrapper* wrapper) { return RemoveEntry(wrapper->handle_id, accelerationStructureKHR_map_); }
    bool RemoveWrapper(const AccelerationStructureNVWrapper* wrapper) { return RemoveEntry(wrapper->handle_id, accelerationStructureNV_map_); }
    bool RemoveWrapper(const BufferWrapper* wrapper) { return RemoveEntry(wrapper->handle_id, buffer_map_); }
    bool RemoveWrapper(const BufferViewWrapper* wrapper) { return RemoveEntry(wrapper->handle_id, bufferView_map_); }
    bool RemoveWrapper(const CommandBufferWrapper* wrapper) { return RemoveEntry(wrapper->handle_id, commandBuffer_map_); }
    bool RemoveWrapper(const CommandPoolWrapper* wrapper) { return RemoveEntry(wrapper->handle_id, commandPool_map_); }
    bool RemoveWrapper(const DebugReportCallbackEXTWrapper* wrapper) { return RemoveEntry(wrapper->handle_id, debugReportCallbackEXT_map_); }
    bool RemoveWrapper(const DebugUtilsMessengerEXTWrapper* wrapper) { return RemoveEntry(wrapper->handle_id, debugUtilsMessengerEXT_map_); }
    bool RemoveWrapper(const DeferredOperationKHRWrapper* wrapper) { return RemoveEntry(wrapper->handle_id, deferredOperationKHR_map_); }
    bool RemoveWrapper(const DescriptorPoolWrapper* wrapper) { return RemoveEntry(wrapper->handle_id, descriptorPool_map_); }
    bool RemoveWrapper(const DescriptorSetWrapper* wrapper) { return RemoveEntry(wrapper->handle_id, descriptorSet_map_); }
    bool RemoveWrapper(const DescriptorSetLayoutWrapper* wrapper) { return RemoveEntry(wrapper->handle_id, descriptorSetLayout_map_); }
    bool RemoveWrapper(const DescriptorUpdateTemplateWrapper* wrapper) { return RemoveEntry(wrapper->handle_id, descriptorUpdateTemplate_map_); }
    bool RemoveWrapper(const DeviceWrapper* wrapper) { return RemoveEntry(wrapper->handle_id, device_map_); }
    bool RemoveWrapper(const DeviceMemoryWrapper* wrapper) { return RemoveEntry(wrapper->handle_id, deviceMemory_map_); }
    bool RemoveWrapper(const DisplayKHRWrapper* wrapper) { return RemoveEntry(wrapper->handle_id, displayKHR_map_); }
    bool RemoveWrapper(const DisplayModeKHRWrapper* wrapper) { return RemoveEntry(wrapper->handle_id, displayModeKHR_map_); }
    bool RemoveWrapper(const EventWrapper* wrapper) { return RemoveEntry(wrapper->handle_id, event_map_); }
    bool RemoveWrapper(const FenceWrapper* wrapper) { return RemoveEntry(wrapper->handle_id, fence_map_); }
    bool RemoveWrapper(const FramebufferWrapper* wrapper) { return RemoveEntry(wrapper->handle_id, framebuffer_map_); }
    bool RemoveWrapper(const ImageWrapper* wrapper) { return RemoveEntry(wrapper->handle_id, image_map_); }
    bool RemoveWrapper(const ImageViewWrapper* wrapper) { return RemoveEntry(wrapper->handle_id, imageView_map_); }
    bool RemoveWrapper(const IndirectCommandsLayoutNVWrapper* wrapper) { return RemoveEntry(wrapper->handle_id, indirectCommandsLayoutNV_map_); }
    bool RemoveWrapper(const InstanceWrapper* wrapper) { return RemoveEntry(wrapper->handle_id, instance_map_); }
    bool RemoveWrapper(const MicromapEXTWrapper* wrapper) { return RemoveEntry(wrapper->handle_id, micromapEXT_map_); }
    bool RemoveWrapper(const OpticalFlowSessionNVWrapper* wrapper) { return RemoveEntry(wrapper->handle_id, opticalFlowSessionNV_map_); }
    bool RemoveWrapper(const PerformanceConfigurationINTELWrapper* wrapper) { return RemoveEntry(wrapper->handle_id, performanceConfigurationINTEL_map_); }
    bool RemoveWrapper(const PhysicalDeviceWrapper* wrapper) { return RemoveEntry(wrapper->handle_id, physicalDevice_map_); }
    bool RemoveWrapper(const PipelineWrapper* wrapper) { return RemoveEntry(wrapper->handle_id, pipeline_map_); }
    bool RemoveWrapper(const PipelineCacheWrapper* wrapper) { return RemoveEntry(wrapper->handle_id, pipelineCache_map_); }
    bool RemoveWrapper(const PipelineLayoutWrapper* wrapper) { return RemoveEntry(wrapper->handle_id, pipelineLayout_map_); }
    bool RemoveWrapper(const PrivateDataSlotWrapper* wrapper) { return RemoveEntry(wrapper->handle_id, privateDataSlot_map_); }
    bool RemoveWrapper(const QueryPoolWrapper* wrapper) { return RemoveEntry(wrapper->handle_id, queryPool_map_); }
    bool RemoveWrapper(const QueueWrapper* wrapper) { return RemoveEntry(wrapper->handle_id, queue_map_); }
    bool RemoveWrapper(const RenderPassWrapper* wrapper) { return RemoveEntry(wrapper->handle_id, renderPass_map_); }
    bool RemoveWrapper(const SamplerWrapper* wrapper) { return RemoveEntry(wrapper->handle_id, sampler_map_); }
    bool RemoveWrapper(const SamplerYcbcrConversionWrapper* wrapper) { return RemoveEntry(wrapper->handle_id, samplerYcbcrConversion_map_); }
    bool RemoveWrapper(const SemaphoreWrapper* wrapper) { return RemoveEntry(wrapper->handle_id, semaphore_map_); }
    bool RemoveWrapper(const ShaderModuleWrapper* wrapper) { return RemoveEntry(wrapper->handle_id, shaderModule_map_); }
    bool RemoveWrapper(const SurfaceKHRWrapper* wrapper) { return RemoveEntry(wrapper->handle_id, surfaceKHR_map_); }
    bool RemoveWrapper(const SwapchainKHRWrapper* wrapper) { return RemoveEntry(wrapper->handle_id, swapchainKHR_map_); }
    bool RemoveWrapper(const ValidationCacheEXTWrapper* wrapper) { return RemoveEntry(wrapper->handle_id, validationCacheEXT_map_); }

    template<typename T>
    const T* GetWrapper(format::HandleId id) const { return nullptr; }
    template<>
    const AccelerationStructureKHRWrapper* GetWrapper<AccelerationStructureKHRWrapper>(format::HandleId id) const { return VulkanStateTableBase::GetWrapper(id, accelerationStructureKHR_map_); }
    template<>
    const AccelerationStructureNVWrapper* GetWrapper<AccelerationStructureNVWrapper>(format::HandleId id) const { return VulkanStateTableBase::GetWrapper(id, accelerationStructureNV_map_); }
    template<>
    const BufferWrapper* GetWrapper<BufferWrapper>(format::HandleId id) const { return VulkanStateTableBase::GetWrapper(id, buffer_map_); }
    template<>
    const BufferViewWrapper* GetWrapper<BufferViewWrapper>(format::HandleId id) const { return VulkanStateTableBase::GetWrapper(id, bufferView_map_); }
    template<>
    const CommandBufferWrapper* GetWrapper<CommandBufferWrapper>(format::HandleId id) const { return VulkanStateTableBase::GetWrapper(id, commandBuffer_map_); }
    template<>
    const CommandPoolWrapper* GetWrapper<CommandPoolWrapper>(format::HandleId id) const { return VulkanStateTableBase::GetWrapper(id, commandPool_map_); }
    template<>
    const DebugReportCallbackEXTWrapper* GetWrapper<DebugReportCallbackEXTWrapper>(format::HandleId id) const { return VulkanStateTableBase::GetWrapper(id, debugReportCallbackEXT_map_); }
    template<>
    const DebugUtilsMessengerEXTWrapper* GetWrapper<DebugUtilsMessengerEXTWrapper>(format::HandleId id) const { return VulkanStateTableBase::GetWrapper(id, debugUtilsMessengerEXT_map_); }
    template<>
    const DeferredOperationKHRWrapper* GetWrapper<DeferredOperationKHRWrapper>(format::HandleId id) const { return VulkanStateTableBase::GetWrapper(id, deferredOperationKHR_map_); }
    template<>
    const DescriptorPoolWrapper* GetWrapper<DescriptorPoolWrapper>(format::HandleId id) const { return VulkanStateTableBase::GetWrapper(id, descriptorPool_map_); }
    template<>
    const DescriptorSetWrapper* GetWrapper<DescriptorSetWrapper>(format::HandleId id) const { return VulkanStateTableBase::GetWrapper(id, descriptorSet_map_); }
    template<>
    const DescriptorSetLayoutWrapper* GetWrapper<DescriptorSetLayoutWrapper>(format::HandleId id) const { return VulkanStateTableBase::GetWrapper(id, descriptorSetLayout_map_); }
    template<>
    const DescriptorUpdateTemplateWrapper* GetWrapper<DescriptorUpdateTemplateWrapper>(format::HandleId id) const { return VulkanStateTableBase::GetWrapper(id, descriptorUpdateTemplate_map_); }
    template<>
    const DeviceWrapper* GetWrapper<DeviceWrapper>(format::HandleId id) const { return VulkanStateTableBase::GetWrapper(id, device_map_); }
    template<>
    const DeviceMemoryWrapper* GetWrapper<DeviceMemoryWrapper>(format::HandleId id) const { return VulkanStateTableBase::GetWrapper(id, deviceMemory_map_); }
    template<>
    const DisplayKHRWrapper* GetWrapper<DisplayKHRWrapper>(format::HandleId id) const { return VulkanStateTableBase::GetWrapper(id, displayKHR_map_); }
    template<>
    const DisplayModeKHRWrapper* GetWrapper<DisplayModeKHRWrapper>(format::HandleId id) const { return VulkanStateTableBase::GetWrapper(id, displayModeKHR_map_); }
    template<>
    const EventWrapper* GetWrapper<EventWrapper>(format::HandleId id) const { return VulkanStateTableBase::GetWrapper(id, event_map_); }
    template<>
    const FenceWrapper* GetWrapper<FenceWrapper>(format::HandleId id) const { return VulkanStateTableBase::GetWrapper(id, fence_map_); }
    template<>
    const FramebufferWrapper* GetWrapper<FramebufferWrapper>(format::HandleId id) const { return VulkanStateTableBase::GetWrapper(id, framebuffer_map_); }
    template<>
    const ImageWrapper* GetWrapper<ImageWrapper>(format::HandleId id) const { return VulkanStateTableBase::GetWrapper(id, image_map_); }
    template<>
    const ImageViewWrapper* GetWrapper<ImageViewWrapper>(format::HandleId id) const { return VulkanStateTableBase::GetWrapper(id, imageView_map_); }
    template<>
    const IndirectCommandsLayoutNVWrapper* GetWrapper<IndirectCommandsLayoutNVWrapper>(format::HandleId id) const { return VulkanStateTableBase::GetWrapper(id, indirectCommandsLayoutNV_map_); }
    template<>
    const InstanceWrapper* GetWrapper<InstanceWrapper>(format::HandleId id) const { return VulkanStateTableBase::GetWrapper(id, instance_map_); }
    template<>
    const MicromapEXTWrapper* GetWrapper<MicromapEXTWrapper>(format::HandleId id) const { return VulkanStateTableBase::GetWrapper(id, micromapEXT_map_); }
    template<>
    const OpticalFlowSessionNVWrapper* GetWrapper<OpticalFlowSessionNVWrapper>(format::HandleId id) const { return VulkanStateTableBase::GetWrapper(id, opticalFlowSessionNV_map_); }
    template<>
    const PerformanceConfigurationINTELWrapper* GetWrapper<PerformanceConfigurationINTELWrapper>(format::HandleId id) const { return VulkanStateTableBase::GetWrapper(id, performanceConfigurationINTEL_map_); }
    template<>
    const PhysicalDeviceWrapper* GetWrapper<PhysicalDeviceWrapper>(format::HandleId id) const { return VulkanStateTableBase::GetWrapper(id, physicalDevice_map_); }
    template<>
    const PipelineWrapper* GetWrapper<PipelineWrapper>(format::HandleId id) const { return VulkanStateTableBase::GetWrapper(id, pipeline_map_); }
    template<>
    const PipelineCacheWrapper* GetWrapper<PipelineCacheWrapper>(format::HandleId id) const { return VulkanStateTableBase::GetWrapper(id, pipelineCache_map_); }
    template<>
    const PipelineLayoutWrapper* GetWrapper<PipelineLayoutWrapper>(format::HandleId id) const { return VulkanStateTableBase::GetWrapper(id, pipelineLayout_map_); }
    template<>
    const PrivateDataSlotWrapper* GetWrapper<PrivateDataSlotWrapper>(format::HandleId id) const { return VulkanStateTableBase::GetWrapper(id, privateDataSlot_map_); }
    template<>
    const QueryPoolWrapper* GetWrapper<QueryPoolWrapper>(format::HandleId id) const { return VulkanStateTableBase::GetWrapper(id, queryPool_map_); }
    template<>
    const QueueWrapper* GetWrapper<QueueWrapper>(format::HandleId id) const { return VulkanStateTableBase::GetWrapper(id, queue_map_); }
    template<>
    const RenderPassWrapper* GetWrapper<RenderPassWrapper>(format::HandleId id) const { return VulkanStateTableBase::GetWrapper(id, renderPass_map_); }
    template<>
    const SamplerWrapper* GetWrapper<SamplerWrapper>(format::HandleId id) const { return VulkanStateTableBase::GetWrapper(id, sampler_map_); }
    template<>
    const SamplerYcbcrConversionWrapper* GetWrapper<SamplerYcbcrConversionWrapper>(format::HandleId id) const { return VulkanStateTableBase::GetWrapper(id, samplerYcbcrConversion_map_); }
    template<>
    const SemaphoreWrapper* GetWrapper<SemaphoreWrapper>(format::HandleId id) const { return VulkanStateTableBase::GetWrapper(id, semaphore_map_); }
    template<>
    const ShaderModuleWrapper* GetWrapper<ShaderModuleWrapper>(format::HandleId id) const { return VulkanStateTableBase::GetWrapper(id, shaderModule_map_); }
    template<>
    const SurfaceKHRWrapper* GetWrapper<SurfaceKHRWrapper>(format::HandleId id) const { return VulkanStateTableBase::GetWrapper(id, surfaceKHR_map_); }
    template<>
    const SwapchainKHRWrapper* GetWrapper<SwapchainKHRWrapper>(format::HandleId id) const { return VulkanStateTableBase::GetWrapper(id, swapchainKHR_map_); }
    template<>
    const ValidationCacheEXTWrapper* GetWrapper<ValidationCacheEXTWrapper>(format::HandleId id) const { return VulkanStateTableBase::GetWrapper(id, validationCacheEXT_map_); }

    template<typename T>
    T* GetWrapper(format::HandleId id){ return nullptr; }
    template<>
    AccelerationStructureKHRWrapper* GetWrapper<AccelerationStructureKHRWrapper>(format::HandleId id) { return VulkanStateTableBase::GetWrapper(id, accelerationStructureKHR_map_); }
    template<>
    AccelerationStructureNVWrapper* GetWrapper<AccelerationStructureNVWrapper>(format::HandleId id) { return VulkanStateTableBase::GetWrapper(id, accelerationStructureNV_map_); }
    template<>
    BufferWrapper* GetWrapper<BufferWrapper>(format::HandleId id) { return VulkanStateTableBase::GetWrapper(id, buffer_map_); }
    template<>
    BufferViewWrapper* GetWrapper<BufferViewWrapper>(format::HandleId id) { return VulkanStateTableBase::GetWrapper(id, bufferView_map_); }
    template<>
    CommandBufferWrapper* GetWrapper<CommandBufferWrapper>(format::HandleId id) { return VulkanStateTableBase::GetWrapper(id, commandBuffer_map_); }
    template<>
    CommandPoolWrapper* GetWrapper<CommandPoolWrapper>(format::HandleId id) { return VulkanStateTableBase::GetWrapper(id, commandPool_map_); }
    template<>
    DebugReportCallbackEXTWrapper* GetWrapper<DebugReportCallbackEXTWrapper>(format::HandleId id) { return VulkanStateTableBase::GetWrapper(id, debugReportCallbackEXT_map_); }
    template<>
    DebugUtilsMessengerEXTWrapper* GetWrapper<DebugUtilsMessengerEXTWrapper>(format::HandleId id) { return VulkanStateTableBase::GetWrapper(id, debugUtilsMessengerEXT_map_); }
    template<>
    DeferredOperationKHRWrapper* GetWrapper<DeferredOperationKHRWrapper>(format::HandleId id) { return VulkanStateTableBase::GetWrapper(id, deferredOperationKHR_map_); }
    template<>
    DescriptorPoolWrapper* GetWrapper<DescriptorPoolWrapper>(format::HandleId id) { return VulkanStateTableBase::GetWrapper(id, descriptorPool_map_); }
    template<>
    DescriptorSetWrapper* GetWrapper<DescriptorSetWrapper>(format::HandleId id) { return VulkanStateTableBase::GetWrapper(id, descriptorSet_map_); }
    template<>
    DescriptorSetLayoutWrapper* GetWrapper<DescriptorSetLayoutWrapper>(format::HandleId id) { return VulkanStateTableBase::GetWrapper(id, descriptorSetLayout_map_); }
    template<>
    DescriptorUpdateTemplateWrapper* GetWrapper<DescriptorUpdateTemplateWrapper>(format::HandleId id) { return VulkanStateTableBase::GetWrapper(id, descriptorUpdateTemplate_map_); }
    template<>
    DeviceWrapper* GetWrapper<DeviceWrapper>(format::HandleId id) { return VulkanStateTableBase::GetWrapper(id, device_map_); }
    template<>
    DeviceMemoryWrapper* GetWrapper<DeviceMemoryWrapper>(format::HandleId id) { return VulkanStateTableBase::GetWrapper(id, deviceMemory_map_); }
    template<>
    DisplayKHRWrapper* GetWrapper<DisplayKHRWrapper>(format::HandleId id) { return VulkanStateTableBase::GetWrapper(id, displayKHR_map_); }
    template<>
    DisplayModeKHRWrapper* GetWrapper<DisplayModeKHRWrapper>(format::HandleId id) { return VulkanStateTableBase::GetWrapper(id, displayModeKHR_map_); }
    template<>
    EventWrapper* GetWrapper<EventWrapper>(format::HandleId id) { return VulkanStateTableBase::GetWrapper(id, event_map_); }
    template<>
    FenceWrapper* GetWrapper<FenceWrapper>(format::HandleId id) { return VulkanStateTableBase::GetWrapper(id, fence_map_); }
    template<>
    FramebufferWrapper* GetWrapper<FramebufferWrapper>(format::HandleId id) { return VulkanStateTableBase::GetWrapper(id, framebuffer_map_); }
    template<>
    ImageWrapper* GetWrapper<ImageWrapper>(format::HandleId id) { return VulkanStateTableBase::GetWrapper(id, image_map_); }
    template<>
    ImageViewWrapper* GetWrapper<ImageViewWrapper>(format::HandleId id) { return VulkanStateTableBase::GetWrapper(id, imageView_map_); }
    template<>
    IndirectCommandsLayoutNVWrapper* GetWrapper<IndirectCommandsLayoutNVWrapper>(format::HandleId id) { return VulkanStateTableBase::GetWrapper(id, indirectCommandsLayoutNV_map_); }
    template<>
    InstanceWrapper* GetWrapper<InstanceWrapper>(format::HandleId id) { return VulkanStateTableBase::GetWrapper(id, instance_map_); }
    template<>
    MicromapEXTWrapper* GetWrapper<MicromapEXTWrapper>(format::HandleId id) { return VulkanStateTableBase::GetWrapper(id, micromapEXT_map_); }
    template<>
    OpticalFlowSessionNVWrapper* GetWrapper<OpticalFlowSessionNVWrapper>(format::HandleId id) { return VulkanStateTableBase::GetWrapper(id, opticalFlowSessionNV_map_); }
    template<>
    PerformanceConfigurationINTELWrapper* GetWrapper<PerformanceConfigurationINTELWrapper>(format::HandleId id) { return VulkanStateTableBase::GetWrapper(id, performanceConfigurationINTEL_map_); }
    template<>
    PhysicalDeviceWrapper* GetWrapper<PhysicalDeviceWrapper>(format::HandleId id) { return VulkanStateTableBase::GetWrapper(id, physicalDevice_map_); }
    template<>
    PipelineWrapper* GetWrapper<PipelineWrapper>(format::HandleId id) { return VulkanStateTableBase::GetWrapper(id, pipeline_map_); }
    template<>
    PipelineCacheWrapper* GetWrapper<PipelineCacheWrapper>(format::HandleId id) { return VulkanStateTableBase::GetWrapper(id, pipelineCache_map_); }
    template<>
    PipelineLayoutWrapper* GetWrapper<PipelineLayoutWrapper>(format::HandleId id) { return VulkanStateTableBase::GetWrapper(id, pipelineLayout_map_); }
    template<>
    PrivateDataSlotWrapper* GetWrapper<PrivateDataSlotWrapper>(format::HandleId id) { return VulkanStateTableBase::GetWrapper(id, privateDataSlot_map_); }
    template<>
    QueryPoolWrapper* GetWrapper<QueryPoolWrapper>(format::HandleId id) { return VulkanStateTableBase::GetWrapper(id, queryPool_map_); }
    template<>
    QueueWrapper* GetWrapper<QueueWrapper>(format::HandleId id) { return VulkanStateTableBase::GetWrapper(id, queue_map_); }
    template<>
    RenderPassWrapper* GetWrapper<RenderPassWrapper>(format::HandleId id) { return VulkanStateTableBase::GetWrapper(id, renderPass_map_); }
    template<>
    SamplerWrapper* GetWrapper<SamplerWrapper>(format::HandleId id) { return VulkanStateTableBase::GetWrapper(id, sampler_map_); }
    template<>
    SamplerYcbcrConversionWrapper* GetWrapper<SamplerYcbcrConversionWrapper>(format::HandleId id) { return VulkanStateTableBase::GetWrapper(id, samplerYcbcrConversion_map_); }
    template<>
    SemaphoreWrapper* GetWrapper<SemaphoreWrapper>(format::HandleId id) { return VulkanStateTableBase::GetWrapper(id, semaphore_map_); }
    template<>
    ShaderModuleWrapper* GetWrapper<ShaderModuleWrapper>(format::HandleId id) { return VulkanStateTableBase::GetWrapper(id, shaderModule_map_); }
    template<>
    SurfaceKHRWrapper* GetWrapper<SurfaceKHRWrapper>(format::HandleId id) { return VulkanStateTableBase::GetWrapper(id, surfaceKHR_map_); }
    template<>
    SwapchainKHRWrapper* GetWrapper<SwapchainKHRWrapper>(format::HandleId id) { return VulkanStateTableBase::GetWrapper(id, swapchainKHR_map_); }
    template<>
    ValidationCacheEXTWrapper* GetWrapper<ValidationCacheEXTWrapper>(format::HandleId id) { return VulkanStateTableBase::GetWrapper(id, validationCacheEXT_map_); }

    void VisitWrappers(std::function<void(AccelerationStructureKHRWrapper*)> visitor) const { for (auto entry : accelerationStructureKHR_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(AccelerationStructureNVWrapper*)> visitor) const { for (auto entry : accelerationStructureNV_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(BufferWrapper*)> visitor) const { for (auto entry : buffer_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(BufferViewWrapper*)> visitor) const { for (auto entry : bufferView_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(CommandBufferWrapper*)> visitor) const { for (auto entry : commandBuffer_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(CommandPoolWrapper*)> visitor) const { for (auto entry : commandPool_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(DebugReportCallbackEXTWrapper*)> visitor) const { for (auto entry : debugReportCallbackEXT_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(DebugUtilsMessengerEXTWrapper*)> visitor) const { for (auto entry : debugUtilsMessengerEXT_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(DeferredOperationKHRWrapper*)> visitor) const { for (auto entry : deferredOperationKHR_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(DescriptorPoolWrapper*)> visitor) const { for (auto entry : descriptorPool_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(DescriptorSetWrapper*)> visitor) const { for (auto entry : descriptorSet_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(DescriptorSetLayoutWrapper*)> visitor) const { for (auto entry : descriptorSetLayout_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(DescriptorUpdateTemplateWrapper*)> visitor) const { for (auto entry : descriptorUpdateTemplate_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(DeviceWrapper*)> visitor) const { for (auto entry : device_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(DeviceMemoryWrapper*)> visitor) const { for (auto entry : deviceMemory_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(DisplayKHRWrapper*)> visitor) const { for (auto entry : displayKHR_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(DisplayModeKHRWrapper*)> visitor) const { for (auto entry : displayModeKHR_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(EventWrapper*)> visitor) const { for (auto entry : event_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(FenceWrapper*)> visitor) const { for (auto entry : fence_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(FramebufferWrapper*)> visitor) const { for (auto entry : framebuffer_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ImageWrapper*)> visitor) const { for (auto entry : image_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ImageViewWrapper*)> visitor) const { for (auto entry : imageView_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(IndirectCommandsLayoutNVWrapper*)> visitor) const { for (auto entry : indirectCommandsLayoutNV_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(InstanceWrapper*)> visitor) const { for (auto entry : instance_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(MicromapEXTWrapper*)> visitor) const { for (auto entry : micromapEXT_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(OpticalFlowSessionNVWrapper*)> visitor) const { for (auto entry : opticalFlowSessionNV_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(PerformanceConfigurationINTELWrapper*)> visitor) const { for (auto entry : performanceConfigurationINTEL_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(PhysicalDeviceWrapper*)> visitor) const { for (auto entry : physicalDevice_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(PipelineWrapper*)> visitor) const { for (auto entry : pipeline_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(PipelineCacheWrapper*)> visitor) const { for (auto entry : pipelineCache_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(PipelineLayoutWrapper*)> visitor) const { for (auto entry : pipelineLayout_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(PrivateDataSlotWrapper*)> visitor) const { for (auto entry : privateDataSlot_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(QueryPoolWrapper*)> visitor) const { for (auto entry : queryPool_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(QueueWrapper*)> visitor) const { for (auto entry : queue_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(RenderPassWrapper*)> visitor) const { for (auto entry : renderPass_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(SamplerWrapper*)> visitor) const { for (auto entry : sampler_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(SamplerYcbcrConversionWrapper*)> visitor) const { for (auto entry : samplerYcbcrConversion_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(SemaphoreWrapper*)> visitor) const { for (auto entry : semaphore_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ShaderModuleWrapper*)> visitor) const { for (auto entry : shaderModule_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(SurfaceKHRWrapper*)> visitor) const { for (auto entry : surfaceKHR_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(SwapchainKHRWrapper*)> visitor) const { for (auto entry : swapchainKHR_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(ValidationCacheEXTWrapper*)> visitor) const { for (auto entry : validationCacheEXT_map_) { visitor(entry.second); } }

  private:
    std::map<format::HandleId, AccelerationStructureKHRWrapper*> accelerationStructureKHR_map_;
    std::map<format::HandleId, AccelerationStructureNVWrapper*> accelerationStructureNV_map_;
    std::map<format::HandleId, BufferWrapper*> buffer_map_;
    std::map<format::HandleId, BufferViewWrapper*> bufferView_map_;
    std::map<format::HandleId, CommandBufferWrapper*> commandBuffer_map_;
    std::map<format::HandleId, CommandPoolWrapper*> commandPool_map_;
    std::map<format::HandleId, DebugReportCallbackEXTWrapper*> debugReportCallbackEXT_map_;
    std::map<format::HandleId, DebugUtilsMessengerEXTWrapper*> debugUtilsMessengerEXT_map_;
    std::map<format::HandleId, DeferredOperationKHRWrapper*> deferredOperationKHR_map_;
    std::map<format::HandleId, DescriptorPoolWrapper*> descriptorPool_map_;
    std::map<format::HandleId, DescriptorSetWrapper*> descriptorSet_map_;
    std::map<format::HandleId, DescriptorSetLayoutWrapper*> descriptorSetLayout_map_;
    std::map<format::HandleId, DescriptorUpdateTemplateWrapper*> descriptorUpdateTemplate_map_;
    std::map<format::HandleId, DeviceWrapper*> device_map_;
    std::map<format::HandleId, DeviceMemoryWrapper*> deviceMemory_map_;
    std::map<format::HandleId, DisplayKHRWrapper*> displayKHR_map_;
    std::map<format::HandleId, DisplayModeKHRWrapper*> displayModeKHR_map_;
    std::map<format::HandleId, EventWrapper*> event_map_;
    std::map<format::HandleId, FenceWrapper*> fence_map_;
    std::map<format::HandleId, FramebufferWrapper*> framebuffer_map_;
    std::map<format::HandleId, ImageWrapper*> image_map_;
    std::map<format::HandleId, ImageViewWrapper*> imageView_map_;
    std::map<format::HandleId, IndirectCommandsLayoutNVWrapper*> indirectCommandsLayoutNV_map_;
    std::map<format::HandleId, InstanceWrapper*> instance_map_;
    std::map<format::HandleId, MicromapEXTWrapper*> micromapEXT_map_;
    std::map<format::HandleId, OpticalFlowSessionNVWrapper*> opticalFlowSessionNV_map_;
    std::map<format::HandleId, PerformanceConfigurationINTELWrapper*> performanceConfigurationINTEL_map_;
    std::map<format::HandleId, PhysicalDeviceWrapper*> physicalDevice_map_;
    std::map<format::HandleId, PipelineWrapper*> pipeline_map_;
    std::map<format::HandleId, PipelineCacheWrapper*> pipelineCache_map_;
    std::map<format::HandleId, PipelineLayoutWrapper*> pipelineLayout_map_;
    std::map<format::HandleId, PrivateDataSlotWrapper*> privateDataSlot_map_;
    std::map<format::HandleId, QueryPoolWrapper*> queryPool_map_;
    std::map<format::HandleId, QueueWrapper*> queue_map_;
    std::map<format::HandleId, RenderPassWrapper*> renderPass_map_;
    std::map<format::HandleId, SamplerWrapper*> sampler_map_;
    std::map<format::HandleId, SamplerYcbcrConversionWrapper*> samplerYcbcrConversion_map_;
    std::map<format::HandleId, SemaphoreWrapper*> semaphore_map_;
    std::map<format::HandleId, ShaderModuleWrapper*> shaderModule_map_;
    std::map<format::HandleId, SurfaceKHRWrapper*> surfaceKHR_map_;
    std::map<format::HandleId, SwapchainKHRWrapper*> swapchainKHR_map_;
    std::map<format::HandleId, ValidationCacheEXTWrapper*> validationCacheEXT_map_;
};

class VulkanStateHandleTable : VulkanStateTableBase
{
  public:
    VulkanStateHandleTable() {}
    ~VulkanStateHandleTable() {}

    bool InsertWrapper(AccelerationStructureKHRWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, accelerationStructureKHR_map_); }
    bool InsertWrapper(AccelerationStructureNVWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, accelerationStructureNV_map_); }
    bool InsertWrapper(BufferWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, buffer_map_); }
    bool InsertWrapper(BufferViewWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, bufferView_map_); }
    bool InsertWrapper(CommandBufferWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, commandBuffer_map_); }
    bool InsertWrapper(CommandPoolWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, commandPool_map_); }
    bool InsertWrapper(DebugReportCallbackEXTWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, debugReportCallbackEXT_map_); }
    bool InsertWrapper(DebugUtilsMessengerEXTWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, debugUtilsMessengerEXT_map_); }
    bool InsertWrapper(DeferredOperationKHRWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, deferredOperationKHR_map_); }
    bool InsertWrapper(DescriptorPoolWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, descriptorPool_map_); }
    bool InsertWrapper(DescriptorSetWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, descriptorSet_map_); }
    bool InsertWrapper(DescriptorSetLayoutWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, descriptorSetLayout_map_); }
    bool InsertWrapper(DescriptorUpdateTemplateWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, descriptorUpdateTemplate_map_); }
    bool InsertWrapper(DeviceWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, device_map_); }
    bool InsertWrapper(DeviceMemoryWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, deviceMemory_map_); }
    bool InsertWrapper(DisplayKHRWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, displayKHR_map_); }
    bool InsertWrapper(DisplayModeKHRWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, displayModeKHR_map_); }
    bool InsertWrapper(EventWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, event_map_); }
    bool InsertWrapper(FenceWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, fence_map_); }
    bool InsertWrapper(FramebufferWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, framebuffer_map_); }
    bool InsertWrapper(ImageWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, image_map_); }
    bool InsertWrapper(ImageViewWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, imageView_map_); }
    bool InsertWrapper(IndirectCommandsLayoutNVWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, indirectCommandsLayoutNV_map_); }
    bool InsertWrapper(InstanceWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, instance_map_); }
    bool InsertWrapper(MicromapEXTWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, micromapEXT_map_); }
    bool InsertWrapper(OpticalFlowSessionNVWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, opticalFlowSessionNV_map_); }
    bool InsertWrapper(PerformanceConfigurationINTELWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, performanceConfigurationINTEL_map_); }
    bool InsertWrapper(PhysicalDeviceWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, physicalDevice_map_); }
    bool InsertWrapper(PipelineWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, pipeline_map_); }
    bool InsertWrapper(PipelineCacheWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, pipelineCache_map_); }
    bool InsertWrapper(PipelineLayoutWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, pipelineLayout_map_); }
    bool InsertWrapper(PrivateDataSlotWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, privateDataSlot_map_); }
    bool InsertWrapper(QueryPoolWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, queryPool_map_); }
    bool InsertWrapper(QueueWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, queue_map_); }
    bool InsertWrapper(RenderPassWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, renderPass_map_); }
    bool InsertWrapper(SamplerWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, sampler_map_); }
    bool InsertWrapper(SamplerYcbcrConversionWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, samplerYcbcrConversion_map_); }
    bool InsertWrapper(SemaphoreWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, semaphore_map_); }
    bool InsertWrapper(ShaderModuleWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, shaderModule_map_); }
    bool InsertWrapper(SurfaceKHRWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, surfaceKHR_map_); }
    bool InsertWrapper(SwapchainKHRWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, swapchainKHR_map_); }
    bool InsertWrapper(ValidationCacheEXTWrapper* wrapper) { return InsertEntry(wrapper->handle, wrapper, validationCacheEXT_map_); }

    bool RemoveWrapper(const VkAccelerationStructureKHR handle) { return RemoveEntry(handle, accelerationStructureKHR_map_); }
    bool RemoveWrapper(const VkAccelerationStructureNV handle) { return RemoveEntry(handle, accelerationStructureNV_map_); }
    bool RemoveWrapper(const VkBuffer handle) { return RemoveEntry(handle, buffer_map_); }
    bool RemoveWrapper(const VkBufferView handle) { return RemoveEntry(handle, bufferView_map_); }
    bool RemoveWrapper(const VkCommandBuffer handle) { return RemoveEntry(handle, commandBuffer_map_); }
    bool RemoveWrapper(const VkCommandPool handle) { return RemoveEntry(handle, commandPool_map_); }
    bool RemoveWrapper(const VkDebugReportCallbackEXT handle) { return RemoveEntry(handle, debugReportCallbackEXT_map_); }
    bool RemoveWrapper(const VkDebugUtilsMessengerEXT handle) { return RemoveEntry(handle, debugUtilsMessengerEXT_map_); }
    bool RemoveWrapper(const VkDeferredOperationKHR handle) { return RemoveEntry(handle, deferredOperationKHR_map_); }
    bool RemoveWrapper(const VkDescriptorPool handle) { return RemoveEntry(handle, descriptorPool_map_); }
    bool RemoveWrapper(const VkDescriptorSet handle) { return RemoveEntry(handle, descriptorSet_map_); }
    bool RemoveWrapper(const VkDescriptorSetLayout handle) { return RemoveEntry(handle, descriptorSetLayout_map_); }
    bool RemoveWrapper(const VkDescriptorUpdateTemplate handle) { return RemoveEntry(handle, descriptorUpdateTemplate_map_); }
    bool RemoveWrapper(const VkDevice handle) { return RemoveEntry(handle, device_map_); }
    bool RemoveWrapper(const VkDeviceMemory handle) { return RemoveEntry(handle, deviceMemory_map_); }
    bool RemoveWrapper(const VkDisplayKHR handle) { return RemoveEntry(handle, displayKHR_map_); }
    bool RemoveWrapper(const VkDisplayModeKHR handle) { return RemoveEntry(handle, displayModeKHR_map_); }
    bool RemoveWrapper(const VkEvent handle) { return RemoveEntry(handle, event_map_); }
    bool RemoveWrapper(const VkFence handle) { return RemoveEntry(handle, fence_map_); }
    bool RemoveWrapper(const VkFramebuffer handle) { return RemoveEntry(handle, framebuffer_map_); }
    bool RemoveWrapper(const VkImage handle) { return RemoveEntry(handle, image_map_); }
    bool RemoveWrapper(const VkImageView handle) { return RemoveEntry(handle, imageView_map_); }
    bool RemoveWrapper(const VkIndirectCommandsLayoutNV handle) { return RemoveEntry(handle, indirectCommandsLayoutNV_map_); }
    bool RemoveWrapper(const VkInstance handle) { return RemoveEntry(handle, instance_map_); }
    bool RemoveWrapper(const VkMicromapEXT handle) { return RemoveEntry(handle, micromapEXT_map_); }
    bool RemoveWrapper(const VkOpticalFlowSessionNV handle) { return RemoveEntry(handle, opticalFlowSessionNV_map_); }
    bool RemoveWrapper(const VkPerformanceConfigurationINTEL handle) { return RemoveEntry(handle, performanceConfigurationINTEL_map_); }
    bool RemoveWrapper(const VkPhysicalDevice handle) { return RemoveEntry(handle, physicalDevice_map_); }
    bool RemoveWrapper(const VkPipeline handle) { return RemoveEntry(handle, pipeline_map_); }
    bool RemoveWrapper(const VkPipelineCache handle) { return RemoveEntry(handle, pipelineCache_map_); }
    bool RemoveWrapper(const VkPipelineLayout handle) { return RemoveEntry(handle, pipelineLayout_map_); }
    bool RemoveWrapper(const VkPrivateDataSlot handle) { return RemoveEntry(handle, privateDataSlot_map_); }
    bool RemoveWrapper(const VkQueryPool handle) { return RemoveEntry(handle, queryPool_map_); }
    bool RemoveWrapper(const VkQueue handle) { return RemoveEntry(handle, queue_map_); }
    bool RemoveWrapper(const VkRenderPass handle) { return RemoveEntry(handle, renderPass_map_); }
    bool RemoveWrapper(const VkSampler handle) { return RemoveEntry(handle, sampler_map_); }
    bool RemoveWrapper(const VkSamplerYcbcrConversion handle) { return RemoveEntry(handle, samplerYcbcrConversion_map_); }
    bool RemoveWrapper(const VkSemaphore handle) { return RemoveEntry(handle, semaphore_map_); }
    bool RemoveWrapper(const VkShaderModule handle) { return RemoveEntry(handle, shaderModule_map_); }
    bool RemoveWrapper(const VkSurfaceKHR handle) { return RemoveEntry(handle, surfaceKHR_map_); }
    bool RemoveWrapper(const VkSwapchainKHR handle) { return RemoveEntry(handle, swapchainKHR_map_); }
    bool RemoveWrapper(const VkValidationCacheEXT handle) { return RemoveEntry(handle, validationCacheEXT_map_); }

    const AccelerationStructureKHRWrapper* GetWrapper(VkAccelerationStructureKHR handle) const { return VulkanStateTableBase::GetWrapper(handle, accelerationStructureKHR_map_); }
    const AccelerationStructureNVWrapper* GetWrapper(VkAccelerationStructureNV handle) const { return VulkanStateTableBase::GetWrapper(handle, accelerationStructureNV_map_); }
    const BufferWrapper* GetWrapper(VkBuffer handle) const { return VulkanStateTableBase::GetWrapper(handle, buffer_map_); }
    const BufferViewWrapper* GetWrapper(VkBufferView handle) const { return VulkanStateTableBase::GetWrapper(handle, bufferView_map_); }
    const CommandBufferWrapper* GetWrapper(VkCommandBuffer handle) const { return VulkanStateTableBase::GetWrapper(handle, commandBuffer_map_); }
    const CommandPoolWrapper* GetWrapper(VkCommandPool handle) const { return VulkanStateTableBase::GetWrapper(handle, commandPool_map_); }
    const DebugReportCallbackEXTWrapper* GetWrapper(VkDebugReportCallbackEXT handle) const { return VulkanStateTableBase::GetWrapper(handle, debugReportCallbackEXT_map_); }
    const DebugUtilsMessengerEXTWrapper* GetWrapper(VkDebugUtilsMessengerEXT handle) const { return VulkanStateTableBase::GetWrapper(handle, debugUtilsMessengerEXT_map_); }
    const DeferredOperationKHRWrapper* GetWrapper(VkDeferredOperationKHR handle) const { return VulkanStateTableBase::GetWrapper(handle, deferredOperationKHR_map_); }
    const DescriptorPoolWrapper* GetWrapper(VkDescriptorPool handle) const { return VulkanStateTableBase::GetWrapper(handle, descriptorPool_map_); }
    const DescriptorSetWrapper* GetWrapper(VkDescriptorSet handle) const { return VulkanStateTableBase::GetWrapper(handle, descriptorSet_map_); }
    const DescriptorSetLayoutWrapper* GetWrapper(VkDescriptorSetLayout handle) const { return VulkanStateTableBase::GetWrapper(handle, descriptorSetLayout_map_); }
    const DescriptorUpdateTemplateWrapper* GetWrapper(VkDescriptorUpdateTemplate handle) const { return VulkanStateTableBase::GetWrapper(handle, descriptorUpdateTemplate_map_); }
    const DeviceWrapper* GetWrapper(VkDevice handle) const { return VulkanStateTableBase::GetWrapper(handle, device_map_); }
    const DeviceMemoryWrapper* GetWrapper(VkDeviceMemory handle) const { return VulkanStateTableBase::GetWrapper(handle, deviceMemory_map_); }
    const DisplayKHRWrapper* GetWrapper(VkDisplayKHR handle) const { return VulkanStateTableBase::GetWrapper(handle, displayKHR_map_); }
    const DisplayModeKHRWrapper* GetWrapper(VkDisplayModeKHR handle) const { return VulkanStateTableBase::GetWrapper(handle, displayModeKHR_map_); }
    const EventWrapper* GetWrapper(VkEvent handle) const { return VulkanStateTableBase::GetWrapper(handle, event_map_); }
    const FenceWrapper* GetWrapper(VkFence handle) const { return VulkanStateTableBase::GetWrapper(handle, fence_map_); }
    const FramebufferWrapper* GetWrapper(VkFramebuffer handle) const { return VulkanStateTableBase::GetWrapper(handle, framebuffer_map_); }
    const ImageWrapper* GetWrapper(VkImage handle) const { return VulkanStateTableBase::GetWrapper(handle, image_map_); }
    const ImageViewWrapper* GetWrapper(VkImageView handle) const { return VulkanStateTableBase::GetWrapper(handle, imageView_map_); }
    const IndirectCommandsLayoutNVWrapper* GetWrapper(VkIndirectCommandsLayoutNV handle) const { return VulkanStateTableBase::GetWrapper(handle, indirectCommandsLayoutNV_map_); }
    const InstanceWrapper* GetWrapper(VkInstance handle) const { return VulkanStateTableBase::GetWrapper(handle, instance_map_); }
    const MicromapEXTWrapper* GetWrapper(VkMicromapEXT handle) const { return VulkanStateTableBase::GetWrapper(handle, micromapEXT_map_); }
    const OpticalFlowSessionNVWrapper* GetWrapper(VkOpticalFlowSessionNV handle) const { return VulkanStateTableBase::GetWrapper(handle, opticalFlowSessionNV_map_); }
    const PerformanceConfigurationINTELWrapper* GetWrapper(VkPerformanceConfigurationINTEL handle) const { return VulkanStateTableBase::GetWrapper(handle, performanceConfigurationINTEL_map_); }
    const PhysicalDeviceWrapper* GetWrapper(VkPhysicalDevice handle) const { return VulkanStateTableBase::GetWrapper(handle, physicalDevice_map_); }
    const PipelineWrapper* GetWrapper(VkPipeline handle) const { return VulkanStateTableBase::GetWrapper(handle, pipeline_map_); }
    const PipelineCacheWrapper* GetWrapper(VkPipelineCache handle) const { return VulkanStateTableBase::GetWrapper(handle, pipelineCache_map_); }
    const PipelineLayoutWrapper* GetWrapper(VkPipelineLayout handle) const { return VulkanStateTableBase::GetWrapper(handle, pipelineLayout_map_); }
    const PrivateDataSlotWrapper* GetWrapper(VkPrivateDataSlot handle) const { return VulkanStateTableBase::GetWrapper(handle, privateDataSlot_map_); }
    const QueryPoolWrapper* GetWrapper(VkQueryPool handle) const { return VulkanStateTableBase::GetWrapper(handle, queryPool_map_); }
    const QueueWrapper* GetWrapper(VkQueue handle) const { return VulkanStateTableBase::GetWrapper(handle, queue_map_); }
    const RenderPassWrapper* GetWrapper(VkRenderPass handle) const { return VulkanStateTableBase::GetWrapper(handle, renderPass_map_); }
    const SamplerWrapper* GetWrapper(VkSampler handle) const { return VulkanStateTableBase::GetWrapper(handle, sampler_map_); }
    const SamplerYcbcrConversionWrapper* GetWrapper(VkSamplerYcbcrConversion handle) const { return VulkanStateTableBase::GetWrapper(handle, samplerYcbcrConversion_map_); }
    const SemaphoreWrapper* GetWrapper(VkSemaphore handle) const { return VulkanStateTableBase::GetWrapper(handle, semaphore_map_); }
    const ShaderModuleWrapper* GetWrapper(VkShaderModule handle) const { return VulkanStateTableBase::GetWrapper(handle, shaderModule_map_); }
    const SurfaceKHRWrapper* GetWrapper(VkSurfaceKHR handle) const { return VulkanStateTableBase::GetWrapper(handle, surfaceKHR_map_); }
    const SwapchainKHRWrapper* GetWrapper(VkSwapchainKHR handle) const { return VulkanStateTableBase::GetWrapper(handle, swapchainKHR_map_); }
    const ValidationCacheEXTWrapper* GetWrapper(VkValidationCacheEXT handle) const { return VulkanStateTableBase::GetWrapper(handle, validationCacheEXT_map_); }

    AccelerationStructureKHRWrapper* GetWrapper(VkAccelerationStructureKHR handle) { return VulkanStateTableBase::GetWrapper(handle, accelerationStructureKHR_map_); }
    AccelerationStructureNVWrapper* GetWrapper(VkAccelerationStructureNV handle) { return VulkanStateTableBase::GetWrapper(handle, accelerationStructureNV_map_); }
    BufferWrapper* GetWrapper(VkBuffer handle) { return VulkanStateTableBase::GetWrapper(handle, buffer_map_); }
    BufferViewWrapper* GetWrapper(VkBufferView handle) { return VulkanStateTableBase::GetWrapper(handle, bufferView_map_); }
    CommandBufferWrapper* GetWrapper(VkCommandBuffer handle) { return VulkanStateTableBase::GetWrapper(handle, commandBuffer_map_); }
    CommandPoolWrapper* GetWrapper(VkCommandPool handle) { return VulkanStateTableBase::GetWrapper(handle, commandPool_map_); }
    DebugReportCallbackEXTWrapper* GetWrapper(VkDebugReportCallbackEXT handle) { return VulkanStateTableBase::GetWrapper(handle, debugReportCallbackEXT_map_); }
    DebugUtilsMessengerEXTWrapper* GetWrapper(VkDebugUtilsMessengerEXT handle) { return VulkanStateTableBase::GetWrapper(handle, debugUtilsMessengerEXT_map_); }
    DeferredOperationKHRWrapper* GetWrapper(VkDeferredOperationKHR handle) { return VulkanStateTableBase::GetWrapper(handle, deferredOperationKHR_map_); }
    DescriptorPoolWrapper* GetWrapper(VkDescriptorPool handle) { return VulkanStateTableBase::GetWrapper(handle, descriptorPool_map_); }
    DescriptorSetWrapper* GetWrapper(VkDescriptorSet handle) { return VulkanStateTableBase::GetWrapper(handle, descriptorSet_map_); }
    DescriptorSetLayoutWrapper* GetWrapper(VkDescriptorSetLayout handle) { return VulkanStateTableBase::GetWrapper(handle, descriptorSetLayout_map_); }
    DescriptorUpdateTemplateWrapper* GetWrapper(VkDescriptorUpdateTemplate handle) { return VulkanStateTableBase::GetWrapper(handle, descriptorUpdateTemplate_map_); }
    DeviceWrapper* GetWrapper(VkDevice handle) { return VulkanStateTableBase::GetWrapper(handle, device_map_); }
    DeviceMemoryWrapper* GetWrapper(VkDeviceMemory handle) { return VulkanStateTableBase::GetWrapper(handle, deviceMemory_map_); }
    DisplayKHRWrapper* GetWrapper(VkDisplayKHR handle) { return VulkanStateTableBase::GetWrapper(handle, displayKHR_map_); }
    DisplayModeKHRWrapper* GetWrapper(VkDisplayModeKHR handle) { return VulkanStateTableBase::GetWrapper(handle, displayModeKHR_map_); }
    EventWrapper* GetWrapper(VkEvent handle) { return VulkanStateTableBase::GetWrapper(handle, event_map_); }
    FenceWrapper* GetWrapper(VkFence handle) { return VulkanStateTableBase::GetWrapper(handle, fence_map_); }
    FramebufferWrapper* GetWrapper(VkFramebuffer handle) { return VulkanStateTableBase::GetWrapper(handle, framebuffer_map_); }
    ImageWrapper* GetWrapper(VkImage handle) { return VulkanStateTableBase::GetWrapper(handle, image_map_); }
    ImageViewWrapper* GetWrapper(VkImageView handle) { return VulkanStateTableBase::GetWrapper(handle, imageView_map_); }
    IndirectCommandsLayoutNVWrapper* GetWrapper(VkIndirectCommandsLayoutNV handle) { return VulkanStateTableBase::GetWrapper(handle, indirectCommandsLayoutNV_map_); }
    InstanceWrapper* GetWrapper(VkInstance handle) { return VulkanStateTableBase::GetWrapper(handle, instance_map_); }
    MicromapEXTWrapper* GetWrapper(VkMicromapEXT handle) { return VulkanStateTableBase::GetWrapper(handle, micromapEXT_map_); }
    OpticalFlowSessionNVWrapper* GetWrapper(VkOpticalFlowSessionNV handle) { return VulkanStateTableBase::GetWrapper(handle, opticalFlowSessionNV_map_); }
    PerformanceConfigurationINTELWrapper* GetWrapper(VkPerformanceConfigurationINTEL handle) { return VulkanStateTableBase::GetWrapper(handle, performanceConfigurationINTEL_map_); }
    PhysicalDeviceWrapper* GetWrapper(VkPhysicalDevice handle) { return VulkanStateTableBase::GetWrapper(handle, physicalDevice_map_); }
    PipelineWrapper* GetWrapper(VkPipeline handle) { return VulkanStateTableBase::GetWrapper(handle, pipeline_map_); }
    PipelineCacheWrapper* GetWrapper(VkPipelineCache handle) { return VulkanStateTableBase::GetWrapper(handle, pipelineCache_map_); }
    PipelineLayoutWrapper* GetWrapper(VkPipelineLayout handle) { return VulkanStateTableBase::GetWrapper(handle, pipelineLayout_map_); }
    PrivateDataSlotWrapper* GetWrapper(VkPrivateDataSlot handle) { return VulkanStateTableBase::GetWrapper(handle, privateDataSlot_map_); }
    QueryPoolWrapper* GetWrapper(VkQueryPool handle) { return VulkanStateTableBase::GetWrapper(handle, queryPool_map_); }
    QueueWrapper* GetWrapper(VkQueue handle) { return VulkanStateTableBase::GetWrapper(handle, queue_map_); }
    RenderPassWrapper* GetWrapper(VkRenderPass handle) { return VulkanStateTableBase::GetWrapper(handle, renderPass_map_); }
    SamplerWrapper* GetWrapper(VkSampler handle) { return VulkanStateTableBase::GetWrapper(handle, sampler_map_); }
    SamplerYcbcrConversionWrapper* GetWrapper(VkSamplerYcbcrConversion handle) { return VulkanStateTableBase::GetWrapper(handle, samplerYcbcrConversion_map_); }
    SemaphoreWrapper* GetWrapper(VkSemaphore handle) { return VulkanStateTableBase::GetWrapper(handle, semaphore_map_); }
    ShaderModuleWrapper* GetWrapper(VkShaderModule handle) { return VulkanStateTableBase::GetWrapper(handle, shaderModule_map_); }
    SurfaceKHRWrapper* GetWrapper(VkSurfaceKHR handle) { return VulkanStateTableBase::GetWrapper(handle, surfaceKHR_map_); }
    SwapchainKHRWrapper* GetWrapper(VkSwapchainKHR handle) { return VulkanStateTableBase::GetWrapper(handle, swapchainKHR_map_); }
    ValidationCacheEXTWrapper* GetWrapper(VkValidationCacheEXT handle) { return VulkanStateTableBase::GetWrapper(handle, validationCacheEXT_map_); }

  private:
    std::map<VkAccelerationStructureKHR, AccelerationStructureKHRWrapper*> accelerationStructureKHR_map_;
    std::map<VkAccelerationStructureNV, AccelerationStructureNVWrapper*> accelerationStructureNV_map_;
    std::map<VkBuffer, BufferWrapper*> buffer_map_;
    std::map<VkBufferView, BufferViewWrapper*> bufferView_map_;
    std::map<VkCommandBuffer, CommandBufferWrapper*> commandBuffer_map_;
    std::map<VkCommandPool, CommandPoolWrapper*> commandPool_map_;
    std::map<VkDebugReportCallbackEXT, DebugReportCallbackEXTWrapper*> debugReportCallbackEXT_map_;
    std::map<VkDebugUtilsMessengerEXT, DebugUtilsMessengerEXTWrapper*> debugUtilsMessengerEXT_map_;
    std::map<VkDeferredOperationKHR, DeferredOperationKHRWrapper*> deferredOperationKHR_map_;
    std::map<VkDescriptorPool, DescriptorPoolWrapper*> descriptorPool_map_;
    std::map<VkDescriptorSet, DescriptorSetWrapper*> descriptorSet_map_;
    std::map<VkDescriptorSetLayout, DescriptorSetLayoutWrapper*> descriptorSetLayout_map_;
    std::map<VkDescriptorUpdateTemplate, DescriptorUpdateTemplateWrapper*> descriptorUpdateTemplate_map_;
    std::map<VkDevice, DeviceWrapper*> device_map_;
    std::map<VkDeviceMemory, DeviceMemoryWrapper*> deviceMemory_map_;
    std::map<VkDisplayKHR, DisplayKHRWrapper*> displayKHR_map_;
    std::map<VkDisplayModeKHR, DisplayModeKHRWrapper*> displayModeKHR_map_;
    std::map<VkEvent, EventWrapper*> event_map_;
    std::map<VkFence, FenceWrapper*> fence_map_;
    std::map<VkFramebuffer, FramebufferWrapper*> framebuffer_map_;
    std::map<VkImage, ImageWrapper*> image_map_;
    std::map<VkImageView, ImageViewWrapper*> imageView_map_;
    std::map<VkIndirectCommandsLayoutNV, IndirectCommandsLayoutNVWrapper*> indirectCommandsLayoutNV_map_;
    std::map<VkInstance, InstanceWrapper*> instance_map_;
    std::map<VkMicromapEXT, MicromapEXTWrapper*> micromapEXT_map_;
    std::map<VkOpticalFlowSessionNV, OpticalFlowSessionNVWrapper*> opticalFlowSessionNV_map_;
    std::map<VkPerformanceConfigurationINTEL, PerformanceConfigurationINTELWrapper*> performanceConfigurationINTEL_map_;
    std::map<VkPhysicalDevice, PhysicalDeviceWrapper*> physicalDevice_map_;
    std::map<VkPipeline, PipelineWrapper*> pipeline_map_;
    std::map<VkPipelineCache, PipelineCacheWrapper*> pipelineCache_map_;
    std::map<VkPipelineLayout, PipelineLayoutWrapper*> pipelineLayout_map_;
    std::map<VkPrivateDataSlot, PrivateDataSlotWrapper*> privateDataSlot_map_;
    std::map<VkQueryPool, QueryPoolWrapper*> queryPool_map_;
    std::map<VkQueue, QueueWrapper*> queue_map_;
    std::map<VkRenderPass, RenderPassWrapper*> renderPass_map_;
    std::map<VkSampler, SamplerWrapper*> sampler_map_;
    std::map<VkSamplerYcbcrConversion, SamplerYcbcrConversionWrapper*> samplerYcbcrConversion_map_;
    std::map<VkSemaphore, SemaphoreWrapper*> semaphore_map_;
    std::map<VkShaderModule, ShaderModuleWrapper*> shaderModule_map_;
    std::map<VkSurfaceKHR, SurfaceKHRWrapper*> surfaceKHR_map_;
    std::map<VkSwapchainKHR, SwapchainKHRWrapper*> swapchainKHR_map_;
    std::map<VkValidationCacheEXT, ValidationCacheEXTWrapper*> validationCacheEXT_map_;
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif
