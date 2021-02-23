#include "Pch.h"
#include "Base/VulkanBase.h"
#include "Device/LogicalDevice.h"
#include "Utilities/FileManagment/readFile.h"
#include "Utilities/FileManagment/GetShaderTypeString.h"


class ShaderModule
{
public:
	ShaderModule(std::shared_ptr<LogicalDevice> TargetedDevice, const char* TargetSpvFileLoc);
	void createShaderModule();
	virtual ~ShaderModule();

	inline const char* getTargetLocation() { return m_TargetedLocation; }
private:
	std::shared_ptr<LogicalDevice> m_TargetedDevice = VK_NULL_HANDLE;
	const char* m_TargetedLocation;
	VkShaderModule m_vkShaderModule = VK_NULL_HANDLE;
	VkShaderModuleCreateInfo shaderModuleCreateInfo = {};
	VkPipelineShaderStageCreateInfo shaderStageCreateInfo = {};



	inline VkShaderStageFlagBits getshaderType();
};