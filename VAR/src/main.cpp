#include "Pch.h"
#include "Logger/Logger.h"
#include "Base/VulkanBase.h"
#include "Renderer/Renderer.h"

GLFWwindow* window;

void initWindow(const char* Title, int width, int height)
{
	// Initialize GLFW
	glfwInit();

	// Set GLFW to NOT work with OpenGL
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	window = glfwCreateWindow(width, height, Title, nullptr, nullptr);
}

int main()
{
	Log::init();

	initWindow("Test Window", 1280, 720);

	RENDER_LOG_ERR("TEST" "Test");
	RENDER_LOG_WARN("Test1");

	Renderer a;

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
	}

	//system("pause");



	return 0;
}