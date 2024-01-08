#pragma once
#include "Data/MeshData.h"

class IMesh
{
public:
	virtual ~IMesh() = default;
	virtual void LoadMeshData(const MeshData& meshData) = 0;
};