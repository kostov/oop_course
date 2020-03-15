#pragma once
#include "Shapes.h"
#include "ShapeType.h"
const int MAX_RANGE = 101;
class ShapeFactory
{
public:
    static Shape * makeShape(ShapeType name);
    static float createRandomValue(uint32_t max);
};

