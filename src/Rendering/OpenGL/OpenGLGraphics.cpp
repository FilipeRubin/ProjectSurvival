#include "OpenGLGraphics.h"

IRendererManipulator& OpenGLGraphics::GetRendererManipulator()
{
	return m_renderer;
}

IWindowManipulator& OpenGLGraphics::GetWindowManipulator()
{
	return m_window;
}

IRendererProcessor& OpenGLGraphics::GetRendererProcessor()
{
	return m_renderer;
}

IWindowProcessor& OpenGLGraphics::GetWindowProcessor()
{
	return m_window;
}
