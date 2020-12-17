#include "../Logger/Logger.h"
#include "ValidationLayers.h"



ValidationLayer::~ValidationLayer()
{
	DestroyDebugUtilsMessengerEXT(debugMessenger, nullptr);
	RENDER_LOG_INFO("Destruction of the validation layer was successful !");
}


