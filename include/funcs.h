#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "init.h"

int removeNode(const char *searchName);
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
void sortByAge();
USERDATA **searchByAgeRange(const int min, const int max);
void printSearchedNodes(USERDATA **pResult);
int getNodeCount();
USERDATA **createAgeIndex();
void printByIndex(USERDATA **index);
USERDATA **searchByAgeIndex(USERDATA **index, const int min, const int max);
USERDATA **createNameIndex();
USERDATA *updateNodeupdateNode(USERDATA *targetNode, const char *updatedName, int updatedAge, const char *updatedPhone);
void rebuildIndexes();
