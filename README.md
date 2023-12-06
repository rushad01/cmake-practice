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

## Warning

Compiler warnings are messages produced by a compiler regarding program code fragments to be considered by the developer, as they may contain errors. Unlike compilation errors, warnings don’t interrupt the compilation process. A warning could result because of the use of obsolete features; or the use of nonstandard features of C++.

- GCC and Clang Options(Most Common ones)

```
-Wall -Wextra -Wpedantic
```

- MSVC

```
/W4
/permissive
```

There a lot of warning that can be found in [GNU Warning options](https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html) and [MSVC](https://github.com/MicrosoftDocs/visualstudio-docs/tree/main/docs/code-quality) pages.

## Sanitizer

Sanitizers that find memory bugs in programs written in memory-unsafe languages. Memory-checking tools are for memory-unsafe languages such as C and C++, not for Java, Python, and similar memory-safe languages. In memory-unsafe languages, it is easy to mistakenly write past the end of a memory buffer or read memory after it has been freed. Programs containing such bugs might run flawlessly most of the time and crash only very rarely. Catching these bugs is difficult, which is why we need tools for that purpose.

- GCC and Clang Option

```
-fsanitize=address -fsanitize=undefined -fno-sanitize-recover=all -fsanitize=float-divide-by-zero -fsanitize=float-cast-overflow -fno-sanitize=null -fno-sanitize=alignment
```

## Dependency Management

There are multiple ways to manage dependency in C/C++ as their standard doesn't define standard for managing dependancy.

- Using github submodule to fetch a repo directly from github and include it into current repo
- Using package manager like [conan](https://conan.io/),[xmake-xrepo](https://xrepo.xmake.io/#/),[vcpkg](https://vcpkg.io/en/),[cpm.cmake package manager](https://github.com/cpm-cmake/CPM.cmake)

In this template I will use [cpm](https://github.com/cpm-cmake/CPM.cmake) as a package manager.

Do not use multiple dependency manager for one project. As this will lead to more problem in run.

## Adding CPM

From [cpm](https://github.com/cpm-cmake/CPM.cmake) repo download cpm.cmake and add it to project directory. Then specify the directory using `include()` function. For more detail read [cpm](https://github.com/cpm-cmake/CPM.cmake) repository.

## Issue

For vscode `clangd` LSP(Language Server Protocol) from `LLVM` directory doesn't bootup and original issue for this has no solution currently. But `clangd` plugin from `Visual Studio Code Marketplace` works perfectly. This issue is only for Windows. I didn't check Linux.
