#!/bin/bash

if [ -d "tools/build" ]
then
  echo "build directory build"
else
  echo "make directory build"
  mkdir "tools/build"
fi

# Change to 'build' directory
cd tools/build

cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug ../

# Make
make

# Install
make install
