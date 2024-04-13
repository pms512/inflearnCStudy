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
//	addInitData();
	eventLoop();
	removeEverything();

	return 0;
}
