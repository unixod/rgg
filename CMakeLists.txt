cmake_minimum_required(VERSION 3.16)
project(rgg VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(compile-options.cmake)
include(deps-config.cmake)
add_subdirectory(src)

