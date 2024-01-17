#pragma once
#include "IGraphicsManipulator.h"
#include "IGraphicsProcessor.h"
#include "IRenderer.h"
#include "IWindow.h"
#include <memory>

class IGraphics : public IGraphicsManipulator, public IGraphicsProcessor
{
public:
	virtual ~IGraphics() = default;
};
