#include <iostream>
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#include <spdlog/sinks/stdout_sinks.h>
#include <spdlog/sinks/stdout_color_sinks.h>


class Log
{
public:
	static void init();
	static std::shared_ptr<spdlog::logger>& getRenderLogger() { return RenderLogger; };
private:
	static std::shared_ptr<spdlog::logger> RenderLogger;
};


#define RENDER_LOG_ERR(...) ::Log::getRenderLogger()->log(spdlog::source_loc{__FILE__, __LINE__,SPDLOG_FUNCTION},spdlog::level::err, __VA_ARGS__ )
#define RENDER_LOG_CRIT(...) ::Log::getRenderLogger()->log(spdlog::source_loc{__FILE__, __LINE__,SPDLOG_FUNCTION},spdlog::level::critical, __VA_ARGS__ ); {exit(1);}
#define RENDER_LOG_WARN(...) ::Log::getRenderLogger()->log(spdlog::source_loc{__FILE__, __LINE__,SPDLOG_FUNCTION},spdlog::level::warn, __VA_ARGS__ )
#define RENDER_LOG_TRACE(...) ::Log::getRenderLogger()->log(spdlog::source_loc{__FILE__, __LINE__,SPDLOG_FUNCTION},spdlog::level::trace, __VA_ARGS__ )
#define RENDER_LOG_INFO(...) ::Log::getRenderLogger()->log(spdlog::source_loc{__FILE__, __LINE__,SPDLOG_FUNCTION},spdlog::level::info, __VA_ARGS__ )