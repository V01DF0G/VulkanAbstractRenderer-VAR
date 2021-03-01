#pragma once
#include "Pch.h"
#include "Base/VulkanBase.h"
#include "Device/PhysicalDevice.h"
#include "Device/LogicalDevice.h"
#include "RenderPass/RenderPass.h"
#include "Rendering/FrameBuffers/FrameBufferPool.h"
#include "GraphicsPipeline/GraphicsPipeline.h"



class CommandBufferPool
{
public:
	CommandBufferPool(std::shared_ptr<LogicalDevice> TargetedDevice, std::shared_ptr<PhysicalDevices> TargetedPhysDevs, std::shared_ptr<RenderPass> TargetedRenderPass, std::shared_ptr<FrameBufferPool> TargetedFrameBuffer, std::shared_ptr<GraphicsPipeline> TargetedGraphicsPipeline);
	~CommandBufferPool();

	void createCommandPool();
	void createCommandBuffers();
	void startCommandBufferRecord();
	void startTargetedRenderPass();

	std::vector<VkCommandBuffer> getCommandBuffers() const { return m_CommandBuffers; }
private:
	std::shared_ptr<LogicalDevice> m_TargetDevice = nullptr;
	std::shared_ptr<RenderPass> m_TargetRenderPass = nullptr;
	std::shared_ptr<PhysicalDevices> m_TargetPhysicalDevice = nullptr;
	std::shared_ptr<FrameBufferPool> m_TargetFrameBufferPool = nullptr;
	std::shared_ptr<GraphicsPipeline> m_TargetGraphicsPipeline = nullptr;

	VkCommandPool m_CommandPool;
	VkCommandPoolCreateInfo m_CommandPoolInfo = {};

	VkCommandBufferAllocateInfo m_CommandBufferAllocInfo = {};
	std::vector<VkCommandBuffer> m_CommandBuffers;

	VkCommandBufferBeginInfo m_commandBufferBeginInfo = {};

	VkRenderPassBeginInfo m_TargetedRenderPassBeginInfo = {};
	
};