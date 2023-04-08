cmake_minimum_required(VERSION 3.11.4)

project(prototype_factory)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB P_SRC *.cpp)

add_executable(${PROJECT_NAME} ${P_SRC})
