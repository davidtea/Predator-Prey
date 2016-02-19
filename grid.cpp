#include "grid.h"

Grid::Grid()
{
    steps = 0;
    for (int i=0; i<XLEN; i++)
    {
        for (int j=0; j<YLEN; j++)
        {
            grid[i][j] = NULL;
        }
    }
    for (int i=0; i<XLEN; i++)
    {
        grid[0][i] = new Wall(0,i);
        grid[XLEN-1][i] = new Wall(XLEN-1,i);
        grid[i][0] = new Wall(i,0);
        grid[i][YLEN-1] = new Wall(i,YLEN-1);
    }
    spawnplague = 0;
}

Grid::Grid(int h, int p, int t, int op)
{
    steps = 0;
    spawnplague = 0;
    srand(time(NULL));
    for (int i=0; i<XLEN; i++)
    {
        for (int j=0; j<YLEN; j++)
        {
            grid[i][j] = NULL;
        }
    }
    for (int i=0; i<XLEN; i++)
    {
        grid[0][i] = new Wall(0,i);
        grid[XLEN-1][i] = new Wall(XLEN-1,i);
        grid[i][0] = new Wall(i,0);
        grid[i][YLEN-1] = new Wall(i,YLEN-1);
    }

//    grid[1][1] = new Hunter(1,1);
//    grid[1][2] = new Prey(1,2);

    for (int i=0; i<h; i++)//for hunters
    {
        int x = rand()%(XLEN);
        int y = rand()%(YLEN);
        while (grid[x][y] != NULL)
        {
            x = rand()%(XLEN);
            y = rand()%(YLEN);
        }
        grid[x][y] = new Hunter(x,y);
    }
    for (int i=0; i<p; i++)//for prey
    {
        int x = rand()%(XLEN);
        int y = rand()%(YLEN);
        while (grid[x][y] != NULL)
        {
            x = rand()%(XLEN);
            y = rand()%(YLEN);
        }
        grid[x][y] = new Prey(x,y);
    }
    for (int i=0; i<t; i++)//for teleporters
    {
        int x = rand()%(XLEN);
        int y = rand()%(YLEN);
        while (grid[x][y] != NULL)
        {
            x = rand()%(XLEN);
            y = rand()%(YLEN);
        }
        grid[x][y] = new Teleport(x,y);
    }
    for (int i=0; i<op; i++)//for OPpreds
    {
        int x = rand()%(XLEN);
        int y = rand()%(YLEN);
        while (grid[x][y] != NULL)
        {
            x = rand()%(XLEN);
            y = rand()%(YLEN);
        }
        grid[x][y] = new OPpred(x,y);
    }
}

Grid::~Grid()
{
    for (int i=0; i<XLEN; i++)
    {
        for (int j=0; j<YLEN; j++)
        {
            delete grid[i][j];
        }
    }
}

int** Grid::returngrid()
{
    int** intgrid = new int*[XLEN];
    for (int i=0; i<XLEN; i++)
    {
        intgrid[i] = new int[YLEN];
    }
    for (int i=0; i<XLEN; i++)
    {
        for (int j=0; j<YLEN; j++)
        {
            if(grid[i][j]->Face() == 'h')
                intgrid[i][j] = 0;
            else if(grid[i][j]->Face() == 'p')
                intgrid[i][j] = 1;
            else if(grid[i][j]->Face() == 'w')
                intgrid[i][j] = 2;
            else if(grid[i][j]->Face() == 't')
                intgrid[i][j] = 4;
            else if(grid[i][j]->Face() == 'o')
                intgrid[i][j] = 5;
            else if(grid[i][j]->Face() == 'l')
                intgrid[i][j] = 6;
            else
                intgrid[i][j] = 3;
        }
    }
    return intgrid;
}

void Grid::Add(int h, int p, int t, int op, int pl)
{
    for (int i=0; i<h; i++)//for hunters
    {
        int x = rand()%(XLEN);
        int y = rand()%(YLEN);
        while (grid[x][y] != NULL)
        {
            x = rand()%(XLEN);
            y = rand()%(YLEN);
        }
        grid[x][y] = new Hunter(x,y);
    }
    for (int i=0; i<p; i++)//for prey
    {
        int x = rand()%(XLEN);
        int y = rand()%(YLEN);
        while (grid[x][y] != NULL)
        {
            x = rand()%(XLEN);
            y = rand()%(YLEN);
        }
        grid[x][y] = new Prey(x,y);
    }
    for (int i=0; i<t; i++)//for teleport
    {
        int x = rand()%(XLEN);
        int y = rand()%(YLEN);
        while (grid[x][y] != NULL)
        {
            x = rand()%(XLEN);
            y = rand()%(YLEN);
        }
        grid[x][y] = new Teleport(x,y);
    }
    for (int i=0; i<op; i++)//for OPpred
    {
        int x = rand()%(XLEN);
        int y = rand()%(YLEN);
        while (grid[x][y] != NULL)
        {
            x = rand()%(XLEN);
            y = rand()%(YLEN);
        }
        grid[x][y] = new OPpred(x,y);
    }
    for (int i=0; i<pl; i++)//for plague
    {
        int x = rand()%(XLEN);
        int y = rand()%(YLEN);
        while (grid[x][y]->Face() != 'h' && grid[x][y]->Face() != 'p')
        {
            x = rand()%(XLEN);
            y = rand()%(YLEN);
        }
        delete grid[x][y];
        grid[x][y] = new Plague(x,y,0);
    }
}

void Grid::NextTurn()
{
    for (int i=0; i<XLEN; i++)
    {
        for (int j=0; j<YLEN; j++)
        {
            if(grid[i][j] != NULL)
                grid[i][j]->MoveReset();
        }
    }
    for (int i=0; i<XLEN; i++)
    {
        for (int j=0; j<YLEN; j++)
        {
            if(grid[i][j] != NULL && !grid[i][j]->Movedyet())
                grid[i][j]->Move(grid);
        }
    }
    if(spawnplague >= 40)
    {
        Add(0,0,0,0,5);
        spawnplague = 0;
    }
    steps++;
    spawnplague++;
}

ostream& operator<<(ostream& out, const Grid& G)
{
    for(int i=0; i<XLEN; i++)
    {
        for (int j=0; j<YLEN; j++)
        {
            if (G.grid[j][i] == NULL)
                out<<"-";
            else
                out<<*G.grid[j][i];
        }
        out<<endl;
    }
    out<<endl;
    out<<"Steps:  "<<G.steps<<endl;
    return out;
}

