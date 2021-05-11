# 生成的目标可执行文件TARGET = app
TARGET = smf
# 源代码路径
SRC = $(wildcard ./src/*.c)
# 目标文件路径
OBJ = $(patsubst %.c, %.o, $(SRC))
# 头文件包含
INCLUDE = ./include/
# 可选参数
CFLAGS = -Wall -O2
# 链接为可运行文件
$(TARGET):$(OBJ)
	gcc $^ -o $@
# 执行make clean清理目标文件和可执行文件
.PHONY:clean
clean:
	rm -rf $(TARGET) $(OBJ)
# 编译规则 $@代表目标文件 $< 代表第一个依赖文件

%.o:%.c
	gcc -c $< -o $@ -I $(INCLUDE) $(CFLAGS)