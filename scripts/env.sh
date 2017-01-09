#!/bin/bash

HK_DIR="$(dirname $(dirname $(readlink -m ${BASH_ARGV[0]})))"

export PATH="$HK_DIR/bin:$HK_DIR/scripts:$PATH"
export LD_LIBRARY_PATH="$HK_DIR/lib:$HK_DIR/lib64:$LD_LIBRARY_PATH"
export HK_MACRO_DIR="$HK_DIR/macros"
