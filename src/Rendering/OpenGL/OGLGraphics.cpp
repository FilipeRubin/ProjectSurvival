#include "OGLGraphics.h"

IRendererManipulator& OGLGraphics::GetRendererManipulator()
{
	return m_renderer;
}

IWindowManipulator& OGLGraphics::GetWindowManipulator()
{
	return m_window;
}

IRendererProcessor& OGLGraphics::GetRendererProcessor()
{
	return m_renderer;
}

IWindowProcessor& OGLGraphics::GetWindowProcessor()
{
	return m_window;
}
