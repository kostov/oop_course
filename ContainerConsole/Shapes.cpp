#include "Shapes.h"
#include <iostream>
#include "corecrt_math_defines.h"
#include <string>
using namespace std;

int Shape::m_shapes = 0;

Point::Point(float x, float y)
	: m_x(x), m_y(y), Named("Point") {}

float Point::X() { return m_x; }
float Point::Y() { return m_y; }

void Point::print(ostream& out) const
{ 
	out << "(" << m_x << ", " << m_y << ")" << endl; 
}

Circle::Circle(float radius, float x, float y)
	: m_center(x,y), m_radius(radius), Named("Circle")
{
	m_area = (float)M_PI * m_radius * m_radius;
}

void Circle::print(ostream& out) const
{
	m_center.print(out);
	out << " radius: " << m_radius << " area: " << m_area << endl;
}

Rect::Rect(const Point & x1,const Point & x2)
	: m_x1(x1), m_x2(x2), Named("Rect")
{
	m_area = abs( ( m_x1.X() - m_x2.X() ) * ( m_x2.Y() - m_x1.Y() ) );
}

void Rect::print(ostream & out) const 
{
	m_x1.print(out);
	m_x2.print(out);
	out << "area: " << m_area << endl;
}

Square::Square(const Point & center, float side)
	: m_center(center), m_side(side), Named("Square") 
{
	m_area = side * side;
}

void Square::print(ostream& out) const 
{
	m_center.print(out);
	out << "area: " << m_area << endl;
}

Polyline::Polyline()
	: Named("Polyline")
{
	m_length = 0;
}

void Polyline::AddPoint(const Point & p)
{
	m_points.push_back(Point(p));
	CalcLength();
}

void Polyline::CalcLength()
{
	if (m_points.size() < 2) return;
	m_length += sqrt(pow(m_points[m_points.size()-1].Y() - m_points[m_points.size() - 1].Y(), 2)
				+ pow(m_points[m_points.size() - 2].X() - m_points[m_points.size() - 2].X(), 2));
}

void Polyline::print(ostream& out) const
{
	for (uint32_t i = 0; i < m_points.size(); i++)
	{
		m_points[i].print(out);
	}
	out << getLength() << endl; 
}

float Polyline::getLength() const { return m_length; }

Polygon::Polygon(const Container<Point> & data)
	: Named("Polygon")
{
	for (uint32_t i = 0; i < data.size(); i++)
	{
		m_data.AddPoint(data[i]);
	}
	m_data.AddPoint(data[0]);
}

void Polygon::print(ostream& out) const { m_data.print(out); }
