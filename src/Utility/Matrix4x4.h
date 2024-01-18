#pragma once
#include "Vector4.h"

class Matrix4x4
{
public:
	Matrix4x4();
	Vector4 operator[](int index) const;
private:
	Vector4 m_data[4];
};