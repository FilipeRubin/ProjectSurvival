#pragma once
#include "Utility/ContiguousArray.h"
#include "Utility/Vertex.h"

struct MeshData
{
	ContiguousArray<Vertex> vertices;
	ContiguousArray<unsigned int> indices;
};