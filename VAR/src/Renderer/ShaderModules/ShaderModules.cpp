#include "ShaderModules.h"
#include "Logger.h"

constexpr unsigned int stringtoint(const char* str, int h = 0) // Hash function
{
	return !str[h] ? 5381 : (stringtoint(str, h + 1) * 33) ^ str[h];
}

ShaderModules::ShaderModules(std::shared_ptr<LogicalDevice> TargetedDevice, std::vector<const char*> TargetSpvFileLocs)
	:m_TargetedDevice(TargetedDevice)
{
	m_currentShaderModules.resize(TargetSpvFileLocs.size());
	for (size_t i = 0; i < TargetSpvFileLocs.size(); i++)
	{
		m_currentShaderModules[i].vkShaderModuleCreateinfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
		m_currentShaderModules[i].vkShaderModuleCreateinfo.pCode = reinterpret_cast<const uint32_t*>(FileManUtils::readFile(TargetSpvFileLocs[i], m_currentShaderModules[i].vkShaderModuleCreateinfo.codeSize));

		m_currentShaderModules[i].vkShaderStage.sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
		m_currentShaderModules[i].vkShaderStage.stage = getshaderType(TargetSpvFileLocs[i]);
		m_currentShaderModules[i].vkShaderStage.pName = "main";
	}
}

void ShaderModules::createShaderModules()
{
	for(auto& shaderModule : m_currentShaderModules)
	{
		if (vkCreateShaderModule(m_TargetedDevice->GetVkLogicalDevice(), &shaderModule.vkShaderModuleCreateinfo, nullptr, &shaderModule.vkShaderModule) != VK_SUCCESS)
		{
			RENDER_LOG_CRIT("failed to create shader module!")
		}
		else
		{
			RENDER_LOG_INFO("ShaderModule was Created Succesfully!");
		}
		shaderModule.vkShaderStage.module = shaderModule.vkShaderModule;
	}
}

ShaderModules::~ShaderModules()
{
	for (auto& shaderModule : m_currentShaderModules)
	{
		vkDestroyShaderModule(m_TargetedDevice->GetVkLogicalDevice(), shaderModule.vkShaderModule, nullptr);
	}
}

VkShaderStageFlagBits ShaderModules::getshaderType(const char* fileLocation)
{
	const char* filename = strrchr(fileLocation, '/'); // Cleaning up the location and getting only the filename which contain proper delimiters.
	switch (stringtoint(FileManUtils::getShaderTypeString(filename)))
	{
	case stringtoint("vert"):
		return VK_SHADER_STAGE_VERTEX_BIT;

	case stringtoint("frag"):
		return VK_SHADER_STAGE_FRAGMENT_BIT;

	case stringtoint("comp"):
		return VK_SHADER_STAGE_COMPUTE_BIT;

	case stringtoint("geom"):
		return VK_SHADER_STAGE_GEOMETRY_BIT;

	case stringtoint("tesc"):
		return VK_SHADER_STAGE_TESSELLATION_CONTROL_BIT;

	case stringtoint("tese"):
		return VK_SHADER_STAGE_TESSELLATION_EVALUATION_BIT;

	default:
		RENDER_LOG_ERR("Unknown shaderType!");
		return VK_SHADER_STAGE_FLAG_BITS_MAX_ENUM;
	}
}
