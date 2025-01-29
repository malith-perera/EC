#!/bin/bash

if [ -d ".ec/build" ]
then
  cd .ec/build
else
  mkdir .ec/build
  cd .ec/build
fi

if [ -f ".ec/build/ec" ]
then
  rm -f build/ec
fi

if [ -f ".ec/build/libEC.so" ]
then
  rm -f build/libEC.so
fi

if [ -f ".ec/build/test" ]
then
  rm -f build/test
fi

cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug .. #Release #Debug

make -j${nproc}

cd ..

if [ -f "build/libEC.so" ]
then
  mv -f build/libEC.so ../libEC.so
fi

if [ -f "build/ec" ]
then
  mv -f build/ec ../ec
fi

if [ -f "build/ec_test" ]
then
  mv -f build/ec_test ../ec_test
fi
