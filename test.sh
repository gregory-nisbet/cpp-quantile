#!/bin/bash

set -e
shopt -s nullglob

for exe in ./test_*.t ./test_*.exe-t; do
  "$exe"
done
