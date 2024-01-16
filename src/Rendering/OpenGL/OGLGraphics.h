#pragma once
#include "Rendering/Common/IGraphics.h"
#include "OGLRenderer.h"
#include "OGLWindow.h"

class OGLGraphics : public IGraphics
{
public:
	IRenderer* GetRenderer() override;
	IWindow* GetWindow() override;
private:
	OGLRenderer m_renderer;
	OGLWindow m_window;
};
