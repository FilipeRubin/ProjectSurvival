#pragma once
#include "Utility/ContiguousArray.h"
#include "Rendering/Common/IMesh.h"

class RenderingListBase
{
public:
	virtual void DrawAll() = 0;
protected:
	ContiguousArray<IMesh> m_meshes;
};