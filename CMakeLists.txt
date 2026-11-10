cmake_minimum_required(VERSION 3.14)
project(8lab)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(prog_int 8.1int.cpp)
add_executable(prog_str 8.1str.cpp)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory(googletest)

enable_testing()
include(GoogleTest)

add_executable(test_8_1int test_8_1int.cpp)
target_link_libraries(test_8_1int GTest::gtest_main)
gtest_discover_tests(test_8_1int)

add_executable(test_8_1str test_8_1str.cpp)
target_link_libraries(test_8_1str GTest::gtest_main)
gtest_discover_tests(test_8_1str)