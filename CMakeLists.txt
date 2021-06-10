cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 17)

project(cube-timer)

add_executable(cube-timer
		src/main.cpp
)

 # put a SDL2Config.cmake file in the directory of your sdl2 and do ``list(APPEND CMAKE_PREFIX_PATH "path to sdl2")``
 # cause I had given up trying to do this cmake thing with sdl2


 # snippet to not make it put in PATH
IF(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  SET(CMAKE_INSTALL_PREFIX <path> CACHE PATH <comment> FORCE)
ENDIF(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)


find_package(SDL2 CONFIG REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

target_link_libraries(cube-timer ${SDL2_LIBRARIES})

