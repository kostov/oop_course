#pragma once
#include <string>
class Printable
{
	virtual void print() = 0;
};

class Named : Printable
{
public:
	Named(std::string name)
		: m_name(name) {}
private:
	std::string m_name;
};

class Shape : Printable
{
public:
	void print();
	Shape() { ++shapes; }
	static int GetCount() {	return shapes; }
private:
	static int shapes;
};
