#!/bin/bash

#if [ -d "build" ]; then
  #rm -r build
#fi

if [ -d "build" ]; then
  cd build
else
  mkdir build
  cd build
fi

cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug .. #Release

make

if [ -f "tests" ]; then
  cp tests ../tests
  cd ..
  #rm -r build
else
  echo "Error: cannot build"
fi
