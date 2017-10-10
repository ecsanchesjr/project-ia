CC := g++ -std=gnu++14

SRC_PATH := sources
INC_PATH := includes

INC := -I includes

OUT_PATH := bin
TARGET := $(OUT_PATH)/exe
TARGET_DIST := $(OUT_PATH)/dist

SOURCES := $(shell find $(SRC_PATH) -type f -name *.cpp)

ARGS := berlin52.tsp batata.log 50 1 1 20 5

all: build run

build:
	@mkdir -p $(OUT_PATH)
	$(CC) $(SOURCES) $(INC) -o $(TARGET)

run:
	@echo "\nRunning..."
	@./$(TARGET) $(ARGS)

dist:
	@echo "\nBuilding optimized Code Overpower!!!!!"
	$(CC) $(SOURCES) $(INC) -o $(TARGET) -O3