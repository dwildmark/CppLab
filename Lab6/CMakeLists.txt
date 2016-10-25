cmake_minimum_required(VERSION 3.6)
project(Lab6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp OperationsInterface.cpp OperationsInterface.h OperationAdd.cpp OperationAdd.h)
add_executable(Lab6 ${SOURCE_FILES})