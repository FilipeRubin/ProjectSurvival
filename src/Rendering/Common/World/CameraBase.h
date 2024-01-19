#pragma once
#include "Utility/Transform.h"
#include "Utility/Projection.h"

class CameraBase
{
public:
	Transform transform;
	Projection projection;
};