#include "OpenGLFramebuffer.h"
#include <glad/glad.h>

OpenGLFramebuffer::OpenGLFramebuffer() :
	m_fbo(0U),
	m_resolution(Dimensions())
{
}

OpenGLFramebuffer::~OpenGLFramebuffer()
{
	Unload();
}

void OpenGLFramebuffer::SetTargetRenderbuffer(const OpenGLRenderbuffer& renderbuffer) const
{
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, renderbuffer.m_rbo);
}

void OpenGLFramebuffer::SetTargetTexture(const OpenGLTexture& texture) const
{
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture.m_texture, 0);
}

void OpenGLFramebuffer::Bind() const
{
	glBindFramebuffer(GL_FRAMEBUFFER, m_fbo);
}

void OpenGLFramebuffer::Load()
{
	glGenFramebuffers(1, &m_fbo);
	glBindFramebuffer(GL_FRAMEBUFFER, m_fbo);
}

void OpenGLFramebuffer::Unload()
{
	glDeleteFramebuffers(1, &m_fbo);
	m_fbo = 0U;
}
