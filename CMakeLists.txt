cmake_minimum_required(VERSION 3.17)
project(ColleyMatrix)

set(CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

IF(CMAKE_BUILD_TYPE MATCHES Debug)
    message("Debug mode")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g3 -O0")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror")
ENDIF()

IF(CMAKE_BUILD_TYPE MATCHES Release)
    message("Release mode")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
ENDIF()

include_directories(eigen)

add_executable(ColleyMatrix main.cpp src/types.h src/CholeskySolver.cpp src/CholeskySolver.h src/TriangularSolver.h)