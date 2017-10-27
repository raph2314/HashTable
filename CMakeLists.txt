cmake_minimum_required(VERSION 3.8)
project(HashTable)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp hash.cpp hash.h)
add_executable(HashTable ${SOURCE_FILES})