#pragma once

#define CMD_UNKNOWN_COMMAND 0
#define CMD_SETUP_SERVICE   1
#define CMD_DELETE_SERVICE  2
#define CMD_START_SERVICE   3
#define CMD_STOP_SERVICE    4
#define CMD_WRITE           5
#define CMD_OPEN            6
#define CMD_CLOSE           7
#define CMD_QUIT            8

#include "serviceTools.h"
#include "deviceIo.h"

unsigned int translateCommand(char* command);
int processCommand(char* command);