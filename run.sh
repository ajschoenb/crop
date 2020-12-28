#!/bin/sh

BUILD_DIR=build

make clean all
./$BUILD_DIR/crop "$@"
