#ifndef __GAME__
#define __GAME__

#include <vector>
#include "slices.h"

class Game
{
public:
    Game();
    ~Game();
    void setup(int num);
    void print();

private:
    std::vector<Slice> *va;
    std::vector<Slice> *vb;
    std::vector<Slice> *vc;
};

#endif