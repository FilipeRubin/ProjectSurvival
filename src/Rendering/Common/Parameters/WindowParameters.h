#pragma once
#include "Utility/Dimensions.h"
#include <string>

struct WindowParameters
{
	std::string windowTitle = "Project Survival";
	Dimensions windowSize = Dimensions(800, 600);
	bool isFullscreen = false;
};
