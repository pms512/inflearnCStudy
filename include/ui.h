#include <stdio.h>

typedef enum commandType {INVALID, ADD, UPDATE, SELECT, PRINTALL, DELETE, COUNT, PRINTBYAGEINDEX, PRINTBYNAMEINDEX, LOADFROMFILE, SAVETOFILE, EXIT} commandType;


void addEvent(void);
void updateEvent(void);
void selectEvent(void);
void deleteEvent(void);
void exitEvent(void);
void eventLoop(void);
void testLoop(void);
void printAllEvent(void);
void countEvent(void);
void printByAgeIndexEvent(void);
void printByNameIndexEvent(void);
void loadFromFileEvent(void);
void saveToFileEvent(void);
