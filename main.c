#include <stdio.h>
#include <string.h>

typedef enum command { ADD, UPDATE, SELECT, DELETE, EXIT } command;

void addEvent(void);
void updateEvent(void);
void selectEvent(void);
void deleteEvent(void);
void exitEvent(void);

int main()
{
	command inputCommand = 0;

	while( inputCommand != EXIT )
	{
		printf("[[INPUT COMMAND]]\n");
		printf("[0] add\t[1] update\t[2] select\t[3] delete\t[4] exit\n");
		scanf("%d", &inputCommand);

		switch(inputCommand)
		{
			case ADD :
				addEvent();
				break;
			case UPDATE :
				updateEvent();
				break;
			case SELECT :
				selectEvent();
				break;
			case DELETE :
				deleteEvent();
				break;
			case EXIT:
				exitEvent();
				break;
			default:
				printf("Invalid input. Please input proper value.\n\n");
				break;
		}

	}
	return 0;

}
