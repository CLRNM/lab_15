cmake_minimum_required(VERSION 3.28)
project(lab_15 C)

set(CMAKE_C_STANDARD 11)

add_executable(lab_15 main.c
        data_structures/matrix/matrix.c
        data_structures/matrix/matrix.h)
