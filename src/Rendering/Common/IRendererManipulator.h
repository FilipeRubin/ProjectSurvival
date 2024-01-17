#pragma once
#include "Utility/Color.h"

class IRendererManipulator
{
public:
	virtual ~IRendererManipulator() = default;
	virtual void SetClearColor(const Color& color) = 0;
};