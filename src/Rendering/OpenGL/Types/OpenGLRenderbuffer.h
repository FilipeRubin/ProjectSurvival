#pragma once
#include "Rendering/OpenGL/Parameters/OpenGLRenderbufferParameters.h"

class OpenGLRenderbuffer
{
	friend class OpenGLFramebuffer;
public:
	OpenGLRenderbuffer();
	~OpenGLRenderbuffer();
	void Bind() const;
	void Load(const OpenGLRenderbufferParameters& data);
	void Unload();
private:
	unsigned int m_rbo;
};
