#!/bin/bash

if [ -d "build" ]; then
  rm -r build
fi

mkdir build
cd build

# CMake
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug ..

make

if [ -f "ectest" ]; then
  cp ectest ../bin
  cd ..
  rm -r build
else
  echo "Error: cannot build"
fi
