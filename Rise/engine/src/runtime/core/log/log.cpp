#include<stdafx.h>
#include "log.h"


namespace Rise
{
    std::shared_ptr<spdlog::logger> Log::s_EngineLogger;
    std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

    void Log::Init()
    {
        spdlog::set_pattern("%^[%T] %n %l: %v%$");
        s_EngineLogger = spdlog::stdout_color_mt("Engine");
        s_EngineLogger->set_level(spdlog::level::trace);
        s_ClientLogger = spdlog::stdout_color_mt("Client");
        s_ClientLogger->set_level(spdlog::level::trace);
    }
} // namespace Rise
