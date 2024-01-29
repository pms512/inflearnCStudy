#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _USERDATA {
	char name[20];
	int age;
	char phone[14];
	struct _USERDATA *pNext;
} USERDATA;

int LoadList()
{
	FILE *fp = NULL;
	fp = fopen("listData.dat", "rb");
	if (fp == NULL)
	{
		puts("ERROR : Failed to open listData.dat");
		return 0;
	}

	USERDATA user = { 0, };
	while (fread(&user, sizeof(USERDATA), 1, fp) > 0)
	{
		printf("%s, %d, %s\n",
			user.name, user.age, user.phone);
		memset(&user, 0, sizeof(USERDATA));
	}
	fclose(fp);

}
int main()
{
	USERDATA person[3] = {
		{"ABCD", 20, "010-1234-5678", NULL},
		{"EFGH", 25, "010-2345-6789", NULL},
		{"IJKL", 30, "010-3456-7890", NULL}
	};

	person[0].pNext = &person[1];
	person[1].pNext = &person[2];
	person[2].pNext = NULL;

	FILE *fp = NULL;
	fp = fopen("listData.dat", "wb");
	if (fp == NULL)
	{
		puts("ERROR : Failed to open listData.dat\n");
		return 0;
	}

	USERDATA* pUser = &person[0];
	while (pUser != NULL)
	{
		fwrite(pUser, sizeof(USERDATA), 1, fp);
		pUser = pUser->pNext;
	}
	fclose(fp);

	LoadList();
	return 0;

}
