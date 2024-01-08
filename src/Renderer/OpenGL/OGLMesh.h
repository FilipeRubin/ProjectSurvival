#pragma once
#include "Renderer/IMesh.h"

class OGLMesh : public IMesh
{
public:
	void LoadMeshData(const MeshData& meshData) override;
private:

};