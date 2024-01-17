#pragma once
#include "Rendering/Common/IRenderer.h"

class OGLRenderer : public IRenderer
{
public:
	OGLRenderer();
	void Initialize() override;
	bool IsInitialized() override;
	void RenderFrame() override;
	void Terminate() override;
	void SetClearColor(const Color& color) override;
private:
	bool m_isInitialized;
};