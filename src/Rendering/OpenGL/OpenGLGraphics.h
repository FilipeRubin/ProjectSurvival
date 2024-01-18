#pragma once
#include "Rendering/Common/IGraphics.h"
#include "OpenGLRenderer.h"
#include "OpenGLWindow.h"

class OpenGLGraphics : public IGraphics
{
public:
	IRendererManipulator& GetRendererManipulator() override;
	IWindowManipulator& GetWindowManipulator() override;
	IRendererProcessor& GetRendererProcessor() override;
	IWindowProcessor& GetWindowProcessor() override;
private:
	OpenGLRenderer m_renderer;
	OpenGLWindow m_window;
};
