#include <stdio.h>
#include "ui.h"
#include "test.h"
#include "funcs.h"

void addEvent(void)
{
	printf("You called addEvent function.\n\n");
}

void updateEvent(void)
{
	printf("You called updateEvent function.\n\n");
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
	index = createAgeIndex();
	pResult = searchByAgeIndex(index, min, max);
	printSearchedNodes(pResult);
	free(index);

}

void deleteEvent(void)
{
	printf("You called deleteEvent function.\n\n");
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

void eventLoop(void)
{
	commandType command = 0;
	while(command != EXIT)
	{
		printf("[0]Add   [1]Update   [2]Select   [3]PrintAllNodes   [4]Delete   [5]Count   [6]Exit\n");
		scanf("%d", &command);
		
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

			case EXIT:
				exitEvent();
				break;

			default:
				printf("Invalid Input. Please input proper value.\n");
				break;
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
