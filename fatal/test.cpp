#include <fatal/type/fast_pass.h>
#include <fatal/container/optional.h>
#include <gtest/gtest.h>

TEST(fatal, fatal) {
    static_assert(std::is_same<const int, fatal::fast_pass<int>>::value,
            "fast_pass type incorrect");
    auto opt = fatal::optional<int>{};
    EXPECT_TRUE(opt.empty());
}

