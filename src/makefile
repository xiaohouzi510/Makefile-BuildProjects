#可执行文件
BIN_NAME := main 
#编译的后缀文件
SRC_EXT = cpp
SRC_PATH = .
COMPILE_FLAGS = -Wall -g
BUILD_PATH := ../debug
debug: export CXXFLAGS := $(CXXFLAGS) $(COMPILE_FLAGS)

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
	@echo -e "\033[1;31mLinking CXX executable $(CUR_DIR)/$@\033[0m"
	@$(CXX) $(OBJECTS) -o $@

CUR_INCR=$(eval CUR_COUNT := $(shell expr $(CUR_COUNT) + 1))

#依赖规则
-include $(DEPS)
OBJ_CMD = echo -e "[$(shell expr $(CUR_COUNT) '*' 100 / $(FILE_COUNT))% ]\033[32mBuilding CXX object $@\033[0m" 

#目标
$(BUILD_PATH)/%.o: $(SRC_PATH)/%.$(SRC_EXT)
	@$(CUR_INCR)
	@$(OBJ_CMD)
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -MP -MMD -c $< -o $@

ifndef STATISTICS 
FILE_COUNT := $(shell make $(MAKECMDGOALS) STATISTICS=1 -nrRf $(MAKEFILE_LIST) 2>/dev/null|grep -c "Building CXX object") 
endif

#清理临时文件
clean:
	@$(RM) $(BIN_NAME)
	@find $(BUILD_PATH) -type f |xargs rm -rf
	@echo "clean $(BIN_NAME)done!"