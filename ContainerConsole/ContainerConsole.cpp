#include <iostream>
#include "Container.h"
#include "Shapes.h"
#include "ShapeFactory.h"
using namespace std;

int main()
{
    Container<Shape*> shapes;
    for (uint8_t i = 0; i < 20; i++)
    {
        try
        {
            Shape* s = ShapeFactory::makeShape(ShapeType(i % 7));
            cout << *s << endl;
        }
        catch (std::exception e)
        {
            cout << e.what();
        }
    }
}