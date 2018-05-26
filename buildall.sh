#!/bin/bash
echo "BEGIN BUILD"

PATH=$(echo "$PATH" | sed -e 's/:\/mnt.*//g') # strip out problematic Windows %PATH% imported var

cd depends

make HOST=x86_64-w64-mingw32

cd ..

./autogen.sh # not required when building from tarball

CONFIG_SITE=$PWD/depends/x86_64-w64-mingw32/share/config.site ./configure --prefix=/ --disable-tests --disable-bench --with-gui=qt5

make

echo "BUILD COMPLETE"
