cmake_minimum_required(VERSION 3.20)

set(CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)

set(EXEC_NAME ${CMAKE_CURRENT_SOURCE_DIR})

project(${EXEC_NAME} CXX)


add_executable(${EXEC_NAME} main.cpp)
