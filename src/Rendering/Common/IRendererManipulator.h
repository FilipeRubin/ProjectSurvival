#pragma once
#include "IViewport.h"

class IRendererManipulator
{
public:
	virtual ~IRendererManipulator() = default;
	virtual IViewport& GetMainViewport() = 0;
};