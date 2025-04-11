cmake_minimum_required(VERSION 3.23)
project(MEP LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED OFF)
set(CMAKE_VERBOSE_MAKEFILE ON)

add_compile_options(/Zc:__cplusplus)

set(CMAKE_INSTALL_PREFIX "${PROJECT_BINARY_DIR}" CACHE PATH "..." FORCE)

add_library(xrt SHARED xrt.cpp)
install(TARGETS xrt)
