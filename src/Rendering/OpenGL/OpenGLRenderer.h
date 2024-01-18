#pragma once
#include "OpenGLViewport.h"
#include "Rendering/Common/IRenderer.h"

class OpenGLRenderer : public IRenderer
{
public:
	OpenGLRenderer();
	IViewport& GetMainViewport() override;
	void Initialize() override;
	bool IsInitialized() override;
	void RenderFrame() override;
	void Terminate() override;
private:
	bool m_isInitialized;
	OpenGLViewport m_mainViewport;
};