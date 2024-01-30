CC = gcc
EVENT = events/*.c
TARGET = result
SRC = main.c

all:	
	$(CC) -o $(TARGET) $(SRC) $(EVENT) -g
	./$(TARGET)
