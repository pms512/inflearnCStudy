#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funcs.h"

void addInitData()
{
	bool isDML = true;
        insertNode("Kim", 10, "010-1111-1111", isDML);
        insertNode("Eddy", 25, "010-2222-2222", isDML);
        insertNode("Amy", 11, "010-3333-3333", isDML);
        insertNode("Jason", 17, "010-4444-4444", isDML);
        insertNode("Dale", 45, "010-5555-5555", isDML);
        insertNode("Loy", 13, "010-6634-1234", isDML);
        insertNode("Mike", 7, "010-4537-8272", isDML);
        insertNode("Tom", 18, "010-1220-5282", isDML);
        insertNode("Tony", 22, "010-2532-1123", isDML);
        insertNode("Sam", 6, "010-4587-2390", isDML);
        insertNode("Peggy", 13, "010-5273-4402", isDML);
	ageIndex = createAgeIndex();
	nameIndex = createNameIndex();
}

void test_removeHeadNode()
{
	bool isDML = true;
        printf("[[TEST 1 : Remove head node]]\n");
        insertNode("aaaa", 10, "010-1111-1111", isDML);
        printAllNodes();
        deleteNode("aaaa");
        insertNode("Newaaaa", 10, "010-1111-1111", isDML);
        searchByName("Newaaaabb");
        printAllNodes();
        removeEverything();
}

void test_removeBodyNode()
{
	bool isDML = true;
        printf("[[TEST 2 : Remove body node]]\n");
        addInitData();
        printAllNodes();
        deleteNode("bbbb");
        insertNode("Newbbbb", 20, "010-2222-2222", isDML);
        printAllNodes();
        removeEverything();
}

void test_removeTailNode()
{
	bool isDML = true;
        printf("[[TEST 3 : Remove tail node]]\n");
        addInitData();
        printAllNodes();
        deleteNode("cccc");
        insertNode("Newcccc", 30, "010-3333-3333", isDML);
        printAllNodes();
        removeEverything();
}

