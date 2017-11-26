CC = gcc
CFLAGS = -Wall -g -std=c99
LIBS =

BIN = ./bin/
SRC = ./src/

SRC_FILES = $(wildcard ./src/*.c)
TEST_FILES = $(wildcard ./tests/*.c)

program:
	$(CC) $(CFLAGS) $(SRC_FILES) -Iinclude -L./lib $(LIBS) -o $(BIN)main.out

testing:
	$(CC) $(CFLAGS) $(TEST_FILES) ./src/heap.c -Iinclude -L./lib $(LIBS) -o $(BIN)testMain.out

show:
	@echo $(SRC_FILES)

showTest:
	@echo $(TEST_FILES)

cls:
	clear

clean:
	rm ./bin/*
