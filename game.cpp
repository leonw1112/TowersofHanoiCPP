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

    for (std::size_t i = 0; i < va->size(); i++)
    {
        cout << va->at(i).GetSize() << " | " << va->at(i).GetSize() << "\n";
    }
    cout << "--A-- \n";
    for (std::size_t i = 0; i < vb->size(); i++)
    {
        cout << vb->at(i).GetSize() << " | " << vb->at(i).GetSize() << "\n";
    }
    cout << "--B-- \n";
    for (std::size_t i = 0; i < vc->size(); i++)
    {
        cout << vc->at(i).GetSize() << " | " << vc->at(i).GetSize() << "\n";
    }
    cout << "--C-- \n";
}