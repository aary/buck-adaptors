#include <gtest/gtest.h>
#include <gmock/gmock.h>

TEST(test, test) {
    // cast the function pointer to force a resolution to the right function
    // since it's an overloaded function
    auto one = static_cast<void (*) (int*, char**)>(&::testing::InitGoogleTest);
    auto two = &RUN_ALL_TESTS;
    EXPECT_TRUE(one);
    EXPECT_TRUE(two);
}
