#include "teleport.h"

Teleport::Teleport(): Creature(0, 0, 't')
{
    spawncount = 0;
    starve = 0;
}

Teleport::Teleport(int x, int y): Creature(x, y, 't')
{
    spawncount = 0;
    starve = 0;
}

void Teleport::Move(Creature* grid[][YLEN])
{
    int x = rand()%(XLEN);
    int y = rand()%(YLEN);
    for (int i=0; i<10; i++)//so that it doesnt check forever
    {
        if(grid[x][y] == NULL)
            break;
        x = rand()%(XLEN);
        y = rand()%(YLEN);
    }
    if(grid[x][y] == NULL)
    {
        starve++;
        MoveCreature(grid, x, y);
        spawncount++;
        Breed(grid);
        Spawn(grid);
        Die(grid);
    }
}

void Teleport::Breed(Creature* grid[][YLEN])
{
    //after 20 steps another one spawns
    if(BreedC() >= 20)
    {
        int x = Xpos();
        int y = Ypos();
        int* temp = AvailSpots(grid);
        int direction = Randomize(temp);
        switch(direction)
        {
        case 0:
            grid[x-1][y-1] = new Teleport(x-1, y-1);
            Creature::Breed(grid);
            break;
        case 1:
            grid[x][y-1] = new Teleport(x, y-1);
            Creature::Breed(grid);
            break;
        case 2:
            grid[x+1][y-1] = new Teleport(x+1, y-1);
            Creature::Breed(grid);
            break;
        case 3:
            grid[x-1][y] = new Teleport(x-1, y);
            Creature::Breed(grid);
            break;
        case 4:
            grid[x+1][y] = new Teleport(x+1, y);
            Creature::Breed(grid);
            break;
        case 5:
            grid[x-1][y+1] = new Teleport(x-1, y+1);
            Creature::Breed(grid);
            break;
        case 6:
            grid[x][y+1] = new Teleport(x, y+1);
            Creature::Breed(grid);
            break;
        case 7:
            grid[x+1][y+1] = new Teleport(x+1, y+1);
            Creature::Breed(grid);
            break;
        default:
            break;
        }
    }
//    if(BreedC() >= 20)
//    {
//        for(int i=0; i<8; i++)
//        {
//            int x = Xpos();
//            int y = Ypos();
//            int randx = (rand()%3 - 1);
//            int randy = (rand()%3 - 1);
//            int tempx = (x-randx);
//            int tempy = (y-randy);
//            if(grid[tempx][tempy] == NULL)
//            {
//                grid[tempx][tempy] = new Teleport(tempx, tempy);
//                Creature::Breed(grid);
//                return;
//            }
//        }
//    }
}

void Teleport::Spawn(Creature* grid[][YLEN])
{
    //every 25 steps, spawns prey
    int x = Xpos();
    int y = Ypos();
    if(spawncount<25)
    {
        return;
    }
    if(grid[x-1][y-1] == NULL)
    {
        grid[x-1][y-1] = new OPpred(x-1, y-1);
    }
    if(grid[x][y-1] == NULL)
    {
        grid[x][y-1] = new OPpred(x, y-1);
    }
    if(grid[x+1][y-1] == NULL)
    {
        grid[x+1][y-1] = new OPpred(x+1, y-1);
    }
    if(grid[x-1][y] == NULL)
    {
        grid[x-1][y] = new OPpred(x-1, y);
    }
    if(grid[x+1][y] == NULL)
    {
        grid[x+1][y] = new OPpred(x+1, y);
    }
    if(grid[x-1][y+1] == NULL)
    {
        grid[x-1][y+1] = new OPpred(x-1, y+1);
    }
    if(grid[x][y+1] == NULL)
    {
        grid[x][y+1] = new OPpred(x, y+1);
    }
    if(grid[x+1][y+1] == NULL)
    {
        grid[x+1][y+1] = new OPpred(x+1, y+1);
    }
    spawncount = 0;
}

void Teleport::Die(Creature* grid[][YLEN])
{
    //after 25 steps
    if (starve >= 25)
    {
        delete grid[Xpos()][Ypos()];
        grid[Xpos()][Ypos()] = NULL;
    }
}

void Teleport::Show(ostream& out)
{
    out<<"T";
}
