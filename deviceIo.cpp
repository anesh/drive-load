#include "stdafx.h"
#include "deviceIo.h"

HANDLE GetHandleToIo(char* deviceName)
{
	return (HANDLE)CreateFile(deviceName, 
							  GENERIC_READ | GENERIC_WRITE,
							  0,
							  0,
							  OPEN_EXISTING, 
							  0,
							  0);
}

int CloseIoHandle(HANDLE hIo)
{
	if(hIo == INVALID_HANDLE_VALUE)
		return -1;
	else
		CloseHandle(hIo);

	return 1;
}

int WriteToDevice(HANDLE hDevice, char* inBuffer)
{
	WriteFile(hDevice, inBuffer, strlen(inBuffer) + 1, 0, 0);
	return 1;
}
