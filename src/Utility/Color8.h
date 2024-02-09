#pragma once

struct Color;
#ifdef _MSC_VER
__declspec(align(1))
#endif
struct Color8
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char a;

	Color8();
	Color8(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
	Color8(unsigned char r, unsigned char g, unsigned char b);
	operator Color();
};
