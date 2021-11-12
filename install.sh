#!/bin/bash

echo "Start Setup"

#echo "$PWD"

# Make EC directory if not exist
if [ -d "EC" ]
then
  echo "EC found"
else
  echo "make EC directory"
  mkdir "EC"
fi

# Make EC/lib if not exist
if [ -d "EC/lib" ]
then
  echo "EC/lib found"
else
  mkdir "EC/lib"
fi

# Make EC/bin if not exist
if [ -d "EC/bin" ]
then
  echo "EC/bin found"
else
  mkdir "EC/bin"
fi

# Make EC/share if not exist
if [ -d "EC/share" ]
then
  echo "EC/share found"
else
  mkdir "EC/share"
  mkdir "EC/share/icons"
fi

# Make EC/include if not exist
if [ -d "EC/include" ]
then
  echo "EC/include found"
else
  mkdir "EC/include"
fi

# Copy readme
echo "copy readme"
cp -r "share/doc" "EC/share"

# Copy eclib/include
echo "copy include"
cp -r "include/" "EC"

# Copy icons
echo "copy icons"
cp -r "share/icons/" "EC/share"

echo "copy libec.so"
cp "build/libec.so" "EC/lib"

echo "copy ec to bin"
cp "ec/ec" "EC/bin/"

echo "Setup Completed"
