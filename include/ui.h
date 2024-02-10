#include <stdio.h>

typedef enum actionType {ADD, UPDATE, SELECT, DELETE, EXIT} actionType;


void addEvent(void);
void updateEvent(void);
void selectEvent(void);
void deleteEvent(void);
void exitEvent(void);
void eventLoop(void);
void testLoop(void);
