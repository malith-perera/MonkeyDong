#!/bin/bash

if [ -d "build" ]; then
  rm -r build
fi

mkdir build
cd build

cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=DEBUG ../

make -j${nproc}

if [ -f "MonkeyDong" ]; then
  cp "MonkeyDong" ..
  cd ..
  rm -r build
else
  echo "Error: cannot build"
fi
