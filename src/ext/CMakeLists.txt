cmake_minimum_required(VERSION 3.20)

project(external)

add_subdirectory(add)
add_subdirectory(sub)
add_subdirectory(mul)
add_subdirectory(div)

# ********** 用于vs中的显示 **********
# 将四个库置于ext文件夹中
set_property (TARGET myadd PROPERTY FOLDER "ext")
set_property (TARGET mysub PROPERTY FOLDER "ext")
set_property (TARGET mymul PROPERTY FOLDER "ext")
set_property (TARGET mydiv PROPERTY FOLDER "ext")