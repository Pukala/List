#!/bin/bash
cd code
cmake .
make
mv executable ../
rm -rf CMakeCache.txt  CMakeFiles  Makefile  cmake_install.cmake
