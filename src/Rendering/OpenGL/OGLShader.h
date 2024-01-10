#pragma once
#include "Renderer/IRenderer.h"
#include <glad/glad.h>
#include <string>

class OGLShader
{
public:
	OGLShader();
	OGLShader(const OGLShader& other) = delete;
	OGLShader(OGLShader&& other) noexcept;
	~OGLShader();
	OGLShader& operator=(const OGLShader& other) = delete;
	OGLShader& operator=(OGLShader&& other) noexcept;
	void Compile();
	void Use();
	void Load(const std::string& vertexShaderSource, const std::string& fragmentShaderSource);
private:
	GLuint m_program;
};