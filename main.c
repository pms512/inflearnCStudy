#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct USERDATA {
	char name[20];
	int age;
	char phone[15];
	struct USERDATA *pNext;
} USERDATA;

//declare global pointer variable : pHead
USERDATA *pHead = NULL;

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

	printAllNodes();

	return 0;
}

void printAllNodes()
{
	USERDATA *pCurrent = NULL;
	pCurrent = pHead;

	while(pCurrent != NULL)
	{
	printf("[%p] %s, %d, %s [%p]\n", pCurrent, pCurrent->name, pCurrent->age, pCurrent->phone, pCurrent->pNext);
	pCurrent = pCurrent->pNext;
	}
}

void addNewNode(const char *newName, int newAge, const char *newPhone)
{
	USERDATA *newNode = malloc(sizeof(USERDATA));
	memset(newNode, 0, sizeof(USERDATA));

	strcpy(newNode->name, newName);
	newNode->age = newAge;
	strcpy(newNode->phone, newPhone);
	newNode->pNext = pHead;
	pHead = newNode;

}

void freeAllNodes()
{
	USERDATA *targetNode = NULL;

	while(pHead != NULL)
	{
		targetNode = pHead;
		pHead = targetNode->pNext;
		printf("Deleting %p...\n", targetNode);
		free(targetNode);

		printf("====[Remained data]====\n");
		printAllNodes();
	}

}
