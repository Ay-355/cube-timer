cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 17)

project(cube-timer)

add_executable(cube-timer
    src/main.cpp
)




find_package(SDL2 CONFIG REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

target_link_libraries(cube-timer ${SDL2_LIBRARIES})

