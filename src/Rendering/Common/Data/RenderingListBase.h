#pragma once
#include "Rendering/Common/Data/IRenderable.h"
#include "Utility/ContiguousArray.h"
#include <memory>

class RenderingListBase
{
public:
	virtual void Render() = 0;
protected:
	ContiguousArray<std::unique_ptr<IRenderable>> m_meshes;
};