#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "init.h"

int deleteNode(const char *searchName);
MYNODE *searchByName(const char *searchName);
void printAllInfo();
void loadNode(const char *newName, int newAge, const char *newPhone, unsigned int skipOffset);
void insertNode(const char *newName, int newAge, const char *newPhone);
void removeEverything();
MYNODE **searchByAgeRange(const int min, const int max);
void printSearchedNodes(MYNODE **pResult);
int getNodeCount();
int getAllCount();
MYNODE **createAgeIndex();
void printByIndex(MYNODE **index);
MYNODE **searchByAgeIndex(MYNODE **index, const int min, const int max);
MYNODE **createNameIndex();
MYNODE *updateNode(MYNODE *targetNode, const char *updatedName, int updatedAge, const char *updatedPhone);
void rebuildIndexes();
void saveToFile(void);
void loadFromFile(void);
void checkSave(void);
void commit(void);
void commitInsert(MYNODE *pCurrent);
void commitUpdate(void);
void commitDelete(void);
void saveToFile(void);
MYNODE *seekNode(int fileOffset);
void commitHeader(void);
