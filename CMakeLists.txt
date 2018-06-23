cmake_minimum_required(VERSION 3.9)
project(untitled01 C)

set(CMAKE_C_STANDARD 99)

add_executable(untitled01 source/main.c source/point.h source/point.c source/graph.h source/graph.c source/ppmWriter.c source/ppmWriter.h source/mandelbrot.h source/mandelbrot.c)