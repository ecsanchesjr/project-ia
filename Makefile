CC := g++ -std=gnu++14

SRC_PATH := sources
INC_PATH := includes

INC := -I $(INC_PATH)

OUT_PATH := bin
TARGET := $(OUT_PATH)/exe
TARGET_DIST := $(OUT_PATH)/dist

SOURCES := $(shell find $(SRC_PATH) -type f -name *.cpp)

all: build run

build:
	@mkdir -p $(OUT_PATH)
	$(CC) $(INC) $(SOURCES) -o $(TARGET)

run:
	@echo "\nRunning..."
	@./$(TARGET)

dist:
	@echo "\nBuilding optimized Code Overpower!!!!!"
	$(CC) $(INC) $(SOURCES) -o $(TARGET) -03