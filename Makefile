CC = gcc
MY_TARGET = myResult
MY_SRC = myMain.c
OFFICIAL_TARGET = officialResult
OFFICIAL_SRC = officialMain.c

mine:	
	$(CC) -o $(MY_TARGET) $(MY_SRC) -g
	./$(MY_TARGET)

official:
	$(CC) -o $(OFFICIAL_TARGET) $(OFFICIAL_SRC) -g
	./$(OFFICIAL_TARGET)
