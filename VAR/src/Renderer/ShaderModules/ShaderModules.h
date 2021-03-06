#pragma once

#include "Pch.h"
#include "Base/VulkanBase.h"
#include "Device/LogicalDevice.h"
#include "Utilities/FileManagment/readFile.h"
#include "Utilities/FileManagment/GetShaderTypeString.h"

namespace VAR_CORE
{
	struct ShaderModule // Basis of all shader modules;
	{
		const char* Location;
		VkShaderModule vkShaderModule;
		VkShaderModuleCreateInfo vkShaderModuleCreateinfo;
		VkPipelineShaderStageCreateInfo vkShaderStage;
	};
	
	class ShaderModules
	{
	public:
	
		ShaderModules(std::shared_ptr<LogicalDevice> TargetedDevice, std::vector<const char*> TargetSpvFileLocs);
		void createShaderModules();
		virtual ~ShaderModules();
	
		
		std::vector<ShaderModule> getCurrentShaderModules() const { return m_currentShaderModules; }
	
	private:
		std::shared_ptr<LogicalDevice> m_TargetedDevice = nullptr;
		std::vector<ShaderModule> m_currentShaderModules;
	
	
	
		inline VkShaderStageFlagBits getshaderType(const char* fileLocation);
	
	};
}