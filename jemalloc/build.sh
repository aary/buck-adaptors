cd jemalloc
git clean --force -x -d
git reset --hard
bash autogen.sh
./configure
make
