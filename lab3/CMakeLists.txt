cmake_minimum_required(VERSION 3.4)
project(lab3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp
        Win/settups.h
        Win/Win.Widgets/MainWindow/include/MainWindow.h
        Win/Win.Widgets/MainWindow/src/MainWindow.cpp
        Win/Win.Core/include/Dimensions.h
        Win/Win.Core/src/Dimensions.cpp
        Win/Win.Core/include/WindowObject.h
        Win/Win.Core/src/WindowObject.cpp
        Win/Win.Core/include/Config.h
        Win/Win.Core/src/Config.cpp
        Win/Win.Widgets/SystemMenu/include/SystemMenu.h
        Win/Win.Widgets/SystemMenu/src/SystemMenu.cpp Win/Win.Widgets/SystemMenu/src/Menu.cpp Win/Win.Widgets/SystemMenu/include/Menu.h Win/Win.Widgets/SystemMenu/src/PopupMenu.cpp Win/Win.Widgets/SystemMenu/include/PopupMenu.h Win/Win.Paint/Core/src/Pen.cpp Win/Win.Paint/Core/include/Pen.h Win/Win.Paint/Shapes/FreeformLine/src/FreeformLine.cpp Win/Win.Paint/Shapes/FreeformLine/include/FreeformLine.h Win/Win.Paint/Shapes/StraightLine/src/StraitLine.cpp Win/Win.Paint/Shapes/StraightLine/include/StraitLine.h Win/Win.Paint/Shapes/Tetragon/src/Tetragon.cpp Win/Win.Paint/Shapes/Tetragon/include/Tetragon.h Win/Win.Paint/Shapes/Ellipse/src/EllipseShape.cpp Win/Win.Paint/Shapes/Ellipse/include/EllipseShape.h Win/Win.Paint/Advanced/src/Bezier.cpp Win/Win.Paint/Advanced/include/Bezier.h)
add_executable(lab3 ${SOURCE_FILES})