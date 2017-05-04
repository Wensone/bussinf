cmake_minimum_required(VERSION 3.5.1)
project(BaseData)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES src/main.cpp src/Reader.cpp src/Cartoteka.cpp src/DataIO.cpp src/DataBase.cpp src/BDcommunity.cpp)
set(HEADERS headers/Cartoteka.h headers/DataBase.h headers/DataIO.h headers/Reader.h src/DataIO.cpp src/DataBase.cpp headers/BDcommunity.h src/BDcommunity.cpp)
add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADERS})