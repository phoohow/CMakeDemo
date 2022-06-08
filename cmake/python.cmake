# 模块展示如何调用python(需要提前安装，并添加到系统环境)
# 本处可看到：
# 1.函数如何定义
# 2.execute_process()命令的使用
function(python_thing)
    message("\n>>> i am processing python thing")
    execute_process(
        COMMAND python --version
    )
endfunction()
