#include "slices.h"
using namespace std;
Slice::Slice(std::string name, int size)
{
    _name = name;
    _size = size;
}
int Slice::GetSize()
{
    return _size;
}
std::string Slice::GetColor()
{
    return _color;
}
std::string Slice::GetName()
{
    return _name;
}