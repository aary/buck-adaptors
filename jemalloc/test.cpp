#include <gtest/gtest.h>
#include <jemalloc/jemalloc.h>

TEST(all, all) {
    void* memory = malloc(1000);
    EXPECT_TRUE(static_cast<bool>(memory));
}
