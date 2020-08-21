#include "stdafx.h"
#include "commandProcessor.h"

const unsigned long CMD_ID_TABLE[] = {CMD_SETUP_SERVICE,
									  CMD_DELETE_SERVICE,
									  CMD_START_SERVICE,
									  CMD_STOP_SERVICE,
									  CMD_WRITE,
									  CMD_OPEN,
									  CMD_CLOSE, 
									  CMD_QUIT};
		
const char* CMD_NAME_TABLE[] =   {"ss"   , 
								  "ds"   , 
								  "start", 
								  "stop" , 
								  "write",
								  "open",
								  "close", 
								  "quit"};

unsigned int translateCommand(char* command)
{
	int tblCmdSize = sizeof(CMD_ID_TABLE) / sizeof(unsigned long);
	int tblCmdName = sizeof(CMD_NAME_TABLE) / sizeof(char*);

	for(unsigned int i = 0; i < tblCmdSize && i < tblCmdName; i++)
		if(!strcmp(command, CMD_NAME_TABLE[i]))
			return CMD_ID_TABLE[i];

	return CMD_UNKNOWN_COMMAND;
}

int processCommand(char* command)
{
	static HANDLE hFileHandle = INVALID_HANDLE_VALUE;

	char buffer[200];
	ZeroMemory(&buffer, 200);
	switch(translateCommand(command))
	{
		case CMD_SETUP_SERVICE:
			scanf("%s", buffer);
			createService("MYDRIVER3", buffer, true);
			break;

		case CMD_DELETE_SERVICE:
			scanf("%s", buffer);
			deleteService(buffer);
			break;

		case CMD_START_SERVICE:
			scanf("%s", buffer);
			startService(buffer);
			break;

		case CMD_STOP_SERVICE:
			scanf("%s", buffer);
			stopService(buffer);
			break;

		case CMD_OPEN:
			scanf("%s", buffer);
			hFileHandle = GetHandleToIo(buffer);
			break;

		case CMD_CLOSE:
			CloseIoHandle(hFileHandle);
			break;

		case CMD_WRITE:
			scanf("%[^\n\t]s", buffer);
			WriteToDevice(hFileHandle, buffer); 
			break;

		case CMD_QUIT:
			return 0;
			break;

		default:
			printf("Unknown command inserted..\n");
	}
	return 1;
}