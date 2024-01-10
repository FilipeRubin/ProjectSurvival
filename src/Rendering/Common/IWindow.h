#pragma once
#include "Utility/Vector2.h"
#include <string>

class IWindow
{
public:
	virtual ~IWindow() = default;
	virtual Vector2 GetWindowSize() = 0;
	virtual std::string GetWindowTitle() = 0;
	virtual void Initialize() = 0;
	virtual bool IsFullscreen() = 0;
	virtual bool IsInitialized() = 0;
	virtual void SetFullscreen(bool value) = 0;
	virtual void SetWindowSize(const Vector2& size) = 0;
	virtual void SetWindowTitle(std::string& title) = 0;
	virtual bool ShouldClose() = 0;
	virtual void Terminate() = 0;
};