cmake_minimum_required(VERSION 3.22)

project(cmake-practice)

set(CMAKE_EXPORT_COMPILE_COMMANDS   ON)
set(CMAKE_CXX_STANDARD              11)
set(CMAKE_CXX_STANDARD_REQUIRED     ON)
set(CMAKE_CXX_EXTENSIONS            OFF)


add_executable(cmake-practice src/main.cpp)