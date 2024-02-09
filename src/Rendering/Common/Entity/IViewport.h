#pragma once
#include "Component/ITexture2D.h"
#include "Parameters/ViewportParameters.h"
#include "Utility/Color.h"
#include "Utility/Dimensions.h"

class IViewport
{
public:
	virtual ~IViewport() = default;
	virtual Dimensions GetResolution() = 0;
	virtual ITexture2D& GetTargetTexture() = 0;
	virtual void Load(const ViewportParameters& parameters) = 0;
	virtual void SetClearColor(const Color& color) = 0;
	virtual void SetResolution(const Dimensions& resolution) = 0;
};