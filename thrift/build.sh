cd thrift
git clean --force -x -d
git reset --hard
mkdir cmake-build
cd cmake-build
cmake .. -DBUILD_COMPILER=OFF
