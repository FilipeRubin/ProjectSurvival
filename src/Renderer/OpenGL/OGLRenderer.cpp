#include "OGLRenderer.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

OGLRenderer::OGLRenderer() :
	m_pWindow(nullptr),
	m_isInitialized(false)
{
}

void OGLRenderer::Initialize()
{
	bool glfwInitialized = glfwInit();
	if (glfwInitialized != GLFW_TRUE)
	{
		return;
	}

	m_pWindow = glfwCreateWindow(1024, 768, "Game", nullptr, nullptr);
	if (m_pWindow == nullptr)
	{
		return;
	}

	glfwMakeContextCurrent(m_pWindow);

	if (gladLoadGL() == 0)
	{
		return;
	}

	m_isInitialized = true;
}

bool OGLRenderer::IsInitialized()
{
	return m_isInitialized;
}

bool OGLRenderer::IsRunning()
{
	return !glfwWindowShouldClose(m_pWindow);
}

void OGLRenderer::RenderFrame()
{
	glfwSwapBuffers(m_pWindow);
	glfwPollEvents();
}

void OGLRenderer::Cleanup()
{
	glfwDestroyWindow(m_pWindow);
	glfwTerminate();

	m_pWindow = nullptr;
	m_isInitialized = false;
}
