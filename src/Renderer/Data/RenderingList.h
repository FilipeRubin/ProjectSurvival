#pragma once
#include "Utility/ContiguousArray.h"
#include "Renderer/IMesh.h"
#include "Renderer/IShader.h"

class RenderingList
{
private:
	IShader m_shader;
	ContiguousArray<IMesh> m_meshes;
};