#include "game.h"
#include <string>
#include <iostream>
#include <fstream>

#include <string>
#include <vector>

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
    cout << "Preparing Game with " << num << " Slices." << endl;
    const char *color[5] = {"blue", "red", "yellow", "green", "magenta"};
    for (int i = num; i > 0; i--)
    {
        va->push_back(Slice("S" + i, i, color[i % num]));
    }
}

void Game::print()
{
    cout << "A = ";
    for (int i = static_cast<int>(va->size()) - 1; i >= 0; i--)
    {
        if (va->at(i).GetColor() == "blue")
        {
            cout << "\033[1;34m" << va->at(i).GetSize() << "\033[1;0m"
                 << ", ";
        }
        else if (va->at(i).GetColor() == "red")
        {
            cout << "\033[1;31m" << va->at(i).GetSize() << "\033[1;0m"
                 << ", ";
        }
        else if (va->at(i).GetColor() == "yellow")
        {
            cout << "\033[1;33m" << va->at(i).GetSize() << "\033[1;0m"
                 << ", ";
        }
        else if (va->at(i).GetColor() == "green")
        {
            cout << "\033[1;32m" << va->at(i).GetSize() << "\033[1;0m"
                 << ", ";
        }
        else if (va->at(i).GetColor() == "magenta")
        {
            cout << "\033[1;35m" << va->at(i).GetSize() << "\033[1;0m"
                 << ", ";
        }
    }
    cout << " | ";

    cout << "B = ";
    for (int i = static_cast<int>(vb->size()) - 1; i >= 0; i--)
    {
        if (vb->at(i).GetColor() == "blue")
        {
            cout << "\033[1;34m" << vb->at(i).GetSize() << "\033[1;0m"
                 << ", ";
        }
        else if (vb->at(i).GetColor() == "red")
        {
            cout << "\033[1;31m" << vb->at(i).GetSize() << "\033[1;0m"
                 << ", ";
        }
        else if (vb->at(i).GetColor() == "yellow")
        {
            cout << "\033[1;33m" << vb->at(i).GetSize() << "\033[1;0m"
                 << ", ";
        }
        else if (vb->at(i).GetColor() == "green")
        {
            cout << "\033[1;32m" << vb->at(i).GetSize() << "\033[1;0m"
                 << ", ";
        }
        else if (vb->at(i).GetColor() == "magenta")
        {
            cout << "\033[1;35m" << vb->at(i).GetSize() << "\033[1;0m"
                 << ", ";
        }
    }
    cout << " | ";

    cout << "C = ";
    for (int i = static_cast<int>(vc->size()) - 1; i >= 0; i--)
    {
        if (vc->at(i).GetColor() == "blue")
        {
            cout << "\033[1;34m" << vc->at(i).GetSize() << "\033[1;0m"
                 << ", ";
        }
        else if (vc->at(i).GetColor() == "red")
        {
            cout << "\033[1;31m" << vc->at(i).GetSize() << "\033[1;0m"
                 << ", ";
        }
        else if (vc->at(i).GetColor() == "yellow")
        {
            cout << "\033[1;33m" << vc->at(i).GetSize() << "\033[1;0m"
                 << ", ";
        }
        else if (vc->at(i).GetColor() == "green")
        {
            cout << "\033[1;32m" << vc->at(i).GetSize() << "\033[1;0m"
                 << ", ";
        }
        else if (vc->at(i).GetColor() == "magenta")
        {
            cout << "\033[1;35m" << vc->at(i).GetSize() << "\033[1;0m"
                 << ", ";
        }
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