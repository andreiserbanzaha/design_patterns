cmake_minimum_required(VERSION 3.13.4)

project(variant-std-visit)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB P_SRC *.cpp)

add_executable(${PROJECT_NAME} ${P_SRC})

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
