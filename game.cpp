#include "game.h"
#include <string>
#include <iostream>
#include <fstream>

#include <string>
#include <vector>

#define RESET "\033[0m"
#define BLACK "\033[30m"              /* Black */
#define RED "\033[31m"                /* Red */
#define GREEN "\033[32m"              /* Green */
#define YELLOW "\033[33m"             /* Yellow */
#define BLUE "\033[34m"               /* Blue */
#define MAGENTA "\033[35m"            /* Magenta */
#define CYAN "\033[36m"               /* Cyan */
#define WHITE "\033[37m"              /* White */
#define BOLDBLACK "\033[1m\033[30m"   /* Bold Black */
#define BOLDRED "\033[1m\033[31m"     /* Bold Red */
#define BOLDGREEN "\033[1m\033[32m"   /* Bold Green */
#define BOLDYELLOW "\033[1m\033[33m"  /* Bold Yellow */
#define BOLDBLUE "\033[1m\033[34m"    /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m" /* Bold Magenta */
#define BOLDCYAN "\033[1m\033[36m"    /* Bold Cyan */
#define BOLDWHITE "\033[1m\033[37m"   /* Bold White */

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
    save();
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
void Game::solve_iterative(int n, Tower source, Tower auxiliary, Tower destination)
{
    int total_moves = (1 << n) - 1;
    if (n % 2 == 1)
    {
        Tower temp = auxiliary;
        auxiliary = destination;
        destination = temp;
    }

    for (int i = 1; i <= total_moves; ++i)
    {
        if (i % 3 == 1)
        {
            move(source, destination);
        }
        else if (i % 3 == 2)
        {
            move(source, auxiliary);
        }
        else
        {
            move(auxiliary, destination);
        }
    }
}

void Game::solve()
{
    int numSlices = va->size();
    solve_recursive(numSlices, TowerA, TowerB, TowerC);
    // solve_iterative(numSlices, TowerA, TowerB, TowerC);
}

void Game::save()
{
    ofstream savefile;
    savefile.open("savefile.txt");
    savefile << "A;";
    for (int i = static_cast<int>(va->size()) - 1; i >= 0; i--)
    {
        savefile << va->at(i).GetSize() << ";";
    }
    savefile << endl;
    savefile << "B;";
    for (int i = static_cast<int>(vb->size()) - 1; i >= 0; i--)
    {
        savefile << vb->at(i).GetSize() << ";";
    }
    savefile << endl;
    savefile << "C;";
    for (int i = static_cast<int>(vc->size()) - 1; i >= 0; i--)
    {
        savefile << vc->at(i).GetSize() << ";";
    }
    savefile << endl;
    savefile.close();
}

void Game::load()
{
}