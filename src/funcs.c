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
        printf("[[pPrev]][pCurrent] name\tage\tphone [[pNext]]\n");
        printf("=========================================================================\n");
        while(pCurrent != NULL)
        {
        printf("[[%p]][%p] %s\t%d\t%s [[%p]]\n", pCurrent->pPrev, pCurrent, pCurrent->name, pCurrent->age, pCurrent->phone, pCurrent->pNext);
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

void updateNode(USERDATA *targetNode, const char *updatedName, int updatedAge, const char *updatedPhone)
{
	strcpy(targetNode->name, updatedName);
	targetNode->age = updatedAge;
	strcpy(targetNode->phone, updatedPhone);
}


void removeAllNodes()
{
        USERDATA *targetNode = NULL;
        printf("=== Removing all nodes and indexes..===\n");
        while(g_Head.pNext != &g_Tail)
        {
                targetNode = g_Head.pNext;
                g_Head.pNext = targetNode->pNext;
                g_Head.pNext->pPrev = &g_Head;
                free(targetNode);
        }
	free(ageIndex);
	free(nameIndex);

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

int removeNode(const char *searchName)
{
        USERDATA *targetNode = searchByName(searchName);
        if ( targetNode == NULL )
        {
                printf("There is no data to remove. - name : %s\n", searchName);
		return 1;
        }
        else
        {
                printf("Removing data - name : %s\n", targetNode->name);
                targetNode->pPrev->pNext = targetNode->pNext;
                targetNode->pNext->pPrev = targetNode->pPrev;
                free(targetNode);
		return 0;
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
	printf("[pCurrent]\tAge\tName\tPhone\n");
	printf("=============================================\n");
	if (pResult != NULL)
	{
		for(int i = 0; pResult[i] != NULL; i++)
		{
		printf("[%p]\t%d\t%s\t%s\n", pResult[i], pResult[i]->age, pResult[i]->name, pResult[i]->phone);
		}
		printf("\n");
	}
	free(pResult);
}

int getNodeCount()
{
	USERDATA *pCurrent = g_Head.pNext;
	int cnt = 0;

	while(pCurrent != &g_Tail)
	{
		cnt++;
		pCurrent = pCurrent->pNext;
	}
	return cnt;
}

USERDATA **createAgeIndex()
{
	USERDATA **ageIndex = NULL;
	int cnt = getNodeCount();
	ageIndex = malloc(sizeof(USERDATA *) * cnt);
	USERDATA *tmp = NULL;
	USERDATA *pCurrent = g_Head.pNext;
	
	//Input address of node into ageIndex
	for (int i = 0; i < cnt; i++)
	{
		ageIndex[i] = pCurrent;
		pCurrent = pCurrent->pNext;
	}

	//bubble sort
	for (int i = cnt - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if(ageIndex[j]->age > ageIndex[j+1]->age)
			{
				tmp = ageIndex[j];
				ageIndex[j] = ageIndex[j + 1];
				ageIndex[j + 1] = tmp;
			}
		}
	}
	return ageIndex;
}

USERDATA **createNameIndex()
{
	USERDATA **nameIndex = NULL;
	int cnt = getNodeCount();
	nameIndex = malloc(sizeof(USERDATA *) * cnt);
	USERDATA *tmp = NULL;
	USERDATA *pCurrent = g_Head.pNext;
	
	//Input address of node into nameIndex
	for (int i = 0; i < cnt; i++)
	{
		nameIndex[i] = pCurrent;
		pCurrent = pCurrent->pNext;
	}

	//bubble sort
	for (int i = cnt - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{	
			if( strcmp(nameIndex[j]->name, nameIndex[j+1]->name) > 0 )
			{
				tmp = nameIndex[j];
				nameIndex[j] = nameIndex[j + 1];
				nameIndex[j + 1] = tmp;
			}
		}
	}
	return nameIndex;
}

void printByIndex(USERDATA **index)
{
	int cnt = getNodeCount();
	printf("Name\tAge\tPhone\n");
	printf("=====================================\n");
	for (int i = 0; i < cnt; i++)
	{
		printf("%s\t%d\t%s\n", index[i]->name, index[i]->age, index[i]->phone);
	}
	printf("\n");
}

USERDATA **searchByAgeIndex(USERDATA **index, const int min, const int max)
{
	USERDATA *minIndex;
	USERDATA *maxIndex;
	int idxCount = getNodeCount();
	int minPos = -1;
	int maxPos = -1;
	int cnt = 1;

	for (int i = 0; i < idxCount; i++)
	{
		if(index[i]->age >= min)
		{
			minIndex = index[i];
			minPos = i;
			break;
		}
	}

	if (minPos == -1)
	{
		printf("There is no proper data.\n");
		return NULL;
	}

	for (int j = minPos; j < idxCount; j++)
	{
		if(index[j]->age > max)
		{
			maxIndex = index[j-1];
			maxPos = j-1;
			break;
		}
		else if(j == idxCount - 1)
		{
			maxPos = j;
		}
	}

	if (minPos > maxPos)
	{
		printf("There is no proper data.\n");
		return NULL;
	}

	USERDATA **searchResult = malloc(sizeof(USERDATA *) * (maxPos - minPos + 2));
	int tmpPos = 0;
	for (int i = minPos; i <= maxPos; i++)
	{
		searchResult[tmpPos] = index[i];
		tmpPos++;
	}
	searchResult[tmpPos] = 0;

	return searchResult;
}

void rebuildIndexes()
{
	free(ageIndex);
        printf("Rebuilding ageIndex..\n");
	ageIndex = createAgeIndex();

	free(nameIndex);
        printf("Rebuilding ageIndex..\n");
	nameIndex = createNameIndex();
}
