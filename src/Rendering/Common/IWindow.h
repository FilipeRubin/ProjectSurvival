#pragma once
#include "IWindowManipulator.h"
#include "IWindowProcessor.h"

class IWindow : public IWindowManipulator, public IWindowProcessor
{
public:
	virtual ~IWindow() = default;
};