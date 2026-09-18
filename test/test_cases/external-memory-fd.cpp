#include <gtest/gtest.h>

#include <filesystem>
#include <fstream>
#include <string>

#include <nlohmann/json.hpp>

#include "verify-gfxr.h"

namespace
{

struct CallCounts
{
    size_t total    = 0;
    size_t matching = 0;
};

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

// Capture the import app, replay that capture, and report what the replayer's own vkCreateImage calls carried in
// their pNext chain. The exporter has to be up first, since the import app blocks on its socket.
CallCounts replay_and_count_external_memory_images(const char* replay_tag, std::vector<std::string> replay_args)
{
    run_in_background("external-memory-fd-export");

    // Wait for the exporter to be ready
    sleep(1);

    std::filesystem::path replay_json_path;
    capture_and_replay_recapture("external-memory-fd-import", replay_tag, replay_args, replay_json_path);
    if (::testing::Test::HasFatalFailure())
    {
        return {};
    }

    return count_calls_mentioning(
        replay_json_path, "vkCreateImage", "VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO");
}

} // namespace

TEST(ExternalMemoryFD, CorrectGFXR)
{
    run_in_background("external-memory-fd-export");

    // Wait for the exporter to be ready
    sleep(1);
    verify_gfxr("external-memory-fd-import");
}

// Control case: with the default allocator, replay hands VkExternalMemoryImageCreateInfo straight through, so any
// failure here points at the test app or the harness rather than at the stripping logic under test.
TEST(ExternalMemoryFD, DefaultAllocatorReplayPreservesExternalMemoryImageCreateInfo)
{
    const CallCounts counts = replay_and_count_external_memory_images("default", {});
    ASSERT_FALSE(::testing::Test::HasFatalFailure());

    ASSERT_GT(counts.total, 0u) << "replay made no vkCreateImage calls";
    EXPECT_GT(counts.matching, 0u) << "replay dropped VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO from every "
                                      "one of the "
                                   << counts.total << " vkCreateImage calls";
}

// Reproduces https://github.com/LunarG/gfxreconstruct/issues/2813.
//
// OverrideCreateImage() strips VkExternalMemoryImageCreateInfo whenever CanPreserveExternalMemory() is false, and
// that is always the case under address replacement (-m rebind), even though the replay device supports
// VK_KHR_external_memory_fd. Dropping the struct changes the memory requirements the driver reports for the image,
// which is what the issue reports as crashes on undersized allocations.
TEST(ExternalMemoryFD, RebindAllocatorReplayPreservesExternalMemoryImageCreateInfo)
{
    const CallCounts counts = replay_and_count_external_memory_images("rebind", { "-m", "rebind" });
    ASSERT_FALSE(::testing::Test::HasFatalFailure());

    ASSERT_GT(counts.total, 0u) << "replay made no vkCreateImage calls";
    EXPECT_GT(counts.matching, 0u) << "replay with -m rebind dropped "
                                      "VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO from every one of the "
                                   << counts.total << " vkCreateImage calls";
}
