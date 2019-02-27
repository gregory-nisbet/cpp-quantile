#!/bin/bash

set -e

if test -z "$LOOSE"; then
  CXXFLAGS+=" -std=c++11 -Wall -Werror -Wextra -pedantic"
fi
INCLUDES+=" -I . -I vendor"
LINKARGS+=

COMPILE="clang++ -c"
LINK="clang++"

# compile object
$COMPILE $CXXFLAGS -fPIC $INCLUDES -o quantile.o quantile.cpp
# link into shared object
$LINK $CXXFLAGS -shared $LINKARGS -o quantile.so quantile.o
# compile test suite (conservatively build it fPIC)
$COMPILE $CXXFLAGS -fPIC -o test_quantile.o test_quantile.cpp
# link test suite
$LINK $CXXFLAGS -o test_quantile.exe-t quantile.o test_quantile.o
