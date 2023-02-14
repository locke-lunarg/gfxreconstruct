/*
** Copyright (c) 2019-2021 LunarG, Inc.
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

#ifndef GFXRECON_ENCODE_VULKAN_STATE_TABLE_BASE_H
#define GFXRECON_ENCODE_VULKAN_STATE_TABLE_BASE_H

#include "encode/vulkan_handle_wrappers.h"
#include "format/format.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"

#include <cassert>
#include <functional>
#include <map>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

class VulkanStateTableBase
{
  public:
    VulkanStateTableBase() {}

    ~VulkanStateTableBase() {}

  protected:
    template <typename Key, typename Wrapper>
    bool InsertEntry(Key key, Wrapper* wrapper, std::map<Key, Wrapper*>& map)
    {
        const auto& inserted = map.insert(std::make_pair(key, wrapper));
        return inserted.second;
    }

    template <typename Key, typename Wrapper>
    bool RemoveEntry(const Key key, std::map<Key, Wrapper*>& map)
    {
        return (map.erase(key) != 0);
    }

    template <typename Key, typename Wrapper>
    Wrapper* GetWrapper(Key key, std::map<Key, Wrapper*>& map)
    {
        auto entry = map.find(key);
        return (entry != map.end()) ? entry->second : nullptr;
    }

    template <typename Key, typename Wrapper>
    const Wrapper* GetWrapper(Key key, const std::map<Key, Wrapper*>& map) const
    {
        auto entry = map.find(key);
        return (entry != map.end()) ? entry->second : nullptr;
    }
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_VULKAN_STATE_TABLE_BASE_H
