#pragma once

class IRendererProcessor
{
public:
	virtual ~IRendererProcessor() = default;
	virtual void Initialize() = 0;
	virtual bool IsInitialized() = 0;
	virtual void RenderFrame() = 0;
	virtual void Terminate() = 0;
};