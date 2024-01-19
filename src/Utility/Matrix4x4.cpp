#include "Matrix4x4.h"
#include <cmath>

Matrix4x4 Matrix4x4::Perspective(float vfov, float aspectRatio, float zNear, float zFar)
{
	Matrix4x4 result;

	const float halfFovTangent = tan(vfov / 2.0f);
	const float frustumLength = zFar - zNear;

	result[0][0] = 1.0f / (aspectRatio * halfFovTangent);
	result[1][1] = 1.0f / halfFovTangent;
	result[2][2] = -(zNear + zFar) / frustumLength;
	result[2][3] = -1.0f;
	result[3][2] = (2.0f * zNear * zFar) / frustumLength;

	return result;
}

Matrix4x4::Matrix4x4() :
	m_data{ Vector4() }
{
}

Vector4 Matrix4x4::operator[](int index) const
{
	return m_data[index];
}
