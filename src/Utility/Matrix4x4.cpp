#include "Matrix4x4.h"
#include <cmath>

Matrix4x4 Matrix4x4::Perspective(float vfov, float aspectRatio, float zNear, float zFar)
{
	Matrix4x4 result;

	const float halfFovTangent = tan(vfov / 2.0f);

	result[0][0] = 1.0f / (aspectRatio * halfFovTangent);
	result[1][1] = 1.0f / halfFovTangent;

	return Matrix4x4();
}

Matrix4x4::Matrix4x4() :
	m_data{ Vector4() }
{
}

Vector4 Matrix4x4::operator[](int index) const
{
	return m_data[index];
}
