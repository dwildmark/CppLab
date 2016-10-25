cmake_minimum_required(VERSION 3.6)
project(Lab6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp OperationsInterface.cpp OperationsInterface.h Add.cpp Add.h Operator.cpp Operator.h Subtract.cpp Subtract.h Multiply.cpp Multiply.h)
add_executable(Lab6 ${SOURCE_FILES})