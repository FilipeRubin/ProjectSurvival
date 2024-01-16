#pragma once
#include "IRenderer.h"
#include "IWindow.h"
#include <memory>

class IGraphics
{
public:
	virtual ~IGraphics() = default;
	virtual IRenderer* GetRenderer() = 0;
	virtual IWindow* GetWindow() = 0;
};
