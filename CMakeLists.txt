cmake_minimum_required(VERSION 3.7)
project(OOP244_Mileston4)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Date.cpp
        Date.h
        ErrorMessage.cpp
        ErrorMessage.h
        general.h
        ms4_tester.cpp
        MyFile.cpp
        MyFile.h
        Product.cpp
        Product.h
        Streamable.h)

add_executable(OOP244_Mileston4 ${SOURCE_FILES})