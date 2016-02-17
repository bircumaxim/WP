cmake_minimum_required(VERSION 3.3)
project(lab1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Window.cpp Window.h Button.cpp Button.h config.h)
add_executable(lab1 ${SOURCE_FILES})