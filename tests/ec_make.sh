#!/bin/bash

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
else
  echo "Error: cannot build"
fi
