#include <gtest/gtest.h>

#include <filesystem>
#include <fstream>
#include <string>

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

// Count the calls to api_call_name recorded in a converted gfxr, and how many of them mention struct_type
// anywhere in their arguments.
CallCounts count_calls_mentioning(const std::filesystem::path& json_path,
                                  const std::string&           api_call_name,
                                  const std::string&           struct_type)
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
        if (contains_string_value(*function, struct_type))
        {
            ++counts.matching;
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

// Replays the same capture with -m rebind, where memory is managed by VMA rather than by the captured
// vkAllocateMemory calls. The external create-info structs have to survive that translation, and the resources
// have to end up bound to exportable allocations. See
// https://github.com/LunarG/gfxreconstruct/issues/2813.
//
// The mock ICD does not validate, so replay exits cleanly whether or not it dropped the structs. Recapture the
// replay process instead and check what it actually handed to the driver.
TEST(ExternalMemoryFD, RebindReplay)
{
    run_in_background("external-memory-fd-export");

    // Wait for the exporter to be ready
    sleep(1);

    std::filesystem::path replay_json_path;
    ASSERT_NO_FATAL_FAILURE(
        capture_and_replay_recapture("external-memory-fd-import", "rebind", { "-m", "rebind" }, replay_json_path));

    const CallCounts counts = count_calls_mentioning(
        replay_json_path, "vkCreateImage", "VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO");

    ASSERT_GT(counts.total, 0u) << "replay made no vkCreateImage calls, see " << replay_json_path;
    EXPECT_GT(counts.matching, 0u) << "replay with -m rebind dropped "
                                      "VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO from every one of the "
                                   << counts.total << " vkCreateImage calls, see " << replay_json_path;
}
