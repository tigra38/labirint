cmake_minimum_required(VERSION 3.14)

project(labirint)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(labirint
  main.cpp
  labirint.h
  labirint.cpp
)
