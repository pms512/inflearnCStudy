.SUFFIXES: .c .o

CC=gcc
CFLAGS=-g
INC=-I./include

SRC_DIR=./src
BUILD_DIR=./build
BIN_DIR=./bin

TARGET=./result
C_SRC=$(wildcard $(SRC_DIR)/*.c)
OBJECT=$(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(C_SRC))

all: $(TARGET)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(TARGET): $(OBJECT)
	$(CC) -o $@ main.c $^ $(INC)
	./result

clean:
	rm -rf $(BUILD_DIR)/*.o $(TARGET)

