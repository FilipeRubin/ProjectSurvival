#include "OpenGLRenderer.h"
#include <glad/glad.h>

OpenGLRenderer::OpenGLRenderer() :
	m_isInitialized(false)
{
}

IViewport& OpenGLRenderer::GetMainViewport()
{
	return m_mainViewport;
}

void OpenGLRenderer::Initialize()
{
	if (gladLoadGL())
	{
		m_isInitialized = true;
	}
}

bool OpenGLRenderer::IsInitialized()
{
	return m_isInitialized;
}

void OpenGLRenderer::RenderFrame()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void OpenGLRenderer::Terminate()
{
}
