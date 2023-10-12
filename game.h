#ifndef GAME_H
#define GAME_H

#include "slices.h"
#include <vector>

// Enum für die Türme
enum Tower
{
    TowerA,
    TowerB,
    TowerC
};

class Game
{
public:
    Game();
    ~Game();

    void setup(int num);
    void print();
    void print_bw();
    void print_color();
    void move(Tower source, Tower destination);
    void solve();
    void solve_recursive(int n, Tower source, Tower auxiliary, Tower destination);
    void solve_iterative(int n, Tower source, Tower auxiliary, Tower destination);
    void save();
    void load();

private:
    std::vector<Slice> *va;
    std::vector<Slice> *vb;
    std::vector<Slice> *vc;
    int count_moves;
    int num_slices;
    const char *color[5] = {"blue", "red", "yellow", "green", "magenta"};
};

#endif
