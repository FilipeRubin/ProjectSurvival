#include "Color.h"

Color::Color() :
	r(0.0f),
	g(0.0f),
	b(0.0f),
	a(0.0f)
{
}

Color::Color(float r, float g, float b, float a) :
	r(r),
	g(g),
	b(b),
	a(a)
{
}

Color::Color(float r, float g, float b) :
	r(r),
	g(g),
	b(b),
	a(1.0f)
{
}

bool Color::operator==(const Color& other)
{
	return
		r == other.r and
		g == other.g and
		b == other.b and
		a == other.a;
}

bool Color::operator!=(const Color& other)
{
	return
		r != other.r or
		g != other.g or
		b != other.b or
		a != other.a;
}
