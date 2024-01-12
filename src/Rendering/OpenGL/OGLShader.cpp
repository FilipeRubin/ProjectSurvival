#include "OGLShader.h"

OGLShader::OGLShader() :
	m_program(0U)
{
	m_program = glCreateProgram();
}

OGLShader::OGLShader(OGLShader&& other) noexcept :
	m_program(other.m_program)
{
	other.m_program = 0U;
}

OGLShader::~OGLShader()
{
	glDeleteProgram(m_program);
}

OGLShader& OGLShader::operator=(OGLShader&& other) noexcept
{
	if (this != &other)
	{

	}
	return *this;
}

void OGLShader::Compile()
{
	
}

void OGLShader::Use()
{
}

void OGLShader::Load(const std::string& vertexShaderSource, const std::string& fragmentShaderSource)
{
}
