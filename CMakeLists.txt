cmake_minimum_required(VERSION 2.8.12)
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

add_subdirectory(pybind11)

pybind11_add_module(Solver
        src/Solver.cpp
        src/CholeskySolver.cpp)

set(CMAKE_INSTALL_PREFIX
        ${PROJECT_SOURCE_DIR}
        CACHE PATH "Python custom modules directory" FORCE)

install(TARGETS Solver DESTINATION ${CMAKE_INSTALL_PREFIX}/notebooks)

add_executable(ColleyMatrix main.cpp src/types.h src/CholeskySolver.cpp src/CholeskySolver.h src/TriangularSolver.h)