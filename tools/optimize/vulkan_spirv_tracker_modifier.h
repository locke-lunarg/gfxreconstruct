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
#ifndef GFXRECON_TOOLS_OPTIMIZE_VULKAN_SPIRV_TRACK_MODIFIER_H
#define GFXRECON_TOOLS_OPTIMIZE_VULKAN_SPIRV_TRACK_MODIFIER_H

#include <cstdint>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <deque>
#include <variant>
#include <vulkan/vulkan_core.h>

#include "decode/api_decoder.h"
#include "format/format.h"
#include "util/defines.h"
#include "encode/parameter_buffer.h"
#include "util/vulkan_modifier_base.h"
#include "framework/spirv_simulator.hpp"

#include <list>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

// Performs the track of spirv simulator input and output.
class VulkanSpirvTrackModifier : public util::VulkanModifierBase
{
  public:
    VulkanSpirvTrackModifier(bool verbose = false);

    virtual bool CanOptimize() override;

    virtual void
    ProcessFillMemoryCommand(uint64_t memory_id, uint64_t offset, uint64_t size, const uint8_t* data) override;

    virtual void Process_vkCreateBuffer(const ApiCallInfo&                                   call_info,
                                        VkResult                                             returnValue,
                                        format::HandleId                                     device,
                                        StructPointerDecoder<Decoded_VkBufferCreateInfo>*    pCreateInfo,
                                        StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
                                        HandlePointerDecoder<VkBuffer>*                      pBuffer) override;

