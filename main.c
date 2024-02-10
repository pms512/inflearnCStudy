#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "init.h"
#include "test.h"
#include "funcs.h"
#include "ui.h"

int main()
{
	initData();
	/*
	printf("=====================================================================================\n");
	test_push();
	printf("=====================================================================================\n");
	test_pop();
	printf("=====================================================================================\n");
	test_enqueue();
	printf("=====================================================================================\n");
	test_dequeue();
	printf("===================================[END OF TEST]=====================================\n");
	*/

	testLoop();
	//eventLoop();

	removeAllNodes();

	return 0;
}
