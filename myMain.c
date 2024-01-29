#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _USERDATA {
	char name[20];
	int age;
	char phone[14];
	struct _USERDATA *pNext;
} USERDATA;

void printData(USERDATA *pUser);
void saveData(USERDATA *pUser, FILE *fp);
void loadData(USERDATA *pUser, FILE *fp);

int main()
{
	USERDATA *pUser;
	USERDATA person[3] = {
		{"ABCD", 20, "010-1234-5678", NULL},
		{"EFGH", 25, "010-2345-6789", NULL},
		{"IJKL", 30, "010-3456-7890", NULL}
	};
	USERDATA person2[3];

	FILE *fp = NULL;
	
	fp = fopen("linkedlist.bin", "wb");

	person[0].pNext = &person[1];
	person[1].pNext = &person[2];
	person[2].pNext = NULL;

	pUser = &person[0];


	printf("========[INITIAL DATA]========\n");
	
	printData(pUser);

	printf("========[SAVING DATA INTO BINARY FILE]========\n");
	
	saveData(pUser, fp);

	printData(pUser);
	
	printf("========[LOADING DATA INTO PERSON2 USING BINARY FILE]========\n");
	
	FILE *fpLoad = NULL;
	fpLoad = fopen("linkedlist.bin", "rb");
	USERDATA *pUser2;

	pUser2 = &person2[0];

	loadData(pUser2, fpLoad);

	printData(pUser);

	fclose(fpLoad);
		
	fclose(fp);

	return 0;
}

void saveData(USERDATA *pUser, FILE *fp)
{
	while (pUser->pNext != NULL)
	{
		fwrite(pUser, sizeof(USERDATA), 1, fp);
		pUser = pUser->pNext;
	}
}

void loadData(USERDATA *pUser, FILE *fp)
{
	//use fread
	fread(pUser, sizeof(USERDATA), 3, fp);
	printf("loadData\n");
}

void printData(USERDATA *pUser)
{
	while (pUser->pNext != NULL)
	{
		printf("Name : %s, age : %d, phone : %s\n", pUser->name, pUser->age, pUser->phone);
		pUser = pUser->pNext;
	}
}
