#include "OpenGLViewport.h"
#include <glad/glad.h>

OpenGLViewport::OpenGLViewport(const Dimensions& resolution) :
	m_framebuffer(OpenGLFramebuffer()),
	m_resolution(resolution)
{
}

Dimensions OpenGLViewport::GetResolution()
{
	return m_resolution;
}

ITexture2D& OpenGLViewport::GetTargetTexture()
{
	// TODO: insert return statement here
}

void OpenGLViewport::Load(const ViewportParameters& parameters)
{
	m_framebuffer.Load()
}

void OpenGLViewport::SetClearColor(const Color& color)
{
	glClearColor(color.r, color.g, color.b, color.a);
}

void OpenGLViewport::SetResolution(const Dimensions& resolution)
{
	m_resolution = resolution;
}
