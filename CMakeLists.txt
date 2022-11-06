cmake_minimum_required(VERSION 3.23)
project(untitled1)

set(CMAKE_CXX_STANDARD 14)

include_directories(Naglowki)

add_executable(untitled1
        Naglowki/Interface.h
        Naglowki/Knight.h
        Naglowki/Warnsdorff.h
        Interface.cpp
        Knight.cpp
        main.cpp
        Warnsdorff.cpp)
