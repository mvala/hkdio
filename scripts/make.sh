#!/bin/bash

HK_DIR="$(dirname $(dirname $(readlink -m $0)))"

[ "$1" = "clean" ] && { shift; rm -rf $HK_DIR/build; }
[ -d $HK_DIR/build ] ||  mkdir $HK_DIR/build

cd $HK_DIR/build || exit 1
[ -f Makefile ] || cmake -DCMAKE_INSTALL_PREFIX=$HK_DIR -DCMAKE_BUILD_TYPE=RelWithDebInfo ../
make -j$(nproc) $*

