/*
** Copyright (c) 2021 Samsung
** Copyright (c) 2023 Google
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

/*
** This file is generated from the Khronos Vulkan XML API Registry.
**
*/

#pragma once

#include "util/defines.h"
#include "vulkan/vulkan.h"
#include "vk_video/vulkan_video_codec_h264std.h"
#include "vk_video/vulkan_video_codec_h264std_decode.h"
#include "vk_video/vulkan_video_codec_h264std_encode.h"
#include "vk_video/vulkan_video_codec_h265std.h"
#include "vk_video/vulkan_video_codec_h265std_decode.h"
#include "vk_video/vulkan_video_codec_h265std_encode.h"
#include "vk_video/vulkan_video_codecs_common.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

std::string GenerateStruct_StdVideoH264SpsVuiFlags(std::ostream &out, const StdVideoH264SpsVuiFlags* structInfo, Decoded_StdVideoH264SpsVuiFlags* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoH264HrdParameters(std::ostream &out, const StdVideoH264HrdParameters* structInfo, Decoded_StdVideoH264HrdParameters* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoH264SequenceParameterSetVui(std::ostream &out, const StdVideoH264SequenceParameterSetVui* structInfo, Decoded_StdVideoH264SequenceParameterSetVui* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoH264SpsFlags(std::ostream &out, const StdVideoH264SpsFlags* structInfo, Decoded_StdVideoH264SpsFlags* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoH264ScalingLists(std::ostream &out, const StdVideoH264ScalingLists* structInfo, Decoded_StdVideoH264ScalingLists* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoH264SequenceParameterSet(std::ostream &out, const StdVideoH264SequenceParameterSet* structInfo, Decoded_StdVideoH264SequenceParameterSet* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoH264PpsFlags(std::ostream &out, const StdVideoH264PpsFlags* structInfo, Decoded_StdVideoH264PpsFlags* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoH264PictureParameterSet(std::ostream &out, const StdVideoH264PictureParameterSet* structInfo, Decoded_StdVideoH264PictureParameterSet* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoDecodeH264PictureInfoFlags(std::ostream &out, const StdVideoDecodeH264PictureInfoFlags* structInfo, Decoded_StdVideoDecodeH264PictureInfoFlags* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoDecodeH264PictureInfo(std::ostream &out, const StdVideoDecodeH264PictureInfo* structInfo, Decoded_StdVideoDecodeH264PictureInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoDecodeH264ReferenceInfoFlags(std::ostream &out, const StdVideoDecodeH264ReferenceInfoFlags* structInfo, Decoded_StdVideoDecodeH264ReferenceInfoFlags* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoDecodeH264ReferenceInfo(std::ostream &out, const StdVideoDecodeH264ReferenceInfo* structInfo, Decoded_StdVideoDecodeH264ReferenceInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoEncodeH264WeightTableFlags(std::ostream &out, const StdVideoEncodeH264WeightTableFlags* structInfo, Decoded_StdVideoEncodeH264WeightTableFlags* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoEncodeH264WeightTable(std::ostream &out, const StdVideoEncodeH264WeightTable* structInfo, Decoded_StdVideoEncodeH264WeightTable* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoEncodeH264SliceHeaderFlags(std::ostream &out, const StdVideoEncodeH264SliceHeaderFlags* structInfo, Decoded_StdVideoEncodeH264SliceHeaderFlags* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoEncodeH264PictureInfoFlags(std::ostream &out, const StdVideoEncodeH264PictureInfoFlags* structInfo, Decoded_StdVideoEncodeH264PictureInfoFlags* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoEncodeH264ReferenceInfoFlags(std::ostream &out, const StdVideoEncodeH264ReferenceInfoFlags* structInfo, Decoded_StdVideoEncodeH264ReferenceInfoFlags* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoEncodeH264ReferenceListsInfoFlags(std::ostream &out, const StdVideoEncodeH264ReferenceListsInfoFlags* structInfo, Decoded_StdVideoEncodeH264ReferenceListsInfoFlags* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoEncodeH264RefListModEntry(std::ostream &out, const StdVideoEncodeH264RefListModEntry* structInfo, Decoded_StdVideoEncodeH264RefListModEntry* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoEncodeH264RefPicMarkingEntry(std::ostream &out, const StdVideoEncodeH264RefPicMarkingEntry* structInfo, Decoded_StdVideoEncodeH264RefPicMarkingEntry* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoEncodeH264ReferenceListsInfo(std::ostream &out, const StdVideoEncodeH264ReferenceListsInfo* structInfo, Decoded_StdVideoEncodeH264ReferenceListsInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoEncodeH264PictureInfo(std::ostream &out, const StdVideoEncodeH264PictureInfo* structInfo, Decoded_StdVideoEncodeH264PictureInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoEncodeH264ReferenceInfo(std::ostream &out, const StdVideoEncodeH264ReferenceInfo* structInfo, Decoded_StdVideoEncodeH264ReferenceInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoEncodeH264SliceHeader(std::ostream &out, const StdVideoEncodeH264SliceHeader* structInfo, Decoded_StdVideoEncodeH264SliceHeader* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoH265ProfileTierLevelFlags(std::ostream &out, const StdVideoH265ProfileTierLevelFlags* structInfo, Decoded_StdVideoH265ProfileTierLevelFlags* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoH265ProfileTierLevel(std::ostream &out, const StdVideoH265ProfileTierLevel* structInfo, Decoded_StdVideoH265ProfileTierLevel* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoH265DecPicBufMgr(std::ostream &out, const StdVideoH265DecPicBufMgr* structInfo, Decoded_StdVideoH265DecPicBufMgr* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoH265SubLayerHrdParameters(std::ostream &out, const StdVideoH265SubLayerHrdParameters* structInfo, Decoded_StdVideoH265SubLayerHrdParameters* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoH265HrdFlags(std::ostream &out, const StdVideoH265HrdFlags* structInfo, Decoded_StdVideoH265HrdFlags* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoH265HrdParameters(std::ostream &out, const StdVideoH265HrdParameters* structInfo, Decoded_StdVideoH265HrdParameters* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoH265VpsFlags(std::ostream &out, const StdVideoH265VpsFlags* structInfo, Decoded_StdVideoH265VpsFlags* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoH265VideoParameterSet(std::ostream &out, const StdVideoH265VideoParameterSet* structInfo, Decoded_StdVideoH265VideoParameterSet* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoH265ScalingLists(std::ostream &out, const StdVideoH265ScalingLists* structInfo, Decoded_StdVideoH265ScalingLists* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoH265ShortTermRefPicSetFlags(std::ostream &out, const StdVideoH265ShortTermRefPicSetFlags* structInfo, Decoded_StdVideoH265ShortTermRefPicSetFlags* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoH265ShortTermRefPicSet(std::ostream &out, const StdVideoH265ShortTermRefPicSet* structInfo, Decoded_StdVideoH265ShortTermRefPicSet* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoH265LongTermRefPicsSps(std::ostream &out, const StdVideoH265LongTermRefPicsSps* structInfo, Decoded_StdVideoH265LongTermRefPicsSps* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoH265SpsVuiFlags(std::ostream &out, const StdVideoH265SpsVuiFlags* structInfo, Decoded_StdVideoH265SpsVuiFlags* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoH265SequenceParameterSetVui(std::ostream &out, const StdVideoH265SequenceParameterSetVui* structInfo, Decoded_StdVideoH265SequenceParameterSetVui* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoH265PredictorPaletteEntries(std::ostream &out, const StdVideoH265PredictorPaletteEntries* structInfo, Decoded_StdVideoH265PredictorPaletteEntries* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoH265SpsFlags(std::ostream &out, const StdVideoH265SpsFlags* structInfo, Decoded_StdVideoH265SpsFlags* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoH265SequenceParameterSet(std::ostream &out, const StdVideoH265SequenceParameterSet* structInfo, Decoded_StdVideoH265SequenceParameterSet* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoH265PpsFlags(std::ostream &out, const StdVideoH265PpsFlags* structInfo, Decoded_StdVideoH265PpsFlags* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoH265PictureParameterSet(std::ostream &out, const StdVideoH265PictureParameterSet* structInfo, Decoded_StdVideoH265PictureParameterSet* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoDecodeH265PictureInfoFlags(std::ostream &out, const StdVideoDecodeH265PictureInfoFlags* structInfo, Decoded_StdVideoDecodeH265PictureInfoFlags* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoDecodeH265PictureInfo(std::ostream &out, const StdVideoDecodeH265PictureInfo* structInfo, Decoded_StdVideoDecodeH265PictureInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoDecodeH265ReferenceInfoFlags(std::ostream &out, const StdVideoDecodeH265ReferenceInfoFlags* structInfo, Decoded_StdVideoDecodeH265ReferenceInfoFlags* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoDecodeH265ReferenceInfo(std::ostream &out, const StdVideoDecodeH265ReferenceInfo* structInfo, Decoded_StdVideoDecodeH265ReferenceInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoEncodeH265WeightTableFlags(std::ostream &out, const StdVideoEncodeH265WeightTableFlags* structInfo, Decoded_StdVideoEncodeH265WeightTableFlags* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoEncodeH265WeightTable(std::ostream &out, const StdVideoEncodeH265WeightTable* structInfo, Decoded_StdVideoEncodeH265WeightTable* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoEncodeH265LongTermRefPics(std::ostream &out, const StdVideoEncodeH265LongTermRefPics* structInfo, Decoded_StdVideoEncodeH265LongTermRefPics* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoEncodeH265SliceSegmentHeaderFlags(std::ostream &out, const StdVideoEncodeH265SliceSegmentHeaderFlags* structInfo, Decoded_StdVideoEncodeH265SliceSegmentHeaderFlags* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoEncodeH265SliceSegmentHeader(std::ostream &out, const StdVideoEncodeH265SliceSegmentHeader* structInfo, Decoded_StdVideoEncodeH265SliceSegmentHeader* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoEncodeH265ReferenceListsInfoFlags(std::ostream &out, const StdVideoEncodeH265ReferenceListsInfoFlags* structInfo, Decoded_StdVideoEncodeH265ReferenceListsInfoFlags* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoEncodeH265ReferenceListsInfo(std::ostream &out, const StdVideoEncodeH265ReferenceListsInfo* structInfo, Decoded_StdVideoEncodeH265ReferenceListsInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoEncodeH265PictureInfoFlags(std::ostream &out, const StdVideoEncodeH265PictureInfoFlags* structInfo, Decoded_StdVideoEncodeH265PictureInfoFlags* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoEncodeH265PictureInfo(std::ostream &out, const StdVideoEncodeH265PictureInfo* structInfo, Decoded_StdVideoEncodeH265PictureInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoEncodeH265ReferenceInfoFlags(std::ostream &out, const StdVideoEncodeH265ReferenceInfoFlags* structInfo, Decoded_StdVideoEncodeH265ReferenceInfoFlags* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_StdVideoEncodeH265ReferenceInfo(std::ostream &out, const StdVideoEncodeH265ReferenceInfo* structInfo, Decoded_StdVideoEncodeH265ReferenceInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkExtent2D(std::ostream &out, const VkExtent2D* structInfo, Decoded_VkExtent2D* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkExtent3D(std::ostream &out, const VkExtent3D* structInfo, Decoded_VkExtent3D* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkOffset2D(std::ostream &out, const VkOffset2D* structInfo, Decoded_VkOffset2D* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkOffset3D(std::ostream &out, const VkOffset3D* structInfo, Decoded_VkOffset3D* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkRect2D(std::ostream &out, const VkRect2D* structInfo, Decoded_VkRect2D* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkBufferMemoryBarrier(std::ostream &out, const VkBufferMemoryBarrier* structInfo, Decoded_VkBufferMemoryBarrier* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDispatchIndirectCommand(std::ostream &out, const VkDispatchIndirectCommand* structInfo, Decoded_VkDispatchIndirectCommand* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDrawIndexedIndirectCommand(std::ostream &out, const VkDrawIndexedIndirectCommand* structInfo, Decoded_VkDrawIndexedIndirectCommand* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDrawIndirectCommand(std::ostream &out, const VkDrawIndirectCommand* structInfo, Decoded_VkDrawIndirectCommand* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImageSubresourceRange(std::ostream &out, const VkImageSubresourceRange* structInfo, Decoded_VkImageSubresourceRange* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImageMemoryBarrier(std::ostream &out, const VkImageMemoryBarrier* structInfo, Decoded_VkImageMemoryBarrier* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMemoryBarrier(std::ostream &out, const VkMemoryBarrier* structInfo, Decoded_VkMemoryBarrier* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineCacheHeaderVersionOne(std::ostream &out, const VkPipelineCacheHeaderVersionOne* structInfo, Decoded_VkPipelineCacheHeaderVersionOne* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAllocationCallbacks(std::ostream &out, const VkAllocationCallbacks* structInfo, Decoded_VkAllocationCallbacks* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkApplicationInfo(std::ostream &out, const VkApplicationInfo* structInfo, Decoded_VkApplicationInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkFormatProperties(std::ostream &out, const VkFormatProperties* structInfo, Decoded_VkFormatProperties* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImageFormatProperties(std::ostream &out, const VkImageFormatProperties* structInfo, Decoded_VkImageFormatProperties* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkInstanceCreateInfo(std::ostream &out, const VkInstanceCreateInfo* structInfo, Decoded_VkInstanceCreateInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMemoryHeap(std::ostream &out, const VkMemoryHeap* structInfo, Decoded_VkMemoryHeap* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMemoryType(std::ostream &out, const VkMemoryType* structInfo, Decoded_VkMemoryType* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceFeatures(std::ostream &out, const VkPhysicalDeviceFeatures* structInfo, Decoded_VkPhysicalDeviceFeatures* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceLimits(std::ostream &out, const VkPhysicalDeviceLimits* structInfo, Decoded_VkPhysicalDeviceLimits* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceMemoryProperties(std::ostream &out, const VkPhysicalDeviceMemoryProperties* structInfo, Decoded_VkPhysicalDeviceMemoryProperties* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceSparseProperties(std::ostream &out, const VkPhysicalDeviceSparseProperties* structInfo, Decoded_VkPhysicalDeviceSparseProperties* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceProperties(std::ostream &out, const VkPhysicalDeviceProperties* structInfo, Decoded_VkPhysicalDeviceProperties* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkQueueFamilyProperties(std::ostream &out, const VkQueueFamilyProperties* structInfo, Decoded_VkQueueFamilyProperties* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDeviceQueueCreateInfo(std::ostream &out, const VkDeviceQueueCreateInfo* structInfo, Decoded_VkDeviceQueueCreateInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDeviceCreateInfo(std::ostream &out, const VkDeviceCreateInfo* structInfo, Decoded_VkDeviceCreateInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkExtensionProperties(std::ostream &out, const VkExtensionProperties* structInfo, Decoded_VkExtensionProperties* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkLayerProperties(std::ostream &out, const VkLayerProperties* structInfo, Decoded_VkLayerProperties* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSubmitInfo(std::ostream &out, const VkSubmitInfo* structInfo, Decoded_VkSubmitInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMappedMemoryRange(std::ostream &out, const VkMappedMemoryRange* structInfo, Decoded_VkMappedMemoryRange* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMemoryAllocateInfo(std::ostream &out, const VkMemoryAllocateInfo* structInfo, Decoded_VkMemoryAllocateInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMemoryRequirements(std::ostream &out, const VkMemoryRequirements* structInfo, Decoded_VkMemoryRequirements* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSparseMemoryBind(std::ostream &out, const VkSparseMemoryBind* structInfo, Decoded_VkSparseMemoryBind* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSparseBufferMemoryBindInfo(std::ostream &out, const VkSparseBufferMemoryBindInfo* structInfo, Decoded_VkSparseBufferMemoryBindInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSparseImageOpaqueMemoryBindInfo(std::ostream &out, const VkSparseImageOpaqueMemoryBindInfo* structInfo, Decoded_VkSparseImageOpaqueMemoryBindInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImageSubresource(std::ostream &out, const VkImageSubresource* structInfo, Decoded_VkImageSubresource* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSparseImageMemoryBind(std::ostream &out, const VkSparseImageMemoryBind* structInfo, Decoded_VkSparseImageMemoryBind* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSparseImageMemoryBindInfo(std::ostream &out, const VkSparseImageMemoryBindInfo* structInfo, Decoded_VkSparseImageMemoryBindInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkBindSparseInfo(std::ostream &out, const VkBindSparseInfo* structInfo, Decoded_VkBindSparseInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSparseImageFormatProperties(std::ostream &out, const VkSparseImageFormatProperties* structInfo, Decoded_VkSparseImageFormatProperties* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSparseImageMemoryRequirements(std::ostream &out, const VkSparseImageMemoryRequirements* structInfo, Decoded_VkSparseImageMemoryRequirements* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkFenceCreateInfo(std::ostream &out, const VkFenceCreateInfo* structInfo, Decoded_VkFenceCreateInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSemaphoreCreateInfo(std::ostream &out, const VkSemaphoreCreateInfo* structInfo, Decoded_VkSemaphoreCreateInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkEventCreateInfo(std::ostream &out, const VkEventCreateInfo* structInfo, Decoded_VkEventCreateInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkQueryPoolCreateInfo(std::ostream &out, const VkQueryPoolCreateInfo* structInfo, Decoded_VkQueryPoolCreateInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkBufferCreateInfo(std::ostream &out, const VkBufferCreateInfo* structInfo, Decoded_VkBufferCreateInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkBufferViewCreateInfo(std::ostream &out, const VkBufferViewCreateInfo* structInfo, Decoded_VkBufferViewCreateInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImageCreateInfo(std::ostream &out, const VkImageCreateInfo* structInfo, Decoded_VkImageCreateInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSubresourceLayout(std::ostream &out, const VkSubresourceLayout* structInfo, Decoded_VkSubresourceLayout* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkComponentMapping(std::ostream &out, const VkComponentMapping* structInfo, Decoded_VkComponentMapping* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImageViewCreateInfo(std::ostream &out, const VkImageViewCreateInfo* structInfo, Decoded_VkImageViewCreateInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkShaderModuleCreateInfo(std::ostream &out, const VkShaderModuleCreateInfo* structInfo, Decoded_VkShaderModuleCreateInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineCacheCreateInfo(std::ostream &out, const VkPipelineCacheCreateInfo* structInfo, Decoded_VkPipelineCacheCreateInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSpecializationMapEntry(std::ostream &out, const VkSpecializationMapEntry* structInfo, Decoded_VkSpecializationMapEntry* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSpecializationInfo(std::ostream &out, const VkSpecializationInfo* structInfo, Decoded_VkSpecializationInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineShaderStageCreateInfo(std::ostream &out, const VkPipelineShaderStageCreateInfo* structInfo, Decoded_VkPipelineShaderStageCreateInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkComputePipelineCreateInfo(std::ostream &out, const VkComputePipelineCreateInfo* structInfo, Decoded_VkComputePipelineCreateInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVertexInputBindingDescription(std::ostream &out, const VkVertexInputBindingDescription* structInfo, Decoded_VkVertexInputBindingDescription* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVertexInputAttributeDescription(std::ostream &out, const VkVertexInputAttributeDescription* structInfo, Decoded_VkVertexInputAttributeDescription* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineVertexInputStateCreateInfo(std::ostream &out, const VkPipelineVertexInputStateCreateInfo* structInfo, Decoded_VkPipelineVertexInputStateCreateInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineInputAssemblyStateCreateInfo(std::ostream &out, const VkPipelineInputAssemblyStateCreateInfo* structInfo, Decoded_VkPipelineInputAssemblyStateCreateInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineTessellationStateCreateInfo(std::ostream &out, const VkPipelineTessellationStateCreateInfo* structInfo, Decoded_VkPipelineTessellationStateCreateInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkViewport(std::ostream &out, const VkViewport* structInfo, Decoded_VkViewport* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineViewportStateCreateInfo(std::ostream &out, const VkPipelineViewportStateCreateInfo* structInfo, Decoded_VkPipelineViewportStateCreateInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineRasterizationStateCreateInfo(std::ostream &out, const VkPipelineRasterizationStateCreateInfo* structInfo, Decoded_VkPipelineRasterizationStateCreateInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineMultisampleStateCreateInfo(std::ostream &out, const VkPipelineMultisampleStateCreateInfo* structInfo, Decoded_VkPipelineMultisampleStateCreateInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkStencilOpState(std::ostream &out, const VkStencilOpState* structInfo, Decoded_VkStencilOpState* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineDepthStencilStateCreateInfo(std::ostream &out, const VkPipelineDepthStencilStateCreateInfo* structInfo, Decoded_VkPipelineDepthStencilStateCreateInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineColorBlendAttachmentState(std::ostream &out, const VkPipelineColorBlendAttachmentState* structInfo, Decoded_VkPipelineColorBlendAttachmentState* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineColorBlendStateCreateInfo(std::ostream &out, const VkPipelineColorBlendStateCreateInfo* structInfo, Decoded_VkPipelineColorBlendStateCreateInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineDynamicStateCreateInfo(std::ostream &out, const VkPipelineDynamicStateCreateInfo* structInfo, Decoded_VkPipelineDynamicStateCreateInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkGraphicsPipelineCreateInfo(std::ostream &out, const VkGraphicsPipelineCreateInfo* structInfo, Decoded_VkGraphicsPipelineCreateInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPushConstantRange(std::ostream &out, const VkPushConstantRange* structInfo, Decoded_VkPushConstantRange* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineLayoutCreateInfo(std::ostream &out, const VkPipelineLayoutCreateInfo* structInfo, Decoded_VkPipelineLayoutCreateInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSamplerCreateInfo(std::ostream &out, const VkSamplerCreateInfo* structInfo, Decoded_VkSamplerCreateInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkCopyDescriptorSet(std::ostream &out, const VkCopyDescriptorSet* structInfo, Decoded_VkCopyDescriptorSet* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDescriptorBufferInfo(std::ostream &out, const VkDescriptorBufferInfo* structInfo, Decoded_VkDescriptorBufferInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDescriptorPoolSize(std::ostream &out, const VkDescriptorPoolSize* structInfo, Decoded_VkDescriptorPoolSize* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDescriptorPoolCreateInfo(std::ostream &out, const VkDescriptorPoolCreateInfo* structInfo, Decoded_VkDescriptorPoolCreateInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDescriptorSetAllocateInfo(std::ostream &out, const VkDescriptorSetAllocateInfo* structInfo, Decoded_VkDescriptorSetAllocateInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDescriptorSetLayoutBinding(std::ostream &out, const VkDescriptorSetLayoutBinding* structInfo, Decoded_VkDescriptorSetLayoutBinding* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDescriptorSetLayoutCreateInfo(std::ostream &out, const VkDescriptorSetLayoutCreateInfo* structInfo, Decoded_VkDescriptorSetLayoutCreateInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAttachmentDescription(std::ostream &out, const VkAttachmentDescription* structInfo, Decoded_VkAttachmentDescription* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAttachmentReference(std::ostream &out, const VkAttachmentReference* structInfo, Decoded_VkAttachmentReference* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkFramebufferCreateInfo(std::ostream &out, const VkFramebufferCreateInfo* structInfo, Decoded_VkFramebufferCreateInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSubpassDescription(std::ostream &out, const VkSubpassDescription* structInfo, Decoded_VkSubpassDescription* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSubpassDependency(std::ostream &out, const VkSubpassDependency* structInfo, Decoded_VkSubpassDependency* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkRenderPassCreateInfo(std::ostream &out, const VkRenderPassCreateInfo* structInfo, Decoded_VkRenderPassCreateInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkCommandPoolCreateInfo(std::ostream &out, const VkCommandPoolCreateInfo* structInfo, Decoded_VkCommandPoolCreateInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkCommandBufferAllocateInfo(std::ostream &out, const VkCommandBufferAllocateInfo* structInfo, Decoded_VkCommandBufferAllocateInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkCommandBufferInheritanceInfo(std::ostream &out, const VkCommandBufferInheritanceInfo* structInfo, Decoded_VkCommandBufferInheritanceInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkCommandBufferBeginInfo(std::ostream &out, const VkCommandBufferBeginInfo* structInfo, Decoded_VkCommandBufferBeginInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkBufferCopy(std::ostream &out, const VkBufferCopy* structInfo, Decoded_VkBufferCopy* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImageSubresourceLayers(std::ostream &out, const VkImageSubresourceLayers* structInfo, Decoded_VkImageSubresourceLayers* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkBufferImageCopy(std::ostream &out, const VkBufferImageCopy* structInfo, Decoded_VkBufferImageCopy* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkClearDepthStencilValue(std::ostream &out, const VkClearDepthStencilValue* structInfo, Decoded_VkClearDepthStencilValue* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkClearAttachment(std::ostream &out, const VkClearAttachment* structInfo, Decoded_VkClearAttachment* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkClearRect(std::ostream &out, const VkClearRect* structInfo, Decoded_VkClearRect* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImageBlit(std::ostream &out, const VkImageBlit* structInfo, Decoded_VkImageBlit* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImageCopy(std::ostream &out, const VkImageCopy* structInfo, Decoded_VkImageCopy* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImageResolve(std::ostream &out, const VkImageResolve* structInfo, Decoded_VkImageResolve* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkRenderPassBeginInfo(std::ostream &out, const VkRenderPassBeginInfo* structInfo, Decoded_VkRenderPassBeginInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceSubgroupProperties(std::ostream &out, const VkPhysicalDeviceSubgroupProperties* structInfo, Decoded_VkPhysicalDeviceSubgroupProperties* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkBindBufferMemoryInfo(std::ostream &out, const VkBindBufferMemoryInfo* structInfo, Decoded_VkBindBufferMemoryInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkBindImageMemoryInfo(std::ostream &out, const VkBindImageMemoryInfo* structInfo, Decoded_VkBindImageMemoryInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDevice16BitStorageFeatures(std::ostream &out, const VkPhysicalDevice16BitStorageFeatures* structInfo, Decoded_VkPhysicalDevice16BitStorageFeatures* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMemoryDedicatedRequirements(std::ostream &out, const VkMemoryDedicatedRequirements* structInfo, Decoded_VkMemoryDedicatedRequirements* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMemoryDedicatedAllocateInfo(std::ostream &out, const VkMemoryDedicatedAllocateInfo* structInfo, Decoded_VkMemoryDedicatedAllocateInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMemoryAllocateFlagsInfo(std::ostream &out, const VkMemoryAllocateFlagsInfo* structInfo, Decoded_VkMemoryAllocateFlagsInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDeviceGroupRenderPassBeginInfo(std::ostream &out, const VkDeviceGroupRenderPassBeginInfo* structInfo, Decoded_VkDeviceGroupRenderPassBeginInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDeviceGroupCommandBufferBeginInfo(std::ostream &out, const VkDeviceGroupCommandBufferBeginInfo* structInfo, Decoded_VkDeviceGroupCommandBufferBeginInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDeviceGroupSubmitInfo(std::ostream &out, const VkDeviceGroupSubmitInfo* structInfo, Decoded_VkDeviceGroupSubmitInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDeviceGroupBindSparseInfo(std::ostream &out, const VkDeviceGroupBindSparseInfo* structInfo, Decoded_VkDeviceGroupBindSparseInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkBindBufferMemoryDeviceGroupInfo(std::ostream &out, const VkBindBufferMemoryDeviceGroupInfo* structInfo, Decoded_VkBindBufferMemoryDeviceGroupInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkBindImageMemoryDeviceGroupInfo(std::ostream &out, const VkBindImageMemoryDeviceGroupInfo* structInfo, Decoded_VkBindImageMemoryDeviceGroupInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceGroupProperties(std::ostream &out, const VkPhysicalDeviceGroupProperties* structInfo, Decoded_VkPhysicalDeviceGroupProperties* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDeviceGroupDeviceCreateInfo(std::ostream &out, const VkDeviceGroupDeviceCreateInfo* structInfo, Decoded_VkDeviceGroupDeviceCreateInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkBufferMemoryRequirementsInfo2(std::ostream &out, const VkBufferMemoryRequirementsInfo2* structInfo, Decoded_VkBufferMemoryRequirementsInfo2* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImageMemoryRequirementsInfo2(std::ostream &out, const VkImageMemoryRequirementsInfo2* structInfo, Decoded_VkImageMemoryRequirementsInfo2* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImageSparseMemoryRequirementsInfo2(std::ostream &out, const VkImageSparseMemoryRequirementsInfo2* structInfo, Decoded_VkImageSparseMemoryRequirementsInfo2* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMemoryRequirements2(std::ostream &out, const VkMemoryRequirements2* structInfo, Decoded_VkMemoryRequirements2* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSparseImageMemoryRequirements2(std::ostream &out, const VkSparseImageMemoryRequirements2* structInfo, Decoded_VkSparseImageMemoryRequirements2* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceFeatures2(std::ostream &out, const VkPhysicalDeviceFeatures2* structInfo, Decoded_VkPhysicalDeviceFeatures2* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceProperties2(std::ostream &out, const VkPhysicalDeviceProperties2* structInfo, Decoded_VkPhysicalDeviceProperties2* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkFormatProperties2(std::ostream &out, const VkFormatProperties2* structInfo, Decoded_VkFormatProperties2* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImageFormatProperties2(std::ostream &out, const VkImageFormatProperties2* structInfo, Decoded_VkImageFormatProperties2* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceImageFormatInfo2(std::ostream &out, const VkPhysicalDeviceImageFormatInfo2* structInfo, Decoded_VkPhysicalDeviceImageFormatInfo2* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkQueueFamilyProperties2(std::ostream &out, const VkQueueFamilyProperties2* structInfo, Decoded_VkQueueFamilyProperties2* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceMemoryProperties2(std::ostream &out, const VkPhysicalDeviceMemoryProperties2* structInfo, Decoded_VkPhysicalDeviceMemoryProperties2* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSparseImageFormatProperties2(std::ostream &out, const VkSparseImageFormatProperties2* structInfo, Decoded_VkSparseImageFormatProperties2* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceSparseImageFormatInfo2(std::ostream &out, const VkPhysicalDeviceSparseImageFormatInfo2* structInfo, Decoded_VkPhysicalDeviceSparseImageFormatInfo2* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDevicePointClippingProperties(std::ostream &out, const VkPhysicalDevicePointClippingProperties* structInfo, Decoded_VkPhysicalDevicePointClippingProperties* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkInputAttachmentAspectReference(std::ostream &out, const VkInputAttachmentAspectReference* structInfo, Decoded_VkInputAttachmentAspectReference* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkRenderPassInputAttachmentAspectCreateInfo(std::ostream &out, const VkRenderPassInputAttachmentAspectCreateInfo* structInfo, Decoded_VkRenderPassInputAttachmentAspectCreateInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImageViewUsageCreateInfo(std::ostream &out, const VkImageViewUsageCreateInfo* structInfo, Decoded_VkImageViewUsageCreateInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineTessellationDomainOriginStateCreateInfo(std::ostream &out, const VkPipelineTessellationDomainOriginStateCreateInfo* structInfo, Decoded_VkPipelineTessellationDomainOriginStateCreateInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkRenderPassMultiviewCreateInfo(std::ostream &out, const VkRenderPassMultiviewCreateInfo* structInfo, Decoded_VkRenderPassMultiviewCreateInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceMultiviewFeatures(std::ostream &out, const VkPhysicalDeviceMultiviewFeatures* structInfo, Decoded_VkPhysicalDeviceMultiviewFeatures* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceMultiviewProperties(std::ostream &out, const VkPhysicalDeviceMultiviewProperties* structInfo, Decoded_VkPhysicalDeviceMultiviewProperties* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceVariablePointersFeatures(std::ostream &out, const VkPhysicalDeviceVariablePointersFeatures* structInfo, Decoded_VkPhysicalDeviceVariablePointersFeatures* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceProtectedMemoryFeatures(std::ostream &out, const VkPhysicalDeviceProtectedMemoryFeatures* structInfo, Decoded_VkPhysicalDeviceProtectedMemoryFeatures* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceProtectedMemoryProperties(std::ostream &out, const VkPhysicalDeviceProtectedMemoryProperties* structInfo, Decoded_VkPhysicalDeviceProtectedMemoryProperties* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDeviceQueueInfo2(std::ostream &out, const VkDeviceQueueInfo2* structInfo, Decoded_VkDeviceQueueInfo2* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkProtectedSubmitInfo(std::ostream &out, const VkProtectedSubmitInfo* structInfo, Decoded_VkProtectedSubmitInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSamplerYcbcrConversionCreateInfo(std::ostream &out, const VkSamplerYcbcrConversionCreateInfo* structInfo, Decoded_VkSamplerYcbcrConversionCreateInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSamplerYcbcrConversionInfo(std::ostream &out, const VkSamplerYcbcrConversionInfo* structInfo, Decoded_VkSamplerYcbcrConversionInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkBindImagePlaneMemoryInfo(std::ostream &out, const VkBindImagePlaneMemoryInfo* structInfo, Decoded_VkBindImagePlaneMemoryInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImagePlaneMemoryRequirementsInfo(std::ostream &out, const VkImagePlaneMemoryRequirementsInfo* structInfo, Decoded_VkImagePlaneMemoryRequirementsInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceSamplerYcbcrConversionFeatures(std::ostream &out, const VkPhysicalDeviceSamplerYcbcrConversionFeatures* structInfo, Decoded_VkPhysicalDeviceSamplerYcbcrConversionFeatures* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSamplerYcbcrConversionImageFormatProperties(std::ostream &out, const VkSamplerYcbcrConversionImageFormatProperties* structInfo, Decoded_VkSamplerYcbcrConversionImageFormatProperties* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDescriptorUpdateTemplateCreateInfo(std::ostream &out, const VkDescriptorUpdateTemplateCreateInfo* structInfo, Decoded_VkDescriptorUpdateTemplateCreateInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkExternalMemoryProperties(std::ostream &out, const VkExternalMemoryProperties* structInfo, Decoded_VkExternalMemoryProperties* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceExternalImageFormatInfo(std::ostream &out, const VkPhysicalDeviceExternalImageFormatInfo* structInfo, Decoded_VkPhysicalDeviceExternalImageFormatInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkExternalImageFormatProperties(std::ostream &out, const VkExternalImageFormatProperties* structInfo, Decoded_VkExternalImageFormatProperties* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceExternalBufferInfo(std::ostream &out, const VkPhysicalDeviceExternalBufferInfo* structInfo, Decoded_VkPhysicalDeviceExternalBufferInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkExternalBufferProperties(std::ostream &out, const VkExternalBufferProperties* structInfo, Decoded_VkExternalBufferProperties* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceIDProperties(std::ostream &out, const VkPhysicalDeviceIDProperties* structInfo, Decoded_VkPhysicalDeviceIDProperties* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkExternalMemoryImageCreateInfo(std::ostream &out, const VkExternalMemoryImageCreateInfo* structInfo, Decoded_VkExternalMemoryImageCreateInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkExternalMemoryBufferCreateInfo(std::ostream &out, const VkExternalMemoryBufferCreateInfo* structInfo, Decoded_VkExternalMemoryBufferCreateInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkExportMemoryAllocateInfo(std::ostream &out, const VkExportMemoryAllocateInfo* structInfo, Decoded_VkExportMemoryAllocateInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceExternalFenceInfo(std::ostream &out, const VkPhysicalDeviceExternalFenceInfo* structInfo, Decoded_VkPhysicalDeviceExternalFenceInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkExternalFenceProperties(std::ostream &out, const VkExternalFenceProperties* structInfo, Decoded_VkExternalFenceProperties* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkExportFenceCreateInfo(std::ostream &out, const VkExportFenceCreateInfo* structInfo, Decoded_VkExportFenceCreateInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkExportSemaphoreCreateInfo(std::ostream &out, const VkExportSemaphoreCreateInfo* structInfo, Decoded_VkExportSemaphoreCreateInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceExternalSemaphoreInfo(std::ostream &out, const VkPhysicalDeviceExternalSemaphoreInfo* structInfo, Decoded_VkPhysicalDeviceExternalSemaphoreInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkExternalSemaphoreProperties(std::ostream &out, const VkExternalSemaphoreProperties* structInfo, Decoded_VkExternalSemaphoreProperties* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceMaintenance3Properties(std::ostream &out, const VkPhysicalDeviceMaintenance3Properties* structInfo, Decoded_VkPhysicalDeviceMaintenance3Properties* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDescriptorSetLayoutSupport(std::ostream &out, const VkDescriptorSetLayoutSupport* structInfo, Decoded_VkDescriptorSetLayoutSupport* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceShaderDrawParametersFeatures(std::ostream &out, const VkPhysicalDeviceShaderDrawParametersFeatures* structInfo, Decoded_VkPhysicalDeviceShaderDrawParametersFeatures* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceVulkan11Features(std::ostream &out, const VkPhysicalDeviceVulkan11Features* structInfo, Decoded_VkPhysicalDeviceVulkan11Features* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceVulkan11Properties(std::ostream &out, const VkPhysicalDeviceVulkan11Properties* structInfo, Decoded_VkPhysicalDeviceVulkan11Properties* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceVulkan12Features(std::ostream &out, const VkPhysicalDeviceVulkan12Features* structInfo, Decoded_VkPhysicalDeviceVulkan12Features* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkConformanceVersion(std::ostream &out, const VkConformanceVersion* structInfo, Decoded_VkConformanceVersion* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceVulkan12Properties(std::ostream &out, const VkPhysicalDeviceVulkan12Properties* structInfo, Decoded_VkPhysicalDeviceVulkan12Properties* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImageFormatListCreateInfo(std::ostream &out, const VkImageFormatListCreateInfo* structInfo, Decoded_VkImageFormatListCreateInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAttachmentDescription2(std::ostream &out, const VkAttachmentDescription2* structInfo, Decoded_VkAttachmentDescription2* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAttachmentReference2(std::ostream &out, const VkAttachmentReference2* structInfo, Decoded_VkAttachmentReference2* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSubpassDescription2(std::ostream &out, const VkSubpassDescription2* structInfo, Decoded_VkSubpassDescription2* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSubpassDependency2(std::ostream &out, const VkSubpassDependency2* structInfo, Decoded_VkSubpassDependency2* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkRenderPassCreateInfo2(std::ostream &out, const VkRenderPassCreateInfo2* structInfo, Decoded_VkRenderPassCreateInfo2* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSubpassBeginInfo(std::ostream &out, const VkSubpassBeginInfo* structInfo, Decoded_VkSubpassBeginInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSubpassEndInfo(std::ostream &out, const VkSubpassEndInfo* structInfo, Decoded_VkSubpassEndInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDevice8BitStorageFeatures(std::ostream &out, const VkPhysicalDevice8BitStorageFeatures* structInfo, Decoded_VkPhysicalDevice8BitStorageFeatures* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceDriverProperties(std::ostream &out, const VkPhysicalDeviceDriverProperties* structInfo, Decoded_VkPhysicalDeviceDriverProperties* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceShaderAtomicInt64Features(std::ostream &out, const VkPhysicalDeviceShaderAtomicInt64Features* structInfo, Decoded_VkPhysicalDeviceShaderAtomicInt64Features* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceShaderFloat16Int8Features(std::ostream &out, const VkPhysicalDeviceShaderFloat16Int8Features* structInfo, Decoded_VkPhysicalDeviceShaderFloat16Int8Features* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceFloatControlsProperties(std::ostream &out, const VkPhysicalDeviceFloatControlsProperties* structInfo, Decoded_VkPhysicalDeviceFloatControlsProperties* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDescriptorSetLayoutBindingFlagsCreateInfo(std::ostream &out, const VkDescriptorSetLayoutBindingFlagsCreateInfo* structInfo, Decoded_VkDescriptorSetLayoutBindingFlagsCreateInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceDescriptorIndexingFeatures(std::ostream &out, const VkPhysicalDeviceDescriptorIndexingFeatures* structInfo, Decoded_VkPhysicalDeviceDescriptorIndexingFeatures* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceDescriptorIndexingProperties(std::ostream &out, const VkPhysicalDeviceDescriptorIndexingProperties* structInfo, Decoded_VkPhysicalDeviceDescriptorIndexingProperties* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDescriptorSetVariableDescriptorCountAllocateInfo(std::ostream &out, const VkDescriptorSetVariableDescriptorCountAllocateInfo* structInfo, Decoded_VkDescriptorSetVariableDescriptorCountAllocateInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDescriptorSetVariableDescriptorCountLayoutSupport(std::ostream &out, const VkDescriptorSetVariableDescriptorCountLayoutSupport* structInfo, Decoded_VkDescriptorSetVariableDescriptorCountLayoutSupport* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSubpassDescriptionDepthStencilResolve(std::ostream &out, const VkSubpassDescriptionDepthStencilResolve* structInfo, Decoded_VkSubpassDescriptionDepthStencilResolve* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceDepthStencilResolveProperties(std::ostream &out, const VkPhysicalDeviceDepthStencilResolveProperties* structInfo, Decoded_VkPhysicalDeviceDepthStencilResolveProperties* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceScalarBlockLayoutFeatures(std::ostream &out, const VkPhysicalDeviceScalarBlockLayoutFeatures* structInfo, Decoded_VkPhysicalDeviceScalarBlockLayoutFeatures* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImageStencilUsageCreateInfo(std::ostream &out, const VkImageStencilUsageCreateInfo* structInfo, Decoded_VkImageStencilUsageCreateInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSamplerReductionModeCreateInfo(std::ostream &out, const VkSamplerReductionModeCreateInfo* structInfo, Decoded_VkSamplerReductionModeCreateInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceSamplerFilterMinmaxProperties(std::ostream &out, const VkPhysicalDeviceSamplerFilterMinmaxProperties* structInfo, Decoded_VkPhysicalDeviceSamplerFilterMinmaxProperties* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceVulkanMemoryModelFeatures(std::ostream &out, const VkPhysicalDeviceVulkanMemoryModelFeatures* structInfo, Decoded_VkPhysicalDeviceVulkanMemoryModelFeatures* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceImagelessFramebufferFeatures(std::ostream &out, const VkPhysicalDeviceImagelessFramebufferFeatures* structInfo, Decoded_VkPhysicalDeviceImagelessFramebufferFeatures* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkFramebufferAttachmentImageInfo(std::ostream &out, const VkFramebufferAttachmentImageInfo* structInfo, Decoded_VkFramebufferAttachmentImageInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkFramebufferAttachmentsCreateInfo(std::ostream &out, const VkFramebufferAttachmentsCreateInfo* structInfo, Decoded_VkFramebufferAttachmentsCreateInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkRenderPassAttachmentBeginInfo(std::ostream &out, const VkRenderPassAttachmentBeginInfo* structInfo, Decoded_VkRenderPassAttachmentBeginInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceUniformBufferStandardLayoutFeatures(std::ostream &out, const VkPhysicalDeviceUniformBufferStandardLayoutFeatures* structInfo, Decoded_VkPhysicalDeviceUniformBufferStandardLayoutFeatures* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures(std::ostream &out, const VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures* structInfo, Decoded_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures(std::ostream &out, const VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures* structInfo, Decoded_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAttachmentReferenceStencilLayout(std::ostream &out, const VkAttachmentReferenceStencilLayout* structInfo, Decoded_VkAttachmentReferenceStencilLayout* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAttachmentDescriptionStencilLayout(std::ostream &out, const VkAttachmentDescriptionStencilLayout* structInfo, Decoded_VkAttachmentDescriptionStencilLayout* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceHostQueryResetFeatures(std::ostream &out, const VkPhysicalDeviceHostQueryResetFeatures* structInfo, Decoded_VkPhysicalDeviceHostQueryResetFeatures* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceTimelineSemaphoreFeatures(std::ostream &out, const VkPhysicalDeviceTimelineSemaphoreFeatures* structInfo, Decoded_VkPhysicalDeviceTimelineSemaphoreFeatures* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceTimelineSemaphoreProperties(std::ostream &out, const VkPhysicalDeviceTimelineSemaphoreProperties* structInfo, Decoded_VkPhysicalDeviceTimelineSemaphoreProperties* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSemaphoreTypeCreateInfo(std::ostream &out, const VkSemaphoreTypeCreateInfo* structInfo, Decoded_VkSemaphoreTypeCreateInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkTimelineSemaphoreSubmitInfo(std::ostream &out, const VkTimelineSemaphoreSubmitInfo* structInfo, Decoded_VkTimelineSemaphoreSubmitInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSemaphoreWaitInfo(std::ostream &out, const VkSemaphoreWaitInfo* structInfo, Decoded_VkSemaphoreWaitInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSemaphoreSignalInfo(std::ostream &out, const VkSemaphoreSignalInfo* structInfo, Decoded_VkSemaphoreSignalInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceBufferDeviceAddressFeatures(std::ostream &out, const VkPhysicalDeviceBufferDeviceAddressFeatures* structInfo, Decoded_VkPhysicalDeviceBufferDeviceAddressFeatures* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkBufferDeviceAddressInfo(std::ostream &out, const VkBufferDeviceAddressInfo* structInfo, Decoded_VkBufferDeviceAddressInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkBufferOpaqueCaptureAddressCreateInfo(std::ostream &out, const VkBufferOpaqueCaptureAddressCreateInfo* structInfo, Decoded_VkBufferOpaqueCaptureAddressCreateInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMemoryOpaqueCaptureAddressAllocateInfo(std::ostream &out, const VkMemoryOpaqueCaptureAddressAllocateInfo* structInfo, Decoded_VkMemoryOpaqueCaptureAddressAllocateInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDeviceMemoryOpaqueCaptureAddressInfo(std::ostream &out, const VkDeviceMemoryOpaqueCaptureAddressInfo* structInfo, Decoded_VkDeviceMemoryOpaqueCaptureAddressInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceVulkan13Features(std::ostream &out, const VkPhysicalDeviceVulkan13Features* structInfo, Decoded_VkPhysicalDeviceVulkan13Features* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceVulkan13Properties(std::ostream &out, const VkPhysicalDeviceVulkan13Properties* structInfo, Decoded_VkPhysicalDeviceVulkan13Properties* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineCreationFeedback(std::ostream &out, const VkPipelineCreationFeedback* structInfo, Decoded_VkPipelineCreationFeedback* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineCreationFeedbackCreateInfo(std::ostream &out, const VkPipelineCreationFeedbackCreateInfo* structInfo, Decoded_VkPipelineCreationFeedbackCreateInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceShaderTerminateInvocationFeatures(std::ostream &out, const VkPhysicalDeviceShaderTerminateInvocationFeatures* structInfo, Decoded_VkPhysicalDeviceShaderTerminateInvocationFeatures* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceToolProperties(std::ostream &out, const VkPhysicalDeviceToolProperties* structInfo, Decoded_VkPhysicalDeviceToolProperties* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures(std::ostream &out, const VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures* structInfo, Decoded_VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDevicePrivateDataFeatures(std::ostream &out, const VkPhysicalDevicePrivateDataFeatures* structInfo, Decoded_VkPhysicalDevicePrivateDataFeatures* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDevicePrivateDataCreateInfo(std::ostream &out, const VkDevicePrivateDataCreateInfo* structInfo, Decoded_VkDevicePrivateDataCreateInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPrivateDataSlotCreateInfo(std::ostream &out, const VkPrivateDataSlotCreateInfo* structInfo, Decoded_VkPrivateDataSlotCreateInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDevicePipelineCreationCacheControlFeatures(std::ostream &out, const VkPhysicalDevicePipelineCreationCacheControlFeatures* structInfo, Decoded_VkPhysicalDevicePipelineCreationCacheControlFeatures* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMemoryBarrier2(std::ostream &out, const VkMemoryBarrier2* structInfo, Decoded_VkMemoryBarrier2* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkBufferMemoryBarrier2(std::ostream &out, const VkBufferMemoryBarrier2* structInfo, Decoded_VkBufferMemoryBarrier2* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImageMemoryBarrier2(std::ostream &out, const VkImageMemoryBarrier2* structInfo, Decoded_VkImageMemoryBarrier2* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDependencyInfo(std::ostream &out, const VkDependencyInfo* structInfo, Decoded_VkDependencyInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSemaphoreSubmitInfo(std::ostream &out, const VkSemaphoreSubmitInfo* structInfo, Decoded_VkSemaphoreSubmitInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkCommandBufferSubmitInfo(std::ostream &out, const VkCommandBufferSubmitInfo* structInfo, Decoded_VkCommandBufferSubmitInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSubmitInfo2(std::ostream &out, const VkSubmitInfo2* structInfo, Decoded_VkSubmitInfo2* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceSynchronization2Features(std::ostream &out, const VkPhysicalDeviceSynchronization2Features* structInfo, Decoded_VkPhysicalDeviceSynchronization2Features* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures(std::ostream &out, const VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures* structInfo, Decoded_VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceImageRobustnessFeatures(std::ostream &out, const VkPhysicalDeviceImageRobustnessFeatures* structInfo, Decoded_VkPhysicalDeviceImageRobustnessFeatures* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkBufferCopy2(std::ostream &out, const VkBufferCopy2* structInfo, Decoded_VkBufferCopy2* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkCopyBufferInfo2(std::ostream &out, const VkCopyBufferInfo2* structInfo, Decoded_VkCopyBufferInfo2* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImageCopy2(std::ostream &out, const VkImageCopy2* structInfo, Decoded_VkImageCopy2* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkCopyImageInfo2(std::ostream &out, const VkCopyImageInfo2* structInfo, Decoded_VkCopyImageInfo2* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkBufferImageCopy2(std::ostream &out, const VkBufferImageCopy2* structInfo, Decoded_VkBufferImageCopy2* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkCopyBufferToImageInfo2(std::ostream &out, const VkCopyBufferToImageInfo2* structInfo, Decoded_VkCopyBufferToImageInfo2* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkCopyImageToBufferInfo2(std::ostream &out, const VkCopyImageToBufferInfo2* structInfo, Decoded_VkCopyImageToBufferInfo2* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImageBlit2(std::ostream &out, const VkImageBlit2* structInfo, Decoded_VkImageBlit2* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkBlitImageInfo2(std::ostream &out, const VkBlitImageInfo2* structInfo, Decoded_VkBlitImageInfo2* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImageResolve2(std::ostream &out, const VkImageResolve2* structInfo, Decoded_VkImageResolve2* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkResolveImageInfo2(std::ostream &out, const VkResolveImageInfo2* structInfo, Decoded_VkResolveImageInfo2* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceSubgroupSizeControlFeatures(std::ostream &out, const VkPhysicalDeviceSubgroupSizeControlFeatures* structInfo, Decoded_VkPhysicalDeviceSubgroupSizeControlFeatures* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceSubgroupSizeControlProperties(std::ostream &out, const VkPhysicalDeviceSubgroupSizeControlProperties* structInfo, Decoded_VkPhysicalDeviceSubgroupSizeControlProperties* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineShaderStageRequiredSubgroupSizeCreateInfo(std::ostream &out, const VkPipelineShaderStageRequiredSubgroupSizeCreateInfo* structInfo, Decoded_VkPipelineShaderStageRequiredSubgroupSizeCreateInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceInlineUniformBlockFeatures(std::ostream &out, const VkPhysicalDeviceInlineUniformBlockFeatures* structInfo, Decoded_VkPhysicalDeviceInlineUniformBlockFeatures* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceInlineUniformBlockProperties(std::ostream &out, const VkPhysicalDeviceInlineUniformBlockProperties* structInfo, Decoded_VkPhysicalDeviceInlineUniformBlockProperties* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkWriteDescriptorSetInlineUniformBlock(std::ostream &out, const VkWriteDescriptorSetInlineUniformBlock* structInfo, Decoded_VkWriteDescriptorSetInlineUniformBlock* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDescriptorPoolInlineUniformBlockCreateInfo(std::ostream &out, const VkDescriptorPoolInlineUniformBlockCreateInfo* structInfo, Decoded_VkDescriptorPoolInlineUniformBlockCreateInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceTextureCompressionASTCHDRFeatures(std::ostream &out, const VkPhysicalDeviceTextureCompressionASTCHDRFeatures* structInfo, Decoded_VkPhysicalDeviceTextureCompressionASTCHDRFeatures* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkRenderingAttachmentInfo(std::ostream &out, const VkRenderingAttachmentInfo* structInfo, Decoded_VkRenderingAttachmentInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkRenderingInfo(std::ostream &out, const VkRenderingInfo* structInfo, Decoded_VkRenderingInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineRenderingCreateInfo(std::ostream &out, const VkPipelineRenderingCreateInfo* structInfo, Decoded_VkPipelineRenderingCreateInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceDynamicRenderingFeatures(std::ostream &out, const VkPhysicalDeviceDynamicRenderingFeatures* structInfo, Decoded_VkPhysicalDeviceDynamicRenderingFeatures* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkCommandBufferInheritanceRenderingInfo(std::ostream &out, const VkCommandBufferInheritanceRenderingInfo* structInfo, Decoded_VkCommandBufferInheritanceRenderingInfo* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceShaderIntegerDotProductFeatures(std::ostream &out, const VkPhysicalDeviceShaderIntegerDotProductFeatures* structInfo, Decoded_VkPhysicalDeviceShaderIntegerDotProductFeatures* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceShaderIntegerDotProductProperties(std::ostream &out, const VkPhysicalDeviceShaderIntegerDotProductProperties* structInfo, Decoded_VkPhysicalDeviceShaderIntegerDotProductProperties* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceTexelBufferAlignmentProperties(std::ostream &out, const VkPhysicalDeviceTexelBufferAlignmentProperties* structInfo, Decoded_VkPhysicalDeviceTexelBufferAlignmentProperties* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkFormatProperties3(std::ostream &out, const VkFormatProperties3* structInfo, Decoded_VkFormatProperties3* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceMaintenance4Features(std::ostream &out, const VkPhysicalDeviceMaintenance4Features* structInfo, Decoded_VkPhysicalDeviceMaintenance4Features* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceMaintenance4Properties(std::ostream &out, const VkPhysicalDeviceMaintenance4Properties* structInfo, Decoded_VkPhysicalDeviceMaintenance4Properties* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDeviceBufferMemoryRequirements(std::ostream &out, const VkDeviceBufferMemoryRequirements* structInfo, Decoded_VkDeviceBufferMemoryRequirements* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDeviceImageMemoryRequirements(std::ostream &out, const VkDeviceImageMemoryRequirements* structInfo, Decoded_VkDeviceImageMemoryRequirements* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSurfaceCapabilitiesKHR(std::ostream &out, const VkSurfaceCapabilitiesKHR* structInfo, Decoded_VkSurfaceCapabilitiesKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSurfaceFormatKHR(std::ostream &out, const VkSurfaceFormatKHR* structInfo, Decoded_VkSurfaceFormatKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSwapchainCreateInfoKHR(std::ostream &out, const VkSwapchainCreateInfoKHR* structInfo, Decoded_VkSwapchainCreateInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImageSwapchainCreateInfoKHR(std::ostream &out, const VkImageSwapchainCreateInfoKHR* structInfo, Decoded_VkImageSwapchainCreateInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkBindImageMemorySwapchainInfoKHR(std::ostream &out, const VkBindImageMemorySwapchainInfoKHR* structInfo, Decoded_VkBindImageMemorySwapchainInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAcquireNextImageInfoKHR(std::ostream &out, const VkAcquireNextImageInfoKHR* structInfo, Decoded_VkAcquireNextImageInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDeviceGroupPresentCapabilitiesKHR(std::ostream &out, const VkDeviceGroupPresentCapabilitiesKHR* structInfo, Decoded_VkDeviceGroupPresentCapabilitiesKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDeviceGroupPresentInfoKHR(std::ostream &out, const VkDeviceGroupPresentInfoKHR* structInfo, Decoded_VkDeviceGroupPresentInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDeviceGroupSwapchainCreateInfoKHR(std::ostream &out, const VkDeviceGroupSwapchainCreateInfoKHR* structInfo, Decoded_VkDeviceGroupSwapchainCreateInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDisplayModeParametersKHR(std::ostream &out, const VkDisplayModeParametersKHR* structInfo, Decoded_VkDisplayModeParametersKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDisplayModeCreateInfoKHR(std::ostream &out, const VkDisplayModeCreateInfoKHR* structInfo, Decoded_VkDisplayModeCreateInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDisplayModePropertiesKHR(std::ostream &out, const VkDisplayModePropertiesKHR* structInfo, Decoded_VkDisplayModePropertiesKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDisplayPlaneCapabilitiesKHR(std::ostream &out, const VkDisplayPlaneCapabilitiesKHR* structInfo, Decoded_VkDisplayPlaneCapabilitiesKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDisplayPlanePropertiesKHR(std::ostream &out, const VkDisplayPlanePropertiesKHR* structInfo, Decoded_VkDisplayPlanePropertiesKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDisplayPropertiesKHR(std::ostream &out, const VkDisplayPropertiesKHR* structInfo, Decoded_VkDisplayPropertiesKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDisplaySurfaceCreateInfoKHR(std::ostream &out, const VkDisplaySurfaceCreateInfoKHR* structInfo, Decoded_VkDisplaySurfaceCreateInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDisplayPresentInfoKHR(std::ostream &out, const VkDisplayPresentInfoKHR* structInfo, Decoded_VkDisplayPresentInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkXlibSurfaceCreateInfoKHR(std::ostream &out, const VkXlibSurfaceCreateInfoKHR* structInfo, Decoded_VkXlibSurfaceCreateInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkXcbSurfaceCreateInfoKHR(std::ostream &out, const VkXcbSurfaceCreateInfoKHR* structInfo, Decoded_VkXcbSurfaceCreateInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkWaylandSurfaceCreateInfoKHR(std::ostream &out, const VkWaylandSurfaceCreateInfoKHR* structInfo, Decoded_VkWaylandSurfaceCreateInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAndroidSurfaceCreateInfoKHR(std::ostream &out, const VkAndroidSurfaceCreateInfoKHR* structInfo, Decoded_VkAndroidSurfaceCreateInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkWin32SurfaceCreateInfoKHR(std::ostream &out, const VkWin32SurfaceCreateInfoKHR* structInfo, Decoded_VkWin32SurfaceCreateInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkQueueFamilyQueryResultStatusPropertiesKHR(std::ostream &out, const VkQueueFamilyQueryResultStatusPropertiesKHR* structInfo, Decoded_VkQueueFamilyQueryResultStatusPropertiesKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkQueueFamilyVideoPropertiesKHR(std::ostream &out, const VkQueueFamilyVideoPropertiesKHR* structInfo, Decoded_VkQueueFamilyVideoPropertiesKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoProfileInfoKHR(std::ostream &out, const VkVideoProfileInfoKHR* structInfo, Decoded_VkVideoProfileInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoProfileListInfoKHR(std::ostream &out, const VkVideoProfileListInfoKHR* structInfo, Decoded_VkVideoProfileListInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoCapabilitiesKHR(std::ostream &out, const VkVideoCapabilitiesKHR* structInfo, Decoded_VkVideoCapabilitiesKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceVideoFormatInfoKHR(std::ostream &out, const VkPhysicalDeviceVideoFormatInfoKHR* structInfo, Decoded_VkPhysicalDeviceVideoFormatInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoFormatPropertiesKHR(std::ostream &out, const VkVideoFormatPropertiesKHR* structInfo, Decoded_VkVideoFormatPropertiesKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoPictureResourceInfoKHR(std::ostream &out, const VkVideoPictureResourceInfoKHR* structInfo, Decoded_VkVideoPictureResourceInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoReferenceSlotInfoKHR(std::ostream &out, const VkVideoReferenceSlotInfoKHR* structInfo, Decoded_VkVideoReferenceSlotInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoSessionMemoryRequirementsKHR(std::ostream &out, const VkVideoSessionMemoryRequirementsKHR* structInfo, Decoded_VkVideoSessionMemoryRequirementsKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkBindVideoSessionMemoryInfoKHR(std::ostream &out, const VkBindVideoSessionMemoryInfoKHR* structInfo, Decoded_VkBindVideoSessionMemoryInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoSessionCreateInfoKHR(std::ostream &out, const VkVideoSessionCreateInfoKHR* structInfo, Decoded_VkVideoSessionCreateInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoSessionParametersCreateInfoKHR(std::ostream &out, const VkVideoSessionParametersCreateInfoKHR* structInfo, Decoded_VkVideoSessionParametersCreateInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoSessionParametersUpdateInfoKHR(std::ostream &out, const VkVideoSessionParametersUpdateInfoKHR* structInfo, Decoded_VkVideoSessionParametersUpdateInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoBeginCodingInfoKHR(std::ostream &out, const VkVideoBeginCodingInfoKHR* structInfo, Decoded_VkVideoBeginCodingInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEndCodingInfoKHR(std::ostream &out, const VkVideoEndCodingInfoKHR* structInfo, Decoded_VkVideoEndCodingInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoCodingControlInfoKHR(std::ostream &out, const VkVideoCodingControlInfoKHR* structInfo, Decoded_VkVideoCodingControlInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoDecodeCapabilitiesKHR(std::ostream &out, const VkVideoDecodeCapabilitiesKHR* structInfo, Decoded_VkVideoDecodeCapabilitiesKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoDecodeUsageInfoKHR(std::ostream &out, const VkVideoDecodeUsageInfoKHR* structInfo, Decoded_VkVideoDecodeUsageInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoDecodeInfoKHR(std::ostream &out, const VkVideoDecodeInfoKHR* structInfo, Decoded_VkVideoDecodeInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoDecodeH264ProfileInfoKHR(std::ostream &out, const VkVideoDecodeH264ProfileInfoKHR* structInfo, Decoded_VkVideoDecodeH264ProfileInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoDecodeH264CapabilitiesKHR(std::ostream &out, const VkVideoDecodeH264CapabilitiesKHR* structInfo, Decoded_VkVideoDecodeH264CapabilitiesKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoDecodeH264SessionParametersAddInfoKHR(std::ostream &out, const VkVideoDecodeH264SessionParametersAddInfoKHR* structInfo, Decoded_VkVideoDecodeH264SessionParametersAddInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoDecodeH264SessionParametersCreateInfoKHR(std::ostream &out, const VkVideoDecodeH264SessionParametersCreateInfoKHR* structInfo, Decoded_VkVideoDecodeH264SessionParametersCreateInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoDecodeH264PictureInfoKHR(std::ostream &out, const VkVideoDecodeH264PictureInfoKHR* structInfo, Decoded_VkVideoDecodeH264PictureInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoDecodeH264DpbSlotInfoKHR(std::ostream &out, const VkVideoDecodeH264DpbSlotInfoKHR* structInfo, Decoded_VkVideoDecodeH264DpbSlotInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkRenderingFragmentShadingRateAttachmentInfoKHR(std::ostream &out, const VkRenderingFragmentShadingRateAttachmentInfoKHR* structInfo, Decoded_VkRenderingFragmentShadingRateAttachmentInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkRenderingFragmentDensityMapAttachmentInfoEXT(std::ostream &out, const VkRenderingFragmentDensityMapAttachmentInfoEXT* structInfo, Decoded_VkRenderingFragmentDensityMapAttachmentInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAttachmentSampleCountInfoAMD(std::ostream &out, const VkAttachmentSampleCountInfoAMD* structInfo, Decoded_VkAttachmentSampleCountInfoAMD* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMultiviewPerViewAttributesInfoNVX(std::ostream &out, const VkMultiviewPerViewAttributesInfoNVX* structInfo, Decoded_VkMultiviewPerViewAttributesInfoNVX* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImportMemoryWin32HandleInfoKHR(std::ostream &out, const VkImportMemoryWin32HandleInfoKHR* structInfo, Decoded_VkImportMemoryWin32HandleInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkExportMemoryWin32HandleInfoKHR(std::ostream &out, const VkExportMemoryWin32HandleInfoKHR* structInfo, Decoded_VkExportMemoryWin32HandleInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMemoryWin32HandlePropertiesKHR(std::ostream &out, const VkMemoryWin32HandlePropertiesKHR* structInfo, Decoded_VkMemoryWin32HandlePropertiesKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMemoryGetWin32HandleInfoKHR(std::ostream &out, const VkMemoryGetWin32HandleInfoKHR* structInfo, Decoded_VkMemoryGetWin32HandleInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImportMemoryFdInfoKHR(std::ostream &out, const VkImportMemoryFdInfoKHR* structInfo, Decoded_VkImportMemoryFdInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMemoryFdPropertiesKHR(std::ostream &out, const VkMemoryFdPropertiesKHR* structInfo, Decoded_VkMemoryFdPropertiesKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMemoryGetFdInfoKHR(std::ostream &out, const VkMemoryGetFdInfoKHR* structInfo, Decoded_VkMemoryGetFdInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkWin32KeyedMutexAcquireReleaseInfoKHR(std::ostream &out, const VkWin32KeyedMutexAcquireReleaseInfoKHR* structInfo, Decoded_VkWin32KeyedMutexAcquireReleaseInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImportSemaphoreWin32HandleInfoKHR(std::ostream &out, const VkImportSemaphoreWin32HandleInfoKHR* structInfo, Decoded_VkImportSemaphoreWin32HandleInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkExportSemaphoreWin32HandleInfoKHR(std::ostream &out, const VkExportSemaphoreWin32HandleInfoKHR* structInfo, Decoded_VkExportSemaphoreWin32HandleInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkD3D12FenceSubmitInfoKHR(std::ostream &out, const VkD3D12FenceSubmitInfoKHR* structInfo, Decoded_VkD3D12FenceSubmitInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSemaphoreGetWin32HandleInfoKHR(std::ostream &out, const VkSemaphoreGetWin32HandleInfoKHR* structInfo, Decoded_VkSemaphoreGetWin32HandleInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImportSemaphoreFdInfoKHR(std::ostream &out, const VkImportSemaphoreFdInfoKHR* structInfo, Decoded_VkImportSemaphoreFdInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSemaphoreGetFdInfoKHR(std::ostream &out, const VkSemaphoreGetFdInfoKHR* structInfo, Decoded_VkSemaphoreGetFdInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDevicePushDescriptorPropertiesKHR(std::ostream &out, const VkPhysicalDevicePushDescriptorPropertiesKHR* structInfo, Decoded_VkPhysicalDevicePushDescriptorPropertiesKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkRectLayerKHR(std::ostream &out, const VkRectLayerKHR* structInfo, Decoded_VkRectLayerKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPresentRegionKHR(std::ostream &out, const VkPresentRegionKHR* structInfo, Decoded_VkPresentRegionKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPresentRegionsKHR(std::ostream &out, const VkPresentRegionsKHR* structInfo, Decoded_VkPresentRegionsKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSharedPresentSurfaceCapabilitiesKHR(std::ostream &out, const VkSharedPresentSurfaceCapabilitiesKHR* structInfo, Decoded_VkSharedPresentSurfaceCapabilitiesKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImportFenceWin32HandleInfoKHR(std::ostream &out, const VkImportFenceWin32HandleInfoKHR* structInfo, Decoded_VkImportFenceWin32HandleInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkExportFenceWin32HandleInfoKHR(std::ostream &out, const VkExportFenceWin32HandleInfoKHR* structInfo, Decoded_VkExportFenceWin32HandleInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkFenceGetWin32HandleInfoKHR(std::ostream &out, const VkFenceGetWin32HandleInfoKHR* structInfo, Decoded_VkFenceGetWin32HandleInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImportFenceFdInfoKHR(std::ostream &out, const VkImportFenceFdInfoKHR* structInfo, Decoded_VkImportFenceFdInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkFenceGetFdInfoKHR(std::ostream &out, const VkFenceGetFdInfoKHR* structInfo, Decoded_VkFenceGetFdInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDevicePerformanceQueryFeaturesKHR(std::ostream &out, const VkPhysicalDevicePerformanceQueryFeaturesKHR* structInfo, Decoded_VkPhysicalDevicePerformanceQueryFeaturesKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDevicePerformanceQueryPropertiesKHR(std::ostream &out, const VkPhysicalDevicePerformanceQueryPropertiesKHR* structInfo, Decoded_VkPhysicalDevicePerformanceQueryPropertiesKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPerformanceCounterKHR(std::ostream &out, const VkPerformanceCounterKHR* structInfo, Decoded_VkPerformanceCounterKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPerformanceCounterDescriptionKHR(std::ostream &out, const VkPerformanceCounterDescriptionKHR* structInfo, Decoded_VkPerformanceCounterDescriptionKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkQueryPoolPerformanceCreateInfoKHR(std::ostream &out, const VkQueryPoolPerformanceCreateInfoKHR* structInfo, Decoded_VkQueryPoolPerformanceCreateInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAcquireProfilingLockInfoKHR(std::ostream &out, const VkAcquireProfilingLockInfoKHR* structInfo, Decoded_VkAcquireProfilingLockInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPerformanceQuerySubmitInfoKHR(std::ostream &out, const VkPerformanceQuerySubmitInfoKHR* structInfo, Decoded_VkPerformanceQuerySubmitInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceSurfaceInfo2KHR(std::ostream &out, const VkPhysicalDeviceSurfaceInfo2KHR* structInfo, Decoded_VkPhysicalDeviceSurfaceInfo2KHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSurfaceCapabilities2KHR(std::ostream &out, const VkSurfaceCapabilities2KHR* structInfo, Decoded_VkSurfaceCapabilities2KHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSurfaceFormat2KHR(std::ostream &out, const VkSurfaceFormat2KHR* structInfo, Decoded_VkSurfaceFormat2KHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDisplayProperties2KHR(std::ostream &out, const VkDisplayProperties2KHR* structInfo, Decoded_VkDisplayProperties2KHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDisplayPlaneProperties2KHR(std::ostream &out, const VkDisplayPlaneProperties2KHR* structInfo, Decoded_VkDisplayPlaneProperties2KHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDisplayModeProperties2KHR(std::ostream &out, const VkDisplayModeProperties2KHR* structInfo, Decoded_VkDisplayModeProperties2KHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDisplayPlaneInfo2KHR(std::ostream &out, const VkDisplayPlaneInfo2KHR* structInfo, Decoded_VkDisplayPlaneInfo2KHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDisplayPlaneCapabilities2KHR(std::ostream &out, const VkDisplayPlaneCapabilities2KHR* structInfo, Decoded_VkDisplayPlaneCapabilities2KHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDevicePortabilitySubsetFeaturesKHR(std::ostream &out, const VkPhysicalDevicePortabilitySubsetFeaturesKHR* structInfo, Decoded_VkPhysicalDevicePortabilitySubsetFeaturesKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDevicePortabilitySubsetPropertiesKHR(std::ostream &out, const VkPhysicalDevicePortabilitySubsetPropertiesKHR* structInfo, Decoded_VkPhysicalDevicePortabilitySubsetPropertiesKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceShaderClockFeaturesKHR(std::ostream &out, const VkPhysicalDeviceShaderClockFeaturesKHR* structInfo, Decoded_VkPhysicalDeviceShaderClockFeaturesKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoDecodeH265ProfileInfoKHR(std::ostream &out, const VkVideoDecodeH265ProfileInfoKHR* structInfo, Decoded_VkVideoDecodeH265ProfileInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoDecodeH265CapabilitiesKHR(std::ostream &out, const VkVideoDecodeH265CapabilitiesKHR* structInfo, Decoded_VkVideoDecodeH265CapabilitiesKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoDecodeH265SessionParametersAddInfoKHR(std::ostream &out, const VkVideoDecodeH265SessionParametersAddInfoKHR* structInfo, Decoded_VkVideoDecodeH265SessionParametersAddInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoDecodeH265SessionParametersCreateInfoKHR(std::ostream &out, const VkVideoDecodeH265SessionParametersCreateInfoKHR* structInfo, Decoded_VkVideoDecodeH265SessionParametersCreateInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoDecodeH265PictureInfoKHR(std::ostream &out, const VkVideoDecodeH265PictureInfoKHR* structInfo, Decoded_VkVideoDecodeH265PictureInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoDecodeH265DpbSlotInfoKHR(std::ostream &out, const VkVideoDecodeH265DpbSlotInfoKHR* structInfo, Decoded_VkVideoDecodeH265DpbSlotInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDeviceQueueGlobalPriorityCreateInfoKHR(std::ostream &out, const VkDeviceQueueGlobalPriorityCreateInfoKHR* structInfo, Decoded_VkDeviceQueueGlobalPriorityCreateInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR(std::ostream &out, const VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR* structInfo, Decoded_VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkQueueFamilyGlobalPriorityPropertiesKHR(std::ostream &out, const VkQueueFamilyGlobalPriorityPropertiesKHR* structInfo, Decoded_VkQueueFamilyGlobalPriorityPropertiesKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkFragmentShadingRateAttachmentInfoKHR(std::ostream &out, const VkFragmentShadingRateAttachmentInfoKHR* structInfo, Decoded_VkFragmentShadingRateAttachmentInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineFragmentShadingRateStateCreateInfoKHR(std::ostream &out, const VkPipelineFragmentShadingRateStateCreateInfoKHR* structInfo, Decoded_VkPipelineFragmentShadingRateStateCreateInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceFragmentShadingRateFeaturesKHR(std::ostream &out, const VkPhysicalDeviceFragmentShadingRateFeaturesKHR* structInfo, Decoded_VkPhysicalDeviceFragmentShadingRateFeaturesKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceFragmentShadingRatePropertiesKHR(std::ostream &out, const VkPhysicalDeviceFragmentShadingRatePropertiesKHR* structInfo, Decoded_VkPhysicalDeviceFragmentShadingRatePropertiesKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceFragmentShadingRateKHR(std::ostream &out, const VkPhysicalDeviceFragmentShadingRateKHR* structInfo, Decoded_VkPhysicalDeviceFragmentShadingRateKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSurfaceProtectedCapabilitiesKHR(std::ostream &out, const VkSurfaceProtectedCapabilitiesKHR* structInfo, Decoded_VkSurfaceProtectedCapabilitiesKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDevicePresentWaitFeaturesKHR(std::ostream &out, const VkPhysicalDevicePresentWaitFeaturesKHR* structInfo, Decoded_VkPhysicalDevicePresentWaitFeaturesKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR(std::ostream &out, const VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR* structInfo, Decoded_VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineInfoKHR(std::ostream &out, const VkPipelineInfoKHR* structInfo, Decoded_VkPipelineInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineExecutablePropertiesKHR(std::ostream &out, const VkPipelineExecutablePropertiesKHR* structInfo, Decoded_VkPipelineExecutablePropertiesKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineExecutableInfoKHR(std::ostream &out, const VkPipelineExecutableInfoKHR* structInfo, Decoded_VkPipelineExecutableInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineExecutableStatisticKHR(std::ostream &out, const VkPipelineExecutableStatisticKHR* structInfo, Decoded_VkPipelineExecutableStatisticKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineExecutableInternalRepresentationKHR(std::ostream &out, const VkPipelineExecutableInternalRepresentationKHR* structInfo, Decoded_VkPipelineExecutableInternalRepresentationKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMemoryMapInfoKHR(std::ostream &out, const VkMemoryMapInfoKHR* structInfo, Decoded_VkMemoryMapInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMemoryUnmapInfoKHR(std::ostream &out, const VkMemoryUnmapInfoKHR* structInfo, Decoded_VkMemoryUnmapInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineLibraryCreateInfoKHR(std::ostream &out, const VkPipelineLibraryCreateInfoKHR* structInfo, Decoded_VkPipelineLibraryCreateInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPresentIdKHR(std::ostream &out, const VkPresentIdKHR* structInfo, Decoded_VkPresentIdKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDevicePresentIdFeaturesKHR(std::ostream &out, const VkPhysicalDevicePresentIdFeaturesKHR* structInfo, Decoded_VkPhysicalDevicePresentIdFeaturesKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeInfoKHR(std::ostream &out, const VkVideoEncodeInfoKHR* structInfo, Decoded_VkVideoEncodeInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeCapabilitiesKHR(std::ostream &out, const VkVideoEncodeCapabilitiesKHR* structInfo, Decoded_VkVideoEncodeCapabilitiesKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkQueryPoolVideoEncodeFeedbackCreateInfoKHR(std::ostream &out, const VkQueryPoolVideoEncodeFeedbackCreateInfoKHR* structInfo, Decoded_VkQueryPoolVideoEncodeFeedbackCreateInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeUsageInfoKHR(std::ostream &out, const VkVideoEncodeUsageInfoKHR* structInfo, Decoded_VkVideoEncodeUsageInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeRateControlLayerInfoKHR(std::ostream &out, const VkVideoEncodeRateControlLayerInfoKHR* structInfo, Decoded_VkVideoEncodeRateControlLayerInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeRateControlInfoKHR(std::ostream &out, const VkVideoEncodeRateControlInfoKHR* structInfo, Decoded_VkVideoEncodeRateControlInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR(std::ostream &out, const VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR* structInfo, Decoded_VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeQualityLevelPropertiesKHR(std::ostream &out, const VkVideoEncodeQualityLevelPropertiesKHR* structInfo, Decoded_VkVideoEncodeQualityLevelPropertiesKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeQualityLevelInfoKHR(std::ostream &out, const VkVideoEncodeQualityLevelInfoKHR* structInfo, Decoded_VkVideoEncodeQualityLevelInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeSessionParametersGetInfoKHR(std::ostream &out, const VkVideoEncodeSessionParametersGetInfoKHR* structInfo, Decoded_VkVideoEncodeSessionParametersGetInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeSessionParametersFeedbackInfoKHR(std::ostream &out, const VkVideoEncodeSessionParametersFeedbackInfoKHR* structInfo, Decoded_VkVideoEncodeSessionParametersFeedbackInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkQueueFamilyCheckpointProperties2NV(std::ostream &out, const VkQueueFamilyCheckpointProperties2NV* structInfo, Decoded_VkQueueFamilyCheckpointProperties2NV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkCheckpointData2NV(std::ostream &out, const VkCheckpointData2NV* structInfo, Decoded_VkCheckpointData2NV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR(std::ostream &out, const VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR* structInfo, Decoded_VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR(std::ostream &out, const VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR* structInfo, Decoded_VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR(std::ostream &out, const VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR* structInfo, Decoded_VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR(std::ostream &out, const VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR* structInfo, Decoded_VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR(std::ostream &out, const VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR* structInfo, Decoded_VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkTraceRaysIndirectCommand2KHR(std::ostream &out, const VkTraceRaysIndirectCommand2KHR* structInfo, Decoded_VkTraceRaysIndirectCommand2KHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceMaintenance5FeaturesKHR(std::ostream &out, const VkPhysicalDeviceMaintenance5FeaturesKHR* structInfo, Decoded_VkPhysicalDeviceMaintenance5FeaturesKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceMaintenance5PropertiesKHR(std::ostream &out, const VkPhysicalDeviceMaintenance5PropertiesKHR* structInfo, Decoded_VkPhysicalDeviceMaintenance5PropertiesKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkRenderingAreaInfoKHR(std::ostream &out, const VkRenderingAreaInfoKHR* structInfo, Decoded_VkRenderingAreaInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImageSubresource2KHR(std::ostream &out, const VkImageSubresource2KHR* structInfo, Decoded_VkImageSubresource2KHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDeviceImageSubresourceInfoKHR(std::ostream &out, const VkDeviceImageSubresourceInfoKHR* structInfo, Decoded_VkDeviceImageSubresourceInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSubresourceLayout2KHR(std::ostream &out, const VkSubresourceLayout2KHR* structInfo, Decoded_VkSubresourceLayout2KHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineCreateFlags2CreateInfoKHR(std::ostream &out, const VkPipelineCreateFlags2CreateInfoKHR* structInfo, Decoded_VkPipelineCreateFlags2CreateInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkBufferUsageFlags2CreateInfoKHR(std::ostream &out, const VkBufferUsageFlags2CreateInfoKHR* structInfo, Decoded_VkBufferUsageFlags2CreateInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR(std::ostream &out, const VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR* structInfo, Decoded_VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkCooperativeMatrixPropertiesKHR(std::ostream &out, const VkCooperativeMatrixPropertiesKHR* structInfo, Decoded_VkCooperativeMatrixPropertiesKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceCooperativeMatrixFeaturesKHR(std::ostream &out, const VkPhysicalDeviceCooperativeMatrixFeaturesKHR* structInfo, Decoded_VkPhysicalDeviceCooperativeMatrixFeaturesKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceCooperativeMatrixPropertiesKHR(std::ostream &out, const VkPhysicalDeviceCooperativeMatrixPropertiesKHR* structInfo, Decoded_VkPhysicalDeviceCooperativeMatrixPropertiesKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDebugReportCallbackCreateInfoEXT(std::ostream &out, const VkDebugReportCallbackCreateInfoEXT* structInfo, Decoded_VkDebugReportCallbackCreateInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineRasterizationStateRasterizationOrderAMD(std::ostream &out, const VkPipelineRasterizationStateRasterizationOrderAMD* structInfo, Decoded_VkPipelineRasterizationStateRasterizationOrderAMD* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDebugMarkerObjectNameInfoEXT(std::ostream &out, const VkDebugMarkerObjectNameInfoEXT* structInfo, Decoded_VkDebugMarkerObjectNameInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDebugMarkerObjectTagInfoEXT(std::ostream &out, const VkDebugMarkerObjectTagInfoEXT* structInfo, Decoded_VkDebugMarkerObjectTagInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDebugMarkerMarkerInfoEXT(std::ostream &out, const VkDebugMarkerMarkerInfoEXT* structInfo, Decoded_VkDebugMarkerMarkerInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDedicatedAllocationImageCreateInfoNV(std::ostream &out, const VkDedicatedAllocationImageCreateInfoNV* structInfo, Decoded_VkDedicatedAllocationImageCreateInfoNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDedicatedAllocationBufferCreateInfoNV(std::ostream &out, const VkDedicatedAllocationBufferCreateInfoNV* structInfo, Decoded_VkDedicatedAllocationBufferCreateInfoNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDedicatedAllocationMemoryAllocateInfoNV(std::ostream &out, const VkDedicatedAllocationMemoryAllocateInfoNV* structInfo, Decoded_VkDedicatedAllocationMemoryAllocateInfoNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceTransformFeedbackFeaturesEXT(std::ostream &out, const VkPhysicalDeviceTransformFeedbackFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceTransformFeedbackFeaturesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceTransformFeedbackPropertiesEXT(std::ostream &out, const VkPhysicalDeviceTransformFeedbackPropertiesEXT* structInfo, Decoded_VkPhysicalDeviceTransformFeedbackPropertiesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineRasterizationStateStreamCreateInfoEXT(std::ostream &out, const VkPipelineRasterizationStateStreamCreateInfoEXT* structInfo, Decoded_VkPipelineRasterizationStateStreamCreateInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImageViewHandleInfoNVX(std::ostream &out, const VkImageViewHandleInfoNVX* structInfo, Decoded_VkImageViewHandleInfoNVX* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImageViewAddressPropertiesNVX(std::ostream &out, const VkImageViewAddressPropertiesNVX* structInfo, Decoded_VkImageViewAddressPropertiesNVX* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeH264CapabilitiesEXT(std::ostream &out, const VkVideoEncodeH264CapabilitiesEXT* structInfo, Decoded_VkVideoEncodeH264CapabilitiesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeH264QpEXT(std::ostream &out, const VkVideoEncodeH264QpEXT* structInfo, Decoded_VkVideoEncodeH264QpEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeH264QualityLevelPropertiesEXT(std::ostream &out, const VkVideoEncodeH264QualityLevelPropertiesEXT* structInfo, Decoded_VkVideoEncodeH264QualityLevelPropertiesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeH264SessionCreateInfoEXT(std::ostream &out, const VkVideoEncodeH264SessionCreateInfoEXT* structInfo, Decoded_VkVideoEncodeH264SessionCreateInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeH264SessionParametersAddInfoEXT(std::ostream &out, const VkVideoEncodeH264SessionParametersAddInfoEXT* structInfo, Decoded_VkVideoEncodeH264SessionParametersAddInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeH264SessionParametersCreateInfoEXT(std::ostream &out, const VkVideoEncodeH264SessionParametersCreateInfoEXT* structInfo, Decoded_VkVideoEncodeH264SessionParametersCreateInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeH264SessionParametersGetInfoEXT(std::ostream &out, const VkVideoEncodeH264SessionParametersGetInfoEXT* structInfo, Decoded_VkVideoEncodeH264SessionParametersGetInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeH264SessionParametersFeedbackInfoEXT(std::ostream &out, const VkVideoEncodeH264SessionParametersFeedbackInfoEXT* structInfo, Decoded_VkVideoEncodeH264SessionParametersFeedbackInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeH264NaluSliceInfoEXT(std::ostream &out, const VkVideoEncodeH264NaluSliceInfoEXT* structInfo, Decoded_VkVideoEncodeH264NaluSliceInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeH264PictureInfoEXT(std::ostream &out, const VkVideoEncodeH264PictureInfoEXT* structInfo, Decoded_VkVideoEncodeH264PictureInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeH264DpbSlotInfoEXT(std::ostream &out, const VkVideoEncodeH264DpbSlotInfoEXT* structInfo, Decoded_VkVideoEncodeH264DpbSlotInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeH264ProfileInfoEXT(std::ostream &out, const VkVideoEncodeH264ProfileInfoEXT* structInfo, Decoded_VkVideoEncodeH264ProfileInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeH264RateControlInfoEXT(std::ostream &out, const VkVideoEncodeH264RateControlInfoEXT* structInfo, Decoded_VkVideoEncodeH264RateControlInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeH264FrameSizeEXT(std::ostream &out, const VkVideoEncodeH264FrameSizeEXT* structInfo, Decoded_VkVideoEncodeH264FrameSizeEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeH264RateControlLayerInfoEXT(std::ostream &out, const VkVideoEncodeH264RateControlLayerInfoEXT* structInfo, Decoded_VkVideoEncodeH264RateControlLayerInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeH264GopRemainingFrameInfoEXT(std::ostream &out, const VkVideoEncodeH264GopRemainingFrameInfoEXT* structInfo, Decoded_VkVideoEncodeH264GopRemainingFrameInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeH265CapabilitiesEXT(std::ostream &out, const VkVideoEncodeH265CapabilitiesEXT* structInfo, Decoded_VkVideoEncodeH265CapabilitiesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeH265SessionCreateInfoEXT(std::ostream &out, const VkVideoEncodeH265SessionCreateInfoEXT* structInfo, Decoded_VkVideoEncodeH265SessionCreateInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeH265QpEXT(std::ostream &out, const VkVideoEncodeH265QpEXT* structInfo, Decoded_VkVideoEncodeH265QpEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeH265QualityLevelPropertiesEXT(std::ostream &out, const VkVideoEncodeH265QualityLevelPropertiesEXT* structInfo, Decoded_VkVideoEncodeH265QualityLevelPropertiesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeH265SessionParametersAddInfoEXT(std::ostream &out, const VkVideoEncodeH265SessionParametersAddInfoEXT* structInfo, Decoded_VkVideoEncodeH265SessionParametersAddInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeH265SessionParametersCreateInfoEXT(std::ostream &out, const VkVideoEncodeH265SessionParametersCreateInfoEXT* structInfo, Decoded_VkVideoEncodeH265SessionParametersCreateInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeH265SessionParametersGetInfoEXT(std::ostream &out, const VkVideoEncodeH265SessionParametersGetInfoEXT* structInfo, Decoded_VkVideoEncodeH265SessionParametersGetInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeH265SessionParametersFeedbackInfoEXT(std::ostream &out, const VkVideoEncodeH265SessionParametersFeedbackInfoEXT* structInfo, Decoded_VkVideoEncodeH265SessionParametersFeedbackInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeH265NaluSliceSegmentInfoEXT(std::ostream &out, const VkVideoEncodeH265NaluSliceSegmentInfoEXT* structInfo, Decoded_VkVideoEncodeH265NaluSliceSegmentInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeH265PictureInfoEXT(std::ostream &out, const VkVideoEncodeH265PictureInfoEXT* structInfo, Decoded_VkVideoEncodeH265PictureInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeH265DpbSlotInfoEXT(std::ostream &out, const VkVideoEncodeH265DpbSlotInfoEXT* structInfo, Decoded_VkVideoEncodeH265DpbSlotInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeH265ProfileInfoEXT(std::ostream &out, const VkVideoEncodeH265ProfileInfoEXT* structInfo, Decoded_VkVideoEncodeH265ProfileInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeH265RateControlInfoEXT(std::ostream &out, const VkVideoEncodeH265RateControlInfoEXT* structInfo, Decoded_VkVideoEncodeH265RateControlInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeH265FrameSizeEXT(std::ostream &out, const VkVideoEncodeH265FrameSizeEXT* structInfo, Decoded_VkVideoEncodeH265FrameSizeEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeH265RateControlLayerInfoEXT(std::ostream &out, const VkVideoEncodeH265RateControlLayerInfoEXT* structInfo, Decoded_VkVideoEncodeH265RateControlLayerInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVideoEncodeH265GopRemainingFrameInfoEXT(std::ostream &out, const VkVideoEncodeH265GopRemainingFrameInfoEXT* structInfo, Decoded_VkVideoEncodeH265GopRemainingFrameInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkTextureLODGatherFormatPropertiesAMD(std::ostream &out, const VkTextureLODGatherFormatPropertiesAMD* structInfo, Decoded_VkTextureLODGatherFormatPropertiesAMD* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkShaderResourceUsageAMD(std::ostream &out, const VkShaderResourceUsageAMD* structInfo, Decoded_VkShaderResourceUsageAMD* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkShaderStatisticsInfoAMD(std::ostream &out, const VkShaderStatisticsInfoAMD* structInfo, Decoded_VkShaderStatisticsInfoAMD* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkStreamDescriptorSurfaceCreateInfoGGP(std::ostream &out, const VkStreamDescriptorSurfaceCreateInfoGGP* structInfo, Decoded_VkStreamDescriptorSurfaceCreateInfoGGP* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceCornerSampledImageFeaturesNV(std::ostream &out, const VkPhysicalDeviceCornerSampledImageFeaturesNV* structInfo, Decoded_VkPhysicalDeviceCornerSampledImageFeaturesNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkExternalImageFormatPropertiesNV(std::ostream &out, const VkExternalImageFormatPropertiesNV* structInfo, Decoded_VkExternalImageFormatPropertiesNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkExternalMemoryImageCreateInfoNV(std::ostream &out, const VkExternalMemoryImageCreateInfoNV* structInfo, Decoded_VkExternalMemoryImageCreateInfoNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkExportMemoryAllocateInfoNV(std::ostream &out, const VkExportMemoryAllocateInfoNV* structInfo, Decoded_VkExportMemoryAllocateInfoNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImportMemoryWin32HandleInfoNV(std::ostream &out, const VkImportMemoryWin32HandleInfoNV* structInfo, Decoded_VkImportMemoryWin32HandleInfoNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkExportMemoryWin32HandleInfoNV(std::ostream &out, const VkExportMemoryWin32HandleInfoNV* structInfo, Decoded_VkExportMemoryWin32HandleInfoNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkWin32KeyedMutexAcquireReleaseInfoNV(std::ostream &out, const VkWin32KeyedMutexAcquireReleaseInfoNV* structInfo, Decoded_VkWin32KeyedMutexAcquireReleaseInfoNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkValidationFlagsEXT(std::ostream &out, const VkValidationFlagsEXT* structInfo, Decoded_VkValidationFlagsEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkViSurfaceCreateInfoNN(std::ostream &out, const VkViSurfaceCreateInfoNN* structInfo, Decoded_VkViSurfaceCreateInfoNN* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImageViewASTCDecodeModeEXT(std::ostream &out, const VkImageViewASTCDecodeModeEXT* structInfo, Decoded_VkImageViewASTCDecodeModeEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceASTCDecodeFeaturesEXT(std::ostream &out, const VkPhysicalDeviceASTCDecodeFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceASTCDecodeFeaturesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDevicePipelineRobustnessFeaturesEXT(std::ostream &out, const VkPhysicalDevicePipelineRobustnessFeaturesEXT* structInfo, Decoded_VkPhysicalDevicePipelineRobustnessFeaturesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDevicePipelineRobustnessPropertiesEXT(std::ostream &out, const VkPhysicalDevicePipelineRobustnessPropertiesEXT* structInfo, Decoded_VkPhysicalDevicePipelineRobustnessPropertiesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineRobustnessCreateInfoEXT(std::ostream &out, const VkPipelineRobustnessCreateInfoEXT* structInfo, Decoded_VkPipelineRobustnessCreateInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkConditionalRenderingBeginInfoEXT(std::ostream &out, const VkConditionalRenderingBeginInfoEXT* structInfo, Decoded_VkConditionalRenderingBeginInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceConditionalRenderingFeaturesEXT(std::ostream &out, const VkPhysicalDeviceConditionalRenderingFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceConditionalRenderingFeaturesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkCommandBufferInheritanceConditionalRenderingInfoEXT(std::ostream &out, const VkCommandBufferInheritanceConditionalRenderingInfoEXT* structInfo, Decoded_VkCommandBufferInheritanceConditionalRenderingInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkViewportWScalingNV(std::ostream &out, const VkViewportWScalingNV* structInfo, Decoded_VkViewportWScalingNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineViewportWScalingStateCreateInfoNV(std::ostream &out, const VkPipelineViewportWScalingStateCreateInfoNV* structInfo, Decoded_VkPipelineViewportWScalingStateCreateInfoNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSurfaceCapabilities2EXT(std::ostream &out, const VkSurfaceCapabilities2EXT* structInfo, Decoded_VkSurfaceCapabilities2EXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDisplayPowerInfoEXT(std::ostream &out, const VkDisplayPowerInfoEXT* structInfo, Decoded_VkDisplayPowerInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDeviceEventInfoEXT(std::ostream &out, const VkDeviceEventInfoEXT* structInfo, Decoded_VkDeviceEventInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDisplayEventInfoEXT(std::ostream &out, const VkDisplayEventInfoEXT* structInfo, Decoded_VkDisplayEventInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSwapchainCounterCreateInfoEXT(std::ostream &out, const VkSwapchainCounterCreateInfoEXT* structInfo, Decoded_VkSwapchainCounterCreateInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkRefreshCycleDurationGOOGLE(std::ostream &out, const VkRefreshCycleDurationGOOGLE* structInfo, Decoded_VkRefreshCycleDurationGOOGLE* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPastPresentationTimingGOOGLE(std::ostream &out, const VkPastPresentationTimingGOOGLE* structInfo, Decoded_VkPastPresentationTimingGOOGLE* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPresentTimeGOOGLE(std::ostream &out, const VkPresentTimeGOOGLE* structInfo, Decoded_VkPresentTimeGOOGLE* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPresentTimesInfoGOOGLE(std::ostream &out, const VkPresentTimesInfoGOOGLE* structInfo, Decoded_VkPresentTimesInfoGOOGLE* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX(std::ostream &out, const VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX* structInfo, Decoded_VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkViewportSwizzleNV(std::ostream &out, const VkViewportSwizzleNV* structInfo, Decoded_VkViewportSwizzleNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineViewportSwizzleStateCreateInfoNV(std::ostream &out, const VkPipelineViewportSwizzleStateCreateInfoNV* structInfo, Decoded_VkPipelineViewportSwizzleStateCreateInfoNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceDiscardRectanglePropertiesEXT(std::ostream &out, const VkPhysicalDeviceDiscardRectanglePropertiesEXT* structInfo, Decoded_VkPhysicalDeviceDiscardRectanglePropertiesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineDiscardRectangleStateCreateInfoEXT(std::ostream &out, const VkPipelineDiscardRectangleStateCreateInfoEXT* structInfo, Decoded_VkPipelineDiscardRectangleStateCreateInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceConservativeRasterizationPropertiesEXT(std::ostream &out, const VkPhysicalDeviceConservativeRasterizationPropertiesEXT* structInfo, Decoded_VkPhysicalDeviceConservativeRasterizationPropertiesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineRasterizationConservativeStateCreateInfoEXT(std::ostream &out, const VkPipelineRasterizationConservativeStateCreateInfoEXT* structInfo, Decoded_VkPipelineRasterizationConservativeStateCreateInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceDepthClipEnableFeaturesEXT(std::ostream &out, const VkPhysicalDeviceDepthClipEnableFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceDepthClipEnableFeaturesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineRasterizationDepthClipStateCreateInfoEXT(std::ostream &out, const VkPipelineRasterizationDepthClipStateCreateInfoEXT* structInfo, Decoded_VkPipelineRasterizationDepthClipStateCreateInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkXYColorEXT(std::ostream &out, const VkXYColorEXT* structInfo, Decoded_VkXYColorEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkHdrMetadataEXT(std::ostream &out, const VkHdrMetadataEXT* structInfo, Decoded_VkHdrMetadataEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkIOSSurfaceCreateInfoMVK(std::ostream &out, const VkIOSSurfaceCreateInfoMVK* structInfo, Decoded_VkIOSSurfaceCreateInfoMVK* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMacOSSurfaceCreateInfoMVK(std::ostream &out, const VkMacOSSurfaceCreateInfoMVK* structInfo, Decoded_VkMacOSSurfaceCreateInfoMVK* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDebugUtilsLabelEXT(std::ostream &out, const VkDebugUtilsLabelEXT* structInfo, Decoded_VkDebugUtilsLabelEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDebugUtilsObjectNameInfoEXT(std::ostream &out, const VkDebugUtilsObjectNameInfoEXT* structInfo, Decoded_VkDebugUtilsObjectNameInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDebugUtilsMessengerCallbackDataEXT(std::ostream &out, const VkDebugUtilsMessengerCallbackDataEXT* structInfo, Decoded_VkDebugUtilsMessengerCallbackDataEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDebugUtilsObjectTagInfoEXT(std::ostream &out, const VkDebugUtilsObjectTagInfoEXT* structInfo, Decoded_VkDebugUtilsObjectTagInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAndroidHardwareBufferUsageANDROID(std::ostream &out, const VkAndroidHardwareBufferUsageANDROID* structInfo, Decoded_VkAndroidHardwareBufferUsageANDROID* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAndroidHardwareBufferPropertiesANDROID(std::ostream &out, const VkAndroidHardwareBufferPropertiesANDROID* structInfo, Decoded_VkAndroidHardwareBufferPropertiesANDROID* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAndroidHardwareBufferFormatPropertiesANDROID(std::ostream &out, const VkAndroidHardwareBufferFormatPropertiesANDROID* structInfo, Decoded_VkAndroidHardwareBufferFormatPropertiesANDROID* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImportAndroidHardwareBufferInfoANDROID(std::ostream &out, const VkImportAndroidHardwareBufferInfoANDROID* structInfo, Decoded_VkImportAndroidHardwareBufferInfoANDROID* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMemoryGetAndroidHardwareBufferInfoANDROID(std::ostream &out, const VkMemoryGetAndroidHardwareBufferInfoANDROID* structInfo, Decoded_VkMemoryGetAndroidHardwareBufferInfoANDROID* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkExternalFormatANDROID(std::ostream &out, const VkExternalFormatANDROID* structInfo, Decoded_VkExternalFormatANDROID* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAndroidHardwareBufferFormatProperties2ANDROID(std::ostream &out, const VkAndroidHardwareBufferFormatProperties2ANDROID* structInfo, Decoded_VkAndroidHardwareBufferFormatProperties2ANDROID* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSampleLocationEXT(std::ostream &out, const VkSampleLocationEXT* structInfo, Decoded_VkSampleLocationEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSampleLocationsInfoEXT(std::ostream &out, const VkSampleLocationsInfoEXT* structInfo, Decoded_VkSampleLocationsInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAttachmentSampleLocationsEXT(std::ostream &out, const VkAttachmentSampleLocationsEXT* structInfo, Decoded_VkAttachmentSampleLocationsEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSubpassSampleLocationsEXT(std::ostream &out, const VkSubpassSampleLocationsEXT* structInfo, Decoded_VkSubpassSampleLocationsEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkRenderPassSampleLocationsBeginInfoEXT(std::ostream &out, const VkRenderPassSampleLocationsBeginInfoEXT* structInfo, Decoded_VkRenderPassSampleLocationsBeginInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineSampleLocationsStateCreateInfoEXT(std::ostream &out, const VkPipelineSampleLocationsStateCreateInfoEXT* structInfo, Decoded_VkPipelineSampleLocationsStateCreateInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceSampleLocationsPropertiesEXT(std::ostream &out, const VkPhysicalDeviceSampleLocationsPropertiesEXT* structInfo, Decoded_VkPhysicalDeviceSampleLocationsPropertiesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMultisamplePropertiesEXT(std::ostream &out, const VkMultisamplePropertiesEXT* structInfo, Decoded_VkMultisamplePropertiesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT(std::ostream &out, const VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT(std::ostream &out, const VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT* structInfo, Decoded_VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineColorBlendAdvancedStateCreateInfoEXT(std::ostream &out, const VkPipelineColorBlendAdvancedStateCreateInfoEXT* structInfo, Decoded_VkPipelineColorBlendAdvancedStateCreateInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineCoverageToColorStateCreateInfoNV(std::ostream &out, const VkPipelineCoverageToColorStateCreateInfoNV* structInfo, Decoded_VkPipelineCoverageToColorStateCreateInfoNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineCoverageModulationStateCreateInfoNV(std::ostream &out, const VkPipelineCoverageModulationStateCreateInfoNV* structInfo, Decoded_VkPipelineCoverageModulationStateCreateInfoNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceShaderSMBuiltinsPropertiesNV(std::ostream &out, const VkPhysicalDeviceShaderSMBuiltinsPropertiesNV* structInfo, Decoded_VkPhysicalDeviceShaderSMBuiltinsPropertiesNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceShaderSMBuiltinsFeaturesNV(std::ostream &out, const VkPhysicalDeviceShaderSMBuiltinsFeaturesNV* structInfo, Decoded_VkPhysicalDeviceShaderSMBuiltinsFeaturesNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDrmFormatModifierPropertiesEXT(std::ostream &out, const VkDrmFormatModifierPropertiesEXT* structInfo, Decoded_VkDrmFormatModifierPropertiesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDrmFormatModifierPropertiesListEXT(std::ostream &out, const VkDrmFormatModifierPropertiesListEXT* structInfo, Decoded_VkDrmFormatModifierPropertiesListEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceImageDrmFormatModifierInfoEXT(std::ostream &out, const VkPhysicalDeviceImageDrmFormatModifierInfoEXT* structInfo, Decoded_VkPhysicalDeviceImageDrmFormatModifierInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImageDrmFormatModifierListCreateInfoEXT(std::ostream &out, const VkImageDrmFormatModifierListCreateInfoEXT* structInfo, Decoded_VkImageDrmFormatModifierListCreateInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImageDrmFormatModifierExplicitCreateInfoEXT(std::ostream &out, const VkImageDrmFormatModifierExplicitCreateInfoEXT* structInfo, Decoded_VkImageDrmFormatModifierExplicitCreateInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImageDrmFormatModifierPropertiesEXT(std::ostream &out, const VkImageDrmFormatModifierPropertiesEXT* structInfo, Decoded_VkImageDrmFormatModifierPropertiesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDrmFormatModifierProperties2EXT(std::ostream &out, const VkDrmFormatModifierProperties2EXT* structInfo, Decoded_VkDrmFormatModifierProperties2EXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDrmFormatModifierPropertiesList2EXT(std::ostream &out, const VkDrmFormatModifierPropertiesList2EXT* structInfo, Decoded_VkDrmFormatModifierPropertiesList2EXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkValidationCacheCreateInfoEXT(std::ostream &out, const VkValidationCacheCreateInfoEXT* structInfo, Decoded_VkValidationCacheCreateInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkShaderModuleValidationCacheCreateInfoEXT(std::ostream &out, const VkShaderModuleValidationCacheCreateInfoEXT* structInfo, Decoded_VkShaderModuleValidationCacheCreateInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkShadingRatePaletteNV(std::ostream &out, const VkShadingRatePaletteNV* structInfo, Decoded_VkShadingRatePaletteNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineViewportShadingRateImageStateCreateInfoNV(std::ostream &out, const VkPipelineViewportShadingRateImageStateCreateInfoNV* structInfo, Decoded_VkPipelineViewportShadingRateImageStateCreateInfoNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceShadingRateImageFeaturesNV(std::ostream &out, const VkPhysicalDeviceShadingRateImageFeaturesNV* structInfo, Decoded_VkPhysicalDeviceShadingRateImageFeaturesNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceShadingRateImagePropertiesNV(std::ostream &out, const VkPhysicalDeviceShadingRateImagePropertiesNV* structInfo, Decoded_VkPhysicalDeviceShadingRateImagePropertiesNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkCoarseSampleLocationNV(std::ostream &out, const VkCoarseSampleLocationNV* structInfo, Decoded_VkCoarseSampleLocationNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkCoarseSampleOrderCustomNV(std::ostream &out, const VkCoarseSampleOrderCustomNV* structInfo, Decoded_VkCoarseSampleOrderCustomNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineViewportCoarseSampleOrderStateCreateInfoNV(std::ostream &out, const VkPipelineViewportCoarseSampleOrderStateCreateInfoNV* structInfo, Decoded_VkPipelineViewportCoarseSampleOrderStateCreateInfoNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkRayTracingShaderGroupCreateInfoNV(std::ostream &out, const VkRayTracingShaderGroupCreateInfoNV* structInfo, Decoded_VkRayTracingShaderGroupCreateInfoNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkRayTracingPipelineCreateInfoNV(std::ostream &out, const VkRayTracingPipelineCreateInfoNV* structInfo, Decoded_VkRayTracingPipelineCreateInfoNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkGeometryTrianglesNV(std::ostream &out, const VkGeometryTrianglesNV* structInfo, Decoded_VkGeometryTrianglesNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkGeometryAABBNV(std::ostream &out, const VkGeometryAABBNV* structInfo, Decoded_VkGeometryAABBNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkGeometryDataNV(std::ostream &out, const VkGeometryDataNV* structInfo, Decoded_VkGeometryDataNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkGeometryNV(std::ostream &out, const VkGeometryNV* structInfo, Decoded_VkGeometryNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAccelerationStructureInfoNV(std::ostream &out, const VkAccelerationStructureInfoNV* structInfo, Decoded_VkAccelerationStructureInfoNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAccelerationStructureCreateInfoNV(std::ostream &out, const VkAccelerationStructureCreateInfoNV* structInfo, Decoded_VkAccelerationStructureCreateInfoNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkBindAccelerationStructureMemoryInfoNV(std::ostream &out, const VkBindAccelerationStructureMemoryInfoNV* structInfo, Decoded_VkBindAccelerationStructureMemoryInfoNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkWriteDescriptorSetAccelerationStructureNV(std::ostream &out, const VkWriteDescriptorSetAccelerationStructureNV* structInfo, Decoded_VkWriteDescriptorSetAccelerationStructureNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAccelerationStructureMemoryRequirementsInfoNV(std::ostream &out, const VkAccelerationStructureMemoryRequirementsInfoNV* structInfo, Decoded_VkAccelerationStructureMemoryRequirementsInfoNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceRayTracingPropertiesNV(std::ostream &out, const VkPhysicalDeviceRayTracingPropertiesNV* structInfo, Decoded_VkPhysicalDeviceRayTracingPropertiesNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkTransformMatrixKHR(std::ostream &out, const VkTransformMatrixKHR* structInfo, Decoded_VkTransformMatrixKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAabbPositionsKHR(std::ostream &out, const VkAabbPositionsKHR* structInfo, Decoded_VkAabbPositionsKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAccelerationStructureInstanceKHR(std::ostream &out, const VkAccelerationStructureInstanceKHR* structInfo, Decoded_VkAccelerationStructureInstanceKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV(std::ostream &out, const VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV* structInfo, Decoded_VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineRepresentativeFragmentTestStateCreateInfoNV(std::ostream &out, const VkPipelineRepresentativeFragmentTestStateCreateInfoNV* structInfo, Decoded_VkPipelineRepresentativeFragmentTestStateCreateInfoNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceImageViewImageFormatInfoEXT(std::ostream &out, const VkPhysicalDeviceImageViewImageFormatInfoEXT* structInfo, Decoded_VkPhysicalDeviceImageViewImageFormatInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkFilterCubicImageViewImageFormatPropertiesEXT(std::ostream &out, const VkFilterCubicImageViewImageFormatPropertiesEXT* structInfo, Decoded_VkFilterCubicImageViewImageFormatPropertiesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImportMemoryHostPointerInfoEXT(std::ostream &out, const VkImportMemoryHostPointerInfoEXT* structInfo, Decoded_VkImportMemoryHostPointerInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMemoryHostPointerPropertiesEXT(std::ostream &out, const VkMemoryHostPointerPropertiesEXT* structInfo, Decoded_VkMemoryHostPointerPropertiesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceExternalMemoryHostPropertiesEXT(std::ostream &out, const VkPhysicalDeviceExternalMemoryHostPropertiesEXT* structInfo, Decoded_VkPhysicalDeviceExternalMemoryHostPropertiesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineCompilerControlCreateInfoAMD(std::ostream &out, const VkPipelineCompilerControlCreateInfoAMD* structInfo, Decoded_VkPipelineCompilerControlCreateInfoAMD* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkCalibratedTimestampInfoEXT(std::ostream &out, const VkCalibratedTimestampInfoEXT* structInfo, Decoded_VkCalibratedTimestampInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceShaderCorePropertiesAMD(std::ostream &out, const VkPhysicalDeviceShaderCorePropertiesAMD* structInfo, Decoded_VkPhysicalDeviceShaderCorePropertiesAMD* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDeviceMemoryOverallocationCreateInfoAMD(std::ostream &out, const VkDeviceMemoryOverallocationCreateInfoAMD* structInfo, Decoded_VkDeviceMemoryOverallocationCreateInfoAMD* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT(std::ostream &out, const VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT* structInfo, Decoded_VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVertexInputBindingDivisorDescriptionEXT(std::ostream &out, const VkVertexInputBindingDivisorDescriptionEXT* structInfo, Decoded_VkVertexInputBindingDivisorDescriptionEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineVertexInputDivisorStateCreateInfoEXT(std::ostream &out, const VkPipelineVertexInputDivisorStateCreateInfoEXT* structInfo, Decoded_VkPipelineVertexInputDivisorStateCreateInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT(std::ostream &out, const VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPresentFrameTokenGGP(std::ostream &out, const VkPresentFrameTokenGGP* structInfo, Decoded_VkPresentFrameTokenGGP* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceComputeShaderDerivativesFeaturesNV(std::ostream &out, const VkPhysicalDeviceComputeShaderDerivativesFeaturesNV* structInfo, Decoded_VkPhysicalDeviceComputeShaderDerivativesFeaturesNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceMeshShaderFeaturesNV(std::ostream &out, const VkPhysicalDeviceMeshShaderFeaturesNV* structInfo, Decoded_VkPhysicalDeviceMeshShaderFeaturesNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceMeshShaderPropertiesNV(std::ostream &out, const VkPhysicalDeviceMeshShaderPropertiesNV* structInfo, Decoded_VkPhysicalDeviceMeshShaderPropertiesNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDrawMeshTasksIndirectCommandNV(std::ostream &out, const VkDrawMeshTasksIndirectCommandNV* structInfo, Decoded_VkDrawMeshTasksIndirectCommandNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceShaderImageFootprintFeaturesNV(std::ostream &out, const VkPhysicalDeviceShaderImageFootprintFeaturesNV* structInfo, Decoded_VkPhysicalDeviceShaderImageFootprintFeaturesNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineViewportExclusiveScissorStateCreateInfoNV(std::ostream &out, const VkPipelineViewportExclusiveScissorStateCreateInfoNV* structInfo, Decoded_VkPipelineViewportExclusiveScissorStateCreateInfoNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceExclusiveScissorFeaturesNV(std::ostream &out, const VkPhysicalDeviceExclusiveScissorFeaturesNV* structInfo, Decoded_VkPhysicalDeviceExclusiveScissorFeaturesNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkQueueFamilyCheckpointPropertiesNV(std::ostream &out, const VkQueueFamilyCheckpointPropertiesNV* structInfo, Decoded_VkQueueFamilyCheckpointPropertiesNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkCheckpointDataNV(std::ostream &out, const VkCheckpointDataNV* structInfo, Decoded_VkCheckpointDataNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL(std::ostream &out, const VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL* structInfo, Decoded_VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPerformanceValueINTEL(std::ostream &out, const VkPerformanceValueINTEL* structInfo, Decoded_VkPerformanceValueINTEL* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkInitializePerformanceApiInfoINTEL(std::ostream &out, const VkInitializePerformanceApiInfoINTEL* structInfo, Decoded_VkInitializePerformanceApiInfoINTEL* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkQueryPoolPerformanceQueryCreateInfoINTEL(std::ostream &out, const VkQueryPoolPerformanceQueryCreateInfoINTEL* structInfo, Decoded_VkQueryPoolPerformanceQueryCreateInfoINTEL* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPerformanceMarkerInfoINTEL(std::ostream &out, const VkPerformanceMarkerInfoINTEL* structInfo, Decoded_VkPerformanceMarkerInfoINTEL* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPerformanceStreamMarkerInfoINTEL(std::ostream &out, const VkPerformanceStreamMarkerInfoINTEL* structInfo, Decoded_VkPerformanceStreamMarkerInfoINTEL* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPerformanceOverrideInfoINTEL(std::ostream &out, const VkPerformanceOverrideInfoINTEL* structInfo, Decoded_VkPerformanceOverrideInfoINTEL* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPerformanceConfigurationAcquireInfoINTEL(std::ostream &out, const VkPerformanceConfigurationAcquireInfoINTEL* structInfo, Decoded_VkPerformanceConfigurationAcquireInfoINTEL* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDevicePCIBusInfoPropertiesEXT(std::ostream &out, const VkPhysicalDevicePCIBusInfoPropertiesEXT* structInfo, Decoded_VkPhysicalDevicePCIBusInfoPropertiesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDisplayNativeHdrSurfaceCapabilitiesAMD(std::ostream &out, const VkDisplayNativeHdrSurfaceCapabilitiesAMD* structInfo, Decoded_VkDisplayNativeHdrSurfaceCapabilitiesAMD* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSwapchainDisplayNativeHdrCreateInfoAMD(std::ostream &out, const VkSwapchainDisplayNativeHdrCreateInfoAMD* structInfo, Decoded_VkSwapchainDisplayNativeHdrCreateInfoAMD* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImagePipeSurfaceCreateInfoFUCHSIA(std::ostream &out, const VkImagePipeSurfaceCreateInfoFUCHSIA* structInfo, Decoded_VkImagePipeSurfaceCreateInfoFUCHSIA* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMetalSurfaceCreateInfoEXT(std::ostream &out, const VkMetalSurfaceCreateInfoEXT* structInfo, Decoded_VkMetalSurfaceCreateInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceFragmentDensityMapFeaturesEXT(std::ostream &out, const VkPhysicalDeviceFragmentDensityMapFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceFragmentDensityMapFeaturesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceFragmentDensityMapPropertiesEXT(std::ostream &out, const VkPhysicalDeviceFragmentDensityMapPropertiesEXT* structInfo, Decoded_VkPhysicalDeviceFragmentDensityMapPropertiesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkRenderPassFragmentDensityMapCreateInfoEXT(std::ostream &out, const VkRenderPassFragmentDensityMapCreateInfoEXT* structInfo, Decoded_VkRenderPassFragmentDensityMapCreateInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceShaderCoreProperties2AMD(std::ostream &out, const VkPhysicalDeviceShaderCoreProperties2AMD* structInfo, Decoded_VkPhysicalDeviceShaderCoreProperties2AMD* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceCoherentMemoryFeaturesAMD(std::ostream &out, const VkPhysicalDeviceCoherentMemoryFeaturesAMD* structInfo, Decoded_VkPhysicalDeviceCoherentMemoryFeaturesAMD* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT(std::ostream &out, const VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT* structInfo, Decoded_VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceMemoryBudgetPropertiesEXT(std::ostream &out, const VkPhysicalDeviceMemoryBudgetPropertiesEXT* structInfo, Decoded_VkPhysicalDeviceMemoryBudgetPropertiesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceMemoryPriorityFeaturesEXT(std::ostream &out, const VkPhysicalDeviceMemoryPriorityFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceMemoryPriorityFeaturesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMemoryPriorityAllocateInfoEXT(std::ostream &out, const VkMemoryPriorityAllocateInfoEXT* structInfo, Decoded_VkMemoryPriorityAllocateInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV(std::ostream &out, const VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV* structInfo, Decoded_VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceBufferDeviceAddressFeaturesEXT(std::ostream &out, const VkPhysicalDeviceBufferDeviceAddressFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceBufferDeviceAddressFeaturesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkBufferDeviceAddressCreateInfoEXT(std::ostream &out, const VkBufferDeviceAddressCreateInfoEXT* structInfo, Decoded_VkBufferDeviceAddressCreateInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkValidationFeaturesEXT(std::ostream &out, const VkValidationFeaturesEXT* structInfo, Decoded_VkValidationFeaturesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkCooperativeMatrixPropertiesNV(std::ostream &out, const VkCooperativeMatrixPropertiesNV* structInfo, Decoded_VkCooperativeMatrixPropertiesNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceCooperativeMatrixFeaturesNV(std::ostream &out, const VkPhysicalDeviceCooperativeMatrixFeaturesNV* structInfo, Decoded_VkPhysicalDeviceCooperativeMatrixFeaturesNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceCooperativeMatrixPropertiesNV(std::ostream &out, const VkPhysicalDeviceCooperativeMatrixPropertiesNV* structInfo, Decoded_VkPhysicalDeviceCooperativeMatrixPropertiesNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceCoverageReductionModeFeaturesNV(std::ostream &out, const VkPhysicalDeviceCoverageReductionModeFeaturesNV* structInfo, Decoded_VkPhysicalDeviceCoverageReductionModeFeaturesNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineCoverageReductionStateCreateInfoNV(std::ostream &out, const VkPipelineCoverageReductionStateCreateInfoNV* structInfo, Decoded_VkPipelineCoverageReductionStateCreateInfoNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkFramebufferMixedSamplesCombinationNV(std::ostream &out, const VkFramebufferMixedSamplesCombinationNV* structInfo, Decoded_VkFramebufferMixedSamplesCombinationNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT(std::ostream &out, const VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceYcbcrImageArraysFeaturesEXT(std::ostream &out, const VkPhysicalDeviceYcbcrImageArraysFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceYcbcrImageArraysFeaturesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceProvokingVertexFeaturesEXT(std::ostream &out, const VkPhysicalDeviceProvokingVertexFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceProvokingVertexFeaturesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceProvokingVertexPropertiesEXT(std::ostream &out, const VkPhysicalDeviceProvokingVertexPropertiesEXT* structInfo, Decoded_VkPhysicalDeviceProvokingVertexPropertiesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineRasterizationProvokingVertexStateCreateInfoEXT(std::ostream &out, const VkPipelineRasterizationProvokingVertexStateCreateInfoEXT* structInfo, Decoded_VkPipelineRasterizationProvokingVertexStateCreateInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSurfaceFullScreenExclusiveInfoEXT(std::ostream &out, const VkSurfaceFullScreenExclusiveInfoEXT* structInfo, Decoded_VkSurfaceFullScreenExclusiveInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSurfaceCapabilitiesFullScreenExclusiveEXT(std::ostream &out, const VkSurfaceCapabilitiesFullScreenExclusiveEXT* structInfo, Decoded_VkSurfaceCapabilitiesFullScreenExclusiveEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSurfaceFullScreenExclusiveWin32InfoEXT(std::ostream &out, const VkSurfaceFullScreenExclusiveWin32InfoEXT* structInfo, Decoded_VkSurfaceFullScreenExclusiveWin32InfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkHeadlessSurfaceCreateInfoEXT(std::ostream &out, const VkHeadlessSurfaceCreateInfoEXT* structInfo, Decoded_VkHeadlessSurfaceCreateInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceLineRasterizationFeaturesEXT(std::ostream &out, const VkPhysicalDeviceLineRasterizationFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceLineRasterizationFeaturesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceLineRasterizationPropertiesEXT(std::ostream &out, const VkPhysicalDeviceLineRasterizationPropertiesEXT* structInfo, Decoded_VkPhysicalDeviceLineRasterizationPropertiesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineRasterizationLineStateCreateInfoEXT(std::ostream &out, const VkPipelineRasterizationLineStateCreateInfoEXT* structInfo, Decoded_VkPipelineRasterizationLineStateCreateInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceShaderAtomicFloatFeaturesEXT(std::ostream &out, const VkPhysicalDeviceShaderAtomicFloatFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceShaderAtomicFloatFeaturesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceIndexTypeUint8FeaturesEXT(std::ostream &out, const VkPhysicalDeviceIndexTypeUint8FeaturesEXT* structInfo, Decoded_VkPhysicalDeviceIndexTypeUint8FeaturesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceExtendedDynamicStateFeaturesEXT(std::ostream &out, const VkPhysicalDeviceExtendedDynamicStateFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceExtendedDynamicStateFeaturesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceHostImageCopyFeaturesEXT(std::ostream &out, const VkPhysicalDeviceHostImageCopyFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceHostImageCopyFeaturesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceHostImageCopyPropertiesEXT(std::ostream &out, const VkPhysicalDeviceHostImageCopyPropertiesEXT* structInfo, Decoded_VkPhysicalDeviceHostImageCopyPropertiesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMemoryToImageCopyEXT(std::ostream &out, const VkMemoryToImageCopyEXT* structInfo, Decoded_VkMemoryToImageCopyEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImageToMemoryCopyEXT(std::ostream &out, const VkImageToMemoryCopyEXT* structInfo, Decoded_VkImageToMemoryCopyEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkCopyMemoryToImageInfoEXT(std::ostream &out, const VkCopyMemoryToImageInfoEXT* structInfo, Decoded_VkCopyMemoryToImageInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkCopyImageToMemoryInfoEXT(std::ostream &out, const VkCopyImageToMemoryInfoEXT* structInfo, Decoded_VkCopyImageToMemoryInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkCopyImageToImageInfoEXT(std::ostream &out, const VkCopyImageToImageInfoEXT* structInfo, Decoded_VkCopyImageToImageInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkHostImageLayoutTransitionInfoEXT(std::ostream &out, const VkHostImageLayoutTransitionInfoEXT* structInfo, Decoded_VkHostImageLayoutTransitionInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSubresourceHostMemcpySizeEXT(std::ostream &out, const VkSubresourceHostMemcpySizeEXT* structInfo, Decoded_VkSubresourceHostMemcpySizeEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkHostImageCopyDevicePerformanceQueryEXT(std::ostream &out, const VkHostImageCopyDevicePerformanceQueryEXT* structInfo, Decoded_VkHostImageCopyDevicePerformanceQueryEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT(std::ostream &out, const VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT* structInfo, Decoded_VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSurfacePresentModeEXT(std::ostream &out, const VkSurfacePresentModeEXT* structInfo, Decoded_VkSurfacePresentModeEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSurfacePresentScalingCapabilitiesEXT(std::ostream &out, const VkSurfacePresentScalingCapabilitiesEXT* structInfo, Decoded_VkSurfacePresentScalingCapabilitiesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSurfacePresentModeCompatibilityEXT(std::ostream &out, const VkSurfacePresentModeCompatibilityEXT* structInfo, Decoded_VkSurfacePresentModeCompatibilityEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceSwapchainMaintenance1FeaturesEXT(std::ostream &out, const VkPhysicalDeviceSwapchainMaintenance1FeaturesEXT* structInfo, Decoded_VkPhysicalDeviceSwapchainMaintenance1FeaturesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSwapchainPresentFenceInfoEXT(std::ostream &out, const VkSwapchainPresentFenceInfoEXT* structInfo, Decoded_VkSwapchainPresentFenceInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSwapchainPresentModesCreateInfoEXT(std::ostream &out, const VkSwapchainPresentModesCreateInfoEXT* structInfo, Decoded_VkSwapchainPresentModesCreateInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSwapchainPresentModeInfoEXT(std::ostream &out, const VkSwapchainPresentModeInfoEXT* structInfo, Decoded_VkSwapchainPresentModeInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSwapchainPresentScalingCreateInfoEXT(std::ostream &out, const VkSwapchainPresentScalingCreateInfoEXT* structInfo, Decoded_VkSwapchainPresentScalingCreateInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkReleaseSwapchainImagesInfoEXT(std::ostream &out, const VkReleaseSwapchainImagesInfoEXT* structInfo, Decoded_VkReleaseSwapchainImagesInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV(std::ostream &out, const VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV* structInfo, Decoded_VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV(std::ostream &out, const VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV* structInfo, Decoded_VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkGraphicsShaderGroupCreateInfoNV(std::ostream &out, const VkGraphicsShaderGroupCreateInfoNV* structInfo, Decoded_VkGraphicsShaderGroupCreateInfoNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkGraphicsPipelineShaderGroupsCreateInfoNV(std::ostream &out, const VkGraphicsPipelineShaderGroupsCreateInfoNV* structInfo, Decoded_VkGraphicsPipelineShaderGroupsCreateInfoNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkBindShaderGroupIndirectCommandNV(std::ostream &out, const VkBindShaderGroupIndirectCommandNV* structInfo, Decoded_VkBindShaderGroupIndirectCommandNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkBindIndexBufferIndirectCommandNV(std::ostream &out, const VkBindIndexBufferIndirectCommandNV* structInfo, Decoded_VkBindIndexBufferIndirectCommandNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkBindVertexBufferIndirectCommandNV(std::ostream &out, const VkBindVertexBufferIndirectCommandNV* structInfo, Decoded_VkBindVertexBufferIndirectCommandNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSetStateFlagsIndirectCommandNV(std::ostream &out, const VkSetStateFlagsIndirectCommandNV* structInfo, Decoded_VkSetStateFlagsIndirectCommandNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkIndirectCommandsStreamNV(std::ostream &out, const VkIndirectCommandsStreamNV* structInfo, Decoded_VkIndirectCommandsStreamNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkIndirectCommandsLayoutTokenNV(std::ostream &out, const VkIndirectCommandsLayoutTokenNV* structInfo, Decoded_VkIndirectCommandsLayoutTokenNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkIndirectCommandsLayoutCreateInfoNV(std::ostream &out, const VkIndirectCommandsLayoutCreateInfoNV* structInfo, Decoded_VkIndirectCommandsLayoutCreateInfoNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkGeneratedCommandsInfoNV(std::ostream &out, const VkGeneratedCommandsInfoNV* structInfo, Decoded_VkGeneratedCommandsInfoNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkGeneratedCommandsMemoryRequirementsInfoNV(std::ostream &out, const VkGeneratedCommandsMemoryRequirementsInfoNV* structInfo, Decoded_VkGeneratedCommandsMemoryRequirementsInfoNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceInheritedViewportScissorFeaturesNV(std::ostream &out, const VkPhysicalDeviceInheritedViewportScissorFeaturesNV* structInfo, Decoded_VkPhysicalDeviceInheritedViewportScissorFeaturesNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkCommandBufferInheritanceViewportScissorInfoNV(std::ostream &out, const VkCommandBufferInheritanceViewportScissorInfoNV* structInfo, Decoded_VkCommandBufferInheritanceViewportScissorInfoNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT(std::ostream &out, const VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkRenderPassTransformBeginInfoQCOM(std::ostream &out, const VkRenderPassTransformBeginInfoQCOM* structInfo, Decoded_VkRenderPassTransformBeginInfoQCOM* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkCommandBufferInheritanceRenderPassTransformInfoQCOM(std::ostream &out, const VkCommandBufferInheritanceRenderPassTransformInfoQCOM* structInfo, Decoded_VkCommandBufferInheritanceRenderPassTransformInfoQCOM* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceDepthBiasControlFeaturesEXT(std::ostream &out, const VkPhysicalDeviceDepthBiasControlFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceDepthBiasControlFeaturesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDepthBiasInfoEXT(std::ostream &out, const VkDepthBiasInfoEXT* structInfo, Decoded_VkDepthBiasInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDepthBiasRepresentationInfoEXT(std::ostream &out, const VkDepthBiasRepresentationInfoEXT* structInfo, Decoded_VkDepthBiasRepresentationInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceDeviceMemoryReportFeaturesEXT(std::ostream &out, const VkPhysicalDeviceDeviceMemoryReportFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceDeviceMemoryReportFeaturesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDeviceMemoryReportCallbackDataEXT(std::ostream &out, const VkDeviceMemoryReportCallbackDataEXT* structInfo, Decoded_VkDeviceMemoryReportCallbackDataEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDeviceDeviceMemoryReportCreateInfoEXT(std::ostream &out, const VkDeviceDeviceMemoryReportCreateInfoEXT* structInfo, Decoded_VkDeviceDeviceMemoryReportCreateInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceRobustness2FeaturesEXT(std::ostream &out, const VkPhysicalDeviceRobustness2FeaturesEXT* structInfo, Decoded_VkPhysicalDeviceRobustness2FeaturesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceRobustness2PropertiesEXT(std::ostream &out, const VkPhysicalDeviceRobustness2PropertiesEXT* structInfo, Decoded_VkPhysicalDeviceRobustness2PropertiesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSamplerCustomBorderColorCreateInfoEXT(std::ostream &out, const VkSamplerCustomBorderColorCreateInfoEXT* structInfo, Decoded_VkSamplerCustomBorderColorCreateInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceCustomBorderColorPropertiesEXT(std::ostream &out, const VkPhysicalDeviceCustomBorderColorPropertiesEXT* structInfo, Decoded_VkPhysicalDeviceCustomBorderColorPropertiesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceCustomBorderColorFeaturesEXT(std::ostream &out, const VkPhysicalDeviceCustomBorderColorFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceCustomBorderColorFeaturesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDevicePresentBarrierFeaturesNV(std::ostream &out, const VkPhysicalDevicePresentBarrierFeaturesNV* structInfo, Decoded_VkPhysicalDevicePresentBarrierFeaturesNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSurfaceCapabilitiesPresentBarrierNV(std::ostream &out, const VkSurfaceCapabilitiesPresentBarrierNV* structInfo, Decoded_VkSurfaceCapabilitiesPresentBarrierNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSwapchainPresentBarrierCreateInfoNV(std::ostream &out, const VkSwapchainPresentBarrierCreateInfoNV* structInfo, Decoded_VkSwapchainPresentBarrierCreateInfoNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceDiagnosticsConfigFeaturesNV(std::ostream &out, const VkPhysicalDeviceDiagnosticsConfigFeaturesNV* structInfo, Decoded_VkPhysicalDeviceDiagnosticsConfigFeaturesNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDeviceDiagnosticsConfigCreateInfoNV(std::ostream &out, const VkDeviceDiagnosticsConfigCreateInfoNV* structInfo, Decoded_VkDeviceDiagnosticsConfigCreateInfoNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkQueryLowLatencySupportNV(std::ostream &out, const VkQueryLowLatencySupportNV* structInfo, Decoded_VkQueryLowLatencySupportNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT(std::ostream &out, const VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT(std::ostream &out, const VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT* structInfo, Decoded_VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkGraphicsPipelineLibraryCreateInfoEXT(std::ostream &out, const VkGraphicsPipelineLibraryCreateInfoEXT* structInfo, Decoded_VkGraphicsPipelineLibraryCreateInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD(std::ostream &out, const VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD* structInfo, Decoded_VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV(std::ostream &out, const VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV* structInfo, Decoded_VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV(std::ostream &out, const VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV* structInfo, Decoded_VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineFragmentShadingRateEnumStateCreateInfoNV(std::ostream &out, const VkPipelineFragmentShadingRateEnumStateCreateInfoNV* structInfo, Decoded_VkPipelineFragmentShadingRateEnumStateCreateInfoNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAccelerationStructureGeometryMotionTrianglesDataNV(std::ostream &out, const VkAccelerationStructureGeometryMotionTrianglesDataNV* structInfo, Decoded_VkAccelerationStructureGeometryMotionTrianglesDataNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAccelerationStructureMotionInfoNV(std::ostream &out, const VkAccelerationStructureMotionInfoNV* structInfo, Decoded_VkAccelerationStructureMotionInfoNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAccelerationStructureMatrixMotionInstanceNV(std::ostream &out, const VkAccelerationStructureMatrixMotionInstanceNV* structInfo, Decoded_VkAccelerationStructureMatrixMotionInstanceNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSRTDataNV(std::ostream &out, const VkSRTDataNV* structInfo, Decoded_VkSRTDataNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAccelerationStructureSRTMotionInstanceNV(std::ostream &out, const VkAccelerationStructureSRTMotionInstanceNV* structInfo, Decoded_VkAccelerationStructureSRTMotionInstanceNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceRayTracingMotionBlurFeaturesNV(std::ostream &out, const VkPhysicalDeviceRayTracingMotionBlurFeaturesNV* structInfo, Decoded_VkPhysicalDeviceRayTracingMotionBlurFeaturesNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT(std::ostream &out, const VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceFragmentDensityMap2FeaturesEXT(std::ostream &out, const VkPhysicalDeviceFragmentDensityMap2FeaturesEXT* structInfo, Decoded_VkPhysicalDeviceFragmentDensityMap2FeaturesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceFragmentDensityMap2PropertiesEXT(std::ostream &out, const VkPhysicalDeviceFragmentDensityMap2PropertiesEXT* structInfo, Decoded_VkPhysicalDeviceFragmentDensityMap2PropertiesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkCopyCommandTransformInfoQCOM(std::ostream &out, const VkCopyCommandTransformInfoQCOM* structInfo, Decoded_VkCopyCommandTransformInfoQCOM* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceImageCompressionControlFeaturesEXT(std::ostream &out, const VkPhysicalDeviceImageCompressionControlFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceImageCompressionControlFeaturesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImageCompressionControlEXT(std::ostream &out, const VkImageCompressionControlEXT* structInfo, Decoded_VkImageCompressionControlEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImageCompressionPropertiesEXT(std::ostream &out, const VkImageCompressionPropertiesEXT* structInfo, Decoded_VkImageCompressionPropertiesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT(std::ostream &out, const VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDevice4444FormatsFeaturesEXT(std::ostream &out, const VkPhysicalDevice4444FormatsFeaturesEXT* structInfo, Decoded_VkPhysicalDevice4444FormatsFeaturesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceFaultFeaturesEXT(std::ostream &out, const VkPhysicalDeviceFaultFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceFaultFeaturesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDeviceFaultCountsEXT(std::ostream &out, const VkDeviceFaultCountsEXT* structInfo, Decoded_VkDeviceFaultCountsEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDeviceFaultAddressInfoEXT(std::ostream &out, const VkDeviceFaultAddressInfoEXT* structInfo, Decoded_VkDeviceFaultAddressInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDeviceFaultVendorInfoEXT(std::ostream &out, const VkDeviceFaultVendorInfoEXT* structInfo, Decoded_VkDeviceFaultVendorInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDeviceFaultInfoEXT(std::ostream &out, const VkDeviceFaultInfoEXT* structInfo, Decoded_VkDeviceFaultInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDeviceFaultVendorBinaryHeaderVersionOneEXT(std::ostream &out, const VkDeviceFaultVendorBinaryHeaderVersionOneEXT* structInfo, Decoded_VkDeviceFaultVendorBinaryHeaderVersionOneEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT(std::ostream &out, const VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT(std::ostream &out, const VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDirectFBSurfaceCreateInfoEXT(std::ostream &out, const VkDirectFBSurfaceCreateInfoEXT* structInfo, Decoded_VkDirectFBSurfaceCreateInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT(std::ostream &out, const VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMutableDescriptorTypeListEXT(std::ostream &out, const VkMutableDescriptorTypeListEXT* structInfo, Decoded_VkMutableDescriptorTypeListEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMutableDescriptorTypeCreateInfoEXT(std::ostream &out, const VkMutableDescriptorTypeCreateInfoEXT* structInfo, Decoded_VkMutableDescriptorTypeCreateInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT(std::ostream &out, const VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVertexInputBindingDescription2EXT(std::ostream &out, const VkVertexInputBindingDescription2EXT* structInfo, Decoded_VkVertexInputBindingDescription2EXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkVertexInputAttributeDescription2EXT(std::ostream &out, const VkVertexInputAttributeDescription2EXT* structInfo, Decoded_VkVertexInputAttributeDescription2EXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceDrmPropertiesEXT(std::ostream &out, const VkPhysicalDeviceDrmPropertiesEXT* structInfo, Decoded_VkPhysicalDeviceDrmPropertiesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceAddressBindingReportFeaturesEXT(std::ostream &out, const VkPhysicalDeviceAddressBindingReportFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceAddressBindingReportFeaturesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDeviceAddressBindingCallbackDataEXT(std::ostream &out, const VkDeviceAddressBindingCallbackDataEXT* structInfo, Decoded_VkDeviceAddressBindingCallbackDataEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceDepthClipControlFeaturesEXT(std::ostream &out, const VkPhysicalDeviceDepthClipControlFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceDepthClipControlFeaturesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineViewportDepthClipControlCreateInfoEXT(std::ostream &out, const VkPipelineViewportDepthClipControlCreateInfoEXT* structInfo, Decoded_VkPipelineViewportDepthClipControlCreateInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT(std::ostream &out, const VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT* structInfo, Decoded_VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImportMemoryZirconHandleInfoFUCHSIA(std::ostream &out, const VkImportMemoryZirconHandleInfoFUCHSIA* structInfo, Decoded_VkImportMemoryZirconHandleInfoFUCHSIA* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMemoryZirconHandlePropertiesFUCHSIA(std::ostream &out, const VkMemoryZirconHandlePropertiesFUCHSIA* structInfo, Decoded_VkMemoryZirconHandlePropertiesFUCHSIA* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMemoryGetZirconHandleInfoFUCHSIA(std::ostream &out, const VkMemoryGetZirconHandleInfoFUCHSIA* structInfo, Decoded_VkMemoryGetZirconHandleInfoFUCHSIA* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImportSemaphoreZirconHandleInfoFUCHSIA(std::ostream &out, const VkImportSemaphoreZirconHandleInfoFUCHSIA* structInfo, Decoded_VkImportSemaphoreZirconHandleInfoFUCHSIA* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSemaphoreGetZirconHandleInfoFUCHSIA(std::ostream &out, const VkSemaphoreGetZirconHandleInfoFUCHSIA* structInfo, Decoded_VkSemaphoreGetZirconHandleInfoFUCHSIA* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceInvocationMaskFeaturesHUAWEI(std::ostream &out, const VkPhysicalDeviceInvocationMaskFeaturesHUAWEI* structInfo, Decoded_VkPhysicalDeviceInvocationMaskFeaturesHUAWEI* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMemoryGetRemoteAddressInfoNV(std::ostream &out, const VkMemoryGetRemoteAddressInfoNV* structInfo, Decoded_VkMemoryGetRemoteAddressInfoNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceExternalMemoryRDMAFeaturesNV(std::ostream &out, const VkPhysicalDeviceExternalMemoryRDMAFeaturesNV* structInfo, Decoded_VkPhysicalDeviceExternalMemoryRDMAFeaturesNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceFrameBoundaryFeaturesEXT(std::ostream &out, const VkPhysicalDeviceFrameBoundaryFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceFrameBoundaryFeaturesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkFrameBoundaryEXT(std::ostream &out, const VkFrameBoundaryEXT* structInfo, Decoded_VkFrameBoundaryEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT(std::ostream &out, const VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSubpassResolvePerformanceQueryEXT(std::ostream &out, const VkSubpassResolvePerformanceQueryEXT* structInfo, Decoded_VkSubpassResolvePerformanceQueryEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMultisampledRenderToSingleSampledInfoEXT(std::ostream &out, const VkMultisampledRenderToSingleSampledInfoEXT* structInfo, Decoded_VkMultisampledRenderToSingleSampledInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceExtendedDynamicState2FeaturesEXT(std::ostream &out, const VkPhysicalDeviceExtendedDynamicState2FeaturesEXT* structInfo, Decoded_VkPhysicalDeviceExtendedDynamicState2FeaturesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkScreenSurfaceCreateInfoQNX(std::ostream &out, const VkScreenSurfaceCreateInfoQNX* structInfo, Decoded_VkScreenSurfaceCreateInfoQNX* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceColorWriteEnableFeaturesEXT(std::ostream &out, const VkPhysicalDeviceColorWriteEnableFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceColorWriteEnableFeaturesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineColorWriteCreateInfoEXT(std::ostream &out, const VkPipelineColorWriteCreateInfoEXT* structInfo, Decoded_VkPipelineColorWriteCreateInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT(std::ostream &out, const VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT* structInfo, Decoded_VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceImageViewMinLodFeaturesEXT(std::ostream &out, const VkPhysicalDeviceImageViewMinLodFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceImageViewMinLodFeaturesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImageViewMinLodCreateInfoEXT(std::ostream &out, const VkImageViewMinLodCreateInfoEXT* structInfo, Decoded_VkImageViewMinLodCreateInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceMultiDrawFeaturesEXT(std::ostream &out, const VkPhysicalDeviceMultiDrawFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceMultiDrawFeaturesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceMultiDrawPropertiesEXT(std::ostream &out, const VkPhysicalDeviceMultiDrawPropertiesEXT* structInfo, Decoded_VkPhysicalDeviceMultiDrawPropertiesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMultiDrawInfoEXT(std::ostream &out, const VkMultiDrawInfoEXT* structInfo, Decoded_VkMultiDrawInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMultiDrawIndexedInfoEXT(std::ostream &out, const VkMultiDrawIndexedInfoEXT* structInfo, Decoded_VkMultiDrawIndexedInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceImage2DViewOf3DFeaturesEXT(std::ostream &out, const VkPhysicalDeviceImage2DViewOf3DFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceImage2DViewOf3DFeaturesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceShaderTileImageFeaturesEXT(std::ostream &out, const VkPhysicalDeviceShaderTileImageFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceShaderTileImageFeaturesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceShaderTileImagePropertiesEXT(std::ostream &out, const VkPhysicalDeviceShaderTileImagePropertiesEXT* structInfo, Decoded_VkPhysicalDeviceShaderTileImagePropertiesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMicromapUsageEXT(std::ostream &out, const VkMicromapUsageEXT* structInfo, Decoded_VkMicromapUsageEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMicromapBuildInfoEXT(std::ostream &out, const VkMicromapBuildInfoEXT* structInfo, Decoded_VkMicromapBuildInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMicromapCreateInfoEXT(std::ostream &out, const VkMicromapCreateInfoEXT* structInfo, Decoded_VkMicromapCreateInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceOpacityMicromapFeaturesEXT(std::ostream &out, const VkPhysicalDeviceOpacityMicromapFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceOpacityMicromapFeaturesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceOpacityMicromapPropertiesEXT(std::ostream &out, const VkPhysicalDeviceOpacityMicromapPropertiesEXT* structInfo, Decoded_VkPhysicalDeviceOpacityMicromapPropertiesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMicromapVersionInfoEXT(std::ostream &out, const VkMicromapVersionInfoEXT* structInfo, Decoded_VkMicromapVersionInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkCopyMicromapToMemoryInfoEXT(std::ostream &out, const VkCopyMicromapToMemoryInfoEXT* structInfo, Decoded_VkCopyMicromapToMemoryInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkCopyMemoryToMicromapInfoEXT(std::ostream &out, const VkCopyMemoryToMicromapInfoEXT* structInfo, Decoded_VkCopyMemoryToMicromapInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkCopyMicromapInfoEXT(std::ostream &out, const VkCopyMicromapInfoEXT* structInfo, Decoded_VkCopyMicromapInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMicromapBuildSizesInfoEXT(std::ostream &out, const VkMicromapBuildSizesInfoEXT* structInfo, Decoded_VkMicromapBuildSizesInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAccelerationStructureTrianglesOpacityMicromapEXT(std::ostream &out, const VkAccelerationStructureTrianglesOpacityMicromapEXT* structInfo, Decoded_VkAccelerationStructureTrianglesOpacityMicromapEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMicromapTriangleEXT(std::ostream &out, const VkMicromapTriangleEXT* structInfo, Decoded_VkMicromapTriangleEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceDisplacementMicromapFeaturesNV(std::ostream &out, const VkPhysicalDeviceDisplacementMicromapFeaturesNV* structInfo, Decoded_VkPhysicalDeviceDisplacementMicromapFeaturesNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceDisplacementMicromapPropertiesNV(std::ostream &out, const VkPhysicalDeviceDisplacementMicromapPropertiesNV* structInfo, Decoded_VkPhysicalDeviceDisplacementMicromapPropertiesNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAccelerationStructureTrianglesDisplacementMicromapNV(std::ostream &out, const VkAccelerationStructureTrianglesDisplacementMicromapNV* structInfo, Decoded_VkAccelerationStructureTrianglesDisplacementMicromapNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI(std::ostream &out, const VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI* structInfo, Decoded_VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI(std::ostream &out, const VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI* structInfo, Decoded_VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceBorderColorSwizzleFeaturesEXT(std::ostream &out, const VkPhysicalDeviceBorderColorSwizzleFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceBorderColorSwizzleFeaturesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSamplerBorderColorComponentMappingCreateInfoEXT(std::ostream &out, const VkSamplerBorderColorComponentMappingCreateInfoEXT* structInfo, Decoded_VkSamplerBorderColorComponentMappingCreateInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT(std::ostream &out, const VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT* structInfo, Decoded_VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceShaderCorePropertiesARM(std::ostream &out, const VkPhysicalDeviceShaderCorePropertiesARM* structInfo, Decoded_VkPhysicalDeviceShaderCorePropertiesARM* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT(std::ostream &out, const VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImageViewSlicedCreateInfoEXT(std::ostream &out, const VkImageViewSlicedCreateInfoEXT* structInfo, Decoded_VkImageViewSlicedCreateInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE(std::ostream &out, const VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE* structInfo, Decoded_VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDescriptorSetBindingReferenceVALVE(std::ostream &out, const VkDescriptorSetBindingReferenceVALVE* structInfo, Decoded_VkDescriptorSetBindingReferenceVALVE* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDescriptorSetLayoutHostMappingInfoVALVE(std::ostream &out, const VkDescriptorSetLayoutHostMappingInfoVALVE* structInfo, Decoded_VkDescriptorSetLayoutHostMappingInfoVALVE* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceDepthClampZeroOneFeaturesEXT(std::ostream &out, const VkPhysicalDeviceDepthClampZeroOneFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceDepthClampZeroOneFeaturesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT(std::ostream &out, const VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM(std::ostream &out, const VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM* structInfo, Decoded_VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM(std::ostream &out, const VkPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM* structInfo, Decoded_VkPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSubpassFragmentDensityMapOffsetEndInfoQCOM(std::ostream &out, const VkSubpassFragmentDensityMapOffsetEndInfoQCOM* structInfo, Decoded_VkSubpassFragmentDensityMapOffsetEndInfoQCOM* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV(std::ostream &out, const VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV* structInfo, Decoded_VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkComputePipelineIndirectBufferInfoNV(std::ostream &out, const VkComputePipelineIndirectBufferInfoNV* structInfo, Decoded_VkComputePipelineIndirectBufferInfoNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineIndirectDeviceAddressInfoNV(std::ostream &out, const VkPipelineIndirectDeviceAddressInfoNV* structInfo, Decoded_VkPipelineIndirectDeviceAddressInfoNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkBindPipelineIndirectCommandNV(std::ostream &out, const VkBindPipelineIndirectCommandNV* structInfo, Decoded_VkBindPipelineIndirectCommandNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceLinearColorAttachmentFeaturesNV(std::ostream &out, const VkPhysicalDeviceLinearColorAttachmentFeaturesNV* structInfo, Decoded_VkPhysicalDeviceLinearColorAttachmentFeaturesNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT(std::ostream &out, const VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkImageViewSampleWeightCreateInfoQCOM(std::ostream &out, const VkImageViewSampleWeightCreateInfoQCOM* structInfo, Decoded_VkImageViewSampleWeightCreateInfoQCOM* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceImageProcessingFeaturesQCOM(std::ostream &out, const VkPhysicalDeviceImageProcessingFeaturesQCOM* structInfo, Decoded_VkPhysicalDeviceImageProcessingFeaturesQCOM* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceImageProcessingPropertiesQCOM(std::ostream &out, const VkPhysicalDeviceImageProcessingPropertiesQCOM* structInfo, Decoded_VkPhysicalDeviceImageProcessingPropertiesQCOM* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceNestedCommandBufferFeaturesEXT(std::ostream &out, const VkPhysicalDeviceNestedCommandBufferFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceNestedCommandBufferFeaturesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceNestedCommandBufferPropertiesEXT(std::ostream &out, const VkPhysicalDeviceNestedCommandBufferPropertiesEXT* structInfo, Decoded_VkPhysicalDeviceNestedCommandBufferPropertiesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkExternalMemoryAcquireUnmodifiedEXT(std::ostream &out, const VkExternalMemoryAcquireUnmodifiedEXT* structInfo, Decoded_VkExternalMemoryAcquireUnmodifiedEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceExtendedDynamicState3FeaturesEXT(std::ostream &out, const VkPhysicalDeviceExtendedDynamicState3FeaturesEXT* structInfo, Decoded_VkPhysicalDeviceExtendedDynamicState3FeaturesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceExtendedDynamicState3PropertiesEXT(std::ostream &out, const VkPhysicalDeviceExtendedDynamicState3PropertiesEXT* structInfo, Decoded_VkPhysicalDeviceExtendedDynamicState3PropertiesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkColorBlendEquationEXT(std::ostream &out, const VkColorBlendEquationEXT* structInfo, Decoded_VkColorBlendEquationEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkColorBlendAdvancedEXT(std::ostream &out, const VkColorBlendAdvancedEXT* structInfo, Decoded_VkColorBlendAdvancedEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT(std::ostream &out, const VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkRenderPassCreationControlEXT(std::ostream &out, const VkRenderPassCreationControlEXT* structInfo, Decoded_VkRenderPassCreationControlEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkRenderPassCreationFeedbackInfoEXT(std::ostream &out, const VkRenderPassCreationFeedbackInfoEXT* structInfo, Decoded_VkRenderPassCreationFeedbackInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkRenderPassCreationFeedbackCreateInfoEXT(std::ostream &out, const VkRenderPassCreationFeedbackCreateInfoEXT* structInfo, Decoded_VkRenderPassCreationFeedbackCreateInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkRenderPassSubpassFeedbackInfoEXT(std::ostream &out, const VkRenderPassSubpassFeedbackInfoEXT* structInfo, Decoded_VkRenderPassSubpassFeedbackInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkRenderPassSubpassFeedbackCreateInfoEXT(std::ostream &out, const VkRenderPassSubpassFeedbackCreateInfoEXT* structInfo, Decoded_VkRenderPassSubpassFeedbackCreateInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDirectDriverLoadingInfoLUNARG(std::ostream &out, const VkDirectDriverLoadingInfoLUNARG* structInfo, Decoded_VkDirectDriverLoadingInfoLUNARG* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDirectDriverLoadingListLUNARG(std::ostream &out, const VkDirectDriverLoadingListLUNARG* structInfo, Decoded_VkDirectDriverLoadingListLUNARG* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT(std::ostream &out, const VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT(std::ostream &out, const VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT* structInfo, Decoded_VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPipelineShaderStageModuleIdentifierCreateInfoEXT(std::ostream &out, const VkPipelineShaderStageModuleIdentifierCreateInfoEXT* structInfo, Decoded_VkPipelineShaderStageModuleIdentifierCreateInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkShaderModuleIdentifierEXT(std::ostream &out, const VkShaderModuleIdentifierEXT* structInfo, Decoded_VkShaderModuleIdentifierEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceOpticalFlowFeaturesNV(std::ostream &out, const VkPhysicalDeviceOpticalFlowFeaturesNV* structInfo, Decoded_VkPhysicalDeviceOpticalFlowFeaturesNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceOpticalFlowPropertiesNV(std::ostream &out, const VkPhysicalDeviceOpticalFlowPropertiesNV* structInfo, Decoded_VkPhysicalDeviceOpticalFlowPropertiesNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkOpticalFlowImageFormatInfoNV(std::ostream &out, const VkOpticalFlowImageFormatInfoNV* structInfo, Decoded_VkOpticalFlowImageFormatInfoNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkOpticalFlowImageFormatPropertiesNV(std::ostream &out, const VkOpticalFlowImageFormatPropertiesNV* structInfo, Decoded_VkOpticalFlowImageFormatPropertiesNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkOpticalFlowSessionCreateInfoNV(std::ostream &out, const VkOpticalFlowSessionCreateInfoNV* structInfo, Decoded_VkOpticalFlowSessionCreateInfoNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkOpticalFlowSessionCreatePrivateDataInfoNV(std::ostream &out, const VkOpticalFlowSessionCreatePrivateDataInfoNV* structInfo, Decoded_VkOpticalFlowSessionCreatePrivateDataInfoNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkOpticalFlowExecuteInfoNV(std::ostream &out, const VkOpticalFlowExecuteInfoNV* structInfo, Decoded_VkOpticalFlowExecuteInfoNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceLegacyDitheringFeaturesEXT(std::ostream &out, const VkPhysicalDeviceLegacyDitheringFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceLegacyDitheringFeaturesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDevicePipelineProtectedAccessFeaturesEXT(std::ostream &out, const VkPhysicalDevicePipelineProtectedAccessFeaturesEXT* structInfo, Decoded_VkPhysicalDevicePipelineProtectedAccessFeaturesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceExternalFormatResolveFeaturesANDROID(std::ostream &out, const VkPhysicalDeviceExternalFormatResolveFeaturesANDROID* structInfo, Decoded_VkPhysicalDeviceExternalFormatResolveFeaturesANDROID* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceExternalFormatResolvePropertiesANDROID(std::ostream &out, const VkPhysicalDeviceExternalFormatResolvePropertiesANDROID* structInfo, Decoded_VkPhysicalDeviceExternalFormatResolvePropertiesANDROID* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAndroidHardwareBufferFormatResolvePropertiesANDROID(std::ostream &out, const VkAndroidHardwareBufferFormatResolvePropertiesANDROID* structInfo, Decoded_VkAndroidHardwareBufferFormatResolvePropertiesANDROID* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceShaderObjectFeaturesEXT(std::ostream &out, const VkPhysicalDeviceShaderObjectFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceShaderObjectFeaturesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceShaderObjectPropertiesEXT(std::ostream &out, const VkPhysicalDeviceShaderObjectPropertiesEXT* structInfo, Decoded_VkPhysicalDeviceShaderObjectPropertiesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkShaderCreateInfoEXT(std::ostream &out, const VkShaderCreateInfoEXT* structInfo, Decoded_VkShaderCreateInfoEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceTilePropertiesFeaturesQCOM(std::ostream &out, const VkPhysicalDeviceTilePropertiesFeaturesQCOM* structInfo, Decoded_VkPhysicalDeviceTilePropertiesFeaturesQCOM* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkTilePropertiesQCOM(std::ostream &out, const VkTilePropertiesQCOM* structInfo, Decoded_VkTilePropertiesQCOM* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceAmigoProfilingFeaturesSEC(std::ostream &out, const VkPhysicalDeviceAmigoProfilingFeaturesSEC* structInfo, Decoded_VkPhysicalDeviceAmigoProfilingFeaturesSEC* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAmigoProfilingSubmitInfoSEC(std::ostream &out, const VkAmigoProfilingSubmitInfoSEC* structInfo, Decoded_VkAmigoProfilingSubmitInfoSEC* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM(std::ostream &out, const VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM* structInfo, Decoded_VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV(std::ostream &out, const VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV* structInfo, Decoded_VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV(std::ostream &out, const VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV* structInfo, Decoded_VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV(std::ostream &out, const VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV* structInfo, Decoded_VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV(std::ostream &out, const VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV* structInfo, Decoded_VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM(std::ostream &out, const VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM* structInfo, Decoded_VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM(std::ostream &out, const VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM* structInfo, Decoded_VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT(std::ostream &out, const VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT* structInfo, Decoded_VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT(std::ostream &out, const VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM(std::ostream &out, const VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM* structInfo, Decoded_VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM(std::ostream &out, const VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM* structInfo, Decoded_VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceImageProcessing2FeaturesQCOM(std::ostream &out, const VkPhysicalDeviceImageProcessing2FeaturesQCOM* structInfo, Decoded_VkPhysicalDeviceImageProcessing2FeaturesQCOM* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceImageProcessing2PropertiesQCOM(std::ostream &out, const VkPhysicalDeviceImageProcessing2PropertiesQCOM* structInfo, Decoded_VkPhysicalDeviceImageProcessing2PropertiesQCOM* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSamplerBlockMatchWindowCreateInfoQCOM(std::ostream &out, const VkSamplerBlockMatchWindowCreateInfoQCOM* structInfo, Decoded_VkSamplerBlockMatchWindowCreateInfoQCOM* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceCubicWeightsFeaturesQCOM(std::ostream &out, const VkPhysicalDeviceCubicWeightsFeaturesQCOM* structInfo, Decoded_VkPhysicalDeviceCubicWeightsFeaturesQCOM* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSamplerCubicWeightsCreateInfoQCOM(std::ostream &out, const VkSamplerCubicWeightsCreateInfoQCOM* structInfo, Decoded_VkSamplerCubicWeightsCreateInfoQCOM* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkBlitImageCubicWeightsInfoQCOM(std::ostream &out, const VkBlitImageCubicWeightsInfoQCOM* structInfo, Decoded_VkBlitImageCubicWeightsInfoQCOM* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceYcbcrDegammaFeaturesQCOM(std::ostream &out, const VkPhysicalDeviceYcbcrDegammaFeaturesQCOM* structInfo, Decoded_VkPhysicalDeviceYcbcrDegammaFeaturesQCOM* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM(std::ostream &out, const VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM* structInfo, Decoded_VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceCubicClampFeaturesQCOM(std::ostream &out, const VkPhysicalDeviceCubicClampFeaturesQCOM* structInfo, Decoded_VkPhysicalDeviceCubicClampFeaturesQCOM* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT(std::ostream &out, const VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceLayeredDriverPropertiesMSFT(std::ostream &out, const VkPhysicalDeviceLayeredDriverPropertiesMSFT* structInfo, Decoded_VkPhysicalDeviceLayeredDriverPropertiesMSFT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV(std::ostream &out, const VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV* structInfo, Decoded_VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAccelerationStructureBuildRangeInfoKHR(std::ostream &out, const VkAccelerationStructureBuildRangeInfoKHR* structInfo, Decoded_VkAccelerationStructureBuildRangeInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAccelerationStructureGeometryTrianglesDataKHR(std::ostream &out, const VkAccelerationStructureGeometryTrianglesDataKHR* structInfo, Decoded_VkAccelerationStructureGeometryTrianglesDataKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAccelerationStructureGeometryAabbsDataKHR(std::ostream &out, const VkAccelerationStructureGeometryAabbsDataKHR* structInfo, Decoded_VkAccelerationStructureGeometryAabbsDataKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAccelerationStructureGeometryInstancesDataKHR(std::ostream &out, const VkAccelerationStructureGeometryInstancesDataKHR* structInfo, Decoded_VkAccelerationStructureGeometryInstancesDataKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAccelerationStructureGeometryKHR(std::ostream &out, const VkAccelerationStructureGeometryKHR* structInfo, Decoded_VkAccelerationStructureGeometryKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAccelerationStructureBuildGeometryInfoKHR(std::ostream &out, const VkAccelerationStructureBuildGeometryInfoKHR* structInfo, Decoded_VkAccelerationStructureBuildGeometryInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAccelerationStructureCreateInfoKHR(std::ostream &out, const VkAccelerationStructureCreateInfoKHR* structInfo, Decoded_VkAccelerationStructureCreateInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkWriteDescriptorSetAccelerationStructureKHR(std::ostream &out, const VkWriteDescriptorSetAccelerationStructureKHR* structInfo, Decoded_VkWriteDescriptorSetAccelerationStructureKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceAccelerationStructureFeaturesKHR(std::ostream &out, const VkPhysicalDeviceAccelerationStructureFeaturesKHR* structInfo, Decoded_VkPhysicalDeviceAccelerationStructureFeaturesKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceAccelerationStructurePropertiesKHR(std::ostream &out, const VkPhysicalDeviceAccelerationStructurePropertiesKHR* structInfo, Decoded_VkPhysicalDeviceAccelerationStructurePropertiesKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAccelerationStructureDeviceAddressInfoKHR(std::ostream &out, const VkAccelerationStructureDeviceAddressInfoKHR* structInfo, Decoded_VkAccelerationStructureDeviceAddressInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAccelerationStructureVersionInfoKHR(std::ostream &out, const VkAccelerationStructureVersionInfoKHR* structInfo, Decoded_VkAccelerationStructureVersionInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkCopyAccelerationStructureToMemoryInfoKHR(std::ostream &out, const VkCopyAccelerationStructureToMemoryInfoKHR* structInfo, Decoded_VkCopyAccelerationStructureToMemoryInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkCopyMemoryToAccelerationStructureInfoKHR(std::ostream &out, const VkCopyMemoryToAccelerationStructureInfoKHR* structInfo, Decoded_VkCopyMemoryToAccelerationStructureInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkCopyAccelerationStructureInfoKHR(std::ostream &out, const VkCopyAccelerationStructureInfoKHR* structInfo, Decoded_VkCopyAccelerationStructureInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkAccelerationStructureBuildSizesInfoKHR(std::ostream &out, const VkAccelerationStructureBuildSizesInfoKHR* structInfo, Decoded_VkAccelerationStructureBuildSizesInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkRayTracingShaderGroupCreateInfoKHR(std::ostream &out, const VkRayTracingShaderGroupCreateInfoKHR* structInfo, Decoded_VkRayTracingShaderGroupCreateInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkRayTracingPipelineInterfaceCreateInfoKHR(std::ostream &out, const VkRayTracingPipelineInterfaceCreateInfoKHR* structInfo, Decoded_VkRayTracingPipelineInterfaceCreateInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkRayTracingPipelineCreateInfoKHR(std::ostream &out, const VkRayTracingPipelineCreateInfoKHR* structInfo, Decoded_VkRayTracingPipelineCreateInfoKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceRayTracingPipelineFeaturesKHR(std::ostream &out, const VkPhysicalDeviceRayTracingPipelineFeaturesKHR* structInfo, Decoded_VkPhysicalDeviceRayTracingPipelineFeaturesKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceRayTracingPipelinePropertiesKHR(std::ostream &out, const VkPhysicalDeviceRayTracingPipelinePropertiesKHR* structInfo, Decoded_VkPhysicalDeviceRayTracingPipelinePropertiesKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkStridedDeviceAddressRegionKHR(std::ostream &out, const VkStridedDeviceAddressRegionKHR* structInfo, Decoded_VkStridedDeviceAddressRegionKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkTraceRaysIndirectCommandKHR(std::ostream &out, const VkTraceRaysIndirectCommandKHR* structInfo, Decoded_VkTraceRaysIndirectCommandKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceRayQueryFeaturesKHR(std::ostream &out, const VkPhysicalDeviceRayQueryFeaturesKHR* structInfo, Decoded_VkPhysicalDeviceRayQueryFeaturesKHR* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceMeshShaderFeaturesEXT(std::ostream &out, const VkPhysicalDeviceMeshShaderFeaturesEXT* structInfo, Decoded_VkPhysicalDeviceMeshShaderFeaturesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkPhysicalDeviceMeshShaderPropertiesEXT(std::ostream &out, const VkPhysicalDeviceMeshShaderPropertiesEXT* structInfo, Decoded_VkPhysicalDeviceMeshShaderPropertiesEXT* metainfo, VulkanCppConsumerBase &consumer);

std::string GenerateStruct_VkDrawMeshTasksIndirectCommandEXT(std::ostream &out, const VkDrawMeshTasksIndirectCommandEXT* structInfo, Decoded_VkDrawMeshTasksIndirectCommandEXT* metainfo, VulkanCppConsumerBase &consumer);

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

