# 必须指定cmake版本
cmake_minimum_required(VERSION 3.23)

# 设置工程名字，及相关属性
project(Demo LANGUAGES CXX)

# ********** 编译设置 **********
# 选择默认构建的项目类型为Debug
# 第一个语法：set()
# 1. 用于声明变量，可初始化
# 2. 用于给内置变量赋值
# 3. 用于设置环境，或给环境变量赋值
set(CMAKE_BUILD_TYPE Debug CACHE STRING "Set Build Type")

# 设置生成项目的路径
set(CMAKE_CACHEFILE_DIR ${PROJECT_SOURCE_DIR}/out)

# 设置最终生成程序的安装路径
# TODO：如何为单个项目设置安装路径？
set(CMAKE_INSTALL_PREFIX ${PROJECT_BINARY_DIR}/src/test/${CMAKE_BUILD_TYPE})


# ********** vs顶层项目目录下的项目设置 **********
# 需要在vs中使用文件夹进行管理，则必须开启USE_FOLDER
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
# 给cmake生成工程默认文件夹命名（技巧：命令A开头，方便管理）
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "ALL")

# ********** 添加其他工程的目录 **********
# 关注点1：从add_subdirectory()中能获取什么信息（target的name）
# 关注点2：这些信息彼此的顺序如何(前面对后面可见，后面对前面不可见)
add_subdirectory(src/ext)
add_subdirectory(src/test)
 

# ********** 设置模块 **********
# include()命令查找路径下的cmake文件，并执行其中的操作
# 模块包含在add_subdirectory()前，则对xxx可见，xxx内的cmake文件可以调用模块；反之，不可见，调用时会报错
# 建议读者自己编辑验证自己的想法
include(cmake/powershell.cmake)
include(cmake/python.cmake)
powershell_thing("system_tool_powershell")
python_thing()
