#pragma once
#include "IWindow.h"
#include "Utility/Color.h"

class IRenderer
{
public:
	virtual ~IRenderer() = default;
	virtual void Initialize() = 0;
	virtual bool IsInitialized() = 0;
	virtual void RenderFrame() = 0;
	virtual void Terminate() = 0;

	// TEMPORARY
	virtual void SetBackgroundColor(const Color& color) = 0;
};