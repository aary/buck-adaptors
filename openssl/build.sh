curl -OL https://github.com/openssl/openssl/archive/OpenSSL-fips-2_0_13.tar.gz
tar -xzf OpenSSL-fips-2_0_13.tar.gz
mv openssl-OpenSSL-fips-2_0_13 openssl
rm OpenSSL-fips-2_0_13.tar.gz
cd openssl
./Configure darwin64-x86_64-cc no-asm
make
mkdir lib
mv lib*.a lib
make clean
