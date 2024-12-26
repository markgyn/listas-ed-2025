cmake_minimum_required(VERSION 3.29)
project(exercicio_6 C)

set(CMAKE_C_STANDARD 11)

add_executable(exercicio_6 main.c
        rational.h
        rational.c)
