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
FILE_COUNT = $(shell find $(SRC_PATH) -name '*.$(SRC_EXT)'|wc -l)

debug: dirs
	@$(MAKE) $(BIN_NAME) --no-print-directory

#创建目录
dirs:
	@mkdir -p $(dir $(OBJECTS))
	@echo 0 > $(PERCENT_FILE)

#可执行文件
$(BIN_NAME): $(OBJECTS)
	@echo -e "\033[1;31mLinking CXX executable $(CUR_DIR)/$@\033[0m"
	@$(CXX) $(OBJECTS) -o $@
	@rm -rf $(PERCENT_FILE)

#依赖规则
-include $(DEPS)

PERCENT_FILE = $(BUILD_PATH)/percent_file.txt 
OBJ_CMD = read ONE < $(PERCENT_FILE) ; \
	TOW=$$((`expr $$ONE + 1`)) ; \
	echo $$TOW > $(PERCENT_FILE) ; \
	THREE=$$((`expr $$TOW*100/$(FILE_COUNT)`)) ; \
	echo -e "[ $$THREE%]\033[32mBuilding CXX object $@\033[0m" 

#目标
$(BUILD_PATH)/%.o: $(SRC_PATH)/%.$(SRC_EXT)
	@$(OBJ_CMD)
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -MP -MMD -c $< -o $@

#清理临时文件
clean:
	@$(RM) $(BIN_NAME)
	@find $(BUILD_PATH) -type f |xargs rm -rf
	@echo "clean $(BIN_NAME)done!"