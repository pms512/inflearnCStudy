#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "init.h"

MYNODE *searchByName(const char *searchName)
{
        MYNODE *pCurrent = g_Head.pNext;

        while ( pCurrent != &g_Tail )
        {
                if ( strcmp(((USERDATA*)pCurrent->pData)->name, searchName) == 0 )
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
        MYNODE *pCurrent = &g_Head;
        printf("Printing all nodes including dummy nodes..\n");
        printf("[[pPrev]][pCurrent]\tname\tage\tphone\t\t[[pNext]]\n");
        printf("=========================================================================\n");
        while(pCurrent != NULL)
        {
        printf("[[%p]][%p]\t%s\t%d\t%s\t[[%p]]\n", 
		pCurrent->pPrev, 
		pCurrent, 
		((USERDATA*)pCurrent->pData)->name, 
		((USERDATA*)pCurrent->pData)->age, 
		((USERDATA*)pCurrent->pData)->phone, 
		pCurrent->pNext);
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
	
	MYNODE *newMyNode = malloc(sizeof(MYNODE));

	newMyNode->pData = newNode;

        g_Tail.pPrev->pNext = newMyNode;
        newMyNode->pPrev = g_Tail.pPrev;

        g_Tail.pPrev = newMyNode;
        newMyNode->pNext = &g_Tail;

        printf("Added data : [%p] %s, %d, %s\n", newMyNode, 
						 newNode->name,
						 newNode->age,
						 newNode->phone
						 );
}

void updateNode(MYNODE *targetNode, const char *updatedName, int updatedAge, const char *updatedPhone)
{
	strcpy(((USERDATA*)targetNode->pData)->name, updatedName);
	((USERDATA*)targetNode->pData)->age = updatedAge;
	strcpy(((USERDATA*)targetNode->pData)->phone, updatedPhone);
}


void removeAllNodes()
{
        MYNODE *targetNode = NULL;
        printf("=== Removing all nodes and indexes..===\n");
        while(g_Head.pNext != &g_Tail)
        {
                targetNode = g_Head.pNext;
                g_Head.pNext = targetNode->pNext;
                g_Head.pNext->pPrev = &g_Head;
		free(targetNode->pData);
                free(targetNode);
        }
	free(g_Head.pData);
	free(g_Tail.pData);
	free(ageIndex);
	free(nameIndex);

}

int removeNode(const char *searchName)
{
        MYNODE *targetNode = searchByName(searchName);
        if ( targetNode == NULL )
        {
                printf("There is no data to remove. - name : %s\n", searchName);
		return 1;
        }
        else
        {
                printf("Removing data - name : %s\n", ((USERDATA*)targetNode->pData)->name);
                targetNode->pPrev->pNext = targetNode->pNext;
                targetNode->pNext->pPrev = targetNode->pPrev;
		free(targetNode->pData);
                free(targetNode);
		return 0;
        }
}

MYNODE **searchByAgeRange(const int min, const int max)
{
	MYNODE *minNode;
	MYNODE *maxNode;
	MYNODE *pCurrent = g_Head.pNext;
	int cnt = 1;

	while (((USERDATA*)pCurrent->pData)->age < min)
	{
		if (pCurrent->pNext == &g_Tail || ((USERDATA*)pCurrent->pNext->pData)->age >= max)
		{
			printf("There is no data matching condition.\n");
			return NULL;
		}
		pCurrent = pCurrent->pNext;
	}
	minNode = pCurrent;
	

	pCurrent = g_Tail.pPrev;

	while (((USERDATA*)pCurrent->pData)->age > max)
	{
		if (pCurrent->pPrev == &g_Head || ((USERDATA*)pCurrent->pPrev->pData)->age <= min)
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

	MYNODE **searchResult = malloc(sizeof(MYNODE *) * (cnt + 1));
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

void printSearchedNodes(MYNODE **pResult)
{
	printf("[pCurrent]\tAge\tName\tPhone\n");
	printf("=============================================\n");
	if (pResult != NULL)
	{
		for(int i = 0; pResult[i] != NULL; i++)
		{
		printf("[%p]\t%d\t%s\t%s\n", pResult[i], 
				             ((USERDATA*)pResult[i]->pData)->age, 
				             ((USERDATA*)pResult[i]->pData)->name, 
				             ((USERDATA*)pResult[i]->pData)->phone
					     );
		}
		printf("\n");
	}
	free(pResult);
}

int getNodeCount()
{
	MYNODE *pCurrent = g_Head.pNext;
	int cnt = 0;

	while(pCurrent != &g_Tail)
	{
		cnt++;
		pCurrent = pCurrent->pNext;
	}
	return cnt;
}

MYNODE **createAgeIndex()
{
	MYNODE **ageIndex = NULL;
	int cnt = getNodeCount();
	ageIndex = malloc(sizeof(MYNODE *) * cnt);
	MYNODE *tmp = NULL;
	MYNODE *pCurrent = g_Head.pNext;
	
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
			if(((USERDATA*)ageIndex[j]->pData)->age > ((USERDATA*)ageIndex[j+1]->pData)->age)
			{
				tmp = ageIndex[j];
				ageIndex[j] = ageIndex[j + 1];
				ageIndex[j + 1] = tmp;
			}
		}
	}
	return ageIndex;
}

MYNODE **createNameIndex()
{
	MYNODE **nameIndex = NULL;
	int cnt = getNodeCount();
	nameIndex = malloc(sizeof(MYNODE *) * cnt);
	MYNODE *tmp = NULL;
	MYNODE *pCurrent = g_Head.pNext;
	
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
			if( strcmp(((USERDATA*)nameIndex[j]->pData)->name, ((USERDATA*)nameIndex[j+1]->pData)->name) > 0 )
			{
				tmp = nameIndex[j];
				nameIndex[j] = nameIndex[j + 1];
				nameIndex[j + 1] = tmp;
			}
		}
	}
	return nameIndex;
}

