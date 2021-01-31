#pragma once

#include <Pch.h>
#include <Base/VulkanBase.h>


struct SwapchainSupportDetails
{
	VkSurfaceCapabilitiesKHR Surfacecapabilities = {};
	std::vector<VkSurfaceFormatKHR> Surfaceformats = {};
	std::vector<VkPresentModeKHR> presentationModes = {};

	inline bool SwapchainSupported() { return !Surfaceformats.empty() && !presentationModes.empty(); };
	
};
