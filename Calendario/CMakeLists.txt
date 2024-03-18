cmake_minimum_required(VERSION 3.26)
project(Calendario)

set(CMAKE_CXX_STANDARD 17)

add_executable(Calendario main.cpp
        Imprimir_calendario.h
        Imprimir_calendario_tools.h)
