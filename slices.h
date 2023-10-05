#ifndef __SLICE__
#define __SLICE__
#include <iostream>

using namespace std;

class Slice
{
private:
    std::string _name;
    int _size;
    std::string _color;

public:
    Slice(std::string name, int size, std::string color);
    std::string GetName();
    std::string GetColor();
    int GetSize();
};

#endif