#pragma once
#include "Renderer/Data/MeshData.h"

class IMesh
{
public:
	virtual ~IMesh() = default;
	virtual void LoadMeshData(const MeshData& meshData) = 0;
	virtual void Render() = 0;
};