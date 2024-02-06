cmake_minimum_required(VERSION 3.25)
project(MyGpaManager)

set(CMAKE_CXX_STANDARD 17)

add_executable(MyGpaManager main.cpp Course.cpp Course.h Grade.cpp Grade.h
        LinkedList.cpp
        LinkedList.h)
