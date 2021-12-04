cmake_minimum_required(VERSION 3.10)

project(data-structures VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_subdirectory(list)
add_subdirectory(heap)
add_subdirectory(tests)