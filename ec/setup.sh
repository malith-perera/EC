#!/bin/bash

if [ -d "build" ]
then
  echo "build directory found"
else
  echo "make build directory"
  mkdir "build"
fi

#Change to application tools
cd "build"

cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug ..

# Make
make

# Install
make install
