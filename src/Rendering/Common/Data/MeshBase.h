#pragma once
#include "MeshData.h"
#include "Utility/Transform.h"

class MeshBase
{
public:
	Transform transform;
	virtual ~MeshBase() = default;
	virtual void LoadMeshData(const MeshData& meshData) = 0;
	virtual void Draw() = 0;
private:
};
