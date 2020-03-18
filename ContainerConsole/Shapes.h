#pragma once
#include "Base.h"
#include "Container.h"
#include <string>
using namespace std;

class Shape : public Named
{
public:
	Shape(const string & name) : Named(name) { ++m_shapes; }
	~Shape() { cout << "Hello\n"; --m_shapes; }
	virtual void print(ostream& out) const = 0;
	friend ostream& operator << (ostream& ioStream, const Shape& p)
	{
		ioStream << p.m_name << endl;
		p.print(ioStream);
		return ioStream;
	}
	static int getCount() { return m_shapes; }
private:
	static int m_shapes;
};

class Point : public Shape
{
public:
	Point(float x, float y);
	float X() const;
	float Y() const;
	void print(ostream & out) const;
private:
	float m_x, m_y;
};

class Circle : public Shape
{
public:
	Circle(float radius, Point & p);
	void print(ostream& out) const;
private:
	float m_radius, m_area;
	Point * m_center;
};

class Rect : public Shape
{
public:
	Rect(Point & x1, Point & x2);
	void print(ostream& out) const;
private:
	Point * m_x1, * m_x2;
	float m_area;
};

class Square : public Shape
{
public:
	Square(Point & center, float side);
	void print(ostream& out) const;
private:
	Point * m_center;
	float m_side, m_area;
};

class Polyline : public Shape
{
public:
	Polyline(Container<Point *> & points);
	~Polyline();
	void addPoint(const Point & point);
	void calcLength();
	float getLength() const;
	void print(ostream& out) const;
private:
	Container<Point *> * m_points;
	float m_length;
};

class Polygon : public Shape
{
public:
	Polygon(Polyline & data);
	~Polygon();
	void print(ostream& out) const;
private:
	Polyline * m_data;
};