#pragma once
#include "Utility/Color8.h"
#include "Utility/ContiguousArray.h"
#include "Utility/Dimensions.h"

struct TextureData
{
	Dimensions resolution;
	ContiguousArray<Color8> pixels;
	bool enableMinificationFilter = true;
	bool enableMagnificationFilter = true;
};