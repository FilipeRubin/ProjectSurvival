#include "VBO.h"
#include <cassert>

VBO::VBO(GLenum bufferTarget) :
	m_vbo(0U),
	m_bufferTarget(bufferTarget)
{
	glGenBuffers(1, &m_vbo);
}

VBO::~VBO()
{
	glDeleteBuffers(1, &m_vbo);
}

void VBO::Bind()
{
	assert(m_vbo != 0);
	glBindBuffer(m_bufferTarget, m_vbo);
}

void VBO::InsertData()
{
	Bind();

}
