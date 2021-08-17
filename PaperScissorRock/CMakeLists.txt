cmake_minimum_required(VERSION 3.15.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

#project
set(PROJECT PaperScissorRock)
project(${PROJECT})

add_executable(${PROJECT}
    ./source/ComputerPlayer.cpp	
    ./source/Game.cpp
    ./source/Paper.cpp
    ./source/Rock.cpp
    ./source/Display.cpp
    ./source/Main.cpp
    ./source/Player.cpp		
    ./source/Scissor.cpp
    )


target_include_directories(${PROJECT} PRIVATE ./include)

