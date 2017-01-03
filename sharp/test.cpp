#include <sharp/Tags/Tags.hpp>
#include <sharp/OrderedContainer/OrderedContainer.hpp>
#include <gtest/gtest.h>

#include <vector>
#include <functional>

TEST(sharp, sharp) {
    sharp::OrderedContainer<std::vector<int>, std::less<void>> oc;
    oc.insert(1);
    EXPECT_EQ(*oc.begin(), 1);
    sharp::initializer_list_construct{};
}
