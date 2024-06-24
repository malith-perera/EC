#!/bin/bash

if [ -d "build" ]; then
  cd build
else
  mkdir build
  cd build
fi

cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug ../ #Release

make

cd ..

if [ -f "build/libEC.so" ]; then
  cp build/libEC.so libEC.so
fi

if [ -f "build/ec" ]; then
  cp -f build/ec ec
fi
