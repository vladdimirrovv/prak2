cmake_minimum_required(VERSION 3.10)
project(prak2 C)

set(CMAKE_C_STANDARD 99)

include_directories(include)

add_executable(prak2
    src/main.c
    src/users.c
    src/processes.c
    src/log.c
    src/errors.c
    src/help.c
)