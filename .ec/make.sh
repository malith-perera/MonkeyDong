#!/bin/bash

if [ ! -d .ec/build ]
then
  mkdir .ec/build
fi

if [ -f .ec/build/MonkeyDong ]
then
  rm -f .ec/build/MonkeyDong
fi

if [ -f MonkeyDong ]
then
  rm -f MonkeyDong
fi

cd .ec/build

cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug .. #Release #Debug

make -j${nproc}

cd ..

if [ -f build/MonkeyDong ]
then
  mv -f build/MonkeyDong ../MonkeyDong
fi



