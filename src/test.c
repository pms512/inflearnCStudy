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

