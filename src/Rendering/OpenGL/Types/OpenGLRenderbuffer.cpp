#include "OpenGLRenderbuffer.h"
#include <glad/glad.h>

OpenGLRenderbuffer::OpenGLRenderbuffer() :
	m_rbo(0U)
{
}

OpenGLRenderbuffer::~OpenGLRenderbuffer()
{
	Unload();
}

void OpenGLRenderbuffer::Bind() const
{
	glBindRenderbuffer(GL_RENDERBUFFER, m_rbo);
}

void OpenGLRenderbuffer::Load(const OpenGLRenderbufferParameters& data)
{
	glGenRenderbuffers(1, &m_rbo);
	glBindRenderbuffer(GL_RENDERBUFFER, m_rbo);
	glRenderbufferStorage(
		GL_RENDERBUFFER,
		static_cast<GLenum>(data.internalFormat),
		data.resolution.width,
		data.resolution.height
	);
}

void OpenGLRenderbuffer::Unload()
{
	glDeleteRenderbuffers(1, &m_rbo);
	m_rbo = 0U;
}
