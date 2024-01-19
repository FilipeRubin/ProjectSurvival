#pragma once
#include "Vector4.h"

class Matrix4x4
{
public:
	static Matrix4x4 Perspective(float vfov, float aspectRatio, float zNear, float zFar);
	Matrix4x4();
	Vector4 operator[](int index) const;
private:
	Vector4 m_data[4];
};