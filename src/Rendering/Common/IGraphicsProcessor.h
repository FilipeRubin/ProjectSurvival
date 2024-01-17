#pragma once
#include "IRendererProcessor.h"
#include "IWindowProcessor.h"

class IGraphicsProcessor
{
public:
	virtual ~IGraphicsProcessor() = default;
	virtual IRendererProcessor& GetRendererProcessor() = 0;
	virtual IWindowProcessor& GetWindowProcessor() = 0;
};