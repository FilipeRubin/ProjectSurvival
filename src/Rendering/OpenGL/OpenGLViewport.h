#pragma once
#include "Rendering/Common/IViewport.h"

class OpenGLViewport : public IViewport
{
public:
	void SetClearColor(const Color& color) override;
};