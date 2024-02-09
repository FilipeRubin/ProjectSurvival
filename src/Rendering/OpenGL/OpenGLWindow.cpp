#include "OpenGLWindow.h"
#include <GLFW/glfw3.h>

OpenGLWindow::OpenGLWindow(const WindowParameters& parameters) :
	m_pWindow(nullptr),
	m_parameters(parameters),
	m_isInitialized(false)
{
}

void OpenGLWindow::Close()
{
	glfwSetWindowShouldClose(m_pWindow, GLFW_TRUE);
}

Dimensions OpenGLWindow::GetWindowSize()
{
	return m_parameters.windowSize;
}

std::string OpenGLWindow::GetWindowTitle()
{
	return m_parameters.windowTitle;
}

void OpenGLWindow::Initialize()
{
	if (glfwInit() != GLFW_TRUE)
	{
		return;
	}
	
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	const int width = m_parameters.windowSize.width;
	const int height = m_parameters.windowSize.height;
	const char* title = m_parameters.windowTitle.c_str();

	m_pWindow = glfwCreateWindow(width, height, title, nullptr, nullptr);
	if (m_pWindow == nullptr)
	{
		Terminate();
		return;
	}
	glfwMakeContextCurrent(m_pWindow);
	m_isInitialized = true;
}

bool OpenGLWindow::IsFullscreen()
{
	return m_parameters.isFullscreen;
}

bool OpenGLWindow::IsInitialized()
{
	return m_isInitialized;
}

void OpenGLWindow::SetFullscreen(bool value)
{
	// Not implemented
}

void OpenGLWindow::SetWindowSize(const Dimensions& size)
{
	const int width = size.width;
	const int height = size.height;
	glfwSetWindowSize(m_pWindow, width, height);
	m_parameters.windowSize = size;
}

void OpenGLWindow::SetWindowTitle(const std::string& title)
{
	glfwSetWindowTitle(m_pWindow, title.c_str());
}

bool OpenGLWindow::ShouldClose()
{
	return glfwWindowShouldClose(m_pWindow);
}

void OpenGLWindow::Process()
{
	glfwSwapBuffers(m_pWindow);
	glfwPollEvents();
}

void OpenGLWindow::Terminate()
{
	glfwDestroyWindow(m_pWindow);
	glfwTerminate();
}
