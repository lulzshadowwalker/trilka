#ifndef TK_LOG_HPP
#define TK_LOG_HPP

#include "Core.hpp"
#include <memory>
#include "Events/Event.hpp"

// This ignores all warnings raised inside External headers
#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#pragma warning(pop)

namespace Trilka {

    class TRILKA_API Log 
    {
    public: 
        static void Init();

        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };

}

#endif

// Core logger
#define TK_CORE_TRACE(...) ::Trilka::Log::GetCoreLogger()->trace(__VA_ARGS__) 
#define TK_CORE_INFO(...) ::Trilka::Log::GetCoreLogger()->info(__VA_ARGS__)
#define TK_CORE_WARN(...) ::Trilka::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define TK_CORE_ERROR(...) ::Trilka::Log::GetCoreLogger()->error(__VA_ARGS__)
#define TK_CORE_FATAL(...) ::Trilka::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client logger
#define TK_TRACE(...) ::Trilka::Log::GetClientLogger()->trace(__VA_ARGS__)
#define TK_INFO(...) ::Trilka::Log::GetClientLogger()->info(__VA_ARGS__)
#define TK_WARN(...) ::Trilka::Log::GetClientLogger()->warn(__VA_ARGS__)
#define TK_ERROR(...) ::Trilka::Log::GetClientLogger()->error(__VA_ARGS__)
#define TK_FATAL(...) ::Trilka::Log::GetClientLogger()->fatal(__VA_ARGS__)