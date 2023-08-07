cmake_minimum_required(VERSION 3.16.3)
project(lista VERSION 1.0.0)

include_directories(src)

add_subdirectory(src)
add_subdirectory(tst)
add_subdirectory(lib/googletest)