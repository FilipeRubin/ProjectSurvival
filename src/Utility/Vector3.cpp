#include "Vector3.h"
#include <cassert>

Vector3::Vector3() :
	x(0.0f),
	y(0.0f),
	z(0.0f)
{
}

Vector3::Vector3(float x, float y, float z) :
	x(x),
	y(y),
	z(z)
{
}

float& Vector3::operator[](int index)
{
    assert(index >= 0 and index <= 2, "Trying to access out of bound elements.");

    switch (index)
    {
    case 0:
        return x;
    case 1:
        return y;
    case 2:
        return z;
    }
}
