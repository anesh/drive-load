// tutDriverConsole.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "commandProcessor.h"

int main(int argc, char* argv[])
{
	char buffer[200];
	int ret;

	do
	{
		printf("\n   >>");
		scanf("%200s", buffer);
		ret = processCommand(buffer);
	}while(ret);
	return 0;
}

