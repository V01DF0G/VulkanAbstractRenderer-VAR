#include "Pch.h"
#include "readFile.h"
#include "Logger.h"

const char* FileManUtils::readFile(const char* filepath, size_t &length)
{
	
	FILE* fp = fopen(filepath, "rb");
	if (fp == NULL)
	{
		RENDER_LOG_CRIT("failed to open file {0}", filepath);
	}
	fseek(fp, 0, SEEK_END);
	length = ftell(fp);
	char* promisedString = (char*)malloc(length);
	fseek(fp, 0, SEEK_SET);
	fread(promisedString, sizeof(char), length, fp);
	fclose(fp);



	return promisedString;
}

