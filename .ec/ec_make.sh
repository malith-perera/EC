#!/bin/bash

if [ -d ".ec/build" ]; then
  cd .ec/build
else
  mkdir .ec/build
  cd .ec/build
fi

cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug .. #Release #Debug

make -j${nproc}

cd ..

if [ -f "build/ec" ]; then
  cp -f build/ec ../ec
  cp -f build/libEC.so ../libEC.so
fi
