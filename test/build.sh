#!/bin/sh -eu

case $1 in
    "unit" )
        rm -rf build
        echo "Building unit tests..."
        cmake -S . -B build
        cmake --build build
        cd build && ctest
        ;;
    "add")
        rm -rf build
        echo "Building add tests..."
        target="add"
        cmake -S . -B build -D TEST_TARGET=$target
        cmake --build build
        cd build && ctest
        ;;    
    "add2")
        rm -rf build
        echo "Building add2 tests..."
        target="add2"
        cmake -S . -B build -D TEST_TARGET=$target
        cmake --build build
        cd build && ctest
        ;;
    "add3")
        rm -rf build
        echo "Building add3 tests..."
        target="add3"
        cmake -S . -B build -D TEST_TARGET=$target
        cmake --build build
        cd build && ctest
        ;;
    "add4")
        rm -rf build
        echo "Building add4 tests..."
        target="add4"
        cmake -S . -B build -D TEST_TARGET=$target
        cmake --build build
        cd build && ctest
        ;;
esac
