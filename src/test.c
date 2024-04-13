#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funcs.h"

void addInitData()
{
	
        insertNode("Kim", 10, "010-1111-1111");
        insertNode("Eddy", 25, "010-2222-2222");
        insertNode("Amy", 11, "010-3333-3333");
        insertNode("Jason", 17, "010-4444-4444");
        insertNode("Dale", 45, "010-5555-5555");
        insertNode("Loy", 13, "010-6634-1234");
        insertNode("Mike", 7, "010-4537-8272");
        insertNode("Tom", 18, "010-1220-5282");
        insertNode("Tony", 22, "010-2532-1123");
        insertNode("Sam", 6, "010-4587-2390");
        insertNode("Peggy", 13, "010-5273-4402");
	ageIndex = createAgeIndex();
	nameIndex = createNameIndex();
}

void test_removeHeadNode()
{
	
        printf("[[TEST 1 : Remove head node]]\n");
        insertNode("aaaa", 10, "010-1111-1111");
        printAllNodes();
        deleteNode("aaaa");
        insertNode("Newaaaa", 10, "010-1111-1111");
        searchByName("Newaaaabb");
        printAllNodes();
        removeEverything();
}

void test_removeBodyNode()
{
	
        printf("[[TEST 2 : Remove body node]]\n");
        addInitData();
        printAllNodes();
        deleteNode("bbbb");
        insertNode("Newbbbb", 20, "010-2222-2222");
        printAllNodes();
        removeEverything();
}

void test_removeTailNode()
{
	
        printf("[[TEST 3 : Remove tail node]]\n");
        addInitData();
        printAllNodes();
        deleteNode("cccc");
        insertNode("Newcccc", 30, "010-3333-3333");
        printAllNodes();
        removeEverything();
}

