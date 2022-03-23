cmake_minimum_required(VERSION 3.21)
project(Colectie)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Teste)

add_executable(Colectie
        Teste/TestExtins.cpp
        Teste/TestExtins.h
        Teste/TestScurt.cpp
        Teste/TestScurt.h
        App.cpp
        Colectie.cpp
        Colectie.h
        IteratorColectie.cpp
        IteratorColectie.h)
