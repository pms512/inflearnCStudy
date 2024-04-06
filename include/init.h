#include <stdio.h>
#ifndef INIT_H
#define INIT_H
typedef struct USERDATA {
        char name[20];
        int age;
        char phone[15];
        struct USERDATA *pPrev;
        struct USERDATA *pNext;
} USERDATA;

//declare global pointer variable : g_Head, g_Tail
USERDATA g_Head;
USERDATA g_Tail;
USERDATA **ageIndex;
USERDATA **nameIndex;
#endif /* INIT_H */
void initData();
