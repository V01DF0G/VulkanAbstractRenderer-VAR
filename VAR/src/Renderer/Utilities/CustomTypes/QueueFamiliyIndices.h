#pragma once
#include "Pch.h"

struct QueueFamilyIndices
{
	uint32_t graphicsFamily = (uint32_t)-1;
	uint32_t presentationFamily = (uint32_t)-1;
	

	bool isComplete()
	{
		return graphicsFamily != UINT32_MAX && presentationFamily != UINT32_MAX;
	}
};
