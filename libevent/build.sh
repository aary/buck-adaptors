cd libevent
git clean --force -x -d
git reset --hard
bash autogen.sh
./configure --disable-openssl
make
mkdir lib
cp .libs/libevent.a lib/liblibevent.a
