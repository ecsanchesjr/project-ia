CC := g++ -std=gnu++14

SRC_PATH := sources
INC_PATH := includes

INC := -I includes

OUT_PATH := bin
TARGET := $(OUT_PATH)/exe
TARGET_DIST := $(OUT_PATH)/dist

SOURCES := $(shell find $(SRC_PATH) -type f -name *.cpp)

ARGS := libs/berlin52.tsp logs/batata.log 10 1 1 20 5 logs/batata.sol

all: build run

build:
	@mkdir -p $(OUT_PATH)
	$(CC) $(SOURCES) $(INC) -o $(TARGET)

run:
	@echo "\nRunning..."
	@./$(TARGET) $(ARGS)

dist:
	@mkdir -p $(OUT_PATH)
	@echo "\nBuilding optimized Code Overpower!!!!!"
	$(CC) $(SOURCES) $(INC) -o $(TARGET) -O3

clean:
	rm -rf bin/
	rm -rf logs/*