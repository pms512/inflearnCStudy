CC = gcc
TARGET = result
SRC = main.c

all:	
	$(CC) -o $(TARGET) $(SRC) -g
