#!/bin/sh

mkdir build
cd build
CXX=clang++ cmake ..
make
