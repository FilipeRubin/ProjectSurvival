#include "OGLGraphics.h"

IRenderer* OGLGraphics::GetRenderer()
{
	return &m_renderer;
}

IWindow* OGLGraphics::GetWindow()
{
	return &m_window;
}
