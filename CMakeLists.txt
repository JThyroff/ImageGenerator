cmake_minimum_required(VERSION 3.14)
project(ImageGenerator)

set(CMAKE_CXX_STANDARD 14)

add_executable(ImageGenerator main.cpp main.h generators.cpp generators.h)