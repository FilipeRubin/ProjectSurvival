#pragma once
#include "Rendering/Common/Entity/IViewport.h"
#include "Rendering/Common/Parameters/ViewportParameters.h"
#include "Types/OpenGLFramebuffer.h"

class OpenGLViewport : public IViewport
{
public:
	OpenGLViewport(const Dimensions& resolution = Dimensions(800, 600));
	Dimensions GetResolution() override;
	ITexture2D& GetTargetTexture() override;
	void Load(const ViewportParameters& parameters) override;
	void SetClearColor(const Color& color) override;
	void SetResolution(const Dimensions& resolution) override;
protected:
	OpenGLFramebuffer m_framebuffer;
	OpenGLTexture m_texture;
	OpenGLRenderbuffer m_renderbuffer;
	Dimensions m_resolution;
};
