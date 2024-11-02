#pragma once

#include "Core.h"

namespace Maybe
{
	class MB_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();

		
		//Call in client
	};
	Application* CreateApplication();
}


