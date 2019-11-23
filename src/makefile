#可执行文件
BIN_NAME := main 
#编译的后缀文件
SRC_EXT = cpp
SRC_PATH = .
COMPILE_FLAGS = -Wall -g
debug: export CXXFLAGS := $(CXXFLAGS) $(COMPILE_FLAGS)
debug: export BUILD_PATH := ../debug

#所有源文件
SOURCES = $(shell find $(SRC_PATH) -name '*.$(SRC_EXT)')
#所有目录
ALL_DIR = $(shell find $(SRC_PATH) -type d)
#包含目录
INCLUDES += $(patsubst %,-I%,$(ALL_DIR))
CUR_DIR = $(shell pwd)
#目标文件
OBJECTS = $(SOURCES:$(SRC_PATH)/%.$(SRC_EXT)=$(BUILD_PATH)/%.o)
#依赖文件
DEPS = $(OBJECTS:.o=.d)

debug: dirs
	@$(MAKE) $(BIN_NAME) --no-print-directory

#创建目录
dirs:
	@mkdir -p $(dir $(OBJECTS))

#可执行文件
$(BIN_NAME): $(OBJECTS)
	@echo -e "\033[31mLinking CXX executable $(CUR_DIR)/$@\033[0m"
	@$(CXX) $(OBJECTS) -o $@

#依赖规则
-include $(DEPS)

#目标
$(BUILD_PATH)/%.o: $(SRC_PATH)/%.$(SRC_EXT)
	@echo -e "\033[32mBuilding CXX object ../debug/$@\033[0m"
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -MP -MMD -c $< -o $@

#清理临时文件
clean:
	@$(RM) $(BIN_NAME)
	@find ../debug -type f |xargs rm -rf
	@echo "clean $(BIN_NAME)done!"