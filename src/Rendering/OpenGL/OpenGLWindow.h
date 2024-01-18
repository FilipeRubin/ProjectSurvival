#pragma once
#include "Rendering/Common/IWindow.h"

struct OpenGLWindowParameters
{
	std::string windowTitle = "Project Survival";
	Dimensions windowSize = Dimensions(800, 600);
	bool isFullscreen = false;
};

class OpenGLWindow : public IWindow
{
public:
	OpenGLWindow();
	OpenGLWindow(OpenGLWindowParameters parameters);
	void Close() override;
	Dimensions GetWindowSize() override;
	std::string GetWindowTitle() override;
	void Initialize() override;
	bool IsFullscreen() override;
	bool IsInitialized() override;
	void Process() override;
	void SetFullscreen(bool value) override;
	void SetWindowSize(const Dimensions& size) override;
	void SetWindowTitle(const std::string& title) override;
	bool ShouldClose() override;
	void Terminate() override;
private:
	struct GLFWwindow* m_pWindow;
	OpenGLWindowParameters m_parameters;
	bool m_isInitialized;
};
