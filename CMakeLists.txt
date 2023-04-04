cmake_minimum_required(VERSION 3.21)
project(Proiect_SDA_final)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Proiect_SDA_final
        eveniment.cpp
        eveniment.h
        list.h
        main.cpp
        mesaj.cpp
        mesaj.h
        multiDictionar.h
        node.h
        retea.cpp
        retea.h
        tests.cpp
        tests.h
        ui.cpp
        ui.h
        Utilizator.cpp
        Utilizator.h)
