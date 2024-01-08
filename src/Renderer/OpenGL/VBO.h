#pragma once
#include <glad/glad.h>

class VBO
{
public:
	VBO(GLenum bufferTarget);
	~VBO();
	void Bind();
	void InsertData();
private:
	GLuint m_vbo;
	GLenum m_bufferTarget;
};