#include <iostream>
#include "game.h"

using namespace std;

int main()
{
    int sli;
    cout << "How many slices?: ";
    cin >> sli;
    Game *g = new Game();

    g->setup(sli);
    // g->load();

    try
    {
        g->solve();
    }
    catch (const char *msg)
    {
        cout << "cought exception: " << msg << endl;
    }
    delete g;

    return 0;
}