#!/bin/bash

if [ -f `pwd`/cmake/toolchain/iOS.cmake ]
then
    CMAKE="`pwd`/cmake/toolchain"
else
    echo "[E] iOS CMake not found"
    exit
fi

echo "[X] iOS CMake    : $CMAKE"

IOSTOOLCHAIN=$CMAKE/iOS.cmake
alias ios-cmake='cmake -DCMAKE_TOOLCHAIN_FILE='"$IOSTOOLCHAIN"' -G Xcode'

echo
echo "Is an alias set to iOS.cmake?"
echo
alias
