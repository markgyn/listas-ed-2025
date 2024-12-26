cmake_minimum_required(VERSION 3.29)
project(exercicio_11 C)

set(CMAKE_C_STANDARD 11)

add_executable(exercicio_11 main.c
        funcionario.h
        funcionario.c)
