#pragma once
#include <glad/glad.h>
#include "Utility/DataArray.h"

class OGLVertexBuffer
{
public:
	OGLVertexBuffer(GLenum bufferTarget);
	~OGLVertexBuffer();
	void Bind() const;
	void InsertData(const DataArray& data) const;
private:
	GLuint m_vbo;
	GLenum m_bufferTarget;
};