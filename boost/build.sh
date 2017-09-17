curl -OL https://dl.bintray.com/boostorg/release/1.65.1/source/boost_1_65_1.tar.gz
tar -xzf boost_1_65_1.tar.gz
mv boost_1_65_1 boost
rm boost_1_65_1.tar.gz

cd boost
./bootstrap.sh
mkdir build
./b2 --prefix=build --with-chrono --with-context --with-coroutine --with-system --with-regex --with-thread
