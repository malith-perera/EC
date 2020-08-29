#!/bin/bash

if [ -d "build" ]
then
  echo "build directory build"
else
  echo "make directory build"
  mkdir "build"
fi

# Change to 'build' directory
cd build

cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug ..

# Make
make

# Install
make install
