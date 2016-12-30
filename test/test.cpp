#include <boost/shared_ptr.hpp>
#include <gtest/gtest.h>
#include <gflags/gflags.h>
#include <glog/logging.h>
#include <double-conversion/double-conversion.h>
#include <jemalloc/jemalloc.h>
#include <snappy.h>

#include <iostream>
#include <string>

using namespace std;

DEFINE_string(information, "placeholder", "something informative");

TEST(all, all) {
    auto to_compress = string{"aaaaaaaa"};
    auto compressed = to_compress;
    snappy::Compress(to_compress.data(), to_compress.size(), &compressed);

    void* memory = malloc(1000);
    EXPECT_TRUE(static_cast<bool>(memory));
    LOG(INFO) << "success";
}
