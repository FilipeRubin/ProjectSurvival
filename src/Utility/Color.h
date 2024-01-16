#pragma once

struct Color
{
	float r;
	float g;
	float b;
	float a;
	Color();
	Color(float r, float g, float b, float a);
	Color(float r, float g, float b);
	bool operator==(const Color& other);
	bool operator!=(const Color& other);
};