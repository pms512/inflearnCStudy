#include <stdio.h>
#ifndef INIT_H
#define INIT_H
typedef struct USERDATA {
        char name[20];
        int age;
        char phone[15];
} USERDATA;

typedef struct MYNODE {
	struct MYNODE *pPrev;
	void *pData;
	struct MYNODE *pNext;
} MYNODE;

//declare global pointer variable : g_Head, g_Tail
MYNODE g_Head;
MYNODE g_Tail;
MYNODE **ageIndex;
MYNODE **nameIndex;
#endif /* INIT_H */
void initData();
