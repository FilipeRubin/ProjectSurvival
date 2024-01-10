#pragma once
#include "Renderer/IRenderer.h"
#include <glad/glad.h>
#include <string>

class OGLShader : IShader
{
public:
	OGLShader();
	OGLShader(const OGLShader& other) = delete;
	OGLShader(OGLShader&& other) noexcept;
	~OGLShader();
	OGLShader& operator=(const OGLShader& other) = delete;
	OGLShader& operator=(OGLShader&& other) noexcept;
	void Compile() override;
	void Use() override;
	void Load(const std::string& vertexShaderSource, const std::string& fragmentShaderSource);
private:
	GLuint m_program;
};