#include <stdio.h>
#include <stdlib.h>

typedef struct _USERDATA {
	char name[20];
	int age;
	char phone[14];
	struct _USERDATA *pNext;
} USERDATA;

int main()
{
	USERDATA *pUser;
	USERDATA person[3] = {
		{"ABCD", 20, "010-1234-5678", NULL},
		{"EFGH", 25, "010-2345-6789", NULL},
		{"IJKL", 30, "010-3456-7890", NULL}
	};

	person[0].pNext = &person[1];
	person[1].pNext = &person[2];
	person[2].pNext = NULL;

	pUser = &person[0];


	while( pUser != NULL )
	{
		printf("[%p] %s %d %s [%p]\n", pUser, pUser->name, pUser->age, pUser->phone, pUser->pNext);
		pUser = pUser->pNext;
	}	
	

	return 0;
}

