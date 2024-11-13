#pragma once

#include "Core.h"
#include "Engine/Events/Event.h"

namespace Maybe
{
    class MB_API Application
    {
      public:
        Application();
        virtual ~Application();
        void Run();

        // Call in client
    };

    Application *CreateApplication();

} // namespace Maybe