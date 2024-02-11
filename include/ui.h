#include <stdio.h>

typedef enum commandType {ADD, UPDATE, SELECT, PRINTALL, DELETE, EXIT} commandType;


void addEvent(void);
void updateEvent(void);
void selectEvent(void);
void deleteEvent(void);
void exitEvent(void);
void eventLoop(void);
void testLoop(void);
void printAllEvent(void);
