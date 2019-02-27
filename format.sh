#!/bin/bash

set -e
shopt -s nullglob

clang-format -i --style=WebKit *.hpp *.cpp
