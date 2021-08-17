cmake_minimum_required(VERSION 3.15.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

#project
set(PROJECT Drawing)
project(${PROJECT})

add_executable(${PROJECT}
    ./source/main.cpp
    ./source/Canvas.cpp
    ./source/DisplayCanvas.cpp
    ./source/MyUtils.cpp
    ./source/DrawingController.cpp
    ./source/CommandFactory.cpp
    ./source/CommandQuit.cpp
    ./source/CommandCreateCanvas.cpp
    ./source/CommandCreateLine.cpp
    ./source/CommandCreateRectangle.cpp
    ./source/CommandFill.cpp
    ./source/CommandParser.cpp
    ./source/CanvasManager.cpp
    )


target_include_directories(${PROJECT} PRIVATE ./include)

