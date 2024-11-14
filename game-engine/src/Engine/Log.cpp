#include "Log.h"

namespace Maybe
{

    std::shared_ptr<spdlog::logger> Maybe::Log::m_ClientLogger;
    std::shared_ptr<spdlog::logger> Maybe::Log::m_EngineLogger;

    Log::Log()
    {
    }

    Log::~Log()
    {
    }

    void Maybe::Log::Init()
    {
        spdlog::set_pattern("%^[%T] %n: %v%$");
        m_ClientLogger = spdlog::stdout_color_mt("Client");
        m_ClientLogger->set_level(spdlog::level::trace);

        m_EngineLogger = spdlog::stdout_color_mt("Engine");
        m_EngineLogger->set_level(spdlog::level::trace);
    }

} // namespace Maybe