#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct USERDATA {
	char name[20];
	int age;
	char phone[15];
	struct USERDATA *pPrev;
	struct USERDATA *pNext;
} USERDATA;

//declare global pointer variable : g_Head, g_Tail
USERDATA g_Head = {"_dummyHead_", 0 };
USERDATA g_Tail = {"_dummyTail_", 0 };

void removeNode(const char *searchName);
USERDATA *searchPrevNodeByName(const char *searchName);
USERDATA *searchByName(const char *searchName);
void addInitData();
void printAllNodes();
void addNewNode();
void freeAllNodes();

int main()
{
	g_Head.pNext = &g_Tail;
	g_Tail.pPrev = &g_Head;
	printf("=====================================================================================\n");
	printf("[[TEST 1 : Remove head node]]\n");
	addNewNode("aaaa", 10, "010-1111-1111");
	printAllNodes();
	removeNode("aaaa");
	addNewNode("Newaaaa", 10, "010-1111-1111");
	
	searchByName("Newaaaabb");
	printAllNodes();
	freeAllNodes();
	printf("=====================================================================================\n");

	printf("[[TEST 2 : Remove body node]]\n");
	addInitData();
	printAllNodes();
	removeNode("bbbb");
	addNewNode("Newbbbb", 20, "010-2222-2222");
	printAllNodes();
	freeAllNodes();
	printf("=====================================================================================\n");

	printf("[[TEST 3 : Remove tail node]]\n");
	addInitData();
	printAllNodes();
	removeNode("cccc");
	addNewNode("Newcccc", 30, "010-3333-3333");
	printAllNodes();
	freeAllNodes();
	printf("=====================================================================================\n");

	return 0;
}

void removeNode(const char *searchName)
{
	USERDATA *targetNode = searchByName(searchName);
	if ( targetNode == NULL )
	{
		printf("There is no data to remove. - name : %s\n", searchName);
	}
	else
	{
		printf("Removing data - name : %s\n", targetNode->name);
		targetNode->pPrev->pNext = targetNode->pNext;
		targetNode->pNext->pPrev = targetNode->pPrev;
		free(targetNode);
	}
}

USERDATA *searchByName(const char *searchName)
{
	USERDATA *pCurrent = g_Head.pNext;

	while ( pCurrent != &g_Tail )
	{
		if ( strcmp(pCurrent->name, searchName) == 0 )
		{
			printf("Found data - name : %s [%p]\n", searchName, pCurrent);
			return pCurrent;
		}
		else
		{
			pCurrent = pCurrent->pNext;
		}
	}

	printf("Not found data - name : %s\n", searchName);
	return NULL;
}

void addInitData()
{
	addNewNode("aaaa", 10, "010-1111-1111");
	addNewNode("bbbb", 20, "010-2222-2222");
	addNewNode("cccc", 30, "010-3333-3333");
}

void printAllNodes()
{
	USERDATA *pCurrent = &g_Head;
	printf("====[Remaining data]====\n");
	while(pCurrent != NULL)
	{
	printf("[%p] %s, %d, %s [%p]\n", pCurrent, pCurrent->name, pCurrent->age, pCurrent->phone, pCurrent->pNext);
	pCurrent = pCurrent->pNext;
	}
	printf("\n");
}

void addNewNode(const char *newName, int newAge, const char *newPhone)
{
	
	USERDATA *newNode = malloc(sizeof(USERDATA));
	memset(newNode, 0, sizeof(USERDATA));
	strcpy(newNode->name, newName);
	newNode->age = newAge;
	strcpy(newNode->phone, newPhone);

	g_Tail.pPrev->pNext = newNode;
	newNode->pPrev = g_Tail.pPrev;

	g_Tail.pPrev = newNode;
	newNode->pNext = &g_Tail;
	
	printf("Added data : [%p] %s, %d, %s\n", newNode, newNode->name, newNode->age, newNode->phone);

}

void freeAllNodes()
{
	USERDATA *targetNode = NULL;
	printf("=== Removing all nodes..===\n");
	while(g_Head.pNext != &g_Tail)
	{
		targetNode = g_Head.pNext;
		g_Head.pNext = targetNode->pNext;
		g_Head.pNext->pPrev = &g_Head;
		printf("Removing %p...\n", targetNode);
		free(targetNode);
		//printAllNodes();
	}

}
