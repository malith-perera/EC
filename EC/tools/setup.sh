#!/bin/bash

echo "Start Setup"
echo "$PWD"

echo "copy libec.so to lib"
cp "$PWD/EC/eclib/lib/libec.so" "$PWD/EC/EC/lib"

echo "copy ec/include directory to EC"
cp -r "$PWD/EC/eclib/include/" "$PWD/EC/EC/"

echo "copy icons directory to EC"
cp -r "$PWD/EC/icons/" "$PWD/EC/EC/"

echo "copy ec-cli to bin"
cp "$PWD/EC/ec-cli/bin/ec-cli" "$PWD/EC/EC/bin/"

echo "copy ec-icon to bin"
cp "$PWD/EC/ec-icon/bin/ec-icon" "$PWD/EC/EC/bin/"

echo "copy ec to bin"
cp "$PWD/EC/ec/bin/ec" "$PWD/EC/EC/bin/"

echo "copy remove-build"
cp "$PWD/EC/remove-build/bin/remove-build" "$PWD/EC/EC/bin/"

echo "Setup Completed"
