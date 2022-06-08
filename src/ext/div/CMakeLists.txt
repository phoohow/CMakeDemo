cmake_minimum_required(VERSION 3.20)

project(pDiv)

set(headers_files 
    include/mydiv.h)

set(sources_files
    mydiv.cpp)

include_directories(include)

add_library(mydiv SHARED
    ${sources_files}
    ${headers_files})
add_library(demo::mydiv ALIAS mydiv)

target_include_directories(mydiv PUBLIC include)
