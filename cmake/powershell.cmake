# 模块展示如何调用系统自带的powershell命令工具
# 本处可看到：
# 1.函数如何定义
# 2.execute_process()命令的使用
function(powershell_thing param)
    message("\n>>> i am processing powersehll thing")
    set(output_string ${param})
    execute_process(
        COMMAND powershell echo "${output_string}"
    )
endfunction()