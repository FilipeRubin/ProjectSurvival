#pragma once
#include "Utility/Dimensions.h"
#include <string>

class IWindow
{
public:
	virtual ~IWindow() = default;
	virtual void Close() = 0;
	virtual Dimensions GetWindowSize() = 0;
	virtual std::string GetWindowTitle() = 0;
	virtual void Initialize() = 0;
	virtual bool IsFullscreen() = 0;
	virtual bool IsInitialized() = 0;
	virtual void SetFullscreen(bool value) = 0;
	virtual void SetWindowSize(const Dimensions& size) = 0;
	virtual void SetWindowTitle(const std::string& title) = 0;
	virtual bool ShouldClose() = 0;
	virtual void Terminate() = 0;
};