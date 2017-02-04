cd fmt
git clean --force -x -d
git reset --hard
mkdir build
cd build
cmake ..
make
