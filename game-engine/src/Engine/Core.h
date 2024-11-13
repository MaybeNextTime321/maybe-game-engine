#pragma once

// clang-format off

#ifdef MB_PLATFORM_WINDOWS
	#ifdef MB_BUILD_DLL
		#define MB_API __declspec(dllexport)
	#else
		#define MB_API __declspec(dllimport)
	#endif 
#else
	#error We support only windows for now
#endif 

#define BIT(x) (1 << x)

// clang-format on