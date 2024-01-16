#include "OGLWindow.h"
#include <GLFW/glfw3.h>

OGLWindow::OGLWindow() :
	m_pWindow(nullptr),
	m_parameters(OGLWindowParameters()),
	m_isInitialized(false)
{
}

OGLWindow::OGLWindow(OGLWindowParameters parameters) :
	m_pWindow(nullptr),
	m_parameters(parameters)
{
}

void OGLWindow::Close()
{
	glfwSetWindowShouldClose(m_pWindow, GLFW_TRUE);
}

Dimensions OGLWindow::GetWindowSize()
{
	return m_parameters.windowSize;
}

std::string OGLWindow::GetWindowTitle()
{
	return m_parameters.windowTitle;
}

void OGLWindow::Initialize()
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

bool OGLWindow::IsFullscreen()
{
	return m_parameters.isFullscreen;
}

bool OGLWindow::IsInitialized()
{
	return m_isInitialized;
}

void OGLWindow::SetFullscreen(bool value)
{
	// Not implemented
}

void OGLWindow::SetWindowSize(const Dimensions& size)
{
	const int width = size.width;
	const int height = size.height;
	glfwSetWindowSize(m_pWindow, width, height);
	m_parameters.windowSize = size;
}

void OGLWindow::SetWindowTitle(const std::string& title)
{
	glfwSetWindowTitle(m_pWindow, title.c_str());
}

bool OGLWindow::ShouldClose()
{
	return glfwWindowShouldClose(m_pWindow);
}

void OGLWindow::Process()
{
	glfwSwapBuffers(m_pWindow);
	glfwPollEvents();
}

void OGLWindow::Terminate()
{
	glfwDestroyWindow(m_pWindow);
	glfwTerminate();
}
