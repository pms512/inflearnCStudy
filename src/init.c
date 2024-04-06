#include <stdio.h>
#include "init.h"
#include "funcs.h"

//declare global pointer variable : g_Head, g_Tail, ageIndex, nameIndex
MYNODE g_Head = { 0 };
MYNODE g_Tail = { 0 };
MYNODE **ageIndex = NULL;
MYNODE **nameIndex = NULL;

void initData()
{       
	USERDATA *headData = malloc(sizeof(USERDATA));
	USERDATA *tailData = malloc(sizeof(USERDATA));

	strcpy(headData->name, "_dummyHead_");
	headData->age = 0;
	strcpy(headData->phone, "0");
	
	strcpy(tailData->name, "_dummyTail_");
	tailData->age = 0;
	strcpy(tailData->phone, "0");
	
	g_Head.pData = headData;
	g_Tail.pData = tailData;

        g_Head.pNext = &g_Tail;
        g_Tail.pPrev = &g_Head;
}
