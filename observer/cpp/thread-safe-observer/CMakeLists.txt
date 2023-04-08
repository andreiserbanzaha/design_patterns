cmake_minimum_required(VERSION 3.13.4)

project(thread-safe-observer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB P_FILES *.h *.cpp)

add_executable(${PROJECT_NAME} ${P_FILES})

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
