#pragma once
#include "Base.h"
#include "Container.h"
#include <string>
using namespace std;

class Shape : public Printable
{
public:
	Shape() { ++m_shapes; }
	~Shape() { --m_shapes; }
	virtual void print(ostream& out) const = 0;
	friend ostream& operator << (ostream& ioStream, const Shape& p)
	{
		p.print(ioStream);
		return ioStream;
	}
	static int GetCount() { return m_shapes; }
private:
	static int m_shapes;
};

class Point : public Shape, Named
{
public:
	Point(float x, float y);
	float X();
	float Y();
	void print(ostream & out) const;
private:
	float m_x, m_y;
};

class Circle : public Shape, Named
{
public:
	Circle(float radius, float x, float y);
	void print(ostream& out) const;
private:
	float m_radius, m_area;
	Point m_center;
};

class Rect : public Shape, Named
{
public:
	Rect(const Point & x1, const Point & x2);
	void print(ostream& out) const;
private:
	Point m_x1, m_x2;
	float m_area;
};

class Square : public Shape, Named
{
public:
	Square(const Point & center, float side);
	void print(ostream& out) const;
private:
	Point m_center;
	float m_side, m_area;
};

class Polyline : public Shape, Named
{
public:
	Polyline();
	void AddPoint(const Point & point);
	float getLength() const;
	friend ostream& operator << (ostream& ioStream, const Polyline& p);
	void print(ostream& out) const;
private:
	void CalcLength();
	Container<Point> m_points;
	float m_length;
};

class Polygon : public Shape, Named
{
public:
	Polygon(const Container<Point> & data);
	void print(ostream& out) const;
private:
	Polyline m_data;
};