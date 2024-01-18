#include "Matrix4x4.h"

Matrix4x4::Matrix4x4() :
	m_data{ Vector4() }
{
	m_data[0][0] = 1.0f;
	m_data[1][1] = 1.0f;
	m_data[2][2] = 1.0f;
	m_data[3][3] = 1.0f;
}

Vector4 Matrix4x4::operator[](int index) const
{
	return m_data[index];
}
