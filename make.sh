#!/bin/bash

cd build
make

cp libEC.so ../../EC/lib/
cp -r ../include ../../EC
