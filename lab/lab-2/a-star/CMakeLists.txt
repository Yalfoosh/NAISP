cmake_minimum_required(VERSION 3.17)
project(a_star)

set(CMAKE_CXX_STANDARD 14)

add_executable(a_star main.cpp src/node.h src/a-star.h src/typedefs.h src/constants.h)