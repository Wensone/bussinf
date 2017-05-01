cmake_minimum_required(VERSION 3.5.1)
project(BaseData)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES src/main.cpp src/ headers/Commands.h src/main.cpp headers/BD.h headers/DataIO.h src/Reader.cpp headers/Reader.h src/Cartoteka.cpp headers/Cartoteka.h)
add_executable(CostOfStep ${SOURCE_FILES})