cmake_minimum_required(VERSION 3.15.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

#project
set(PROJECT Visitor)
project(${PROJECT})

add_executable(${PROJECT}
    ./source/main.cpp
    ./source/AreaVisitor.cpp	
    ./source/Circle.cpp	
    ./source/MyUtils.cpp
    ./source/Rectangle.cpp	
    ./source/Triangle.cpp
    )


target_include_directories(${PROJECT} PRIVATE ./include)


