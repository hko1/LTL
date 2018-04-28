cmake_minimum_required(VERSION 2.6)
project(ltl)

# include custom find files
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/CMakeModules)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(ltl main.cpp)
target_link_libraries(ltl ${SDL2_LIBRARIES})
