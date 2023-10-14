/*
** Copyright (c) 2022-2023 LunarG, Inc.
** Copyright (c) 2023 Valve Corporation.
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

/// @file API-agnostic options and helpers for outputting JSON used by all
/// the JSON-generating components such as the Consumers in.
/// @note This currently looks overkill for one constant but there is a fuller
/// version incoming from an in-progress PR.

#ifndef GFXRECON_UTIL_JSON_UTIL_H
#define GFXRECON_UTIL_JSON_UTIL_H

#include "util/defines.h"
#include "util/logging.h"
#include "format/format.h"
#include "nlohmann/json.hpp"

#include <sstream>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

static constexpr int kJsonIndentWidth = 2;

enum class JsonFormat
{
    JSON,
    JSONL
};

inline std::string get_json_format(JsonFormat format)
{
    switch (format)
    {
        case gfxrecon::util::JsonFormat::JSONL:
            return "jsonl";
        case gfxrecon::util::JsonFormat::JSON:
            return "json";
        default:
            break;
    }
    GFXRECON_LOG_WARNING("Unrecognized format %d. Defaulting to JSON format.", static_cast<int>(format));
    return "json";
}

inline JsonFormat get_json_format(std::string format)
{
    if (format == "json")
    {
        return gfxrecon::util::JsonFormat::JSON;
    }
    else if (format == "jsonl")
    {
        return gfxrecon::util::JsonFormat::JSONL;
    }
    GFXRECON_LOG_WARNING("Unrecognized format %s. Defaulting to JSON format.", format.c_str());
    return gfxrecon::util::JsonFormat::JSON;
}

struct JsonOptions
{
    JsonFormat  format = JsonFormat::JSON;
    std::string root_dir;
    std::string data_sub_dir;
    bool        dump_binaries = false;
    bool        expand_flags  = false;
    bool        hex_handles   = false;
};

template <typename T>
std::string to_hex_variable_width(T value)
{
    std::ostringstream stream;
    stream << "0x" << std::hex << value;
    return stream.str();
}

template <typename T>
std::string to_hex_fixed_width(T value)
{
    std::ostringstream stream;
    stream << "0x" << std::setfill('0') << std::setw(sizeof(T) * 2) << std::hex << value;
    return stream.str();
}

inline std::string uuid_to_string(uint32_t size, const uint8_t* uuid)
{
    std::ostringstream stream;
    stream << std::setfill('0') << std::setw(2) << std::hex;
    for (size_t i = 0; i < size; ++i)
    {
        stream << (uint32_t)uuid[i];
    }
    return stream.str();
}

/// @brief Convert the integer representation of a handle in capture files into
/// either a JSON number or a JSON string with the number represented in
/// hexadecimal.
inline void HandleToJson(nlohmann::ordered_json& jdata, const format::HandleId handle, const JsonOptions& options)
{
    if (options.hex_handles)
    {
        // A JSON string
        jdata = to_hex_variable_width(handle);
    }
    else
    {
        // A JSON number
        jdata = handle;
    }
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_JSON_UTIL_H
