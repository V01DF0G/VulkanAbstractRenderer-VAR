#include "GetShaderTypeString.h"



const char* FileManUtils::getShaderTypeString(const char* file)
{
	char* ptr = strdup(file);

	ptr = strchr(ptr, '.') + 1;
	if (strchr(ptr, '.') != NULL)
	{
		char** ptr1 = NULL;
		ptr1 = (char**)strchr(ptr, '.');
		*ptr1 = '\0';
	}
	
	return ptr;
}
