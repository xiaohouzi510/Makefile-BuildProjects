#目标文件目录
TARGET_DIR="../debug"

#所有目录
ALL_DIR = $(shell find -type d)

#include 目录
INCLUDE_DIR = $(patsubst %,-I%,$(ALL_DIR))

#所有 .cpp 文件，即依赖文件
ALL_DEPEND = $(shell find -type f -name "*cpp")

#所有 .o 文件，即目标文件
ALL_TARGET = $(patsubst ./%.cpp,../debug/%.o,$(ALL_DEPEND))

#生成 .o 目录变量
define MAKE_TARGET_DIR
	$(shell mkdir -p $(TARGET_DIR)/$(1)) 
endef
#生成 .o 目录
$(foreach dir,$(ALL_DIR),$(eval $(call MAKE_TARGET_DIR,$(dir))))

main : $(ALL_TARGET)
	g++ -g -o $@ $^

#编译所有 cpp 变量
define COMPILE_CPP
#ONE 变量用于去掉.，TOW 用于去掉 /
ONE=$(patsubst .%,%,$(1))
TOW=$(patsubst /%,%,$(ONE))
../debug/$(TOW)%.o:$(1)/%.cpp
	g++ -g -c -o $$@ $$^ $(INCLUDE_DIR) 
endef

#生成所有目录下所有 cpp 目标 
$(foreach dir,$(ALL_DIR),$(eval $(call COMPILE_CPP,$(dir))))

#清理目标
clean :
	rm -rf main 
	find $(TARGET_DIR) -type f |xargs rm -rf 