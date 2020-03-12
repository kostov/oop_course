#pragma once
#include "Base.h"
#include "Container.h"
class Point : Shape, Named
{
public:
	Point(float x, float y);
	float GetX();
	float GetY();
	void print();
private:
	float m_x, m_y;
};

class Circle : Shape, Named
{
public:
	Circle(float radius, float x, float y);
	void print();
private:
	float m_radius, m_area;
	Point m_center;
};

class Rect : Shape, Named
{
public:
	Rect(Point x1, Point x2, string name);
	void print();
protected:
	Point m_x1, m_x2;
	float m_area;
};

class Square : Rect
{
	Square(Point x1, Point x2);
};

class Polyline : Shape, Named
{
public:
	Polyline();
	void AddPoint(const Point & point);
	void print();
	float GetLength();
private:
	void CalcLength();
	Container<Point> m_points;
	float length;
};

class Polygon : Shape, Named
{
public:
	Polygon(const Container<Point> & data);
private:
	Polyline m_data;
};