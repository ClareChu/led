# cmake_minimum_required(VERSION <specify CMake version here>)
project(demo C)

set(CMAKE_C_STANDARD 11)

add_executable(demo
        led.c led1.c segment/led8.c util/delay.h util/delay.c key/key1.c time/time.c calculator/calculator.c)
