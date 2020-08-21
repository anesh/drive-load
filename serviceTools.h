#pragma once
#include <stdio.h>
#include <windows.h>

int createService(char* serviceName, char* executablePath, bool relative);
int startService(char* serviceName);
int stopService(char* serviceName);
int deleteService(char* serviceName);