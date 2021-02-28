#include "GraphicsPipeline.h"
#include "Logger.h"



GraphicsPipeline::GraphicsPipeline(std::shared_ptr<LogicalDevice> TargetedDevice, std::shared_ptr<PipelineLayout> TargetedLayout, std::shared_ptr<RenderPass> TargetedRenderPass, std::shared_ptr<ShaderModules> TargetedShaderModules)
	:m_TargetDevice(TargetedDevice),m_TargetLayout(TargetedLayout), m_TargetRenderPass(TargetedRenderPass), m_TargetShaderModules(TargetedShaderModules)
{
	fillFixedFuncs();

	m_PipelineCreateInfo.sType = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO;

	m_PipelineCreateInfo.pVertexInputState = &m_vertexInputInfo;
	m_PipelineCreateInfo.pInputAssemblyState = &m_inputAssemblyCreateInfo;
	m_PipelineCreateInfo.pViewportState = &m_ViewportStateCreateInfo;
	m_PipelineCreateInfo.pRasterizationState = &m_RasterizerInfo;
	m_PipelineCreateInfo.pMultisampleState = &m_MultisamplingInfo;
	m_PipelineCreateInfo.pDepthStencilState = nullptr;
	m_PipelineCreateInfo.pColorBlendState = &m_colorBlendingStateInfo;
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

void GraphicsPipeline::fillFixedFuncs()
{
	//This function is temporary solution to fixed function parameter filling it will be replaced with something better in the future.

	m_vertexInputInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO;
	m_vertexInputInfo.vertexBindingDescriptionCount = 0;
	m_vertexInputInfo.pVertexBindingDescriptions = nullptr; // Optional
	m_vertexInputInfo.vertexAttributeDescriptionCount = 0;
	m_vertexInputInfo.pVertexAttributeDescriptions = nullptr; // Optional

	m_inputAssemblyCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO;
	m_inputAssemblyCreateInfo.topology = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;
	m_inputAssemblyCreateInfo.primitiveRestartEnable = VK_FALSE;

	m_RasterizerInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO;
	m_RasterizerInfo.depthClampEnable = VK_FALSE;
	m_RasterizerInfo.rasterizerDiscardEnable = VK_FALSE;
	m_RasterizerInfo.polygonMode = VK_POLYGON_MODE_FILL;
	m_RasterizerInfo.lineWidth = 1.0f;
	m_RasterizerInfo.cullMode = VK_CULL_MODE_BACK_BIT;
	m_RasterizerInfo.frontFace = VK_FRONT_FACE_CLOCKWISE;
	m_RasterizerInfo.depthBiasEnable = VK_FALSE;
	m_RasterizerInfo.depthBiasConstantFactor = 0.0f;
	m_RasterizerInfo.depthBiasClamp = 0.0f;
	m_RasterizerInfo.depthBiasSlopeFactor = 0.0f;

	m_MultisamplingInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO;
	m_MultisamplingInfo.sampleShadingEnable = VK_FALSE;
	m_MultisamplingInfo.rasterizationSamples = VK_SAMPLE_COUNT_1_BIT;
	m_MultisamplingInfo.minSampleShading = 1.0f; // Optional
	m_MultisamplingInfo.pSampleMask = nullptr; // Optional
	m_MultisamplingInfo.alphaToCoverageEnable = VK_FALSE; // Optional
	m_MultisamplingInfo.alphaToOneEnable = VK_FALSE; // Optional
	
	m_colorBlendAttachmentInfo.colorWriteMask = VK_COLOR_COMPONENT_R_BIT | VK_COLOR_COMPONENT_G_BIT | VK_COLOR_COMPONENT_B_BIT | VK_COLOR_COMPONENT_A_BIT;
	m_colorBlendAttachmentInfo.blendEnable = VK_TRUE;
	m_colorBlendAttachmentInfo.srcColorBlendFactor = VK_BLEND_FACTOR_SRC_ALPHA;
	m_colorBlendAttachmentInfo.dstColorBlendFactor = VK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA;
	m_colorBlendAttachmentInfo.colorBlendOp = VK_BLEND_OP_ADD;
	m_colorBlendAttachmentInfo.srcAlphaBlendFactor = VK_BLEND_FACTOR_ONE;
	m_colorBlendAttachmentInfo.dstAlphaBlendFactor = VK_BLEND_FACTOR_ZERO;
	m_colorBlendAttachmentInfo.alphaBlendOp = VK_BLEND_OP_ADD;

	m_colorBlendingStateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO;
	m_colorBlendingStateInfo.logicOpEnable = VK_FALSE;
	m_colorBlendingStateInfo.logicOp = VK_LOGIC_OP_COPY; // Optional
	m_colorBlendingStateInfo.attachmentCount = 1;
	m_colorBlendingStateInfo.pAttachments = &m_colorBlendAttachmentInfo;
	m_colorBlendingStateInfo.blendConstants[0] = 0.0f; // Optional
	m_colorBlendingStateInfo.blendConstants[1] = 0.0f; // Optional
	m_colorBlendingStateInfo.blendConstants[2] = 0.0f; // Optional
	m_colorBlendingStateInfo.blendConstants[3] = 0.0f; // Optional

	VkDynamicState dynamicStates[] = {
	VK_DYNAMIC_STATE_VIEWPORT,
	VK_DYNAMIC_STATE_LINE_WIDTH
	};

	m_dynamicStateCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO;
	m_dynamicStateCreateInfo.dynamicStateCount = 2;
	m_dynamicStateCreateInfo.pDynamicStates = dynamicStates;
}
