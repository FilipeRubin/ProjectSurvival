#include "OGLWindow.h"
#include <GLFW/glfw3.h>

OGLWindow::OGLWindow() :
	m_pWindow(nullptr),
	m_windowWidth(0),
	m_windowHeight(0)
{
}

Vector2 OGLWindow::GetWindowSize()
{
	float width = static_cast<float>(m_windowWidth);
	float height = static_cast<float>(m_windowHeight);
	return Vector2(width, height);
}

std::string OGLWindow::GetWindowTitle()
{
	return m_windowTitle;
}

void OGLWindow::Initialize()
{
	m_pWindow = glfwCreateWindow(m_windowWidth, m_windowHeight, m_windowTitle.c_str(), nullptr, nullptr);
}

bool OGLWindow::IsFullscreen()
{
	return false;
}

bool OGLWindow::IsInitialized()
{
	return m_pWindow != nullptr;
}

void OGLWindow::SetFullscreen(bool value)
{
	// Not implemented
}

void OGLWindow::SetWindowSize(const Vector2& size)
{
	int width = static_cast<int>(size.x);
	int height = static_cast<int>(size.y);
	glfwSetWindowSize(m_pWindow, width, height);
	m_windowWidth = width;
	m_windowHeight = height;
}

void OGLWindow::SetWindowTitle(std::string& title)
{
	glfwSetWindowTitle(m_pWindow, title.c_str());
}

bool OGLWindow::ShouldClose()
{
	return glfwWindowShouldClose(m_pWindow);
}

void OGLWindow::Terminate()
{
	glfwDestroyWindow(m_pWindow);
}