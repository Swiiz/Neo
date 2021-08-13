## DOESN'T WORK: ONLY HERE FOR IDE TO UNDERSTAND INCLUDE DIRS

cmake_minimum_required(VERSION 3.20)
project(Neo C)

set(CMAKE_C_STANDARD 11)

include_directories(src/intf)

add_executable(Neo
        src/impl/kernel/main.c
        src/intf/print.h src/impl/kernel/io/print.c src/impl/kernel/io/print.h)
