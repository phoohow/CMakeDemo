cmake_minimum_required(VERSION 3.20)

project(pMul)

set(headers_files 
    include/mymul.h)

set(sources_files
    mymul.cpp)

include_directories(include)

add_library(mymul SHARED
    ${sources_files}
    ${headers_files})
add_library(demo::mymul ALIAS mymul)

target_include_directories(mymul PUBLIC include)
