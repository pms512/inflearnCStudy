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
