#pragma once
#include "Utility/Dimensions.h"

struct OpenGLRenderbufferParameters
{
	enum class InternalFormat : unsigned int
	{
		DEPTH24_STENCIL8 = 0x88F0
	};

	Dimensions resolution;
	InternalFormat internalFormat = InternalFormat::DEPTH24_STENCIL8;
};