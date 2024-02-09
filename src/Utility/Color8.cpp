#include "Color8.h"
#include "Color.h"

Color8::Color8() :
	r(0U),
	g(0U),
	b(0U),
	a(0U)
{
}

Color8::Color8(unsigned char r, unsigned char g, unsigned char b, unsigned char a) :
	r(r),
	g(g),
	b(b),
	a(a)
{
}

Color8::Color8(unsigned char r, unsigned char g, unsigned char b) :
	r(r),
	g(g),
	b(b),
	a(255U)
{
}

Color8::operator Color()
{
	return Color
	(
		static_cast<float>(r) / 255.0f,
		static_cast<float>(g) / 255.0f,
		static_cast<float>(b) / 255.0f,
		static_cast<float>(a) / 255.0f
	);
}
