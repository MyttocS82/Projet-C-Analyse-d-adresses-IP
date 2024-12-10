cmake_minimum_required(VERSION 3.27)
project(Code C)

set(CMAKE_C_STANDARD 11)

add_executable(Code
        cartouche.c
        main.c
        Fonctions.h
        Fonctions.c
        )
