#include "Shapes.h"
#include <iostream>
#include "corecrt_math_defines.h"
#include <string>
using namespace std;

int Shape::sm_shapes = 0;

Point::Point( float x, float y )
	: Shape( "Point" ), m_x( x ), m_y( y ) {}

float Point::X() const { return m_x; }
float Point::Y() const { return m_y; }

void Point::print( ostream & out ) const
{
	out << "(" << m_x << ", " << m_y << ")" << endl;
}

Circle::Circle( float radius, Point & p )
	: Shape( "Circle" ), m_center( &p ), m_radius( radius )
{
	m_area = (float)M_PI * m_radius * m_radius;
}

Circle::~Circle() { delete m_center; }

void Circle::print( ostream & out ) const
{
	m_center->print( out );
	out << "Radius: " << m_radius << " Area: " << m_area << endl;
}

Rect::Rect( Point & x1, Point & x2 )
	: Shape( "Rect" ), m_x1( &x1 ), m_x2( &x2 )
{
	m_area = abs( (m_x1->X() - m_x2->X()) * (m_x2->Y() - m_x1->Y()) );
}

Rect::~Rect() { delete m_x1; delete m_x2; }

void Rect::print( ostream & out ) const
{
	m_x1->print( out );
	m_x2->print( out );
	out << "Area: " << m_area << endl;
}

Square::Square( Point & center, float side )
	: Shape( "Square" ), m_center( &center ), m_side( side )
{
	m_area = side * side;
}

Square::~Square() { delete m_center; }

void Square::print( ostream & out ) const
{
	m_center->print( out );
	out << "Area: " << m_area << endl;
}

Polyline::Polyline( Container<Point *> & points )
	: m_length( 0 ), m_points( &points ), Shape( "Polyline" )
{
	if (m_points->size() == 0) return;
	calcLength();
}

Polyline::~Polyline()
{
	uint32_t s = m_points->size();
	for (uint32_t i = 0; i < s; i++)
	{
		delete (*m_points)[i];
	}
	delete m_points;
}

void Polyline::calcLength()
{
	uint32_t size = m_points->size() - 1;
	for (uint32_t i = 0; i < size; i++)
	{
		Point * p1 = (*m_points)[i];
		Point * p2 = (*m_points)[i + 1];

		m_length += sqrt( pow( p1->Y() - p2->Y(), 2 )
			+ pow( p1->X() - p2->X(), 2 ) );
	}
}

void Polyline::addPoint( Point & p )
{
	m_points->push_back( &p );
	uint32_t s = m_points->size();
	if (s <= 1) return;
	Point * p1 = (*m_points)[m_points->size() - 1];
	Point * p2 = (*m_points)[m_points->size() - 2];

	m_length += sqrt( pow( p1->Y() - p2->Y(), 2 )
		+ pow( p1->X() - p2->X(), 2 ) );
}

void Polyline::print( ostream & out ) const
{
	for (uint32_t i = 0; i < m_points->size(); i++)
	{
		(*m_points)[i]->print( out );
	}
	out << "Length: " << getLength() << endl;
}

Point & Polyline::getStartPoint() const { return *(*m_points)[0]; }

float Polyline::getLength() const { return m_length; }

Polygon::Polygon( Polyline & shape )
	: shape( &shape ), Shape( "Polygon" )
{
	Point * startPoint = new Point( shape.getStartPoint().X(), shape.getStartPoint().Y() );
	shape.addPoint( *startPoint );
}

Polygon::~Polygon() { delete shape; }

void Polygon::print( ostream & out ) const { shape->print( out ); }
