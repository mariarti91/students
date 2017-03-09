cmake_minimum_required(VERSION 3.5)

add_compile_options(-std=c++0x)

project(FORMATER)

set(SOURCE_LIB format.cpp)

add_library(format STATIC ${SOURCE_LIB})
