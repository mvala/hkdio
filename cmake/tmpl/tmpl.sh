#!/bin/bash

if [ -z "$1" ];then
    echo "./%0 <name>"
    exit 1
fi

cp -f HkTaskExample.h HkTask${1}.h
cp -f HkTaskExample.cxx HkTask${1}.cxx

sed -i -e 's/HkTaskExample/HkTask'$1'/g' HkTask${1}.h
sed -i -e 's/HkTaskExample/HkTask'$1'/g' HkTask${1}.cxx

echo "Files 'HkTask${1}.h' and 'HkTask${1}.cxx' were created."
