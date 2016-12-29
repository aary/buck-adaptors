#include <boost/shared_ptr.hpp>
#include <gtest/gtest.h>
#include <gflags/gflags.h>
#include <glog/logging.h>
#include <double-conversion/double-conversion.h>
#include <jemalloc/jemalloc.h>

#include <iostream>

using namespace std;

DEFINE_string(information, "placeholder", "something informative");

TEST(all, all) {
    void* memory = malloc(1000);
    EXPECT_TRUE(static_cast<bool>(memory));
    LOG(INFO) << "success";
}
