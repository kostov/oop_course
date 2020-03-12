// ContainerConsole.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Container.h"

template <class T>
void print(Container<T> c)
{
    std::cout << "Size: " << c.size() << std::endl;
    std::cout << "Empty?: " << c.empty() << std::endl;

    for (uint32_t i = 0; i < c.size(); i++)
    {
        std::cout << c[i] << std::endl;
    }
}


int main()
{
    Container<int> boop;
    boop.push_back(INT_MAX);
    boop.push_back(255);
    boop.push_back(257);
    
    print(boop);
    std::cout << std::endl;
    /*
    boop.clear();
    print(boop);
    std::cout << std::endl;

    Container<int> boob(boop);
    boob.push_back(INT_MIN);
    print(boob);
    std::cout << std::endl;

    Container<int> rawr(1);
    rawr.push_back(2);
    rawr.pop_back();

    print(rawr);*/
    //boob.push_back(10);
   //std::cout << boob[boob.size()-1];
}