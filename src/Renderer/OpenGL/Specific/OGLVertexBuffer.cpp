#include "OGLVertexBuffer.h"
#include <cassert>

OGLVertexBuffer::OGLVertexBuffer(GLenum bufferTarget) :
	m_vbo(0U),
	m_bufferTarget(bufferTarget)
{
	glGenBuffers(1, &m_vbo);
}

OGLVertexBuffer::~OGLVertexBuffer()
{
	glDeleteBuffers(1, &m_vbo);
}

void OGLVertexBuffer::Bind() const
{
	assert(m_vbo != 0);
	glBindBuffer(m_bufferTarget, m_vbo);
}

void OGLVertexBuffer::InsertData(const DataArray& data) const
{
	Bind();
	glBufferData(m_bufferTarget, data.Size(), data.GetData(), GL_STATIC_DRAW);
}
