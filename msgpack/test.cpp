#include <sstream>
#include <tuple>

#include <gtest/gtest.h>
#include <msgpack.hpp>

TEST(all, all) {
    auto t = std::make_tuple("1", 1, 1.0);
    auto buffer = std::stringstream{};
    msgpack::pack(buffer, t);
    EXPECT_TRUE(!buffer.str().empty());
}