    virtual void Process_vkDestroyBuffer(const ApiCallInfo&                                   call_info,
                                         format::HandleId                                     device,
                                         format::HandleId                                     buffer,
                                         StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkAllocateMemory(const ApiCallInfo&                                   call_info,
                                          VkResult                                             returnValue,
                                          format::HandleId                                     device,
                                          StructPointerDecoder<Decoded_VkMemoryAllocateInfo>*  pAllocateInfo,
                                          StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
                                          HandlePointerDecoder<VkDeviceMemory>*                pMemory) override;

    virtual void Process_vkFreeMemory(const ApiCallInfo&                                   call_info,
                                      format::HandleId                                     device,
                                      format::HandleId                                     memory,
                                      StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkBindBufferMemory(const ApiCallInfo& call_info,
                                            VkResult           returnValue,
                                            format::HandleId   device,
                                            format::HandleId   buffer,
                                            format::HandleId   memory,
                                            VkDeviceSize       memory_offset) override;

    virtual void Process_vkBindBufferMemory2(const ApiCallInfo&                                    call_info,
                                             VkResult                                              returnValue,
                                             format::HandleId                                      device,
                                             uint32_t                                              bindInfoCount,
                                             StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>* pBindInfos) override;

    virtual void Process_vkMapMemory(const ApiCallInfo&               call_info,
                                     VkResult                         returnValue,
                                     format::HandleId                 device,
                                     format::HandleId                 memory,
                                     VkDeviceSize                     offset,
                                     VkDeviceSize                     size,
                                     VkMemoryMapFlags                 flags,
                                     PointerDecoder<uint64_t, void*>* ppData) override;

    virtual void Process_vkMapMemory2(const ApiCallInfo&                             call_info,
                                      VkResult                                       returnValue,
                                      format::HandleId                               device,
                                      StructPointerDecoder<Decoded_VkMemoryMapInfo>* pMemoryMapInfo,
                                      PointerDecoder<uint64_t, void*>*               ppData) override;

    virtual void Process_vkUnmapMemory2(const ApiCallInfo&                               call_info,
                                        VkResult                                         returnValue,
                                        format::HandleId                                 device,
                                        StructPointerDecoder<Decoded_VkMemoryUnmapInfo>* pMemoryUnmapInfo) override;

    virtual void
    Process_vkUnmapMemory(const ApiCallInfo& call_info, format::HandleId device, format::HandleId memory) override;

    virtual void Process_vkCreateAccelerationStructureKHR(
        const ApiCallInfo&                                                  call_info,
        VkResult                                                            returnValue,
        format::HandleId                                                    device,
        StructPointerDecoder<Decoded_VkAccelerationStructureCreateInfoKHR>* pCreateInfo,
        StructPointerDecoder<Decoded_VkAllocationCallbacks>*                pAllocator,
        HandlePointerDecoder<VkAccelerationStructureKHR>*                   pAccelerationStructure) override;

    virtual void
    Process_vkDestroyAccelerationStructureKHR(const ApiCallInfo& call_info,
                                              format::HandleId   device,
                                              format::HandleId   accelerationStructure,
                                              StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkCreateShaderModule(const ApiCallInfo&                                      call_info,
                                              VkResult                                                returnValue,
                                              format::HandleId                                        device,
                                              StructPointerDecoder<Decoded_VkShaderModuleCreateInfo>* pCreateInfo,
                                              StructPointerDecoder<Decoded_VkAllocationCallbacks>*    pAllocator,
                                              HandlePointerDecoder<VkShaderModule>* pShaderModule) override;

    virtual void
    Process_vkCreateDescriptorSetLayout(const ApiCallInfo&                                             call_info,
                                        VkResult                                                       returnValue,
                                        format::HandleId                                               device,
                                        StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>* pCreateInfo,
                                        StructPointerDecoder<Decoded_VkAllocationCallbacks>*           pAllocator,
                                        HandlePointerDecoder<VkDescriptorSetLayout>* pSetLayout) override;

    virtual void
    Process_vkDestroyDescriptorSetLayout(const ApiCallInfo&                                   call_info,
                                         format::HandleId                                     device,
                                         format::HandleId                                     descriptorSetLayout,
                                         StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void Process_vkGetDescriptorSetLayoutSizeEXT(const ApiCallInfo&            call_info,
                                                         format::HandleId              device,
                                                         format::HandleId              layout,
                                                         PointerDecoder<VkDeviceSize>* pLayoutSizeInBytes) override;

    virtual void Process_vkGetDescriptorSetLayoutBindingOffsetEXT(const ApiCallInfo&            call_info,
                                                                  format::HandleId              device,
                                                                  format::HandleId              layout,
                                                                  uint32_t                      binding,
                                                                  PointerDecoder<VkDeviceSize>* pOffset) override;

    virtual void Process_vkCreateDescriptorPool(const ApiCallInfo&                                        call_info,
                                                VkResult                                                  returnValue,
                                                format::HandleId                                          device,
                                                StructPointerDecoder<Decoded_VkDescriptorPoolCreateInfo>* pCreateInfo,
                                                StructPointerDecoder<Decoded_VkAllocationCallbacks>*      pAllocator,
                                                HandlePointerDecoder<VkDescriptorPool>* pDescriptorPool) override;

    virtual void
    Process_vkDestroyDescriptorPool(const ApiCallInfo&                                   call_info,
                                    format::HandleId                                     device,
                                    format::HandleId                                     descriptorPool,
                                    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void
    Process_vkAllocateDescriptorSets(const ApiCallInfo&                                         call_info,
                                     VkResult                                                   returnValue,
                                     format::HandleId                                           device,
                                     StructPointerDecoder<Decoded_VkDescriptorSetAllocateInfo>* pAllocateInfo,
                                     HandlePointerDecoder<VkDescriptorSet>* pDescriptorSets) override;

    virtual void
    Process_vkUpdateDescriptorSets(const ApiCallInfo&                                  call_info,
                                   format::HandleId                                    device,
                                   uint32_t                                            descriptorWriteCount,
                                   StructPointerDecoder<Decoded_VkWriteDescriptorSet>* pDescriptorWrites,
                                   uint32_t                                            descriptorCopyCount,
                                   StructPointerDecoder<Decoded_VkCopyDescriptorSet>*  pDescriptorCopies) override;

    virtual void Process_vkCreatePipelineLayout(const ApiCallInfo&                                        call_info,
                                                VkResult                                                  returnValue,
                                                format::HandleId                                          device,
                                                StructPointerDecoder<Decoded_VkPipelineLayoutCreateInfo>* pCreateInfo,
                                                StructPointerDecoder<Decoded_VkAllocationCallbacks>*      pAllocator,
                                                HandlePointerDecoder<VkPipelineLayout>* pPipelineLayout) override;

    virtual void
    Process_vkDestroyPipelineLayout(const ApiCallInfo&                                   call_info,
                                    format::HandleId                                     device,
                                    format::HandleId                                     pipelineLayout,
                                    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void
    Process_vkCreateComputePipelines(const ApiCallInfo&                                         call_info,
                                     VkResult                                                   returnValue,
                                     format::HandleId                                           device,
                                     format::HandleId                                           pipelineCache,
                                     uint32_t                                                   createInfoCount,
                                     StructPointerDecoder<Decoded_VkComputePipelineCreateInfo>* pCreateInfos,
                                     StructPointerDecoder<Decoded_VkAllocationCallbacks>*       pAllocator,
                                     HandlePointerDecoder<VkPipeline>*                          pPipelines) override;

    virtual void
    Process_vkCreateGraphicsPipelines(const ApiCallInfo&                                          call_info,
                                      VkResult                                                    returnValue,
                                      format::HandleId                                            device,
                                      format::HandleId                                            pipelineCache,
                                      uint32_t                                                    createInfoCount,
                                      StructPointerDecoder<Decoded_VkGraphicsPipelineCreateInfo>* pCreateInfos,
                                      StructPointerDecoder<Decoded_VkAllocationCallbacks>*        pAllocator,
                                      HandlePointerDecoder<VkPipeline>*                           pPipelines) override;

    virtual void Process_vkDestroyPipeline(const ApiCallInfo&                                   call_info,
                                           format::HandleId                                     device,
                                           format::HandleId                                     pipeline,
                                           StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator) override;

    virtual void
    Process_vkAllocateCommandBuffers(const ApiCallInfo&                                         call_info,
                                     VkResult                                                   returnValue,
                                     format::HandleId                                           device,
                                     StructPointerDecoder<Decoded_VkCommandBufferAllocateInfo>* pAllocateInfo,
                                     HandlePointerDecoder<VkCommandBuffer>* pCommandBuffers) override;

    virtual void Process_vkFreeCommandBuffers(const ApiCallInfo&                     call_info,
                                              format::HandleId                       device,
                                              format::HandleId                       commandPool,
                                              uint32_t                               commandBufferCount,
                                              HandlePointerDecoder<VkCommandBuffer>* pCommandBuffers) override;

    virtual void Process_vkResetCommandBuffer(const ApiCallInfo&        call_info,
                                              VkResult                  returnValue,
                                              format::HandleId          commandBuffer,
                                              VkCommandBufferResetFlags flags) override;

    virtual void
    Process_vkBeginCommandBuffer(const ApiCallInfo&                                      call_info,
                                 VkResult                                                returnValue,
                                 format::HandleId                                        commandBuffer,
                                 StructPointerDecoder<Decoded_VkCommandBufferBeginInfo>* pBeginInfo) override;

    virtual void Process_vkEndCommandBuffer(const ApiCallInfo& call_info,
                                            VkResult           returnValue,
                                            format::HandleId   commandBuffer) override;

    virtual void
    Process_vkGetBufferDeviceAddress(const ApiCallInfo&                                       call_info,
                                     VkDeviceAddress                                          returnValue,
                                     format::HandleId                                         device,
                                     StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo) override;

    virtual void
    Process_vkGetBufferDeviceAddressKHR(const ApiCallInfo&                                       call_info,
                                        VkDeviceAddress                                          returnValue,
                                        format::HandleId                                         device,
                                        StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo) override;

    virtual void
    Process_vkGetBufferDeviceAddressEXT(const ApiCallInfo&                                       call_info,
                                        VkDeviceAddress                                          returnValue,
                                        format::HandleId                                         device,
                                        StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo) override;

    virtual void Process_vkGetAccelerationStructureDeviceAddressKHR(
        const ApiCallInfo&                                                         call_info,
        VkDeviceAddress                                                            returnValue,
        format::HandleId                                                           device,
        StructPointerDecoder<Decoded_VkAccelerationStructureDeviceAddressInfoKHR>* pInfo) override;

    virtual void Process_vkCmdBindPipeline(const ApiCallInfo&  call_info,
                                           format::HandleId    commandBuffer,
                                           VkPipelineBindPoint pipelineBindPoint,
                                           format::HandleId    pipeline) override;

    virtual void Process_vkCmdBindDescriptorSets(const ApiCallInfo&                     call_info,
                                                 format::HandleId                       commandBuffer,
                                                 VkPipelineBindPoint                    pipelineBindPoint,
                                                 format::HandleId                       layout,
                                                 uint32_t                               firstSet,
                                                 uint32_t                               descriptorSetCount,
                                                 HandlePointerDecoder<VkDescriptorSet>* pDescriptorSets,
                                                 uint32_t                               dynamicOffsetCount,
                                                 PointerDecoder<uint32_t>*              pDynamicOffsets) override;

    virtual void Process_vkCmdBindDescriptorBuffersEXT(
        const ApiCallInfo&                                              call_info,
        format::HandleId                                                commandBuffer,
        uint32_t                                                        bufferCount,
        StructPointerDecoder<Decoded_VkDescriptorBufferBindingInfoEXT>* pBindingInfos) override;

    virtual void Process_vkCmdSetDescriptorBufferOffsetsEXT(const ApiCallInfo&            call_info,
                                                            format::HandleId              commandBuffer,
                                                            VkPipelineBindPoint           pipelineBindPoint,
                                                            format::HandleId              layout,
                                                            uint32_t                      firstSet,
                                                            uint32_t                      setCount,
                                                            PointerDecoder<uint32_t>*     pBufferIndices,
                                                            PointerDecoder<VkDeviceSize>* pOffsets) override;

    virtual void Process_vkCmdPushConstants(const ApiCallInfo&       call_info,
                                            format::HandleId         commandBuffer,
                                            format::HandleId         layout,
                                            VkShaderStageFlags       stageFlags,
                                            uint32_t                 offset,
                                            uint32_t                 size,
                                            PointerDecoder<uint8_t>* pValues) override;

    virtual void Process_vkCmdFillBuffer(const ApiCallInfo& call_info,
                                         format::HandleId   commandBuffer,
                                         format::HandleId   dstBuffer,
                                         VkDeviceSize       dstOffset,
                                         VkDeviceSize       size,
                                         uint32_t           data) override;

    virtual void Process_vkCmdUpdateBuffer(const ApiCallInfo&       call_info,
                                           format::HandleId         commandBuffer,
                                           format::HandleId         dstBuffer,
                                           VkDeviceSize             dstOffset,
                                           VkDeviceSize             dataSize,
                                           PointerDecoder<uint8_t>* pData) override;

    virtual void Process_vkCmdCopyBuffer(const ApiCallInfo&                          call_info,
                                         format::HandleId                            commandBuffer,
                                         format::HandleId                            srcBuffer,
                                         format::HandleId                            dstBuffer,
                                         uint32_t                                    regionCount,
                                         StructPointerDecoder<Decoded_VkBufferCopy>* pRegions) override;

    virtual void Process_vkCmdCopyBuffer2(const ApiCallInfo&                               call_info,
                                          format::HandleId                                 commandBuffer,
                                          StructPointerDecoder<Decoded_VkCopyBufferInfo2>* pCopyBufferInfo) override;

    virtual void Process_vkCmdCopyBuffer2KHR(const ApiCallInfo&                               call_info,
                                             format::HandleId                                 commandBuffer,
                                             StructPointerDecoder<Decoded_VkCopyBufferInfo2>* pCopyBufferInfo) override;

    virtual void Process_vkCmdBuildAccelerationStructuresKHR(
        const ApiCallInfo&                                                         call_info,
        format::HandleId                                                           commandBuffer,
        uint32_t                                                                   infoCount,
        StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR>* pInfos,
        StructPointerDecoder<Decoded_VkAccelerationStructureBuildRangeInfoKHR*>*   ppBuildRangeInfos) override;

    virtual void Process_vkCmdDispatch(const ApiCallInfo& call_info,
                                       format::HandleId   commandBuffer,
                                       uint32_t           groupCountX,
                                       uint32_t           groupCountY,
                                       uint32_t           groupCountZ) override;

    virtual void Process_vkCmdDispatchIndirect(const ApiCallInfo& call_info,
                                               format::HandleId   commandBuffer,
                                               format::HandleId   buffer,
                                               VkDeviceSize       offset) override;

    virtual void Process_vkCmdDraw(const ApiCallInfo& call_info,
                                   format::HandleId   commandBuffer,
                                   uint32_t           vertexCount,
                                   uint32_t           instanceCount,
                                   uint32_t           firstVertex,
                                   uint32_t           firstInstance) override;

    virtual void Process_vkCmdDrawIndexed(const ApiCallInfo& call_info,
                                          format::HandleId   commandBuffer,
                                          uint32_t           indexCount,
                                          uint32_t           instanceCount,
                                          uint32_t           firstIndex,
                                          int32_t            vertexOffset,
                                          uint32_t           firstInstance) override;

    virtual void Process_vkCmdDrawIndirect(const ApiCallInfo& call_info,
                                           format::HandleId   commandBuffer,
                                           format::HandleId   buffer,
                                           VkDeviceSize       offset,
                                           uint32_t           drawCount,
                                           uint32_t           stride) override;

    virtual void Process_vkCmdDrawIndexedIndirect(const ApiCallInfo& call_info,
                                                  format::HandleId   commandBuffer,
                                                  format::HandleId   buffer,
                                                  VkDeviceSize       offset,
                                                  uint32_t           drawCount,
                                                  uint32_t           stride) override;

    virtual void Process_vkQueueSubmit(const ApiCallInfo&                          call_info,
                                       VkResult                                    returnValue,
                                       format::HandleId                            queue,
                                       uint32_t                                    submitCount,
                                       StructPointerDecoder<Decoded_VkSubmitInfo>* pSubmits,
                                       format::HandleId                            fence) override;

    virtual void Process_vkQueueSubmit2(const ApiCallInfo&                           call_info,
                                        VkResult                                     returnValue,
                                        format::HandleId                             queue,
                                        uint32_t                                     submitCount,
                                        StructPointerDecoder<Decoded_VkSubmitInfo2>* pSubmits,
                                        format::HandleId                             fence) override;

    virtual void Process_vkQueueSubmit2KHR(const ApiCallInfo&                           call_info,
                                           VkResult                                     returnValue,
                                           format::HandleId                             queue,
                                           uint32_t                                     submitCount,
                                           StructPointerDecoder<Decoded_VkSubmitInfo2>* pSubmits,
                                           format::HandleId                             fence) override;

  private:
    void process_SubmitInfo(uint64_t                             submitIndex,
                            const std::vector<format::HandleId>& commandBuffers,
                            const std::vector<format::HandleId>& waitSems     = {},
                            const std::vector<format::HandleId>& signalSems   = {},
                            const std::vector<uint64_t>&         waitValues   = {},
                            const std::vector<uint64_t>&         signalValues = {});

    void signalSemaphoresFrom(uint64_t submitIndex);

    void executeCommandBuffer(format::HandleId commandBuffer_id);
    void executeDispatchDraw(format::HandleId commandBuffer_id, VkPipelineBindPoint bindPoint);
    void outputSimulator(const SPIRVSimulator::SimulationData& data);

    void resetRecording(format::HandleId commandBuffer);

  private:
    struct ObjectInfo
    {
        format::HandleId handle;
        uint64_t         creation_index;
        uint64_t         destruction_index;
    };

    struct BufferInfo : public ObjectInfo
    {
        uint64_t             size;
        VkBufferUsageFlags   usage;
        VkBufferCreateFlags  flags;
        std::vector<uint8_t> data;
    };

    struct MemoryBindingRecord
    {
        format::HandleId handle;
        bool             isBuffer;
        VkDeviceSize     offset;
    };

    struct MemoryMapping
    {
        VkDeviceSize offset;
        VkDeviceSize size;
        uint64_t     map_memory;
        uint64_t     shadow_memory;
    };

    struct DeviceMemoryInfo : public ObjectInfo
    {
        uint64_t                         size;
        uint32_t                         type_index;
        VkMemoryAllocateFlags            flags;
        MemoryMapping                    mapping;
        std::vector<MemoryBindingRecord> memory_binding_records_;
    };

    enum class CommandBufferLifeCycle
    {
        Inital = 0,
        Recording,
        Executable,
        Pending,
        Invalid
    };
    struct CommandBufferInfo : public ObjectInfo
    {
        CommandBufferLifeCycle state;
    };

    struct AccelerationStructureInfo : public ObjectInfo
    {
        format::HandleId               buf_handle;
        uint64_t                       size;
        uint64_t                       offset;
        VkAccelerationStructureTypeKHR type;
        VkDeviceAddress                device_address;
    };

    struct ShaderModuleInfo : public ObjectInfo
    {
        size_t                codeSize;
        std::vector<uint32_t> pCode;
    };

    struct Binding
    {
        uint32_t                    binding;
        VkDescriptorType            type;
        uint32_t                    descriptorCount;
        VkShaderStageFlags          stageFlags;
        VkDescriptorBindingFlagsEXT binding_flags;
        // Binding offset for descriptor_buffer_bit flag. Unused otherwise.
        VkDeviceSize offset;
    };

    struct SetLayoutInfo : public ObjectInfo
    {
        VkDescriptorSetLayoutCreateFlags flags;
        // binding num -> binding info
        std::map<uint32_t, Binding> bindings;
        // descriptorSetLayout size when creating for descriptor buffer. Unused otherwise.
        VkDeviceSize                  size;
    };

    struct DescriptorPoolInfo : public ObjectInfo
    {
        std::vector<format::HandleId> descriptorSets;
    };

    struct DescriptorEntry
    {
        VkDescriptorType type;
        union
        {
            struct
            {
                format::HandleId handle;
                VkDeviceSize     range;
                VkDeviceSize     offset;
            } buffer;
            struct
            {
                format::HandleId handle;
            } acceleration;
        };
    };

    struct DescriptorArray : public Binding
    {
        // array index of descriptors -> descriptor entry
        std::map<uint32_t, DescriptorEntry> descriptor_entries;
    };

    struct DescriptorSetInfo : public ObjectInfo
    {
        // binding -> descriptors updated on the binding
        std::map<uint32_t, DescriptorArray> binding_descriptor_array;
    };

    struct DynamicBindingRef
    {
        uint32_t         set;
        uint32_t         binding;
        uint32_t         start_index;
        uint32_t         elementCount;
        VkDescriptorType type;
    };

    struct PipelineLayoutInfo : public ObjectInfo
    {
        // index:set number -> setLayout Id
        std::vector<format::HandleId>    setLayouts;
        // set number -> dynamic Ref
        std::unordered_map<uint32_t, std::vector<DynamicBindingRef>> dynamicBindingRef;

        std::vector<VkPushConstantRange> pushConstantRanges;
        struct Range
        {
            uint32_t offset;
            uint32_t size;
        };
        std::unordered_map<VkShaderStageFlagBits, std::vector<uint32_t>> rangeIndicesPerStage;
        std::unordered_map<VkShaderStageFlagBits, Range>                 mergedRangePerStage;
    };

    struct ShaderStage
    {
        std::string                          pName;
        format::HandleId                     module;
        VkShaderStageFlagBits                stageFlagBit;
        size_t                               specialization_dataSize;
        std::vector<uint8_t>                 specialization_constant;
        std::unordered_map<uint32_t, size_t> specialization_offset_entries;
    };

    struct PipelineInfo : public ObjectInfo
    {
        format::HandleId         layout;
        std::vector<ShaderStage> stages;
    };

    // used for BindDescriptorBufferEXT
    struct DescriptorBufferBindingInfo
    {
        format::HandleId   handle;  // descriptor buffer handle
        VkDeviceAddress    address; // descriptor buffer address
        VkBufferUsageFlags usage;
    };

    // used for SetDescriptorBufferOffsetEXT()
    struct DescriptorBufferOffset
    {
        uint32_t     buffer_index; // the index of descriptor buffer array in CmdBindDescriptorBuffers
        VkDeviceSize offset;
    };

    enum class SourceType
    {
        HostMemory = 0,
        CopyBuffer,
        Update,
        Fill,
        Dispatch,
        Unknow
    };

    struct BufferWriteEvent
    {
        SourceType                sourceType;
        format::HandleId          buffer;
        format::HandleId          srcBuffer;
        std::vector<uint8_t>      srcPointer;
        std::vector<VkBufferCopy> regions;
    };

    struct AccelerationStructureBuildInfo
    {
        // per geometry
        std::vector<std::pair<format::HandleId, uint64_t>> instance_buffers;
        std::vector<uint32_t>                              primitive_counts;
        std::vector<uint32_t>                              primitive_offsets;
    };

    struct PushConstantData
    {
        uint32_t             offset;
        uint32_t             size;
        VkShaderStageFlags   stageFlags;
        format::HandleId     layout;
        std::vector<uint8_t> pValues;
    };

    struct DescriptorSetMap
    {
        uint64_t         set;
        format::HandleId descriptor_set;
        format::HandleId layout;
    };

    struct DynamicBindingOffsetMap
    {
        uint32_t         set;
        format::HandleId layout;
        // binding -> offsets array, ordered map
        std::map<uint32_t, std::vector<uint32_t>> binding_offsets;
    };

    struct CommandBufferRecording
    {
        format::HandleId    command_buffer = 0;
        VkPipelineBindPoint bind_point     = VK_PIPELINE_BIND_POINT_MAX_ENUM;
        bool                in_operation   = false;

        std::vector<PushConstantData> push_constants;

        // bind point -> pipeline handle
        std::unordered_map<VkPipelineBindPoint, format::HandleId> pipelines;
        // bind point -> array of descriptorSet map
        std::unordered_map<VkPipelineBindPoint, std::vector<DescriptorSetMap>> descriptor_sets;
        // bind point -> array of DynamicBindingOffset map
        std::unordered_map<VkPipelineBindPoint, std::vector<DynamicBindingOffsetMap>> dynamic_offsets;

        std::vector<DescriptorBufferBindingInfo> descriptor_buffers;

        // index of bound descriptor buffers -> valid or not
        // invalidate the offset once rebinding the descriptor buffer
        std::unordered_map<uint32_t, bool> descriptor_offset_valid;

        std::vector<BufferWriteEvent> buffer_write_list;

        ////////////////////////////////////
        // bind point -> pipeline layout handle -> set num -> DescriptorBufferOffset
        std::unordered_map<VkPipelineBindPoint,
                           std::unordered_map<format::HandleId, std::unordered_map<uint64_t, DescriptorBufferOffset>>>
            layout_bind_descriptorOffsets;

        // acceleration structure handle -> AS build info
        std::unordered_map<format::HandleId, AccelerationStructureBuildInfo> build_acceleration_structure;
    };

    struct BindPointState
    {
        format::HandleId pipeline;
        format::HandleId pipeline_layout;

        // set num -> descriptorSet handle
        std::unordered_map<uint64_t, format::HandleId> descriptor_set_map;
        // dynamic offsets
        std::vector<uint32_t> dynamic_offsets;
        // set num -> array of dynamic offsets. Auxiliary function
        std::map<uint32_t, std::vector<uint32_t>> dynamic_offsets_perSet;
        // set num -> binding -> dynamic offset count, used to check compatibility
        std::unordered_map<uint32_t, std::unordered_map<uint32_t, uint32_t>> dynamic_offsets_count;
        // set num -> DescriptorBufferOffset
        std::unordered_map<uint64_t, DescriptorBufferOffset> descriptorOffsets;
    };

    struct CommandBufferState
    {
        format::HandleId                                        command_buffer;
        std::vector<uint8_t>                                    push_constant;
        std::unordered_map<VkPipelineBindPoint, BindPointState> bind_point_state;
    };

    // Semaphore state tracker
    struct BinarySemaphoreState
    {
        bool                 signaled         = false;
        uint32_t             signaledBySubmit = 0;
        std::deque<uint64_t> waitingSubmits; // submit indices in submission order
    };
    struct TimelineSemaphoreState
    {
        uint64_t currentValue = 0;
        // pair<submit index, requiredValue>
        std::deque<std::pair<uint64_t, uint64_t>> waitingSubmits;
    };
    struct SemaphoreState
    {
        VkSemaphoreType                                            type;
        std::variant<BinarySemaphoreState, TimelineSemaphoreState> state;
        SemaphoreState() : type(VK_SEMAPHORE_TYPE_BINARY), state(BinarySemaphoreState{}) {}
    };

    // Per-submit metadata
    struct SubmitInfo
    {
        uint32_t submit_index; // API sequence index

        std::vector<format::HandleId> command_buffers;
        std::vector<format::HandleId> wait_semaphores;
        std::vector<format::HandleId> signal_semaphores;

        std::vector<uint64_t> wait_values;   // timeline values (same index as wait_semaphores)
        std::vector<uint64_t> signal_values; // timeline values (same index as signal_semaphores)

        bool submitted = false;
        bool ready     = false;
    };

  private:
    // handle id -> obj info
    std::unordered_map<format::HandleId, BufferInfo>                buffer_entries_;
    std::unordered_map<format::HandleId, DeviceMemoryInfo>          memory_binding_entries_;
    std::unordered_map<format::HandleId, CommandBufferInfo>         command_buffer_entries_;
    std::unordered_map<format::HandleId, AccelerationStructureInfo> acceleration_structure_entries_;
    std::unordered_map<format::HandleId, PipelineInfo>              pipeline_entries_;
    std::unordered_map<format::HandleId, PipelineLayoutInfo>        pipeline_layout_entries_;
    std::unordered_map<format::HandleId, ShaderModuleInfo>          shader_module_entries_;
    std::unordered_map<format::HandleId, SetLayoutInfo>             set_layout_entries_;
    std::unordered_map<format::HandleId, DescriptorPoolInfo>        descriptor_pool_entries_;
    std::unordered_map<format::HandleId, DescriptorSetInfo>         descriptor_set_entries_;

    // buffer device address -> buffer handle
    std::unordered_map<VkDeviceAddress, format::HandleId> buffer_device_addresses_;

    // acceleration structure device address -> as handle
    std::unordered_map<VkDeviceAddress, format::HandleId> acceleration_structure_device_addresses_;

    std::unordered_map<format::HandleId, CommandBufferRecording> command_buffer_recording;

    // command buffer handle -> recording status per dispatch/draw call
    std::unordered_map<format::HandleId, std::vector<CommandBufferRecording>> command_buffer_submit_recordings;

    // command buffer handle -> executing state of command buffer
    std::unordered_map<format::HandleId, CommandBufferState> command_buffer_state;

    uint64_t global_submit_index = 0;

    // global unique submit index -> submit info
    std::unordered_map<uint64_t, SubmitInfo>             submit_entries_;
    std::unordered_map<format::HandleId, SemaphoreState> semaphore_state;
    std::deque<uint64_t>                                 ready_submits; // submit index

    // for internal debug
    uint64_t global_draw_index = 0;
    bool     m_verbose         = false;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_TOOLS_OPTIMIZE_VULKAN_SPIRV_TRACK_MODIFIER_H