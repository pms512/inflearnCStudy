#include <stdio.h>
#include <stdbool.h>
#ifndef INIT_H
#define INIT_H

typedef struct HEADER {
	int firstDeleted;
	int nextFirstDeleted;
	int lastDeleted;
	int prevLastDeleted;
} HEADER;

typedef struct USERDATA {
	bool isDeleted;
	int dPrev;
	int dNext;
        char name[20];
        int age;
        char phone[15];
} USERDATA;

typedef struct MYNODE {
	struct MYNODE *pPrev;
	bool toBeInserted;
	bool toBeUpdated;
	bool toBeDeleted;
	unsigned int fileOffset;
	void *pData;
	struct MYNODE *pNext;
} MYNODE;

//declare global pointer variable : g_Head, g_Tail
MYNODE g_Head;
MYNODE g_Tail;
HEADER g_Header;
MYNODE **ageIndex;
MYNODE **nameIndex;
#endif /* INIT_H */
void initData();
