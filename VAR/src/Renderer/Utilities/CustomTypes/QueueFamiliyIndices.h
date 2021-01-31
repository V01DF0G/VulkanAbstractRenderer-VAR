#pragma once
#include "Pch.h"

struct QueueFamilyIndices
{
	uint32_t graphicsFamily = -1;
	uint32_t presentationFamily = -1;
	

	bool isComplete()
	{
		return graphicsFamily != UINT32_MAX && presentationFamily != UINT32_MAX;
	}
};
