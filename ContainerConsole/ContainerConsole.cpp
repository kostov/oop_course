#include <iostream>
#include "Container.h"
#include "Shapes.h"
#include "ShapeFactory.h"
using namespace std;

int main()
{
    Container<Shape *> shapes;
    for (uint8_t i = 0; i < 20; i++)
    {
        try
        {
            Shape* s = ShapeFactory::makeShape(ShapeType(1));//i % sizeof(ShapeType)));
            shapes.push_back(s);
        }
        catch (std::exception e)
        {
            cout << e.what();
        }
    }

    shapes.print(cout);
    cout << Shape::getCount() << endl;
    shapes.clear();
    cout << Shape::getCount() << endl;

    /*Container<int> z;
    z.push_back(2);
    z.print(cout);*/

}