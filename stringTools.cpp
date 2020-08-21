#include "stdafx.h"
#include "stringTools.h"
int getParam(char* source, char* out, unsigned int outSize, unsigned int param, char clipChar) 
{
	
	unsigned int clipCount  = 0;
	unsigned int bufCount   = 0;
	unsigned int i          = 0;
	unsigned int len        = 0;

	char* buffer;


	buffer = out;

	len = strlen(source);
	
	ZeroMemory(buffer, outSize);

	
	for(i = 0; i < len; i++) {

		if(bufCount > outSize - 1)
			return -1;

		if(source[i] == clipChar) {
			clipCount++;
			continue;
		}

		if(clipCount == param) {
			buffer[bufCount] = source[i];
			bufCount++;
		}else if(clipCount >= param)
			break;
	}

	if(clipCount < param)
	{
		buffer[0] = 0;
		return -1;
	}

	return 1;
}