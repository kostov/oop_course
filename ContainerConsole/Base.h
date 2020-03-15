#pragma once
#include <string>
#include <iostream>
class Printable
{
public:
	virtual void print(std::ostream& out) const = 0;
};

class Named : Printable
{
public:
	Named(std::string name)
		: m_name(name) {}

private:
	std::string m_name;
};


