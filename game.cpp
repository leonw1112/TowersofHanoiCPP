#include "game.h"
#include <string>
using namespace std;
Game::Game()
{
    va = new std::vector<Slice>();
    vb = new std::vector<Slice>();
    vc = new std::vector<Slice>();
    count_moves = 0;
}

Game::~Game()
{
    delete va;
    delete vb;
    delete vc;
}

void Game::setup(int num)
{
    for (int i = num; i > 0; i--)
    {
        va->push_back(Slice("S" + i, i));
    }
}

void Game::print()
{
    cout << "A = ";
    for (int i = static_cast<int>(va->size()) - 1; i >= 0; i--)
    {
        cout << va->at(i).GetSize() << ", ";
    }
    cout << " | ";

    cout << "B = ";
    for (int i = static_cast<int>(vb->size()) - 1; i >= 0; i--)
    {
        cout << vb->at(i).GetSize() << ", ";
    }
    cout << " | ";

    cout << "C = ";
    for (int i = static_cast<int>(vc->size()) - 1; i >= 0; i--)
    {
        cout << vc->at(i).GetSize() << ", ";
    }
    cout << " | ";
    cout << count_moves << ".";
    cout << endl;
}

void Game::move(Tower source, Tower destination)
{
    std::vector<Slice> *sourceTower;
    std::vector<Slice> *destinationTower;
    switch (source)
    {
    case TowerA:
        sourceTower = va;
        break;
    case TowerB:
        sourceTower = vb;
        break;
    case TowerC:
        sourceTower = vc;
        break;
    }
    switch (destination)
    {
    case TowerA:
        destinationTower = va;
        break;
    case TowerB:
        destinationTower = vb;
        break;
    case TowerC:
        destinationTower = vc;
        break;
    }
    if (sourceTower->size() > 0)
    {
        Slice x = sourceTower->back();
        sourceTower->pop_back();
        destinationTower->push_back(x);
    }
    count_moves++;
    print();
}

void Game::solve_recursive(int n, Tower source, Tower auxiliary, Tower destination)
{
    if (n > 0)
    {

        solve_recursive(n - 1, source, destination, auxiliary);

        move(source, destination);

        solve_recursive(n - 1, auxiliary, source, destination);
    }
}
void Game::solve()
{
    int numSlices = va->size();
    solve_recursive(numSlices, TowerA, TowerB, TowerC);
}