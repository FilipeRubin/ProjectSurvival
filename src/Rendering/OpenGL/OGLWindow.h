#pragma once
#include "Rendering/Common/IWindow.h"
#include "Rendering/Common/WindowParameters.h"

class OGLWindow : public IWindow
{
public:
	OGLWindow();
	Vector2 GetWindowSize() override;
	std::string GetWindowTitle() override;
	void Initialize() override;
	bool IsFullscreen() override;
	bool IsInitialized() override;
	void SetFullscreen(bool value) override;
	void SetWindowSize(const Vector2& size) override;
	void SetWindowTitle(std::string& title) override;
	bool ShouldClose() override;
	void Terminate() override;
private:
	struct GLFWwindow* m_pWindow;
	int m_windowWidth;
	int m_windowHeight;
	std::string m_windowTitle;

};