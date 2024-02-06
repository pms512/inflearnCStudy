#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct USERDATA {
	char name[20];
	int age;
	char phone[15];
	struct USERDATA *pNext;
} USERDATA;

//declare global pointer variable : g_pHead
USERDATA g_Head = {"_dummy_", 0 };

void removeNode(const char *searchName);
USERDATA *searchPrevNodeByName(const char *searchName);
USERDATA *searchByName(const char *searchName);
void addInitData();
void printAllNodes();
void addNewNode();
void freeAllNodes();

int main()
{
	printf("=====================================================================================\n");
	printf("[[TEST 1 : Remove head node]]\n");
	addNewNode("aaaa", 10, "010-1111-1111");
	printAllNodes();
	removeNode("aaaa");
	addNewNode("Newaaaa", 10, "010-1111-1111");
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
	USERDATA *prevNode = searchPrevNodeByName(searchName);
	if ( targetNode == NULL )
	{
		printf("There is no data to remove. - name : %s\n", searchName);
	}
	else
	{
		printf("Removing data - name : %s\n", targetNode->name);
		prevNode->pNext = targetNode->pNext;
		free(targetNode);
	}
}

USERDATA *searchPrevNodeByName(const char *searchName)
{
	USERDATA *pCurrent = NULL;
	pCurrent = &g_Head;
	
	while ( pCurrent != NULL )
	{
		if ( pCurrent->pNext == NULL)
		{
			return NULL;
		}
		else
		{
			if ( strcmp(pCurrent->pNext->name, searchName) == 0 )
			{
				return pCurrent;
			}
			else
			{
				pCurrent = pCurrent->pNext;
			}
		}
	}
}

USERDATA *searchByName(const char *searchName)
{
	USERDATA *pCurrent = g_Head.pNext;

	while ( pCurrent != NULL )
	{
		if ( strcmp(pCurrent->name, searchName) == 0 )
		{
		//	printf("Found data - name : %s [%p]\n", searchName, pCurrent);
			return pCurrent;
		}
		else
		{
			if ( pCurrent->pNext == NULL)
			{
		//		printf("Not found data - name : %s\n", searchName);
				return NULL;
			}
			else
			{
				pCurrent = pCurrent->pNext;
			}
		}
	}

	//If there is no data ( g_pHead == NULL )
	printf("There is no data.\n");
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
	//Add a node behind of tail node (QUEUE)
	
	USERDATA *newNode = malloc(sizeof(USERDATA));
	memset(newNode, 0, sizeof(USERDATA));
	strcpy(newNode->name, newName);
	newNode->age = newAge;
	strcpy(newNode->phone, newPhone);

	USERDATA *pTail = &g_Head;
	while( pTail->pNext != NULL )
	{
		pTail = pTail->pNext;
	}
	pTail->pNext = newNode;
	printf("Added data : [%p] %s, %d, %s\n", newNode, newNode->name, newNode->age, newNode->phone);

}

void freeAllNodes()
{
	USERDATA *targetNode = NULL;
	printf("=== Removing all nodes..===\n");
	while(g_Head.pNext != NULL)
	{
		targetNode = g_Head.pNext;
		g_Head.pNext = targetNode->pNext;
		printf("Removing %p...\n", targetNode);
		free(targetNode);
		//printAllNodes();
	}

}
