#pragma once

#include "Pch.h"
#include "VulkanBase.h"
#include "Instance.h"
#include "PhysicalDevice.h"
#include "LogicalDevice.h"


class Renderer
{
public:
	Renderer();



	virtual ~Renderer();

private:
	std::shared_ptr<Instance> m_instance = nullptr;
	std::shared_ptr<PhysicalDevices> m_physicalDevice = nullptr;
	std::shared_ptr<LogicalDevice> m_LogicalDevice = nullptr;

};