#pragma once
#include "Rendering/Common/IGraphics.h"
#include "OGLRenderer.h"
#include "OGLWindow.h"

class OGLGraphics : public IGraphics
{
public:
	IRendererManipulator& GetRendererManipulator() override;
	IWindowManipulator& GetWindowManipulator() override;
	IRendererProcessor& GetRendererProcessor() override;
	IWindowProcessor& GetWindowProcessor() override;
private:
	OGLRenderer m_renderer;
	OGLWindow m_window;
};
