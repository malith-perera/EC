#!/bin/bash

if [ -d "tools/build" ]
then
  echo "build directory found"
else
  echo "make build directory"
  mkdir "build"
fi

# Change to 'build' directory
cd tools/build

cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug ../

# Make
make

# Install
make install
