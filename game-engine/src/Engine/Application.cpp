#include "Application.h"
#include "Engine/Events/ApplicationEvent.h"
#include "Engine/Log.h"

namespace Maybe
{

    Application::Application()
    {
    }

    Application::~Application()
    {
    }

    void Application::Run()
    {
        WindowResizeEvent e(1920, 1080);
        
        if (e.IsInCategory(EventCategory::EventCategoryApplication))
        {
            MB_LOG_TRACE_ENGINE(e.ToString());
        }

        if (e.IsInCategory(EventCategory::EventCategoryInput))
        {
            MB_LOG_TRACE_ENGINE(e.ToString());
        }
        
        while (true)
        {
        }
    }
} // namespace Maybe
