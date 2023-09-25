#include "slices.h"

Slice::Slice(std::string name, int size)
{
    _name = name;
    _size = size;
}
int Slice::GetSize()
{
    return _size;
}