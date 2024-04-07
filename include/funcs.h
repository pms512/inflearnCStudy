#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "init.h"

int removeNode(const char *searchName);
MYNODE *searchByName(const char *searchName);
void printAllNodes();
void addNewNode(const char *newName, int newAge, const char *newPhone);
void removeAllNodes();
MYNODE **searchByAgeRange(const int min, const int max);
void printSearchedNodes(MYNODE **pResult);
int getNodeCount();
MYNODE **createAgeIndex();
void printByIndex(MYNODE **index);
MYNODE **searchByAgeIndex(MYNODE **index, const int min, const int max);
MYNODE **createNameIndex();
MYNODE *updateNode(MYNODE *targetNode, const char *updatedName, int updatedAge, const char *updatedPhone);
void rebuildIndexes();
void saveToFile(void);
void loadFromFile(void);
void checkSave(void);
