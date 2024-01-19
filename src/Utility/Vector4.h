#pragma once

#ifdef _MSC_VER
__declspec(align(16))
#endif
struct Vector4
{
	float x;
	float y;
	float z;
	float w;

	Vector4();
	Vector4(float x, float y, float z, float w);

	float& operator[](int index);
};