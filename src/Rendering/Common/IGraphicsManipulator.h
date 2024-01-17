#pragma once
#include "IRendererManipulator.h"
#include "IWindowManipulator.h"

class IGraphicsManipulator
{
public:
	virtual ~IGraphicsManipulator() = default;
	virtual IRendererManipulator& GetRendererManipulator() = 0;
	virtual IWindowManipulator& GetWindowManipulator() = 0;
};