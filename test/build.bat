chcp 65001
@echo off
echo "Remove build directory"
rmdir build /s /q
echo "Building unit tests..."
cmake -S . -B build -G "MinGW Makefiles"
cmake --build build
cd build && ctest
cd ..
