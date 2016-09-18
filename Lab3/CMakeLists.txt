cmake_minimum_required(VERSION 3.6)
project(Lab3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp PersonReg.cpp PersonReg.h Person.cpp Person.h)
add_executable(Lab3 ${SOURCE_FILES})