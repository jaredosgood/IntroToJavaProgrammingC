cmake_minimum_required(VERSION 4.3)
project(IntroToJavaProgrammingC C)

set(CMAKE_C_STANDARD 23)

add_library(IntroToJavaProgrammingC STATIC library.c
        chapter03/problem3_28/problem3_28.h
        chapter03/problem3_28/problem3_28.c
        chapter03/problem3_28/main.c
        chapter03/problem3_28/problem3_28_test.c
        chapter03/problem3_29/problem3_29.c
        chapter03/problem3_29/problem3_29.h
        chapter03/problem3_29/main.c
        chapter03/problem3_29/problem3_29_test.c)
