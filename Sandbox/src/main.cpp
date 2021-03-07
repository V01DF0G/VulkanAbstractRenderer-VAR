#include "Renderer/Renderer.h"


int main()
{
	std::vector<const char*> shaderList = { "./src/Shaders/Compiled/Vertex/test.vert.spv", "./src/Shaders/Compiled/Fragment/test.frag.spv" };
	VAR_CORE::VAR_SIMPLE_RENDERER::Renderer a;
	a.setShaderLocs(shaderList);
	a.AllocateRendererObjects();
	a.Init();

	return 0;
}