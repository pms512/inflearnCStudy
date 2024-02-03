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

void printAllNodes();
void addNewNode();
void freeAllNodes();

int main()
{
	printAllNodes();
	
	addNewNode("aaaa", 10, "010-1234-1234");
	addNewNode("bbbb", 30, "010-4567-1237");
	addNewNode("cccc", 50, "010-1235-5166");
	
	printAllNodes();

	freeAllNodes();

	
	return 0;
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
	printf("Added data : [%p] %s, %d, %s [%p]\n", newNode, newNode->name, newNode->age, newNode->phone, newNode->pNext);

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
		printAllNodes();
	}

}
