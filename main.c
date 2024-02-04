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
USERDATA *g_pHead = NULL;

USERDATA *searchByName(const char *searchName);
void addInitData();
void printAllNodes();
void addNewNode();
void freeAllNodes();

int main()
{

	searchByName("asdfkj");

	addInitData();
	
	searchByName("aaaa");
	searchByName("bbbb");
	searchByName("cccc");
	searchByName("dddd");
	searchByName("eeee");
	searchByName("ffff");
	searchByName("gggg");
	searchByName("asdf");

	freeAllNodes();

	
	return 0;
}

USERDATA *searchByName(const char *searchName)
{
	USERDATA *pCurrent = NULL;
	pCurrent = g_pHead;

	while ( pCurrent != NULL )
	{
		if ( strcmp(pCurrent->name, searchName) == 0 )
		{
			printf("Found data - name : %s [%p]\n", searchName, pCurrent);
			return pCurrent;
		}
		else
		{
			if ( pCurrent->pNext == NULL)
			{
				printf("Not found data - name : %s\n", searchName);
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
	addNewNode("dddd", 40, "010-4444-4444");
	addNewNode("eeee", 50, "010-5555-5555");
	addNewNode("ffff", 60, "010-6666-6666");
	addNewNode("gggg", 70, "010-7777-7777");
}

void printAllNodes()
{
	USERDATA *pCurrent = NULL;
	pCurrent = g_pHead;
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
/*	
 	//Add a node ahead of head node (STACK)
 	
 	USERDATA *newNode = malloc(sizeof(USERDATA));
	memset(newNode, 0, sizeof(USERDATA));
	strcpy(newNode->name, newName);
	newNode->age = newAge;
	strcpy(newNode->phone, newPhone);
	newNode->pNext = g_pHead;
	g_pHead = newNode;
	printf("Added data : [%p] %s, %d, %s [%p]\n", newNode, newNode->name, newNode->age, newNode->phone, newNode->pNext);
*/

	//Add a node behind of tail node (QUEUE)
	
	USERDATA *newNode = malloc(sizeof(USERDATA));
	memset(newNode, 0, sizeof(USERDATA));
	strcpy(newNode->name, newName);
	newNode->age = newAge;
	strcpy(newNode->phone, newPhone);

	if ( g_pHead == NULL )
	{
		g_pHead = newNode;
	}
	else
	{
		USERDATA *pTail = g_pHead;
		while( pTail->pNext != NULL )
		{
			pTail = pTail->pNext;
		}
		pTail->pNext = newNode;
	}
	printf("Added data : [%p] %s, %d, %s\n", newNode, newNode->name, newNode->age, newNode->phone);

}

void freeAllNodes()
{
	USERDATA *targetNode = NULL;

	while(g_pHead != NULL)
	{
		targetNode = g_pHead;
		g_pHead = targetNode->pNext;
		printf("Deleting %p...\n", targetNode);
		free(targetNode);
		//printAllNodes();
	}

}
