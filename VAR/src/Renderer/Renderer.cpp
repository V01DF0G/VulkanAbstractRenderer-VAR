#include "Pch.h"
#include "Renderer.h"
#include "Logger.h"

Renderer::Renderer()
{
	m_instance = std::make_shared<Instance>();
	m_physicalDevice = std::make_shared<PhysicalDevices>(m_instance->getVkInstance());
	RENDER_LOG_INFO(std::string("GPU: ") + std::string(m_physicalDevice->getDeviceProps().deviceName));
	m_LogicalDevice = std::make_shared<LogicalDevice>(m_instance,m_physicalDevice);
}

Renderer::~Renderer()
{
}
