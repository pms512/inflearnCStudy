#include <stdio.h>
#include "init.h"
#include "funcs.h"

//declare global pointer variable : g_Head, g_Tail, ageIndex, nameIndex
USERDATA g_Head = {"_dummyHead_", 0 };
USERDATA g_Tail = {"_dummyTail_", 0 };
USERDATA **ageIndex = NULL;
USERDATA **nameIndex = NULL;

void initData()
{       
        g_Head.pNext = &g_Tail;
        g_Tail.pPrev = &g_Head;
}
