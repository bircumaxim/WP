cmake_minimum_required(VERSION 3.3)
project(lab2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp MainWindow.cpp MainWindow.h WindowObject.cpp WindowObject.h Dimensions.cpp Dimensions.h config.h Button.cpp Button.h  temp.cpp TextBox.cpp TextBox.h TextLabel.cpp TextLabel.h ScrollBar.cpp ScrollBar.h Resource.h Resource.rc ListBox.cpp ListBox.h)
add_executable(lab2 ${SOURCE_FILES})