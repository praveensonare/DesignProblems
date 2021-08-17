cmake_minimum_required(VERSION 3.15.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

#project
set(PROJECT DaVinci)
project(${PROJECT})

add_executable(${PROJECT}
    ./src/main.cpp
    ./src/Order.cpp
    ./src/OrderBase.cpp
    ./src/OrderBuy.cpp
    ./src/OrderSell.cpp
    ./src/Parser.cpp
    ./src/Utility.cpp
    ./src/OrderManager.cpp
    )


target_include_directories(${PROJECT} PRIVATE ./include)

