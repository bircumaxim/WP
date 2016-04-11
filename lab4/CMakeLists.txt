cmake_minimum_required(VERSION 3.4)
project(lab3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

INCLUDE_DIRECTORIES("C:/Program Files (x86)/CodeBlocks/MinGW/include")
link_directories("C:/Program Files (x86)/CodeBlocks/MinGW/lib")

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
        Win/Win.Widgets/SystemMenu/src/SystemMenu.cpp
        Win/Win.Widgets/SystemMenu/src/Menu.cpp
        Win/Win.Widgets/SystemMenu/include/Menu.h
        Win/Win.Widgets/SystemMenu/src/PopupMenu.cpp
        Win/Win.Widgets/SystemMenu/include/PopupMenu.h
        Win/Win.Paint/Tools/Pen/src/Pen.cpp
        Win/Win.Paint/Tools/Pen/include/Pen.h
        Win/Win.Paint/Shapes/FreeformLine/src/FreeformLine.cpp
        Win/Win.Paint/Shapes/FreeformLine/include/FreeformLine.h
        Win/Win.Paint/Shapes/StraightLine/src/StraightLine.cpp
        Win/Win.Paint/Shapes/StraightLine/include/StraightLine.h
        Win/Win.Paint/Shapes/Tetragon/src/Tetragon.cpp
        Win/Win.Paint/Shapes/Tetragon/include/Tetragon.h
        Win/Win.Paint/Shapes/Ellipse/src/EllipseShape.cpp
        Win/Win.Paint/Shapes/Ellipse/include/EllipseShape.h
        Win/Win.Paint/Advanced/src/Bezier.cpp
        Win/Win.Paint/Advanced/include/Bezier.h
        Win/Win.Paint/Tools/Eraser/src/Eraser.cpp
        Win/Win.Paint/Tools/Eraser/include/Eraser.h
        Win/Win.Core/src/ShortKey.cpp
        Win/Win.Core/include/ShortKey.h
        resource.h Resource.rc main.h Win/Win.Widgets/ScrollBar/src/ScrollBar.cpp Win/Win.Widgets/ScrollBar/include/ScrollBar.h Win/Win.Widgets/Label/src'/TextLabel.cpp Win/Win.Widgets/Label/include/TextLabel.h Win/Win.Widgets/TextBox/src/TextBox.cpp Win/Win.Widgets/TextBox/include/TextBox.h)
add_executable(lab3 ${SOURCE_FILES})

TARGET_LINK_LIBRARIES(lab3 comctl32)