cmake_minimum_required(VERSION 3.5)

add_compile_options(-std=c++0x)

project(task1)

set(SOURCE_BIN main.cpp)

include_directories(libs)

add_executable(task1.bin ${SOURCE_BIN})

add_subdirectory(libs)

target_link_libraries(task1.bin format)
