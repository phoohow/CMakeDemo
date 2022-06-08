cmake_minimum_required(VERSION 3.23.2)

# ******************************************************************
# *********************** 基本构建流程：开始 ************************
# ******************************************************************
project(Test LANGUAGES CXX)

set(material
    res/a.mat
    res/b.mat)

set(test_source 
    main.cpp
    print/myPrint.cpp
    print/myPrint2.cpp)

set(mylib_name 
    myadd
    mysub)

set(mydll_name
    mymul
    mydiv)

set(mylib_dir
    ../ext/myadd
    ../ext/mysub)

set(mydll_dir
    ../ext/mymul
    ../ext/mydiv
)

# ********** 指定头文件路径 **********
include_directories(include)
include_directories(print)

# ********** 指定一个target **********
link_libraries(${mylib_name})
link_directories(${mylib_dir})

add_executable(test ${test_source} ${material})

#target_compile_definitions(test PRIVATE USE_ALL)
target_link_libraries(test PRIVATE ${mydll_name})
target_include_directories(test PRIVATE 
    ${PROJECT_BINARY_DIR} ${mydll_dir})

# ********** 拷贝dll到项目执行文件夹中 **********
# ********** 错误示范1 **********
#file(COPY ../ext/mul/Debug/mymul.dll 
#          ../ext/div/Debug/mydiv.dll
#     DESTINATION ${PROJECT_BINARY_DIR}/Debug)

# ********** 错误示范2 **********
# execute_process(COMMAND COPY)

# 思考： Why？

# ********** 项目安装 **********

set(CMAKE_INSTALL_PREFIX ${PROJECT_BINARY_DIR}/${CMAKE_BUILD_TYPE})

set(install_targets
    # ***** exe *****
    test
    # ***** dll *****
    ${mydll_name}
    # ***** lib *****
    ${mylib_name})

install(TARGETS ${install_targets}
    RUNTIME DESTINATION .
    LIBRARY DESTINATION .
    ARCHIVE DESTINATION lib)

install(FILES ${material} 
    DESTINATION res)


# ******************************************************************
# ************************* vs中组织项目 ****************************
# ******************************************************************
# ********** vs顶层项目目录下的项目设置 **********
set_property(TARGET test PROPERTY FOLDER "Test")

# ********** 在单个vs项目中组织文件 **********
# ********** 文件在vs项目文件夹下显示 **********
# ***** 在源码中有添加到某个Target中的源文件 *****
#source_group(TREE ${CMAKE_SOURCE_DIR} 
#    FILES src/include/myPrint.h
#    FILES src/main.cpp src/print/myPrint.cpp src/print/myPrint2.cpp)

#source_group("Source Files/print" 
#    FILES src/print/myPrint.cpp
#    FILES src/print/myPrint2.cpp)

# cmake 对 source_group()的支持不是很好，需要进一步核实版本之间的依赖
# 在filament内部不知道做了什么操作，可以保证这里不产生冲突，需要核实
source_group(src main.cpp)
source_group(src/print print/*) 
# 注：使用source_group(src/print src/print/*.cpp)并不能得到正确结果
# 目前尚不清楚问题, 后续会进一步查证
source_group(res res/*)



# ******************************************************************
# ************************** 基本语法 ******************************
# ******************************************************************
# 核心：对字符串进行操作（但是也可以进行数学运算，使用math()方法）
# 一元操作符：EXIST, COMMAND, DEFINED
# 二元操作符：EQUAL，LESS，LESS_EQUAL，GREATER，MATCHES等等
# 逻辑操作符：NOT，AND，OR
# 优先级是 () > 一元操作符 > 二元操作符 > 逻辑操作符
# 设置变量：set(), list()
# 控制语句：if(), foreach(), while()----注：配套endXXX()使用
# 控制语句：continue(), break()
# 函数：function()----------------------注：配套endXXX()使用



# ******************************************************************
# ************************ 对字符串进行操作 *************************
# ******************************************************************
# 参考官方文档：https://cmake.org/cmake/help/latest/command/string.html
# 参考中文文档：https://runebook.dev/zh-CN/docs/cmake/command/string
# 其他有用教程：https://www.bookstack.cn/read/CMake-Cookbook/README.md
# string(FIND str1 str2 var_int)
# string(REPLACE str1 str2 var_str str_input)
# string(LENGTH str var_int)
# string(COMPARE EQUAL str1 str2 var_bool)
# ......



# ******************************************************************
# ************************ 对文件进行操作 ***************************
# ******************************************************************
#file(READ src/main.cpp main_cpp)
#file(STRINGS src/main.cpp main_cpp)
#file(MD5 ${CMAKE_SOURCE_DIR}/src/main.cpp hash_var)
#file(SHA1 ${CMAKE_SOURCE_DIR}/src/main.cpp hash_var)
#file(TIMESTAMP test.txt test_cont FORCE)
set(test_content 
"Hello CMake\n\
This is a Test\n\
Nothing else to do")
#file(WRITE test.txt ${test_content})
#file(TOUCH test.txt)
#file(TOUCH_NOCREATE test.txt)
#file(GLOB file_all src/*.cpp)
#file(GLOB_RECURSE file_all src/*.cpp)

# ********** 其他有用的操作有 **********
# list()：数据结构



# ******************************************************************
# ************************ 一些练习和补充 ***************************
# ******************************************************************
#[[
# 练习1：过滤当前文件夹下含myPrint关键字的文件
#]]
# TIP：file(),list(),string()组合使用
set(file_all)
file(GLOB_RECURSE file_all src/*.cpp)
foreach(i ${file_all})
    string(FIND ${i} myPrint temp_i)
    if(${temp_i}  EQUAL -1)
        continue()
    else()
        list(APPEND file_list ${i})
    endif()
endforeach()

#[[
# 练习2：将main.cpp，myPrint.h和myPrint.cpp文件中的myPrint()函数名
#        改为demoPrint()
#        注：出于练习考虑和通用性考虑，尽量不要使用绝对路径
#]]

#[[
# 练习3：改写8行-32行的设置变量方式，使得工程更加自动化，不用每次添加
#       文件都要修改CMakeLists.txt配置文件（参考练习1）
#]]

# ********** 还有哪些没有讲到的内容？ **********
# 语法（如宏：marco()---------------------------注：配套endXXX()使用）
# 内置变量（查官方手册）
# 跨平台---对编译器的设置（查具体编译器手册）
# CTest模块（欢迎分享）
# CPack模块（欢迎分享）
