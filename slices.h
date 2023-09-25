#ifndef __SLICE__
#define __SLICE__

#include <iostream>

class Slice
{
private:
    std::string _name;
    int _size;

public:
    Slice(std::string name, int size);
    int GetSize();
};

#endif