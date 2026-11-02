cmake_minimum_required(VERSION 3.20)
project(lox LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)  

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

file(GLOB_RECURSE LOX_SOURCES CONFIGURE_DEPENDS src/*.cpp)

add_executable(lox ${LOX_SOURCES})
target_include_directories(lox PRIVATE src)
target_compile_options(lox PRIVATE -Wall -Wextra -Wpedantic)

option(LOX_SANITIZE "Enable ASan and UBSan" OFF)
if(LOX_SANITIZE)
  target_compile_options(lox PRIVATE -fsanitize=address,undefined -fno-omit-frame-pointer)
  target_link_options(lox PRIVATE -fsanitize=address,undefined)
endif()