cmake_minimum_required(VERSION 3.6)
project(Lab4Remake)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Person.cpp Person.h PersonReg.cpp PersonReg.h)
add_executable(Lab4Remake ${SOURCE_FILES})