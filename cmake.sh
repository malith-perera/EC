#!/bin/bash

if [ -d "build" ]; then
  rm -r "build"
fi

mkdir "build"
cd "build"
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug ../

make

cp libEC.so ../../EC/lib/
cp -r ../include ../../EC
cp -r ../../EC ../../ec_examples/
