cmake_minimum_required(VERSION 3.17)
project(a_star_faster)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-O3")

add_executable(a_star_faster main.cpp)