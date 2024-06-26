#include <stdio.h>

typedef enum commandType {INVALID, ADD, UPDATE, SELECT, PRINTALL, DELETE, COUNT, PRINTBYAGEINDEX, PRINTBYNAMEINDEX, LOADFROMFILE, SEEKNODE, COMMIT, EXIT} commandType;


void addEvent(void);
void updateEvent(void);
void selectEvent(void);
void deleteEvent(void);
void exitEvent(void);
void eventLoop(void);
void testLoop(void);
void printAllEvent(void);
void countEvent(void);
void countAllEvent(void);
void printByAgeIndexEvent(void);
void printByNameIndexEvent(void);
void loadFromFileEvent(void);
void seekNodeEvent(void);
void commitEvent(void);
