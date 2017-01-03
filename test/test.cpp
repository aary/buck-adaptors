#include <boost/shared_ptr.hpp>
#include <gtest/gtest.h>
#include <gflags/gflags.h>
#include <glog/logging.h>
#include <double-conversion/double-conversion.h>
#include <jemalloc/jemalloc.h>
#include <snappy.h>
#include <lz4.h>
#include <openssl/ssl.h>
#include <fatal/string/string_view.h>

#include <iostream>
#include <string>

using namespace std;

DEFINE_string(information, "placeholder", "something informative");

TEST(all, all) {
    OpenSSL_add_ssl_algorithms();
    auto to_compress = string{"aaaaaaaa"};
    auto compressed = to_compress;
    auto view = fatal::string_view{"saaaaa"};
    EXPECT_EQ(view, "saaaaa");
    snappy::Compress(to_compress.data(), to_compress.size(), &compressed);
    LZ4_compress_default(to_compress.data(), (char*)compressed.data(),
            to_compress.size(), compressed.size());

    void* memory = malloc(1000);
    EXPECT_TRUE(static_cast<bool>(memory));
    LOG(INFO) << "success";
}
