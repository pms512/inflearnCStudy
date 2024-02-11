#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "init.h"

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


void printAllNodes()
{
        USERDATA *pCurrent = &g_Head;
        printf("Printing all nodes..\n");
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

void changePosition(USERDATA *node1, USERDATA *node2)
{
	USERDATA *pTmp;

	if ( node1 != node2 )
	{
		pTmp = node1->pPrev;
		node1->pPrev = node2->pPrev;
		node2->pPrev = pTmp;

		pTmp = node1->pPrev->pNext;
		node1->pPrev->pNext = node2->pPrev->pNext;
		node2->pPrev->pNext = pTmp;

		pTmp = node1->pNext;
		node1->pNext = node2->pNext;
		node2->pNext = pTmp;

		pTmp = node1->pNext->pPrev;
		node1->pNext->pPrev = node2->pNext->pPrev;
		node2->pNext->pPrev = pTmp;
	}
}

void sortByName()
{
	USERDATA *sortPos = g_Head.pNext;
	USERDATA *sortTarget = g_Head.pNext;
	USERDATA *sortCurrentScanPos = g_Head.pNext;

	while (sortPos != &g_Tail)
	{
		while(sortCurrentScanPos != &g_Tail)
		{
			if (strcmp(sortTarget->name, sortCurrentScanPos->name) > 0)
			{
				sortTarget = sortCurrentScanPos;
			}
			sortCurrentScanPos = sortCurrentScanPos->pNext;
		}
		changePosition(sortPos, sortTarget);
		sortPos = sortTarget->pNext;
		sortTarget = sortPos;
		sortCurrentScanPos = sortPos;
	}
}

void sortByAge()
{
        USERDATA *sortPos = g_Head.pNext;
        USERDATA *sortTarget = g_Head.pNext;
        USERDATA *sortCurrentScanPos = g_Head.pNext;

        while (sortPos != &g_Tail)
        {
                while(sortCurrentScanPos != &g_Tail)
                {
                        if (sortTarget->age > sortCurrentScanPos->age)
                        {
                                sortTarget = sortCurrentScanPos;
                        }
                        sortCurrentScanPos = sortCurrentScanPos->pNext;
                }
                changePosition(sortPos, sortTarget);
                sortPos = sortTarget->pNext;
                sortTarget = sortPos;
                sortCurrentScanPos = sortPos;
        }

}

USERDATA **searchByAgeRange(const int min, const int max)
{
	USERDATA *minNode;
	USERDATA *maxNode;
	USERDATA *pCurrent = g_Head.pNext;
	int cnt = 1;

	while (pCurrent->age < min)
	{
		if (pCurrent->pNext == &g_Tail || pCurrent->pNext->age >= max)
		{
			printf("There is no data matching condition.\n");
			return NULL;
		}
		pCurrent = pCurrent->pNext;
	}
	minNode = pCurrent;
	

	pCurrent = g_Tail.pPrev;

	while (pCurrent->age > max)
	{
		if (pCurrent->pPrev == &g_Head || pCurrent->pPrev->age <= min)
		{
			printf("There is no data matching condition.\n");
			return NULL;
		}
		pCurrent = pCurrent->pPrev;
	}
	maxNode = pCurrent;

	pCurrent = minNode;

	while(pCurrent != maxNode)
	{
		cnt++;
		pCurrent = pCurrent->pNext;
	}

	USERDATA **searchResult = malloc(sizeof(USERDATA *) * (cnt + 1));
	memset(searchResult, 0, sizeof(searchResult));
	pCurrent = minNode;
	int arrPos = 0;
	for(int i = 0; i < cnt; i++)
	{
		searchResult[i] = pCurrent;
		pCurrent = pCurrent->pNext;
	}

	return searchResult;	
}

void printSearchedNodes(USERDATA **pResult)
{
	if (pResult != NULL)
	{
		for(int i = 0; pResult[i] != NULL; i++)
		{
		printf("[%p] %d, %s, %s\n", pResult[i], pResult[i]->age, pResult[i]->name, pResult[i]->phone);
		}
	}
	free(pResult);
}
