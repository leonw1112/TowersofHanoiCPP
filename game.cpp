#include <iostream>
#include <vector>
#include "game.h"
#include "slices.h"
using namespace std;

Game::Game()
{
    va = new std::vector<Slice>();
    vb = new std::vector<Slice>();
    vc = new std::vector<Slice>();
}

Game::~Game()
{
    delete va;
    delete vb;
    delete vc;
}

void Game::setup(int num)
{
    for (int i = 1; i <= num; i++)
    {
        va->push_back(Slice("S" + i, i));
    }
}
void Game::print()
{

    for (int i = 0; i < va->size(); i++)
    {
        // int x = va->at(i).GetSize();
        cout << va->at(i).GetSize() << " | " << va->at(i).GetSize() << "\n";
        // cout << i << endl;
    }
    cout << "--A-- \n";
}