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

# Make EC/etc if not exist
if [ -d "EC/etc" ]
then
  echo "EC/etc found"
else
  mkdir "EC/etc"
fi

# Copy readme
echo "copy readme"
cp "share/doc/readme" "EC"

# Copy eclib/include
echo "copy ec/include"
cp -r "eclib/include/" "EC"

# Copy icons
echo "copy icons"
cp -r "share/icons/" "EC/share"

echo "copy libec.so"
cp "eclib/libec.so" "EC/lib"

#echo "copy ec-cli"
#cp "ec-cli/ec-cli" "EC/bin/"

#echo "copy ec-shortcut to bin"
#cp "ec-shortcut/ec-shortcut" "EC/bin/"

#echo "copy reset-shortcut to bin"
#cp "reset-shortcut/reset-shortcut" "EC/bin/"

echo "copy ec to bin"
cp "ec/ec" "EC/bin/"

#echo "copy remove-build"
#cp "remove-build/remove-build" "EC/bin/"

echo "Setup Completed"
