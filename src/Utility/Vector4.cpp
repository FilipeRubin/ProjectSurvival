#include "Vector4.h"
#include <cassert>

Vector4::Vector4() :
    x(0.0f),
    y(0.0f),
    z(0.0f),
    w(0.0f)
{
}

Vector4::Vector4(float x, float y, float z, float w) :
    x(0.0f),
    y(0.0f),
    z(0.0f),
    w(0.0f)
{
}

float& Vector4::operator[](int index)
{
    assert(index >= 0 and index <= 3, "Trying to access out of bound elements.");
    
    switch (index)
    {
    case 0:
        return x;
    case 1:
        return y;
    case 2:
        return z;
    case 3:
        return w;
    }
}
