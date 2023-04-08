cmake_minimum_required(VERSION 3.13.4)

project(chat-room)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB P_INC inc/*.h)
file(GLOB P_SRC src/*.cpp)

add_executable(${PROJECT_NAME} ${P_INC} ${P_SRC})

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
