#include <glog/logging.h>
#include <gtest/gtest.h>

TEST(glog, glog) {
    LOG(INFO) << "Something that should be logged via google log";
}
