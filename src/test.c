#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funcs.h"

void addInitData()
{
        addNewNode("Kim", 10, "010-1111-1111");
        addNewNode("Eddy", 25, "010-2222-2222");
        addNewNode("Amy", 11, "010-3333-3333");
        addNewNode("Jason", 17, "010-4444-4444");
        addNewNode("Dale", 45, "010-5555-5555");
        addNewNode("Loy", 13, "010-6634-1234");
        addNewNode("Mike", 7, "010-4537-8272");
        addNewNode("Tom", 18, "010-1220-5282");
        addNewNode("Tony", 22, "010-2532-1123");
        addNewNode("Sam", 6, "010-4587-2390");
        addNewNode("Peggy", 13, "010-5273-4402");
	ageIndex = createAgeIndex();
	nameIndex = createNameIndex();
}

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

void test_sort1()
{
	printf("===== test_sort1 =====\n");
	addNewNode("aaaa", 20, "010-1111-1111");
	printf("\n");	
	printAllNodes();
	printf("sorting...\n\n");
	sortByName();
	printAllNodes();
	removeAllNodes();
	printf("---------------------------------------------------------\n");
}

void test_sort2()
{
	printf("===== test_sort2 =====\n");
	addNewNode("aacc", 20, "010-1111-1234");
	addNewNode("aaaa", 20, "010-1111-1111");
	printf("\n");	
	printAllNodes();
	printf("sorting...\n\n");
	sortByName();
	printAllNodes();
	removeAllNodes();
	printf("---------------------------------------------------------\n");
}

void test_sort3()
{
	printf("===== test_sort3 =====\n");
	addNewNode("aaaa35834", 20, "010-1111-3582");
	addNewNode("aaaa", 20, "010-1111-1111");
	printf("\n");	
	printAllNodes();
	printf("sorting...\n\n");
	sortByName();
	printAllNodes();
	removeAllNodes();
	printf("---------------------------------------------------------\n");
}

void test_sort4()
{
	printf("===== test_sort4 =====\n");
	addNewNode("Jay", 10, "010-2342-5780");
	addNewNode("Chloe", 20, "010-2346-2273");
	addNewNode("Amy", 30, "010-4592-0112");
	addNewNode("Chloe", 20, "010-2346-2273");
	addNewNode("Jason", 22, "010-4478-5903");
	printf("\n");	
	printAllNodes();
	printf("sorting...\n\n");
	sortByName();
	printAllNodes();
	removeAllNodes();
	printf("---------------------------------------------------------\n");
}
