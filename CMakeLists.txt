cmake_minimum_required(VERSION 3.6)
project(string)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES stringList.c stringList.h priorityQueue.c maptree.c priorityQueue.h hash_table.c hash_table.h frequencyCounter.c frequencyCounter.h main.c header.h maptree.h extractData.c extractData.h bitVector.c bitVector.h)
add_executable(string ${SOURCE_FILES})