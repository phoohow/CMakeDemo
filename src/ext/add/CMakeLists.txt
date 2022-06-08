cmake_minimum_required(VERSION 3.20)

project(pAdd)

set(headers_files 
    include/myadd.h)

set(sources_files
    myadd.cpp
    myadd2.cpp)
    
set(mat
    res/1.mat
    res/2.mat)

# 该命令非常方便，包含了路径之后，在源文件中可以直接加#include<xxx.h>而不用加前面路径
# 不过，项目比较复杂之后，存在文件重名的情况，暂时未测这种情况下的结果。读者可自测
include_directories(include)

# 设置生成的静态库名及依赖文件
add_library(myadd 
    ${headers_files}
    ${sources_files}
    ${mat})

# 该命令将库的头文件路径暴露给调用者
# 搭配include_directories()使用非常省事
target_include_directories(myadd PUBLIC include)

# ********** 设置vs项目下文件的显示 **********
# 需要注意的是，只有包含在生成目标下的文件才会起作用
source_group(res res/*)
source_group(src ./*.cpp)
source_group(include include/*)