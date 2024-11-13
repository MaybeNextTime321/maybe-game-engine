#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
#include <memory>

namespace Maybe
{
    class MB_API Log
    {
      public:
        Log();
        ~Log();
        static void Init();

        static inline std::shared_ptr<spdlog::logger> GetClientLogger()
        {
            return m_ClientLogger;
        }

        static inline std::shared_ptr<spdlog::logger> GetEngineLogger()
        {
            return m_EngineLogger;
        }

      private:
        static std::shared_ptr<spdlog::logger> m_ClientLogger;
        static std::shared_ptr<spdlog::logger> m_EngineLogger;
    };
} // namespace Maybe

// clang-format off

// engine side
#define MB_LOG_TRACE_ENGINE(...)    ::Maybe::Log::GetEngineLogger()->trace(__VA_ARGS__)
#define MB_LOG_INFO_ENGINE(...)     ::Maybe::Log::GetEngineLogger()->info(__VA_ARGS__)
#define MB_LOG_WARN_ENGINE(...)     ::Maybe::Log::GetEngineLogger()->warn(__VA_ARGS__)
#define MB_LOG_ERROR_ENGINE(...)    ::Maybe::Log::GetEngineLogger()->error(__VA_ARGS__)
#define MB_LOG_FATAL_ENGINE(...)    ::Maybe::Log::GetEngineLogger()->fatal(__VA_ARGS__)

// client side
#define MB_LOG_TRACE(...)           ::Maybe::Log::GetClientLogger()->trace(__VA_ARGS__)
#define MB_LOG_INFO(...)            ::Maybe::Log::GetClientLogger()->info(__VA_ARGS__)
#define MB_LOG_WARN(...)            ::Maybe::Log::GetClientLogger()->warn(__VA_ARGS__)
#define MB_LOG_ERROR(...)           ::Maybe::Log::GetClientLogger()->error(__VA_ARGS__)
#define MB_LOG_FATAL(...)           ::Maybe::Log::GetClientLogger()->fatal(__VA_ARGS__)

// clang-format on