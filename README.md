## Introduction

CMake is a build system for projects build with C or C++ programmig language. There are many build system for C/C++ but CMake is the most popular one. This repo will contain my practice for building project using C/C++. I will mainly use C++ as a programming language for this repo but almost everything is applicable for C language too.

## How to build this project

Make sure your system has cmake installed.
To check whether your system has cmake installed properly you can the command below

```
cmake --version
```

Then make a build directory for building the project and compiling it using the below command

```
mkdir build
cd build
cmake ..
```

## Enabling Options

CMake allow certain feature of project depending on the option passed during build process. This can be activated using the below approach.

```
cmake -DOPTION_NAME=ON ..
```

The project will be built using the given feature enabled. Options needed to be explicitly declared in CMakeLists file for building.

## Selecting Generator

We can use microsoft or gcc for generating a project from command line using cmake.

```
cmake -G"Visual Studio 16 2019" //Microsoft Toolchain
cmake -G "Unix Makefiles" . //Unix Makefile
```
