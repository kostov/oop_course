#pragma once
#include "Base.h"
#include "Container.h"
#include <string>
using namespace std;

class Shape : public Named
{
public:
	Shape( string const & name ) : Named( name ) { ++sm_shapes; }
	virtual ~Shape() { --sm_shapes; }
	virtual void print( ostream & out ) const = 0;
	friend ostream & operator << ( ostream & ioStream, Shape const & p )
	{
		ioStream << p.m_name << endl;
		p.print( ioStream );
		return ioStream;
	}
	static int getCount() { return sm_shapes; }
private:
	static int sm_shapes;
};

class Point : public Shape
{
public:
	Point( float x, float y );
	float X() const;
	float Y() const;
	void print( ostream & out ) const;
private:
	float m_x, m_y;
};

class Circle : public Shape
{
public:
	Circle( float radius, Point & p );
	~Circle();
	void print( ostream & out ) const;
private:
	float m_radius, m_area;
	Point * m_center;
};

class Rect : public Shape
{
public:
	Rect( Point & x1, Point & x2 );
	~Rect();
	void print( ostream & out ) const;
private:
	Point * m_x1, * m_x2;
	float m_area;
};

class Square : public Shape
{
public:
	Square( Point & center, float side );
	~Square();
	void print( ostream & out ) const;
private:
	Point * m_center;
	float m_side, m_area;
};

class Polyline : public Shape
{
public:
	Polyline( Container<Point *> & points );
	~Polyline();
	void addPoint( Point & point );
	void calcLength();
	Point & getStartPoint() const;
	float getLength() const;
	void print( ostream & out ) const;
private:
	Container<Point *> * m_points;
	float m_length;
};

class Polygon : public Shape
{
public:
	Polygon( Polyline & points );
	~Polygon();
	void print( ostream & out ) const;
private:
	Polyline * shape;
};