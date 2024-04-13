#include <stdio.h>
#include "init.h"
#include "funcs.h"

//declare global pointer variable : g_Head, g_Tail, ageIndex, nameIndex
MYNODE g_Head = { 0 };
MYNODE g_Tail = { 0 };
MYNODE **ageIndex = NULL;
MYNODE **nameIndex = NULL;
HEADER g_Header = {-1, -1, -1, -1};

void initData()
{       
	USERDATA *headData = malloc(sizeof(USERDATA));
	USERDATA *tailData = malloc(sizeof(USERDATA));

	strcpy(headData->name, "_dHead_");
	headData->age = -1;
	strcpy(headData->phone, "THISISDUMMY");
	
	strcpy(tailData->name, "_dTail_");
	tailData->age = -1;
	strcpy(tailData->phone, "THISISDUMMY");
	
	g_Head.pData = headData;
	g_Tail.pData = tailData;

        g_Head.pNext = &g_Tail;
        g_Tail.pPrev = &g_Head;

	g_Head.fileOffset = -1;
	g_Tail.fileOffset = -1;
}
