cmake_minimum_required(VERSION 3.22)

project(cmake-practice)

set(CMAKE_EXPORT_COMPILE_COMMANDS   ON)
set(CMAKE_CXX_STANDARD              20)
set(CMAKE_CXX_STANDARD_REQUIRED     ON)
set(CMAKE_CXX_EXTENSIONS            OFF)

option(INCLUDE_USER_HEADER "Include predefined header uses for this project" ON)


#adding cpm
include(cmake/CPM.cmake)

CPMAddPackage("gh:glfw/glfw#3.3.8")

include_directories(include)

#glad directory
add_library(glad include/glad.h src/glad.c)
target_include_directories(glad PUBLIC include)

#compile executable
add_executable(cmake-practice src/main.cpp)

#link dependencies
target_link_libraries(cmake-practice glfw glad)