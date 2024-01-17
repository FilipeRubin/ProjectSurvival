#pragma once
#include "IRendererManipulator.h"
#include "IRendererProcessor.h"

class IRenderer : public IRendererManipulator, public IRendererProcessor
{
public:
	virtual ~IRenderer() = default;
};