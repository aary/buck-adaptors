#include <fmt/format.h>
#include <gtest/gtest.h>

TEST(fmt, fmt) {
    EXPECT_EQ(fmt::format("{0}{1}{0}", "abra", "cad"), "abracadabra");
}
