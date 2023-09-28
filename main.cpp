#include <iostream>
#include "game.h"

using namespace std;

int main()
{
    int sli = 5;
    // cout << "How many slices?: ";
    // cin >> sli;

    Game *g = new Game();
    g->setup(sli);
    // g->move(TowerA, TowerB);
    g->solve();
    delete g;
    return 0;
}