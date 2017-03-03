#include <gtest/gtest.h>
#include <json/json.hpp>

TEST(all, all) {
    using json = nlohmann::json;
    auto obj = R"(
        {
            "happy" : true,
            "pi" : 3.141
        }
    )"_json;
}
