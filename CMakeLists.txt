cmake_minimum_required(VERSION 3.14)
project(ImageGenerator)

set(CMAKE_CXX_STANDARD 14)

add_executable(ImageGenerator main.cpp main.h Gen/generators.cpp Gen/generators.h Gen/FunctionGenerator.cpp Fun/Function.h Fun/FunctionParts.h Fun/BinaryFunction.cpp Fun/BinaryFunction.h Fun/UnaryFunction.cpp Fun/UnaryFunction.h Fun/ConstFunction.h Gen/FunctionGenerator.h ConfigParser.cpp ConfigParser.h)