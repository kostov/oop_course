#include "ShapeFactory.h"

shared_ptr<Shape> ShapeFactory::makeShape( ShapeType type )
{
	Shape * shape = nullptr;
	switch (type)
	{
	case ShapeType::Point:
	{
		float x = createRandomFloat( MAX_RANGE );
		float y = createRandomFloat( MAX_RANGE );
		shape = new Point( x, y );
		break;
	}
	case ShapeType::Circle:
	{
		float x = createRandomFloat( MAX_RANGE );
		float y = createRandomFloat( MAX_RANGE );
		Point * p = new Point( x, y );
		float radius = createRandomFloat( MAX_RANGE );
		shape = new Circle( radius, *p );
		break;
	}
	case ShapeType::Rect:
	{
		float x1 = createRandomFloat( MAX_RANGE );
		float y1 = createRandomFloat( MAX_RANGE );
		Point * p1 = new Point( x1, y1 );
		float x2 = createRandomFloat( MAX_RANGE );
		float y2 = createRandomFloat( MAX_RANGE );
		Point * p2 = new Point( x2, y2 );
		shape = new Rect( *p1, *p2 );
		break;
	}
	case ShapeType::Square:
	{
		float x = createRandomFloat( MAX_RANGE );
		float y = createRandomFloat( MAX_RANGE );
		Point * p = new Point( x, y );
		float sideLength = createRandomFloat( MAX_RANGE );
		shape = new Square( *p, sideLength );
		break;
	}
	case ShapeType::Polyline:
	{
		Container<Point *> * container = new Container<Point *>;
		Polyline * tmp = new Polyline( *container );
		uint32_t rand_range = createRandomUInt( 10 );
		for (uint32_t i = 0; i < rand_range; i++)
		{
			float x = createRandomFloat( MAX_RANGE );
			float y = createRandomFloat( MAX_RANGE );
			Point * p = new Point( x, y );
			tmp->addPoint( *p );
		}
		shape = tmp;
		break;
	}
	case ShapeType::Polygon:
	{
		Container<Point *> * container = new Container<Point *>;
		Polyline * pl = new Polyline( *container );
		uint32_t rand_range = createRandomUInt( 10 );
		for (uint32_t i = 0; i < rand_range; i++)
		{
			float x = createRandomFloat( MAX_RANGE );
			float y = createRandomFloat( MAX_RANGE );
			Point * p = new Point( x, y );
			pl->addPoint( *p );
		}
		Polygon * p = new Polygon( *pl );
		shape = p;
		break;
	}

	}
	return shared_ptr<Shape>( shape );
}

float ShapeFactory::createRandomFloat( uint32_t max_range )
{
	return static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / max_range));
}

uint32_t ShapeFactory::createRandomUInt( uint32_t max_range )
{
	return 1 + rand() / (RAND_MAX / max_range);
}