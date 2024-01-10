#pragma once
#include "Utility/ContiguousArray.h"
#include "Renderer/IMesh.h"

class RenderingListBase
{
protected:
	ContiguousArray<IMesh> m_meshes;
};