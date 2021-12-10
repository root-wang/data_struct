cmake_minimum_required(VERSION 3.20)
project(learning)

set(CMAKE_CXX_STANDARD 14)

add_executable(demo Struct/matrix/matrix.cpp
        Struct/matrix/matrix.h
        Struct/matrix/use_matrix.cpp)