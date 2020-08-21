#pragma once
#define PARAM_CLIP_CHAR '\\'

struct Msg
{
	char command[80];
	char param1[80];
	char param2[80];
	char param3[80];
}Msg;

int  StringToMsg(Msg* msg, char* charBuffer);