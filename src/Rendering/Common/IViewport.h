#pragma once
#include "Utility/Color.h"

class IViewport
{
public:
	virtual ~IViewport() = default;
	virtual void SetClearColor(const Color& color) = 0;
};