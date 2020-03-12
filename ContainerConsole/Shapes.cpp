#include "Shapes.h"
#include <iostream>
#include "corecrt_math_defines.h"
using namespace std;

Point::Point(float x, float y)
	: m_x(x), m_y(y), Named("Point") {}

float Point::GetX() { return m_x; }
float Point::GetY() { return m_y; }

void Point::print()
{
	cout << "x: " << m_x << "y: " << m_y << endl;
}

Circle::Circle(float radius, float x, float y)
	: m_center(x,y), m_radius(radius), Named("Circle")
{
	m_area = (float)M_PI * m_radius * m_radius;
}

void Circle::print()
{
	cout << "center: "; m_center.print();
	cout << "radius: " << m_radius << "area: " << m_area << endl;
}

Rect::Rect(Point x1, Point x2, string name)
	: m_x1(x1), m_x2(x2), Named(name)
{
	m_area = abs( ( m_x1.GetX() - m_x2.GetX() ) * ( m_x2.GetY() - m_x1.GetY() ) );
}

void Rect::print()
{
	m_x1.print();
	m_x2.print();
	cout << "area: " << m_area;
}

Square::Square(Point x1, Point x2)
	: Rect(x1, x2, "Square") {}


Polyline::Polyline()
	: Named("Polyline")
{
	m_points.clear();
	length = 0;
}

void Polyline::AddPoint(const Point& p)
{
	m_points.push_back(p);
	CalcLength();
}

void Polyline::CalcLength()
{
	if (m_points.size < 2) return;
	length += sqrt(pow(m_points[m_points.size-1].m_y - m_points[m_points.size - 1].m_y, 2)
				+ pow(m_points[m_points.size - 2].m_x - m_points[m_points.size - 2].m_x, 2));
}

void Polyline::print()
{
	for (uint32_t i = 0; i < m_points.size; i++)
	{
		m_points[i].print();
	}
	cout << GetLength() << endl;
}

float Polyline::GetLength() { return length; }

Polygon::Polygon(const Container<Point> & data)
	: Named("Polygon")
{
	for (uint32_t i = 0; i < data.size; i++)
	{
		m_data.AddPoint(data[i]);
	}
	m_data.AddPoint(data[0]);
}
