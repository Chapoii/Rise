#pragma once

#include "core/base/macro.h"
#include "spdlog/fmt/ostr.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/spdlog.h"

namespace Rise
{
    class Log
    {
    public:
        static void Init();

        inline static std::shared_ptr<spdlog::logger>& GetEngineLogger() { return s_EngineLogger; }
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

    private:
        static std::shared_ptr<spdlog::logger> s_EngineLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
} // namespace Rise

#ifdef RS_DEBUG
// Core log macros
#define RS_CORE_TRACE(...) ::Rise::Log::GetEngineLogger()->trace("[" + std::string(__FUNCTION__) + "] " + __VA_ARGS__)
#define RS_CORE_DEBUG(...) ::Rise::Log::GetEngineLogger()->debug("[" + std::string(__FUNCTION__) + "] " + __VA_ARGS__)
#define RS_CORE_INFO(...) ::Rise::Log::GetEngineLogger()->info("[" + std::string(__FUNCTION__) + "] " + __VA_ARGS__)
#define RS_CORE_WARN(...) ::Rise::Log::GetEngineLogger()->warn("[" + std::string(__FUNCTION__) + "] " + __VA_ARGS__)
#define RS_CORE_ERROR(...) ::Rise::Log::GetEngineLogger()->error("[" + std::string(__FUNCTION__) + "] " + __VA_ARGS__)
#define RS_CORE_CRITICAL(...) \
    ::Rise::Log::GetEngineLogger()->critical("[" + std::string(__FUNCTION__) + "] " + __VA_ARGS__)

// Client log macros
#define RS_TRACE(...) ::Rise::Log::GetClientLogger()->trace "[" + std::string(__FUNCTION__) + "] " + (__VA_ARGS__)
#define RS_DEBUG(...) ::Rise::Log::GetClientLogger()->debug("[" + std::string(__FUNCTION__) + "] " + __VA_ARGS__)
#define RS_INFO(...) ::Rise::Log::GetClientLogger()->info("[" + std::string(__FUNCTION__) + "] " + __VA_ARGS__)
#define RS_WARN(...) ::Rise::Log::GetClientLogger()->warn("[" + std::string(__FUNCTION__) + "] " + __VA_ARGS__)
#define RS_ERROR(...) ::Rise::Log::GetClientLogger()->error("[" + std::string(__FUNCTION__) + "] " + __VA_ARGS__)
#define RS_CRITICAL(...) ::Rise::Log::GetClientLogger()->critical("[" + std::string(__FUNCTION__) + "] " + __VA_ARGS__)
#else
#define RS_CORE_TRACE(...)
#define RS_CORE_DEBUG(...)
#define RS_CORE_INFO(...)
#define RS_CORE_WARN(...)
#define RS_CORE_ERROR(...)
#define RS_CORE_CRITICAL(...)

// Client log macros
#define RS_TRACE(...)
#define RS_DEBUG(...)
#define RS_INFO(...)
#define RS_WARN(...)
#define RS_ERROR(...)
#define RS_CRITICAL(...)
#endif
