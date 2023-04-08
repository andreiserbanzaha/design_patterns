cmake_minimum_required(VERSION 3.13.4)

project(bank-account-command)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB P_SRC composite-command.cpp)

add_executable(${PROJECT_NAME} ${P_SRC})

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
