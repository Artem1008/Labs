cmake_minimum_required(VERSION 4.0)
project(Hash)
add_library(${PROJECT_NAME} src/hash.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC include)