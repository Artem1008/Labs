cmake_minimum_required(VERSION 4.0)
project(Crc)
add_library(${PROJECT_NAME} src/crc.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC include)