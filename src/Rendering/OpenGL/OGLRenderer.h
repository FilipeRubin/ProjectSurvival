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

	// TEMPORARY
	void SetBackgroundColor(const Vector3& color) override;
private:
	bool m_isInitialized;
};