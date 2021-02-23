#include "Pch.h"
#include "GetSuffix.h"



const char* FileManUtils::GetSuffix(const char* name)
{
	const char* dot = strchr(name, '.');
	if (!dot || dot == name) return "";
	return dot + 1;
}

