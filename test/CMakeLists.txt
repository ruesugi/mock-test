cmake_minimum_required(VERSION 3.14)
project(my_project)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(WIN32)
  set(CMAKE_CXX_FLAGS "-Wa,-mbig-obj -g --coverage")
  set(CMAKE_C_FLAGS "-Wa,-mbig-obj -g --coverage")
endif()

if(UNIX)
  set(CMAKE_CXX_FLAGS "-g --coverage")
  set(CMAKE_C_FLAGS "-g --coverage")
endif()

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

set(TEST_TARGET "unit" CACHE STRING description)
message(STATUS "TEST_TARGET : ${TEST_TARGET}")

if(("${TEST_TARGET}" STREQUAL "add") OR("${TEST_TARGET}" STREQUAL "unit"))
  add_executable(
    add_test
    targets/test_add.cc
    ../source/add.c
  )
  target_include_directories(add_test PRIVATE ../source)
  target_include_directories(add_test PRIVATE ./mocks)
  target_link_libraries(
    add_test
    GTest::gmock_main
  )
endif()

if(("${TEST_TARGET}" STREQUAL "add2") OR("${TEST_TARGET}" STREQUAL "unit"))
  add_executable(
    add2_test
    targets/test_add2.cc
    ../source/add2.c
    ./mocks/addMock.cc
  )
  target_include_directories(add2_test PRIVATE ../source)
  target_include_directories(add2_test PRIVATE ./mocks)
  target_link_libraries(
    add2_test
    GTest::gmock_main
  )
endif()

if(("${TEST_TARGET}" STREQUAL "add3") OR("${TEST_TARGET}" STREQUAL "unit"))
  add_executable(
    add3_test
    targets/test_add3.cc
    ../source/add3.c
    ./mocks/addMock.cc
  )
  target_include_directories(add3_test PRIVATE ../source)
  target_include_directories(add3_test PRIVATE ./mocks)
  target_link_libraries(
    add3_test
    GTest::gmock_main
  )
endif()

if(("${TEST_TARGET}" STREQUAL "add4") OR("${TEST_TARGET}" STREQUAL "unit"))
  add_executable(
    add4_test
    targets/test_add4.cc
    ../source/add4.c
    ./mocks/addMock.cc
  )
  target_include_directories(add4_test PRIVATE ../source)
  target_include_directories(add4_test PRIVATE ./mocks)
  target_link_libraries(
    add4_test
    GTest::gmock_main
  )
endif()

include(GoogleTest)

if(("${TEST_TARGET}" STREQUAL "add") OR("${TEST_TARGET}" STREQUAL "unit"))
  gtest_discover_tests(add_test)
endif()

if(("${TEST_TARGET}" STREQUAL "add2") OR("${TEST_TARGET}" STREQUAL "unit"))
  gtest_discover_tests(add2_test)
endif()

if(("${TEST_TARGET}" STREQUAL "add3") OR("${TEST_TARGET}" STREQUAL "unit"))
  gtest_discover_tests(add3_test)
endif()

if(("${TEST_TARGET}" STREQUAL "add4") OR("${TEST_TARGET}" STREQUAL "unit"))
  gtest_discover_tests(add4_test)
endif()
