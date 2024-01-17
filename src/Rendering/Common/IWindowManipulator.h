#pragma once
#include "Utility/Dimensions.h"
#include <string>

class IWindowManipulator
{
public:
	virtual ~IWindowManipulator() = default;
	virtual void Close() = 0;
	virtual Dimensions GetWindowSize() = 0;
	virtual std::string GetWindowTitle() = 0;
	virtual bool IsFullscreen() = 0;
	virtual void SetFullscreen(bool value) = 0;
	virtual void SetWindowSize(const Dimensions& size) = 0;
	virtual void SetWindowTitle(const std::string& title) = 0;
};