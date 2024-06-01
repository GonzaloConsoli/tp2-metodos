cmake_minimum_required(VERSION 2.8.12)
project(tp2)

set (CMAKE_CXX_STANDARD 11)
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

set(PYTHON_EXECUTABLE "/bin/python")
set(PYTHON_LIBRARY "/lib/libpytho.so")

include_directories(eigen)

add_subdirectory(pybind11)

pybind11_add_module(metnum
                    src/metnum.cpp
                    src/pca.cpp
                    src/eigen.cpp)


set(CMAKE_INSTALL_PREFIX
        ${PROJECT_SOURCE_DIR}
        CACHE PATH "Python custom modules directory" FORCE)

message(CMAKE_INSTALL_PREFIX = "${CMAKE_INSTALL_PREFIX}")

install(TARGETS metnum DESTINATION ${CMAKE_INSTALL_PREFIX}/notebooks)

add_executable(tp2
        src/main.cpp
        src/pca.cpp
        src/eigen.cpp)