void printByIndex(MYNODE **index)
{
	int cnt = getNodeCount();
	printf("Name\tAge\tPhone\n");
	printf("=====================================\n");
	for (int i = 0; i < cnt; i++)
	{
		printf("%s\t%d\t%s\n", 
			((USERDATA*)index[i]->pData)->name, 
			((USERDATA*)index[i]->pData)->age, 
			((USERDATA*)index[i]->pData)->phone
			);
	}
	printf("\n");
}

MYNODE **searchByAgeIndex(MYNODE **index, const int min, const int max)
{
	MYNODE *minIndex;
	MYNODE *maxIndex;
	int idxCount = getNodeCount();
	int minPos = -1;
	int maxPos = -1;
	int cnt = 1;

	for (int i = 0; i < idxCount; i++)
	{
		if(((USERDATA*)index[i]->pData)->age >= min)
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
		if(((USERDATA*)index[j]->pData)->age > max)
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

	MYNODE **searchResult = malloc(sizeof(MYNODE *) * (maxPos - minPos + 2));
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
        printf("Rebuilding nameIndex..\n");
	nameIndex = createNameIndex();
}

void saveToFile(void)
{
	//g_Head 가져오기
	//->pNext부터 write
	//g_Tail이면 빠져나오기
	MYNODE *pCurrent = g_Head.pNext;
	FILE *fp = fopen("savedata.dat", "wb");
	
	int dataCount = getNodeCount();

	if (fp == NULL)
	{
		printf("Cannot open file savedata.dat to write data.\n");
		return;
	}

	fwrite(&dataCount, sizeof(int), 1, fp);
	
	while (pCurrent != &g_Tail)
	{
		fwrite(((USERDATA*)pCurrent->pData), sizeof(USERDATA), 1, fp);
		pCurrent = pCurrent->pNext;
	}

	printf("Finished save data to savedata.dat\n");

	fclose(fp);
}

void loadFromFile(void)
{
	MYNODE *pCurrent = g_Head.pNext;
	FILE *fp = fopen("savedata.dat", "rb");
	USERDATA loadedData;

	int dataCount = 0;
	

	if (fp == NULL)
	{
		printf("Cannot open file savedata.dat\n");
		return;
	}

	fread(&dataCount, sizeof(int), 1, fp);

	printf("Count of data from savedata.dat : %d\n", dataCount);

	for(int i = 0; i < dataCount; i++)
	{
		fread(&loadedData, sizeof(USERDATA), 1, fp);
		addNewNode(loadedData.name, loadedData.age, loadedData.phone);
	}

	rebuildIndexes();

	fclose(fp);

}

void checkSave(void)
{
	int saveIt = 0;

	while (saveIt == 0)
        {
                printf("Do you want to save current dataset into file?\n");
		printf("[1] : Yes / [2] : No > \n");
                scanf("%d", &saveIt);

                if (saveIt == 1)
                {
                        printf("Saving dataset into savedata.dat..\n");
                        saveToFile();
                }
                else if (saveIt == 2)
                {
                        printf("Skip saving dataset into savedata.dat..\n");
                }
                else
                {
                        printf("Invalid input. Please input proper character(Y/N).\n");
                        saveIt = 0;
                }
        }

}
