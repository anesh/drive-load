#pragma once
#include <windows.h>

HANDLE GetHandleToIo(char* deviceName);
int    CloseIoHandle(HANDLE hIo);
int    WriteToDevice(HANDLE hDevice, char* inBuffer);

