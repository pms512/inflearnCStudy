#include <stdio.h>
#include "ui.h"
#include "test.h"

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
	printf("You called selectEvent function.\n\n");
}

void deleteEvent(void)
{
	printf("You called deleteEvent function.\n\n");
}

void exitEvent(void)
{
	printf("You called exitEvent function.\n\n");
}

void eventLoop(void)
{
	actionType action;

	while(action != EXIT)
	{
		printf("[0]Add   [1]Update   [2]Select   [3]Delete   [4]Exit\n");
		scanf("%d", &action);

		switch(action)
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

			case DELETE:
				deleteEvent();
				break;

			default:
				printf("Invalid Input. Please input proper value.\n");
				break;
		}
	}
	exitEvent();
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
