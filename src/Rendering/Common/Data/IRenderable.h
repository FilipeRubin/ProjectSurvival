#pragma once

class IRenderable
{
public:
	virtual ~IRenderable() = default;
	virtual void Render() = 0;
};