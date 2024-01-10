#pragma once

class IShader
{
public:
	virtual ~IShader() = default;
	virtual void Compile() = 0;
	virtual void Use() = 0;
};