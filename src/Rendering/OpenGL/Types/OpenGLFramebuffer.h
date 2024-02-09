#pragma once
#include "OpenGLRenderbuffer.h"
#include "OpenGLTexture.h"

class OpenGLFramebuffer
{
public:
	OpenGLFramebuffer();
	~OpenGLFramebuffer();
	void SetTargetRenderbuffer(const OpenGLRenderbuffer& renderbuffer) const;
	void SetTargetTexture(const OpenGLTexture& texture) const;
	void Bind() const;
	void Load();
	void Unload();
private:
	unsigned int m_fbo;
	Dimensions m_resolution;
};
