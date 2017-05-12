cmake_minimum_required(VERSION 3.5)
project(Base)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES src/Auto.cpp src/BDcommunity.cpp src/DataIO.cpp src/main.cpp
        src/Shopper.cpp headers/Auto.h headers/BDcommunity.h headers/DataBase.h
        headers/DataIO.h headers/Shopper.h)
add_executable(Base ${SOURCE_FILES})