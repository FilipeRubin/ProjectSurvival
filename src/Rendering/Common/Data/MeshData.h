#pragma once
#include "Utility/ContiguousArray.h"
#include "Utility/Vertex.h"

class MeshData
{
public:
	ContiguousArray<Vertex> vertices;
	ContiguousArray<unsigned int> indices;
};