#pragma once
#include <memory>
#include "IWindow.h"

class IGraphicsApplication
{
public:
	virtual ~IGraphicsApplication() = default;
	virtual std::unique_ptr<IWindow> CreateWindow() = 0;
};
