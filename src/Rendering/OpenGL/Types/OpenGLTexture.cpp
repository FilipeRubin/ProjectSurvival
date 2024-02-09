#include "OpenGLTexture.h"
#include <glad/glad.h>

OpenGLTexture::OpenGLTexture() :
	m_texture(0U)
{
}

OpenGLTexture::~OpenGLTexture()
{
	Unload();
}

void OpenGLTexture::Bind() const
{
	glBindTexture(GL_TEXTURE_2D, m_texture);
}

Dimensions OpenGLTexture::GetResolution() const
{
	return m_resolution;
}

void OpenGLTexture::Load(const OpenGLTextureParameters& parameters)
{
	glGenTextures(1, &m_texture);
	glBindTexture(GL_TEXTURE_2D, m_texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, parameters.textureData.resolution.width, parameters.textureData.resolution.height, 0, GL_RGBA, GL_UNSIGNED_BYTE, parameters.textureData.pixels.GetDataPointer());
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, parameters.textureData.enableMinificationFilter ? GL_NEAREST : GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, parameters.textureData.enableMagnificationFilter ? GL_NEAREST : GL_LINEAR);
	m_resolution = parameters.textureData.resolution;
}

void OpenGLTexture::Unload()
{
	glDeleteTextures(1, &m_texture);
	m_resolution = Dimensions();
}
