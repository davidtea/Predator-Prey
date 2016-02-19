#ifndef GRID_H
#define GRID_H
#include <iostream>
#include "hunter.h"
#include "prey.h"
#include "wall.h"
#include "teleport.h"
#include "oppred.h"
#include "plague.h"

using namespace std;

class Grid
{
public:
    Grid();
    Grid(int h, int p, int t, int op);
    ~Grid();
    int** returngrid();
    void Add(int h, int p, int t, int op, int pl);
    void NextTurn();

    friend ostream& operator <<(ostream& out, const Grid& G);

private:
    Creature* grid[XLEN][YLEN];
    int steps;
    int spawnplague;

};

#endif // GRID_H
