#include <gtest/gtest.h>
#include <tbb/concurrent_queue.h>

TEST(all, all) {
    auto q = tbb::concurrent_queue<int>{};
    q.push(1);
    auto top_value = int{};
    EXPECT_TRUE(q.try_pop(top_value));
    EXPECT_EQ(top_value, 1);
    EXPECT_TRUE(q.empty());
}
