#include "GraphicsPipeline.h"
#include "Logger.h"



GraphicsPipeline::GraphicsPipeline(std::shared_ptr<LogicalDevice> TargetedDevice, std::shared_ptr<PipelineLayout> TargetedLayout, std::shared_ptr<RenderPass> TargetedRenderPass, std::shared_ptr<ShaderModules> TargetedShaderModules)
	:m_TargetDevice(TargetedDevice),m_TargetLayout(TargetedLayout), m_TargetRenderPass(TargetedRenderPass), m_TargetShaderModules(TargetedShaderModules)
{
	m_PipelineCreateInfo.sType = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO;

	m_PipelineCreateInfo.pVertexInputState = &m_FixedFuncs->m_vertexInputInfo;
	m_PipelineCreateInfo.pInputAssemblyState = &m_FixedFuncs->m_inputAssemblyCreateInfo;
	m_PipelineCreateInfo.pViewportState = &m_ViewportStateCreateInfo;
	m_PipelineCreateInfo.pRasterizationState = &m_FixedFuncs->m_RasterizerInfo;
	m_PipelineCreateInfo.pMultisampleState = &m_FixedFuncs->m_MultisamplingInfo;
	m_PipelineCreateInfo.pDepthStencilState = nullptr;
	m_PipelineCreateInfo.pColorBlendState = &m_FixedFuncs->m_colorBlendingStateInfo;
	m_PipelineCreateInfo.pDynamicState = nullptr;
}

void GraphicsPipeline::createGraphicsPipeline()
{	
	m_PipelineCreateInfo.stageCount = m_TargetShaderModules->getCurrentShaderModules().size();

	std::vector<VkPipelineShaderStageCreateInfo> tempStages;
	tempStages.reserve(m_PipelineCreateInfo.stageCount);
	for (auto& shaderModule : m_TargetShaderModules->getCurrentShaderModules())
	{
		tempStages.emplace_back(shaderModule.vkShaderStage);
	}

	m_PipelineCreateInfo.pStages = tempStages.data();
	m_PipelineCreateInfo.renderPass = m_TargetRenderPass->getvkRenderPass();
	m_PipelineCreateInfo.layout = m_TargetLayout->getvkPipelineLayout();

	VkViewport viewport{};
	viewport.x = 0.0f;
	viewport.y = 0.0f;
	viewport.width = (float)m_TargetRenderPass->getTargetedSwapchain()->getcurrentSwapchainExtent().width;
	viewport.height = (float)m_TargetRenderPass->getTargetedSwapchain()->getcurrentSwapchainExtent().height;
	viewport.minDepth = 0.0f;
	viewport.maxDepth = 1.0f;

	VkRect2D scissor{};
	scissor.offset = { 0, 0 };
	scissor.extent = m_TargetRenderPass->getTargetedSwapchain()->getcurrentSwapchainExtent();

	m_ViewportStateCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO;
	m_ViewportStateCreateInfo.viewportCount = 1;
	m_ViewportStateCreateInfo.pViewports = &viewport;
	m_ViewportStateCreateInfo.scissorCount = 1;
	m_ViewportStateCreateInfo.pScissors = &scissor;

	if (vkCreateGraphicsPipelines(m_TargetDevice->GetVkLogicalDevice(), VK_NULL_HANDLE, 1, &m_PipelineCreateInfo, nullptr, &m_vkPipeline) != VK_SUCCESS) 
	{
		RENDER_LOG_CRIT("failed to create graphics pipeline!");
	}
	else
	{
		RENDER_LOG_INFO("Succesfuly created graphics pipeline!");
	}
}

GraphicsPipeline::~GraphicsPipeline()
{
	vkDestroyPipeline(m_TargetDevice->GetVkLogicalDevice(), m_vkPipeline, nullptr);
}