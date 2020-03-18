#pragma once
#include "Shapes.h"
#include "ShapeType.h"
const int MAX_RANGE = 101;
class ShapeFactory
{
public:
    static Shape * makeShape(ShapeType name);
    static float createRandomFloat(uint32_t max);
    static uint32_t createRandomUInt(uint32_t max);
};

