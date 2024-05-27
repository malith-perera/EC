#!/bin/bash

if [ -d "build" ]; then
  rm -r build
fi

mkdir build
cd build

cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug ../

make

if [ -f "libEC.so" ]; then
  cp libEC.so ../lib/
  cd ..
  rm -r build
else
  echo "Error: cannot build"
fi
