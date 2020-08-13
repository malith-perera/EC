#!/bin/bash

echo "Start Setup"

cd ".."

echo "copy libec.so to lib"
cp "$PWD/eclib/lib/libec.so" "$PWD/EC/lib"

echo "copy ec/include directory to EC"
cp -r "$PWD/eclib/include/" "$PWD/EC"

echo "copy icons directory to EC"
cp -r "$PWD/icons/" "$PWD/EC"

echo "copy ec-cli to bin"
cp "$PWD/ec-cli/bin/ec-cli" "$PWD/EC/bin/"

echo "copy ec-shortcut to bin"
cp "$PWD/ec-shortcut/bin/ec-shortcut" "$PWD/EC/bin/"

echo "copy reset-shortcut to bin"
cp "$PWD/reset-shortcut/bin/reset-shortcut" "$PWD/EC/bin/"

echo "copy ec to bin"
cp "$PWD/ec/bin/ec" "$PWD/EC/bin/"

echo "copy remove-build"
cp "$PWD/remove-build/bin/remove-build" "$PWD/EC/bin/"

echo "Setup Completed"
