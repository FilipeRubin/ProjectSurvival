#pragma once
#include "Renderer/IRenderer.h"

class OGLRenderer : public IRenderer
{
public:
	OGLRenderer();
	void Initialize() override;
	bool IsInitialized() override;
	bool IsRunning() override;
	void RenderFrame() override;
	void Terminate() override;
private:
	bool m_isInitialized;
	struct GLFWwindow* m_pWindow;
};