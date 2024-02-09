#pragma once
#include "Rendering/OpenGL/Parameters/OpenGLTextureParameters.h"

class OpenGLTexture
{
	friend class OpenGLFramebuffer;
public:
	OpenGLTexture();
	~OpenGLTexture();
	void Bind() const;
	Dimensions GetResolution() const;
	void Load(const OpenGLTextureParameters& parameters);
	void Unload();
private:
	unsigned int m_texture;
	Dimensions m_resolution;
};
