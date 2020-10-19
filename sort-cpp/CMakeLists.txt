cmake_minimum_required(VERSION 3.17)
project(sort_cpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(sort_cpp src/main.cpp src/sorting/QuickSort.h src/sorting/SortUtil.h src/testing/Test.h src/testing/Stopwatch.cpp src/testing/Stopwatch.h)