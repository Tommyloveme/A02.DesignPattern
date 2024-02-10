SET(CMAKE_C_COMPILER gcc)
SET(CMAKE_CXX_COMPILER g++)
SET(CMAKE_CXX_STANDARD 17)

cmake_minimum_required(VERSION 3.15)
project(GTest)

add_subdirectory(src)
add_subdirectory(test)