cmake_minimum_required (VERSION 2.6)
project(maximum_subsequence)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_COMPILER "gcc-7")

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

add_subdirectory(src)
add_subdirectory(tests)

enable_testing()