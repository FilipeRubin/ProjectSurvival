#pragma once
#include "Rendering/Common/IWindow.h"
#include "Data/OGLWindowParameters.h"

class OGLWindow : public IWindow
{
public:
	OGLWindow();
	OGLWindow(OGLWindowParameters parameters);
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
	OGLWindowParameters m_parameters;
	bool m_isInitialized;
};
