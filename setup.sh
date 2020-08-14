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

# Copy readme
echo "copy readme"
cp "doc/readme" "EC"

# Copy eclib/include
echo "copy ec/include"
cp -r "eclib/include/" "EC"

# Copy icons
echo "copy icons"
cp -r "icons/" "EC"

echo "copy libec.so"
cp "eclib/lib/libec.so" "EC/lib"

echo "copy ec-cli"
cp "ec-cli/bin/ec-cli" "EC/bin/"

echo "copy ec-shortcut to bin"
cp "ec-shortcut/bin/ec-shortcut" "EC/bin/"

echo "copy reset-shortcut to bin"
cp "reset-shortcut/bin/reset-shortcut" "EC/bin/"

echo "copy ec to bin"
cp "ec/bin/ec" "EC/bin/"

echo "copy remove-build"
cp "remove-build/bin/remove-build" "EC/bin/"

echo "Setup Completed"
