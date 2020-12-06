cmake_minimum_required(VERSION 3.17)
project(dp)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-O3")

add_executable(dp main.cpp src/node.h src/dp.h)