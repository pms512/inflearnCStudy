#include <stdio.h>
#include "init.h"

//declare global pointer variable : g_Head, g_Tail
USERDATA g_Head = {"_dummyHead_", 0 };
USERDATA g_Tail = {"_dummyTail_", 0 };

void initData()
{       
        g_Head.pNext = &g_Tail;
        g_Tail.pPrev = &g_Head;
}
