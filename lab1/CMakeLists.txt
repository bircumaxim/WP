cmake_minimum_required(VERSION 3.3)
project(lab1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "C:/WindowPrograming/WP/lab1/binaries")
set(SOURCE_FILES main.cpp MainWindow.cpp MainWindow.h  config.h Button.cpp Button.h WindowObject.cpp WindowObject.h Dimensions.cpp Dimensions.h TextLabel.cpp TextLabel.h TextBox.cpp TextBox.h)
add_executable(lab1 ${SOURCE_FILES})