#pragma once
#include <memory>
#include "IMesh.h"

class IRenderer
{
public:
	virtual ~IRenderer() = default;
	virtual void Initialize() = 0;
	virtual bool IsInitialized() = 0;
	virtual bool IsRunning() = 0;
	virtual void RenderFrame() = 0;
	virtual void Cleanup() = 0;
	//virtual std::unique_ptr<IMesh> CreateMesh() = 0;
};