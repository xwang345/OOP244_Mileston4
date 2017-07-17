cmake_minimum_required(VERSION 3.7)
project(MS4)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        ms4_tester.cpp
        Product.cpp
        Product.h
        Streamable.h
        general.h
        MyFile.h
        MyFile.cpp
        ErrorMessage.h
        ErrorMessage.cpp
        Date.cpp
        Date.h)

add_executable(MS4 ${SOURCE_FILES})