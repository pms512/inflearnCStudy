#include <stdio.h>
#include "ui.h"
#include "init.h"
#include "test.h"
#include "funcs.h"

void addEvent(void)
{
	char addName[20];
	int addAge;
	char addPhone[15];

	printf("Input new name : ");
	scanf("%s", addName);
	printf("Input new age : ");
	scanf("%d", &addAge);
	printf("Input new phone : ");
	scanf("%s", addPhone);

	insertNode(addName, addAge, addPhone);

//	checkSave();

	rebuildIndexes();	
}

void updateEvent(void)
{
	char targetName[20];
	MYNODE *updateTarget = NULL;

	char updatedName[20];
	int updatedAge;
	char updatedPhone[15];

	printf("Input target name to be updated : ");
	scanf("%s", targetName);
	updateTarget = searchByName(targetName);

	if (updateTarget == NULL)
	{
		return;
	}
	printf("Input updated name : ");
	scanf("%s", updatedName);
	printf("Input new age : ");
	scanf("%d", &updatedAge);
	printf("Input new phone : ");
	scanf("%s", updatedPhone);

	updateNode(updateTarget, updatedName, updatedAge, updatedPhone);
	
//	checkSave();

	rebuildIndexes();	
}

void selectEvent(void)
{
	int min = 0;
	int max = 1;
	int tmp = 0;

	MYNODE **index = NULL;

	MYNODE **pResult = NULL;

	printf("Input age range : ");
	scanf("%d %d", &min, &max);

	if (min > max)
	{
		printf("Min value is greater than max value. Changing..\n");
		tmp = min;
		min = max;
		max = tmp;
	}
	printf("Min : %d, Max : %d\n", min, max);
	pResult = searchByAgeIndex(ageIndex, min, max);
	if (pResult != NULL)
	{
		printSearchedNodes(pResult);
	}
}

void deleteEvent(void)
{
	char targetName[20];
	int deleteResult;

	printf("Input name to delete : ");
	scanf("%s",targetName);
	deleteResult = deleteNode(targetName);
	
	if (deleteResult == 1) return;
	
//	checkSave();

	rebuildIndexes();
}

void exitEvent(void)
{
	printf("You called exitEvent function.\n\n");
}

void printAllEvent(void)
{
	printAllInfo();
	countAllEvent();
}

void countEvent(void)
{
	printf("COUNT : %d\n", getNodeCount());
}

void countAllEvent(void)
{
	printf("COUNT(ALL) : %d\n", getAllCount());
}

void printByAgeIndexEvent(void)
{
	printByIndex(ageIndex);
	countEvent();
}

void printByNameIndexEvent(void)
{
	printByIndex(nameIndex);
	countEvent();
}

void loadFromFileEvent(void)
{
	printf("You called loadFromFileEvent.\n");
	loadFromFile();
}

void saveToFileEvent(void)
{
	printf("You called seekNodeEvent.\n");
	saveToFile();
}

void seekNodeEvent(void)
{
	int nodeIndex;
	MYNODE *pResult;
	printf("Input number of node : ");
	scanf("%d", &nodeIndex);
	pResult = seekNode(nodeIndex);

	printf("Name : %s\nAge : %d\nPhone : %s\n",
			((USERDATA*)pResult->pData)->name,
			((USERDATA*)pResult->pData)->age,
			((USERDATA*)pResult->pData)->phone
	      );

}

void commitEvent(void)
{
	printf("You called commitEvent.\n");
	commit();
}

void eventLoop(void)
{
	int inputCommand;
	commandType command;
	while(command != EXIT)
	{
		printf("\n");
		printf("===================== [INPUT COMMAND NUMBER] =====================\n");
		printf("[1]Add\t\t\t[2]Update\t\t[3]Select        |\n");
	        printf("[4]PrintAllInfo\t\t[5]Delete\t\t[6]Count         |\n");
	        printf("[7]PrintByAgeIndex\t[8]PrintByNameIndex\t[9]LoadFromFile  |\n");
	        printf("[10]SeekNode\t\t[11]Commit\t\t[12]Exit         |\n");
		printf("==================================================================\n");
		printf("input>");
		scanf("%d", &inputCommand);

		if ( (inputCommand < 1) || (inputCommand > 12) )
		{
			printf("Invalid input. Please input proper value (1 ~ 11) \n");
			return;
		}
		else
		{		
			command = (commandType) inputCommand;

			switch(command)
			{
				case ADD:
					addEvent();
					break;
					
				case UPDATE:
					updateEvent();
					break;

				case SELECT:
					selectEvent();
					break;

				case PRINTALL:
					printAllEvent();
					break;

				case DELETE:
					deleteEvent();
					break;

				case COUNT:
					countEvent();
					break;

				case PRINTBYAGEINDEX:
					printByAgeIndexEvent();
					break;

				case PRINTBYNAMEINDEX:
					printByNameIndexEvent();
					break;
					
				case LOADFROMFILE:
					loadFromFileEvent();
					break;

				case SEEKNODE:
					seekNodeEvent();
					break;

				case COMMIT:
					commitEvent();
					break;

				case EXIT:
					exitEvent();
					break;

				default:
					printf("Invalid Input. Please input proper value.\n");
					break;
			}
		}
	}
}



