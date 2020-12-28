#!/bin/sh

BUILD_DIR=build

make clean all
gdb ./$BUILD_DIR/crop
