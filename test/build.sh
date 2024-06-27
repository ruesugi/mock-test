#!/bin/sh

case $1 in
	"" )
		rm -rf build
		echo "Building unit tests..."
		cmake -S . -B build
		cmake --build build
		cd build && ctest
		cd ..
		;;
esac
