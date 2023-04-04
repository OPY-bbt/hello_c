# Caution:
# command 需要tab开头

# define the target
# TARGET = main

# define the Build Directory
BUILD_DIR = build
# OBJ_DIR = $(BUILD_DIR)/objs

# # define PATH
# LOCAL_PATH = $(shell pwd)

# # define the sources and objects
# SOURCES := $(shell find $(LOCAL_PATH)/ -name "*.c")
# OBJS := $(addprefix $(OBJ_DIR)/, $(patsubst %.c, %.o, $(notdir $(SOURCES))))

all: prepare main

prepare:
	@if [ ! -d $(BUILD_DIR) ]; then mkdir -p $(BUILD_DIR); fi;\

main: main.o function.o
	gcc $(BUILD_DIR)/main.o $(BUILD_DIR)/function.o -o $(BUILD_DIR)/main.exe -lstdc++ -lwsock32 -ldnsapi

main.o:
	gcc main.cpp -c -o $(BUILD_DIR)/main.o -lstdc++ -lwsock32 -ldnsapi

function.o:
	gcc function.cpp -c -o $(BUILD_DIR)/function.o -lstdc++
