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

void test_removeHeadNode();
void test_removeBodyNode();
void test_removeTailNode();
void test_push();
void test_pop();
void test_enqueue();
void test_dequeue();

void removeNode(const char *searchName);
USERDATA *searchByName(const char *searchName);
void initData();
void addInitData();
void printAllNodes();
void addNewNode();
void removeAllNodes();
void pushNode(const char *newName, int newAge, const char *newPhone);
USERDATA *popNode();
void enqueueNode(const char *newName, int newAge, const char *newPhone);
USERDATA *dequeueNode();

int main()
{
	initData();
	printf("=====================================================================================\n");
	test_push();
	printf("=====================================================================================\n");
	test_pop();
	printf("=====================================================================================\n");
	test_enqueue();
	printf("=====================================================================================\n");
	test_dequeue();
	printf("===================================[END OF TEST]=====================================\n");

	return 0;
}

//////////////////// test scenarios ////////////////////

void test_push()
{
	printf("[[TEST - Push(Stack)]]\n");
	pushNode("aaaa", 10, "010-1111-1111");
	pushNode("bbbb", 20, "010-2222-2222");
	printAllNodes();
	removeAllNodes();
}

void test_pop()
{
	USERDATA *pUser = NULL;
	printf("[[TEST - Pop(Stack)]]\n");
	pushNode("aaaa", 10, "010-1111-1111");
	pushNode("bbbb", 20, "010-2222-2222");
	printAllNodes();
	pUser = popNode();
	printf("Popped data : [%p] %s, %d, %s\n", pUser, pUser->name, pUser->age, pUser->phone);
	free(pUser);
	printAllNodes();
	
	pUser = popNode();
	printf("Popped data : [%p] %s, %d, %s\n", pUser, pUser->name, pUser->age, pUser->phone);
	free(pUser);
	printAllNodes();
	removeAllNodes();
}

void test_enqueue()
{
	printf("[[TEST - Enqueue(Queue)]]\n");
	enqueueNode("aaaa", 10, "010-1111-1111");
	enqueueNode("bbbb", 20, "010-2222-2222");
	printAllNodes();
	removeAllNodes();
}

void test_dequeue()
{
	USERDATA *pUser = NULL;
	printf("[[TEST - Dequeue(Queue)]]\n");
	enqueueNode("aaaa", 10, "010-1111-1111");
	enqueueNode("bbbb", 20, "010-2222-2222");
	printAllNodes();
	pUser = dequeueNode();
	printf("Dequeued data : [%p] %s, %d, %s\n", pUser, pUser->name, pUser->age, pUser->phone);
	free(pUser);
	printAllNodes();
	
	pUser = dequeueNode();
	printf("Dequeued data : [%p] %s, %d, %s\n", pUser, pUser->name, pUser->age, pUser->phone);
	free(pUser);
	printAllNodes();
	removeAllNodes();
}

void test_removeHeadNode()
{
	printf("[[TEST 1 : Remove head node]]\n");
	addNewNode("aaaa", 10, "010-1111-1111");
	printAllNodes();
	removeNode("aaaa");
	addNewNode("Newaaaa", 10, "010-1111-1111");
	searchByName("Newaaaabb");
	printAllNodes();
	removeAllNodes();
}

void test_removeBodyNode()
{
	printf("[[TEST 2 : Remove body node]]\n");
	addInitData();
	printAllNodes();
	removeNode("bbbb");
	addNewNode("Newbbbb", 20, "010-2222-2222");
	printAllNodes();
	removeAllNodes();
}

void test_removeTailNode()
{
	printf("[[TEST 3 : Remove tail node]]\n");
	addInitData();
	printAllNodes();
	removeNode("cccc");
	addNewNode("Newcccc", 30, "010-3333-3333");
	printAllNodes();
	removeAllNodes();
}

//////////////////// functions ////////////////////

void initData()
{
	g_Head.pNext = &g_Tail;
	g_Tail.pPrev = &g_Head;
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
	printf("[[%p]][%p] %s, %d, %s [[%p]]\n", pCurrent->pPrev, pCurrent, pCurrent->name, pCurrent->age, pCurrent->phone, pCurrent->pNext);
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

void removeAllNodes()
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
	}

}


void pushNode(const char *newName, int newAge, const char *newPhone)
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
	
	printf("Pushed data : [%p] %s, %d, %s\n", newNode, newNode->name, newNode->age, newNode->phone);
}

USERDATA *popNode()
{
	 USERDATA *targetNode = g_Tail.pPrev;

	 if (g_Tail.pPrev == &g_Head)
	 {
		 printf("There is no data to pop.\n");
		 return NULL;
	 }

	 g_Tail.pPrev = targetNode->pPrev;
	 targetNode->pPrev->pNext = &g_Tail;

	 return targetNode;
}


void enqueueNode(const char *newName, int newAge, const char *newPhone)
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
	
	printf("Enqueued data : [%p] %s, %d, %s\n", newNode, newNode->name, newNode->age, newNode->phone);
}

USERDATA *dequeueNode()
{
	 USERDATA *targetNode = g_Head.pNext;

	 if (g_Head.pNext == &g_Tail)
	 {
		 printf("There is no data to dequeue.\n");
		 return NULL;
	 }

	 g_Head.pNext = targetNode->pNext;
	 targetNode->pNext->pPrev = &g_Head;

	 return targetNode;
}
