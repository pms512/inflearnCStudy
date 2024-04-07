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
	//addInitData();
	//testLoop();
	eventLoop();


	//test_sort1();
	//test_sort2();
	//test_sort3();
	//test_sort4();


	removeAllNodes();

	return 0;
}
