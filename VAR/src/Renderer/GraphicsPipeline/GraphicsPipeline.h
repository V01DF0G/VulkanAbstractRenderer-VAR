#pragma once

#include "Pch.h"
#include "Base/VulkanBase.h"
#include "PipelineLayout/PipelineLayout.h"
#include "ShaderModules/ShaderModules.h"
#include "RenderPass/RenderPass.h"
#include "Device/LogicalDevice.h"

class GraphicsPipeline
{
public:
	GraphicsPipeline(std::shared_ptr<LogicalDevice> TargetedDevice,std::shared_ptr<PipelineLayout> TargetedLayout, std::shared_ptr<RenderPass> TargetedRenderPass, std::shared_ptr<ShaderModules> TargetedShaderModules);
	void createGraphicsPipeline();
	~GraphicsPipeline();


	inline VkPipeline getvkPipeline() const { return m_vkPipeline; }
private:
	std::shared_ptr<LogicalDevice> m_TargetDevice = nullptr;
	std::shared_ptr<PipelineLayout> m_TargetLayout = nullptr;
	std::shared_ptr<RenderPass> m_TargetRenderPass = nullptr;
	std::shared_ptr<ShaderModules> m_TargetShaderModules = nullptr;

	VkGraphicsPipelineCreateInfo m_PipelineCreateInfo = {};
	VkPipeline m_vkPipeline = VK_NULL_HANDLE;

	//Fixed Funcs
	VkPipelineVertexInputStateCreateInfo m_vertexInputInfo{};
	VkPipelineInputAssemblyStateCreateInfo m_inputAssemblyCreateInfo{};
	VkPipelineViewportStateCreateInfo m_ViewportStateCreateInfo{};
	VkPipelineRasterizationStateCreateInfo m_RasterizerInfo{};
	VkPipelineMultisampleStateCreateInfo m_MultisamplingInfo{};
	VkPipelineColorBlendAttachmentState m_colorBlendAttachmentInfo{};
	VkPipelineColorBlendStateCreateInfo m_colorBlendingStateInfo{};
	VkPipelineDynamicStateCreateInfo m_dynamicStateCreateInfo{};

	//FixedFunc functors
	void fillFixedFuncs();

};