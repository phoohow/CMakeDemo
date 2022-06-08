cmake_minimum_required(VERSION 3.20)

project(pSub)

set(headers 
    include/mysub.h)
    
# 该命令为生成目标链接静态库
link_libraries(myadd)
link_directories(../add/)

include_directories(include)

add_library(mysub 
    mysub.cpp
    ${headers})
    
target_include_directories(mysub PUBLIC include)

# 注意项目依赖关系
# add_subdirectory(../mul)
# target_link_libraries(mymul)
# target_link_directories(../mul)
