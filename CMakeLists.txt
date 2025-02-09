cmake_minimum_required(VERSION 3.30)
project(Peiman_Timaji_IN2029_Coursework)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Peiman_Timaji_IN2029_Coursework
    FileManager.cpp
    FileManager.h
    main.cpp
        Person.cpp
    Person.h
    StatementPrinter.cpp
    StatementPrinter.h)
