#pragma once
#include "Utility/Dimensions.h"

struct OGLWindowParameters
{
	std::string windowTitle = "Project Survival";
	Dimensions windowSize = Dimensions(800, 600);
	bool isFullscreen = false;
};