#include <gtest/gtest.h>

#include <filesystem>
#include <fstream>
#include <string>
#include <vector>

#include <nlohmann/json.hpp>

#include "verify-gfxr.h"

namespace
{

bool contains_string_value(const nlohmann::json& value, const std::string& needle)
{
    if (value.is_string())
    {
        return value.get<std::string>() == needle;
    }

    if (value.is_object() || value.is_array())
    {
        for (const auto& child : value)
        {
            if (contains_string_value(child, needle))
            {
                return true;
            }
        }
    }

    return false;
}

struct CallCounts
{
    size_t total    = 0;
    size_t matching = 0;
};

// pNext structs, any one of which satisfies the expectation for a given entry point.
struct Expectation
{
    const char*              api_call;
    std::vector<const char*> struct_types;
};

// Count the calls to api_call_name recorded in a converted gfxr, and how many of them mention struct_type
// anywhere in their arguments.
CallCounts count_calls_mentioning(const std::filesystem::path&    json_path,
                                  const std::string&              api_call_name,
                                  const std::vector<const char*>& struct_types)
{
    std::ifstream file{ json_path };
    EXPECT_TRUE(file.is_open()) << "json file: " << json_path << " would not open";

    const auto blocks = nlohmann::json::parse(file);

    CallCounts counts;
    for (const auto& block : blocks)
    {
        const auto function = block.find("function");
        if (function == block.end() || !function->is_object() ||
            function->value("name", std::string{}) != api_call_name)
        {
            continue;
        }

        ++counts.total;
        for (const char* struct_type : struct_types)
        {
            if (contains_string_value(*function, struct_type))
            {
                ++counts.matching;
                break;
            }
        }
    }

    return counts;
}

} // namespace

TEST(ExternalMemoryFD, CorrectGFXR)
{
    run_in_background("external-memory-fd-export");

    // Wait for the exporter to be ready
    sleep(1);
    verify_gfxr("external-memory-fd-import");
}

TEST(ExternalMemoryFD, RebindReplay)
{
    run_in_background("external-memory-fd-export");

    // Wait for the exporter to be ready
    sleep(1);

    std::filesystem::path replay_json_path;
    ASSERT_NO_FATAL_FAILURE(
        capture_and_replay_recapture("external-memory-fd-import", "rebind", { "-m", "rebind" }, replay_json_path));

    const Expectation expectations[] = {
        { "vkCreateImage", { "VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO" } },
        { "vkCreateBuffer", { "VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO" } },
        // The memory backing those resources has to be external too. Replay either forwards the captured import
        // (VkImportMemoryFdInfoKHR with a replacement FD) or, under address replacement, allocates exportable
        // memory of its own.
        { "vkAllocateMemory",
          { "VK_STRUCTURE_TYPE_IMPORT_MEMORY_FD_INFO_KHR", "VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO" } },
    };

    for (const Expectation& expected : expectations)
    {
        const CallCounts counts = count_calls_mentioning(replay_json_path, expected.api_call, expected.struct_types);

        EXPECT_GT(counts.total, 0u) << "replay made no " << expected.api_call << " calls, see " << replay_json_path;
        EXPECT_GT(counts.matching, 0u) << "replay with -m rebind dropped " << expected.struct_types.front()
                                       << " from every one of the " << counts.total << " " << expected.api_call
                                       << " calls, see " << replay_json_path;
    }
}
