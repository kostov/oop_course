#include "ShapeFactory.h"

Shape * ShapeFactory::makeShape(ShapeType type)
{
	Shape * shape = nullptr;
	switch (type)
	{
	case ShapeType::Point:
	{
		float x = createRandomValue(MAX_RANGE);
		float y = createRandomValue(MAX_RANGE);
		shape = new Point(x, y);
		break;
	}
	case ShapeType::Circle:
	{
		float x = createRandomValue(MAX_RANGE);
		float y = createRandomValue(MAX_RANGE);
		float radius = createRandomValue(MAX_RANGE);
		shape = new Circle(radius, x, y);
		break;
	}
	case ShapeType::Rect:
	{
		float x1 = createRandomValue(MAX_RANGE);
		float y1 = createRandomValue(MAX_RANGE);
		float x2 = createRandomValue(MAX_RANGE);
		float y2 = createRandomValue(MAX_RANGE);
		shape = new Rect(*new Point(x1, y1), *new Point(x2, y2));
		break;
	}
	case ShapeType::Square:
	{
		float x1 = createRandomValue(MAX_RANGE);
		float y1 = createRandomValue(MAX_RANGE);
		float sideLength = createRandomValue(MAX_RANGE);
		shape = new Square(*new Point(x1, y1), sideLength);
		break;
	}
	case ShapeType::Polyline:
	{
		Polyline * tmp = new Polyline();
		uint32_t rand_range = createRandomValue(10);
		for (uint32_t i = 0; i < rand_range; i++)
		{
			float x = createRandomValue(MAX_RANGE);
			float y = createRandomValue(MAX_RANGE);
			tmp->AddPoint(*new Point(x,y));
			shape = tmp;
		}
		break;
	}
	case ShapeType::Polygon:
	{
		Container<Point> data;
		shape = new Polygon(data);
		break;
	}
	
	}
	return static_cast<Shape*>(shape);
}

float ShapeFactory::createRandomValue(uint32_t max_range)
{
	return static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / max_range));
}