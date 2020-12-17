#include "Pch.h"
#include "Logger.h"

std::shared_ptr<spdlog::logger> Log::RenderLogger;

void Log::init()
{
	RenderLogger = spdlog::stdout_color_mt("RENDER");
	spdlog::set_pattern("%^[%T][%s|%!:%#] %n: %v%$");
	RenderLogger->set_level(spdlog::level::trace);
}
