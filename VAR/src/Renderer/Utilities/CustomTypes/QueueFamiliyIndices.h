#pragma once
#include "Pch.h"

struct QueueFamilyIndices
{
	std::optional<uint32_t> graphicsFamily;
	//std::optional<uint32_t> presentationFamily;
	

	bool isComplete()
	{
		return graphicsFamily.has_value();// && presentationFamily.has_value();
	}
};
