#pragma once
#include "Rendering/Common/Data/IRenderable.h"
#include "Utility/ContiguousArray.h"
#include <memory>

class RenderingListBase
{
public:
	ContiguousArray<std::unique_ptr<IRenderable>> renderables;
	virtual void Render() = 0;
};