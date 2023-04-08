cmake_minimum_required(VERSION 3.11.4)

project(abstract_factory)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB P_INC ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
file(GLOB P_SRC ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_executable(${PROJECT_NAME} ${P_INC} ${P_SRC})

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
