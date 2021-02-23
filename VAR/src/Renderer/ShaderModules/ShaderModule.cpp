#include "ShaderModule.h"
#include "Logger.h"

constexpr unsigned int stringtoint(const char* str, int h = 0) // Hash function
{
	return !str[h] ? 5381 : (stringtoint(str, h + 1) * 33) ^ str[h];
}

ShaderModule::ShaderModule(std::shared_ptr<LogicalDevice> TargetedDevice, const char* TargetSpvFileLoc)
	:m_TargetedDevice(TargetedDevice), m_TargetedLocation(TargetSpvFileLoc)
{
	shaderModuleCreateInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
	shaderModuleCreateInfo.pCode = reinterpret_cast<const uint32_t*>(FileManUtils::readFile(m_TargetedLocation, shaderModuleCreateInfo.codeSize));

	shaderStageCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
	shaderStageCreateInfo.stage = getshaderType();
	shaderStageCreateInfo.pName = "main";
}

void ShaderModule::createShaderModule()
{
	if (vkCreateShaderModule(m_TargetedDevice->GetVkLogicalDevice(), &shaderModuleCreateInfo, nullptr, &m_vkShaderModule) != VK_SUCCESS)
	{
		RENDER_LOG_CRIT("failed to create shader module!")
	}
	{
		RENDER_LOG_INFO("ShaderModule was Created Succesfully!");
	}
	shaderStageCreateInfo.module = m_vkShaderModule;
}

ShaderModule::~ShaderModule()
{
	vkDestroyShaderModule(m_TargetedDevice->GetVkLogicalDevice(), m_vkShaderModule, nullptr);
}

VkShaderStageFlagBits ShaderModule::getshaderType()
{
	const char* filename = strrchr(m_TargetedLocation, '/'); // Cleaning up the location and getting only the filename which contain proper delimiters.
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
