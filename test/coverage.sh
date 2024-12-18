#!/bin/sh -eu

cd build
find . -type f -name "*.gcda" | xargs -I@ gcov -b @
TESTCODE_PATH=$(pwd | xargs dirname)/targets
SOURCECODE_PATH=$(pwd | xargs dirname | xargs dirname)/source
lcov -c -d . -o output_testcode.info --include "$TESTCODE_PATH/*"
lcov -c -d . -o output_sourcecode.info --include "$SOURCECODE_PATH/*" --rc lcov_branch_coverage=1
lcov -a output_testcode.info -a output_sourcecode.info -o output.info --rc lcov_branch_coverage=1
genhtml -o output -p . -f output.info --branch-coverage
