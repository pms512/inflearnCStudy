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

	addNewNode(addName, addAge, addPhone);
	
	rebuildIndexes();	
}

void updateEvent(void)
{
	char targetName[20];
	USERDATA *updateTarget = NULL;

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
	
	rebuildIndexes();	
}

void selectEvent(void)
{
	int min = 0;
	int max = 1;
	int tmp = 0;

	USERDATA **index = NULL;

	USERDATA **pResult = NULL;

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
/*
	//Using sort
	sortByAge();
	pResult = searchByAgeRange(min, max);
	printSearchedNodes(pResult);
*/

	//Using index
//	index = createAgeIndex();
	pResult = searchByAgeIndex(ageIndex, min, max);
	printSearchedNodes(pResult);
//	free(index);

}

void deleteEvent(void)
{
	char targetName[20];
	int deleteResult;
	printf("Input name to remove : ");
	scanf("%s",targetName);
	deleteResult = removeNode(targetName);
	
	if (deleteResult == 1) return;
	
	rebuildIndexes();
}

void exitEvent(void)
{
	printf("You called exitEvent function.\n\n");
}

void printAllEvent(void)
{
	printAllNodes();
}

void countEvent(void)
{
	printf("COUNT : %d\n", getNodeCount());
}

void printByAgeIndexEvent(void)
{
	printByIndex(ageIndex);
}

void printByNameIndexEvent(void)
{
	printByIndex(nameIndex);
}

void eventLoop(void)
{
	int inputCommand;
	commandType command;
	while(command != EXIT)
	{
		printf("[1]Add   [2]Update   [3]Select   [4]PrintAllNodes   [5]Delete   [6]Count   [7]PrintByAgeIndex    [8]PrintByNameIndex    [9]Exit\n");
		scanf("%d", &inputCommand);

		if ( (inputCommand < 1) || (inputCommand > 9) )
		{
			printf("Invalid input. Please input proper value (1 ~ 9) \n");
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



void testLoop(void)
{
	int testAction = 0;

	while(testAction != 4)
	{
		printf("[0]Push   [1]Pop   [2]Enqueue   [3]Dequeue   [4]Exit\n");
		scanf("%d", &testAction);

		switch(testAction)
		{
			case 0:
				test_push();
				break;
				
			case 1:
				test_pop();
				break;

			case 2:
				test_enqueue();
				break;

			case 3:
				test_dequeue();
				break;

			default:
				printf("Invalid Input. Please input proper value.\n");
				break;
		}
	}
	exitEvent();
}
