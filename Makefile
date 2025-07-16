CXX = g++
CXXFLAGS = -std=c++20 -Wall -Werror -pedantic

SRC_DIR = src
BUILD_DIR = build

INCLUDE_DIR = include

LIB_DIR = lib
LIB_NAME = numbers
STATIC_LIB= $(LIB_DIR)/lib$(LIB_NAME).a

CPP_FILES = $(shell find $(SRC_DIR) -name '*.cpp')
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(CPP_FILES))
DEP_FILES = $(OBJ_FILES:.o=.d)

.PHONY: all
all: $(STATIC_LIB)

$(STATIC_LIB): $(OBJ_FILES)
	@mkdir -p $(dir $@)
	ar rcs $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -MMD -c $< -o $@

-include $(DEP_FILES)

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)/* $(LIB_DIR)/*
