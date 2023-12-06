cmake_minimum_required(VERSION 3.22)

project(cmake-practice)

set(CMAKE_EXPORT_COMPILE_COMMANDS   ON)
set(CMAKE_CXX_STANDARD              20)
set(CMAKE_CXX_STANDARD_REQUIRED     ON)
set(CMAKE_CXX_EXTENSIONS            OFF)

option(INCLUDE_USER_HEADER "Include predefined header uses for this project" ON)
option(ENABLE_WARNINGS "Enable compiler warnings for a target" ON)

option(ENABLE_SANITIZE_ADDR "Enable address sanitizer" ON)
option(ENABLE_SANITIZE_UNDEF "Enable undefined sanitizer" ON)

#adding cpm
include(cmake/CPM.cmake)

#adding warning to compiler
if(ENABLE_WARNINGS)
  include(cmake/Warnings.cmake)
endif()

#adding satizier for a target
if(ENABLE_SANITIZE_ADDR OR ENABLE_SANITIZE_UNDEF)
    include(cmake/Sanitizer.cmake)
    add_sanitizer_flags()
endif()

#With test and everything
#CPMAddPackage("gh:glfw/glfw#3.3.8")

#without test and examples
CPMAddPackage(
        NAME GLFW
        GITHUB_REPOSITORY glfw/glfw
        GIT_TAG 3.3.8
        OPTIONS
          "GLFW_BUILD_TESTS OFF"
          "GLFW_BUILD_EXAMPLES OFF"
          "GLFW_BULID_DOCS OFF"
)

include_directories(include)

#glad directory
add_library(glad include/glad.h src/glad.c)
target_include_directories(glad PUBLIC include)

#compile executable
add_executable(cmake-practice src/main.cpp)

#link dependencies
target_link_libraries(cmake-practice glfw glad)