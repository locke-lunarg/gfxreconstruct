/*
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

#include "graphics/dx12_dump_resources.h"
// TODO: It should change the file name of "vulkan"
#include "generated/generated_vulkan_struct_to_json.h"
#include "../build/project_version.h"
#include "util/platform.h"
#include "util/logging.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

Dx12DumpResources::Dx12DumpResources() : json_file_handle_(nullptr) {}

Dx12DumpResources::~Dx12DumpResources()
{
    EndFile();
}

void Dx12DumpResources::WriteBeforeResources(nlohmann::ordered_json&              jdata,
                                             const std::string&                   prefix_file_name,
                                             const std::vector<CopyResourceData>& reousce_datas)
{
    uint32_t i = 0;
    for (const auto& resouce : reousce_datas)
    {
        WriteBeforeResource(jdata[i], prefix_file_name, resouce);
        ++i;
    }
}

void Dx12DumpResources::WriteBeforeResource(nlohmann::ordered_json& jdata,
                                            const std::string&      prefix_file_name,
                                            const CopyResourceData& reousce_data)
{
    if (reousce_data.before_resource == nullptr)
    {
        return;
    }
    WriteResource(jdata, prefix_file_name, "_before.bin", reousce_data, reousce_data.before_resource);
}

void Dx12DumpResources::WriteAfterResources(nlohmann::ordered_json&              jdata,
                                            const std::string&                   prefix_file_name,
                                            const std::vector<CopyResourceData>& reousce_datas)
{
    uint32_t i = 0;
    for (const auto& resouce : reousce_datas)
    {
        WriteAfterResource(jdata[i], prefix_file_name, resouce);
        ++i;
    }
}

void Dx12DumpResources::WriteAfterResource(nlohmann::ordered_json& jdata,
                                           const std::string&      prefix_file_name,
                                           const CopyResourceData& reousce_data)
{
    if (reousce_data.after_resource == nullptr)
    {
        return;
    }
    WriteResource(jdata, prefix_file_name, "_after.bin", reousce_data, reousce_data.after_resource);
}

void Dx12DumpResources::WriteResource(nlohmann::ordered_json&           jdata,
                                      const std::string&                prefix_file_name,
                                      const std::string&                suffix_file_name,
                                      const CopyResourceData&           reousce_data,
                                      const dx12::ID3D12ResourceComPtr& reousce)
{
    if (reousce == nullptr)
    {
        return;
    }
    std::string file_name =
        prefix_file_name + "_resource_id_" + std::to_string(reousce_data.source_resource_id) + suffix_file_name;

    decode::FieldToJson(jdata["file_name"], file_name.c_str(), json_options_);
    decode::FieldToJson(jdata["size"], reousce_data.size, json_options_);

    uint8_t*    data_begin;
    D3D12_RANGE read_Range = { 0, 0 };
    reousce->Map(0, &read_Range, reinterpret_cast<void**>(&data_begin));
    reousce->Unmap(0, nullptr);

    std::string filepath = gfxrecon::util::filepath::Join(json_options_.root_dir, file_name);
    WriteBinaryFile(filepath, reousce_data.size, data_begin);
}

void Dx12DumpResources::WriteDrawcallResources(const TrackDumpResourcesDrawcall& resources)
{
    // before
    WriteMetaCommandToFile("before", [&](auto& jdata) {
        // vertex
        WriteBeforeResources(jdata["vertex"], json_options_.data_sub_dir, resources.copy_vertex_resources);

        // index
        WriteBeforeResource(jdata["index"], json_options_.data_sub_dir, resources.copy_index_resource);

        // descriptor
        uint32_t dh_index = 0;
        for (const auto& dh_data : resources.descriptor_heap_datas)
        {
            std::string filename = json_options_.data_sub_dir + "_heap_id_" + std::to_string(dh_data.id);
            WriteBeforeResources(jdata["descriptor_heap"][dh_index]["constant_buffer"],
                                 filename,
                                 dh_data.copy_constant_buffer_resources);
            WriteBeforeResources(
                jdata["descriptor_heap"][dh_index]["shader_resource"], filename, dh_data.copy_shader_resources);
            ++dh_index;
        }

        // render target
        WriteBeforeResources(
            jdata["render_target"], json_options_.data_sub_dir, resources.copy_render_target_resources);
        WriteBeforeResource(jdata["depth_stencil"], json_options_.data_sub_dir, resources.copy_depth_stencil_resource);
    });

    // after
    WriteMetaCommandToFile("after", [&](auto& jdata) {
        // vertex
        WriteAfterResources(jdata["vertex"], json_options_.data_sub_dir, resources.copy_vertex_resources);

        // index
        WriteAfterResource(jdata["index"], json_options_.data_sub_dir, resources.copy_index_resource);

        // descriptor
        uint32_t dh_index = 0;
        for (const auto& dh_data : resources.descriptor_heap_datas)
        {
            std::string filename = json_options_.data_sub_dir + "_heap_id_" + std::to_string(dh_data.id);
            WriteAfterResources(jdata["descriptor_heap"][dh_index]["constant_buffer"],
                                filename,
                                dh_data.copy_constant_buffer_resources);
            WriteAfterResources(
                jdata["descriptor_heap"][dh_index]["shader_resource"], filename, dh_data.copy_shader_resources);
            ++dh_index;
        }

        // render target
        WriteAfterResources(jdata["render_target"], json_options_.data_sub_dir, resources.copy_render_target_resources);
        WriteAfterResource(jdata["depth_stencil"], json_options_.data_sub_dir, resources.copy_depth_stencil_resource);
    });
}

std::unique_ptr<Dx12DumpResources> Dx12DumpResources::Create(const Dx12DumpResourcesConfig& config)
{
    std::unique_ptr<Dx12DumpResources> out(new Dx12DumpResources());

    if (out != nullptr)
    {
        if (out->Init(config) != S_OK)
        {
            GFXRECON_LOG_WARNING("Dx12DumpResources initialization failed");
        }
    }
    return std::move(out);
}

HRESULT Dx12DumpResources::Init(const Dx12DumpResourcesConfig& config)
{
    HRESULT result       = S_OK;
    json_options_.format = kDefaultDumpResourcesFileFormat;

    json_filename_    = config.captured_file_name;
    auto ext_pos      = json_filename_.find_last_of(".");
    auto path_sep_pos = json_filename_.find_last_of(util::filepath::kPathSepStr);
    if (ext_pos != std::string::npos && (path_sep_pos == std::string::npos || ext_pos > path_sep_pos))
    {
        json_filename_ = json_filename_.substr(0, ext_pos);
    }
    json_filename_ += "_resources_" + decode::GetDumpResourcesType(config.type) + "_" +
                      std::to_string(config.argument) + "." + util::get_json_format(json_options_.format);

    json_options_.data_sub_dir = util::filepath::GetFilenameStem(json_filename_);
    json_options_.root_dir     = util::filepath::GetBasedir(json_filename_);

    util::platform::FileOpen(&json_file_handle_, json_filename_.c_str(), "w");

    header_["source-path"]      = config.captured_file_name;
    header_["gfxrecon-version"] = GFXRECON_PROJECT_VERSION_STRING;

    StartFile();
    return result;
}

void Dx12DumpResources::StartFile()
{
    num_objects_ = 0;
    if (json_options_.format == util::JsonFormat::JSON)
    {
        util::platform::FilePuts("[\n", json_file_handle_);
    }

    // Emit the header object as the first line of the file:
    WriteBlockStart();
    json_data_["header"] = header_;
    WriteBlockEnd();
}

void Dx12DumpResources::EndFile()
{
    if (json_file_handle_ != nullptr)
    {
        if (json_options_.format == util::JsonFormat::JSON)
        {
            util::platform::FilePuts("\n]\n", json_file_handle_);
        }
        else
        {
            util::platform::FilePuts("\n", json_file_handle_);
        }
        util::platform::FileClose(json_file_handle_);
        json_file_handle_ = nullptr;
    }
}

void Dx12DumpResources::WriteBlockStart()
{
    json_data_.clear(); // < Dominates profiling (1/2).
    num_objects_++;
}

void Dx12DumpResources::WriteBlockEnd()
{
    if (num_objects_ > 1)
    {
        util::platform::FilePuts(json_options_.format == util::JsonFormat::JSONL ? "\n" : ",\n", json_file_handle_);
    }
    // Dominates profiling (2/2):
    const std::string block =
        json_data_.dump(json_options_.format == util::JsonFormat::JSONL ? -1 : util::kJsonIndentWidth);
    util::platform::FileWriteNoLock(block.data(), sizeof(std::string::value_type), block.length(), json_file_handle_);
    util::platform::FileFlush(json_file_handle_); /// @todo Implement a FileFlushNoLock() for all platforms.
}

bool Dx12DumpResources::WriteBinaryFile(const std::string& filename, uint64_t data_size, const uint8_t* data)
{
    FILE* file_output = nullptr;
    if (util::platform::FileOpen(&file_output, filename.c_str(), "wb") == 0)
    {
        util::platform::FileWrite(data, static_cast<size_t>(data_size), 1, file_output);
        util::platform::FileClose(file_output);
        return true;
    }
    return false;
}

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)
