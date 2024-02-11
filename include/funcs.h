#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "init.h"

void removeNode(const char *searchName);
USERDATA *searchByName(const char *searchName);
void printAllNodes();
void addNewNode(const char *newName, int newAge, const char *newPhone);
void removeAllNodes();
void pushNode(const char *newName, int newAge, const char *newPhone);
USERDATA *popNode();
void enqueueNode(const char *newName, int newAge, const char *newPhone);
USERDATA *dequeueNode();
void sortByName();
void changePosition(USERDATA *node1, USERDATA *node2);
