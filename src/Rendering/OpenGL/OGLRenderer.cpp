#include "OGLRenderer.h"
#include <glad/glad.h>

OGLRenderer::OGLRenderer() :
	m_isInitialized(false)
{
}

void OGLRenderer::Initialize()
{
	if (gladLoadGL())
	{
		m_isInitialized = true;
	}
}

bool OGLRenderer::IsInitialized()
{
	return m_isInitialized;
}

void OGLRenderer::RenderFrame()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void OGLRenderer::Terminate()
{
}

void OGLRenderer::SetClearColor(const Color& color)
{
	glClearColor(color.r, color.g, color.b, color.a);
}
