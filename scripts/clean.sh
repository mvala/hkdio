#!/bin/bash

HK_DIR="$(dirname $(dirname $(readlink -m $0)))"

for d in bin lib lib64 share pars; do
  [ -d $HK_DIR/$d ] && rm -rf $HK_DIR/$d
done
