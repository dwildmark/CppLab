cmake_minimum_required(VERSION 3.6)
project(Lab6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp OperationsInterface.h Add.cpp Add.h Operator.cpp Operator.h Subtract.cpp Subtract.h Multiply.cpp Multiply.h SortAlgInterface.h BubbleSort.cpp BubbleSort.h StdSort.cpp StdSort.h)
add_executable(Lab6 ${SOURCE_FILES})