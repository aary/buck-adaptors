#include <boost/shared_ptr.hpp>
#include <gtest/gtest.h>
#include <gflags/gflags.h>
#include <glog/logging.h>
#include <double-conversion/double-conversion.h>

#include <iostream>

using namespace std;

DEFINE_string(information, "placeholder", "something informative");

TEST(all, all) {
    LOG(INFO) << "success";
}
