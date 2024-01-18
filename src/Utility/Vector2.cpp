#include "Vector2.h"
#include <cassert>

Vector2::Vector2() :
    x(0.0f),
    y(0.0f)
{
}

Vector2::Vector2(float x, float y) :
    x(x),
    y(y)
{
}

float& Vector2::operator[](int index)
{
    assert(index >= 0 and index <= 1, "Trying to access out of bound elements.");

    switch (index)
    {
    case 0:
        return x;
    case 1:
        return y;
    }
}
