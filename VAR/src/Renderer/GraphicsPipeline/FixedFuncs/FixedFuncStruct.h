#pragma once

#include "Pch.h"
#include "Base/VulkanBase.h"


//First iteration of the fixed function abstratctization

struct FixedFuncStruct
{
	FixedFuncStruct()
	{
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
		VK_DYNAMIC_STATE_LINE_WIDTH,
		};

		m_dynamicStateCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO;
		m_dynamicStateCreateInfo.dynamicStateCount = 2;
		m_dynamicStateCreateInfo.pDynamicStates = dynamicStates;
	}; //Default Constructor

	VkPipelineVertexInputStateCreateInfo m_vertexInputInfo = {};
	VkPipelineInputAssemblyStateCreateInfo m_inputAssemblyCreateInfo = {};
	VkPipelineRasterizationStateCreateInfo m_RasterizerInfo = {};
	VkPipelineMultisampleStateCreateInfo m_MultisamplingInfo = {};
	VkPipelineColorBlendAttachmentState m_colorBlendAttachmentInfo = {};
	VkPipelineColorBlendStateCreateInfo m_colorBlendingStateInfo = {};
	VkPipelineDynamicStateCreateInfo m_dynamicStateCreateInfo = {};

};
