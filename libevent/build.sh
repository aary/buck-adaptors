cd libevent
git clean -x --force
git reset --hard
bash autogen.sh
./configure --disable-openssl
make
mkdir lib
cp .libs/libevent.a lib/liblibevent.a
