//
// Copyright (c) 2021 Samsung
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "vulkan_cpp_utilities.h"

#include <algorithm>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

std::string GfxToCppVariable::str() const
{
    std::string varString = type + " " + name;
    if (count > 0)
    {
        return varString + " [" + std::to_string(count) + "]";
    }
    return varString;
}

std::vector<std::string> GfxToCppVariable::toStrVec(const std::vector<GfxToCppVariable>& variables)
{
    std::vector<std::string> varStrings;
    varStrings.reserve(variables.size());
    std::transform(variables.begin(),
                   variables.end(),
                   std::back_inserter(varStrings),
                   [](const GfxToCppVariable& variable) { return variable.str(); });
    return varStrings;
}

const std::map<std::string, std::string>& GetWSIRemapInfo(GfxTocppPlatform platform)
{
    static const std::map<std::string, std::string> xcbExtensionReplacementMap = {
        { VK_KHR_WAYLAND_SURFACE_EXTENSION_NAME, VK_KHR_XCB_SURFACE_EXTENSION_NAME },
        { VK_KHR_ANDROID_SURFACE_EXTENSION_NAME, VK_KHR_XCB_SURFACE_EXTENSION_NAME },
    };

    static const std::map<std::string, std::string> androidExtensionReplacementMap = {
        { VK_KHR_XCB_SURFACE_EXTENSION_NAME, VK_KHR_ANDROID_SURFACE_EXTENSION_NAME },
        { VK_KHR_WAYLAND_SURFACE_EXTENSION_NAME, VK_KHR_ANDROID_SURFACE_EXTENSION_NAME },
    };

    static const std::map<std::string, std::string> empty;

    switch (platform)
    {
        case GfxTocppPlatform::XCB:
            return xcbExtensionReplacementMap;
        case GfxTocppPlatform::ANDROID:
            return androidExtensionReplacementMap;
        case GfxTocppPlatform::NONE:
        default:
            return empty;
    }
}

void PrintToFile(FILE* file, const std::string& format, const std::vector<std::string>& data)
{
    for (const std::string& string : data)
    {
        fprintf(file, format.c_str(), string.c_str());
    }
}

std::string DescriptorCreateInfoTypeToString(VkDescriptorType descriptorType)
{
    switch (descriptorType)
    {
        case VK_DESCRIPTOR_TYPE_SAMPLER:
        case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
        case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
        case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
        case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
            return "VkDescriptorImageInfo";
        case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
        case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
        case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
        case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
            return "VkDescriptorBufferInfo";
        case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
        case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
            return "VkBufferView";
        case VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK_EXT:
            return "VkWriteDescriptorSetInlineUniformBlockEXT";
        case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR:
            return "VkWriteDescriptorSetAccelerationStructureKHR";
        default:
            return "";
    }
}

DescriptorBaseType GetDescriptorBaseType(VkDescriptorType descriptorType)
{
    switch (descriptorType)
    {
        case VK_DESCRIPTOR_TYPE_SAMPLER:
            return DESCRIPTOR_BASE_TYPE_SAMPLER;
        case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
        case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
        case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
            return DESCRIPTOR_BASE_TYPE_IMAGE;
        case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
            return DESCRIPTOR_BASE_TYPE_COMBINED_IMAGE_SAMPLER;
        case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
        case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
        case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
        case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
            return DESCRIPTOR_BASE_TYPE_BUFFER;
        case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
        case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
            return DESCRIPTOR_BASE_TYPE_TEXEL;
        case VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK_EXT:
            return DESCRIPTOR_BASE_TYPE_INLINE_UNIFORM_BLOCK;
        case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR:
            return DESCRIPTOR_BASE_TYPE_ACCELERATION_STRUCTURE;
        default:
            return DESCRIPTOR_BASE_TYPE_NONE;
    }
}

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)
