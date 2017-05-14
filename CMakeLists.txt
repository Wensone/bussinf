cmake_minimum_required(VERSION 3.5)
project(Base)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES src/sick.cpp src/BDcommunity.cpp src/DataIO.cpp src/main.cpp
        src/medic.cpp headers/sick.h headers/BDcommunity.h headers/DataBase.h
        headers/DataIO.h headers/medic.h)
add_executable(Base ${SOURCE_FILES})