#pragma once

#include <algorithm>
#include <functional>
#include <iostream>
#include <memory>
#include <utility>

#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/spdlog.h"

// clang-format off
#ifdef MB_PLATFORM_WINDOWS
	#include <Windows.h>
#endif // MB_PLATFORM_WINDOWS
// clang-format on