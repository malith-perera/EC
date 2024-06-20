#!/bin/bash

if [ -d "build" ]; then
  rm -r build
fi

mkdir build
cd build

cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug ../ #Release

make

cd ..

BUILDED=0

if [ -f "build/libEC.so" ]; then
  cp build/libEC.so lib/libEC.so
  BUILDED=1
fi

if [ -f "build/ec" ]; then
  cp -f build/ec bin/ec
  ln -sf bin/ec ec
  BUILDED=1
fi

if [ $BUILDED != 1 ]; then
  echo "Error: Cannot build"
else
  rm -r build
  echo "Build Successful"
fi
