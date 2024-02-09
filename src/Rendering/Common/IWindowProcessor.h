#pragma once
#include "Parameters/WindowParameters.h"

class IWindowProcessor
{
public:
	virtual ~IWindowProcessor() = default;
	virtual void Initialize() = 0;
	virtual bool IsInitialized() = 0;
	virtual void Process() = 0;
	virtual bool ShouldClose() = 0;
	virtual void Terminate() = 0;
};