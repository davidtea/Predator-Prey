#include "hunter.h"

Hunter::Hunter(): Creature(0,0,'h')
{
    starvecounter = 0;
}

Hunter::Hunter(int x, int y): Creature(x,y,'h')
{
    starvecounter = 0;
}

void Hunter::Move(Creature *grid[][YLEN])
{
    starvecounter++;
    int* temp = AvailPrey(grid);
    if(*temp == -1) //if no prey
    {
        temp = AvailSpots(grid);
    }
    int direction = Randomize(temp);
    switch(direction)
    {
    case 0:
        Eat(grid, 0);
        break;
    case 1:
        Eat(grid, 1);
        break;
    case 2:
        Eat(grid, 2);
        break;
    case 3:
        Eat(grid, 3);
        break;
    case 4:
        Eat(grid, 4);
        break;
    case 5:
        Eat(grid, 5);
        break;
    case 6:
        Eat(grid, 6);
        break;
    case 7:
        Eat(grid, 7);
        break;
    default:
        break;
    }
    delete temp;
    Breed(grid);
    Die(grid);
}

void Hunter::Breed(Creature* grid[][YLEN])
{
    if(BreedC() < 8)
        return;
    int x = Xpos();
    int y = Ypos();
    int* temp = AvailSpots(grid);
    int direction = Randomize(temp);
    switch(direction)
    {
    case 0:
        grid[x-1][y-1] = new Hunter(x-1, y-1);
        Creature::Breed(grid);
        break;
    case 1:
        grid[x][y-1] = new Hunter(x, y-1);
        Creature::Breed(grid);
        break;
    case 2:
        grid[x+1][y-1] = new Hunter(x+1, y-1);
        Creature::Breed(grid);
        break;
    case 3:
        grid[x-1][y] = new Hunter(x-1, y);
        Creature::Breed(grid);
        break;
    case 4:
        grid[x+1][y] = new Hunter(x+1, y);
        Creature::Breed(grid);
        break;
    case 5:
        grid[x-1][y+1] = new Hunter(x-1, y+1);
        Creature::Breed(grid);
        break;
    case 6:
        grid[x][y+1] = new Hunter(x, y+1);
        Creature::Breed(grid);
        break;
    case 7:
        grid[x+1][y+1] = new Hunter(x+1, y+1);
        Creature::Breed(grid);
        break;
    default:
        break;
    }
}

void Hunter::Die(Creature* grid[][YLEN])
{
    if (starvecounter >= 3)
    {
        delete grid[Xpos()][Ypos()];
        grid[Xpos()][Ypos()] = NULL;
    }
}

void Hunter::Eat(Creature* grid[][YLEN], int direction)
{
    int x = Xpos();
    int y = Ypos();
    switch(direction)
    {
    case 0:
        if(grid[x-1][y-1]->IsPrey())
        {
            starvecounter = 0;
            delete grid[x-1][y-1];
            grid[x-1][y-1] = NULL;
        }
        MoveCreature(grid, x-1, y-1);
        break;
    case 1:
        if(grid[x][y-1]->IsPrey())
        {
            starvecounter = 0;
            delete grid[x][y-1];
            grid[x][y-1] = NULL;
        }
        MoveCreature(grid, x, y-1);
        break;
    case 2:
        if(grid[x+1][y-1]->IsPrey())
        {
            starvecounter = 0;
            delete grid[x+1][y-1];
            grid[x+1][y-1] = NULL;
        }
        MoveCreature(grid, x+1, y-1);
        break;
    case 3:
        if(grid[x-1][y]->IsPrey())
        {
            starvecounter = 0;
            delete grid[x-1][y];
            grid[x-1][y] = NULL;
        }
        MoveCreature(grid, x-1, y);
        break;
    case 4:
        if(grid[x+1][y]->IsPrey())
        {
            starvecounter = 0;
            delete grid[x+1][y];
            grid[x+1][y] = NULL;
        }
        MoveCreature(grid, x+1, y);
        break;
    case 5:
        if(grid[x-1][y+1]->IsPrey())
        {
            starvecounter = 0;
            delete grid[x-1][y+1];
            grid[x-1][y+1] = NULL;
        }
        MoveCreature(grid, x-1, y+1);
        break;
    case 6:
        if(grid[x][y+1]->IsPrey())
        {
            starvecounter = 0;
            delete grid[x][y+1];
            grid[x][y+1] = NULL;
        }
        MoveCreature(grid, x, y+1);
        break;
    case 7:
        if(grid[x+1][y+1]->IsPrey())
        {
            starvecounter = 0;
            delete grid[x+1][y+1];
            grid[x+1][y+1] = NULL;
        }
        MoveCreature(grid, x+1, y+1);
        break;
    default:
        break;
    }
}

int* Hunter::AvailPrey(Creature* grid[][YLEN])
{
    int* array = new int[9];
    int x = Xpos();
    int y = Ypos();
    int i = 0;
    if(grid[x-1][y-1]->IsPrey())
    {
        array[i] = 0;
        i++;
    }
    if(grid[x][y-1]->IsPrey())
    {
        array[i] = 1;
        i++;
    }
    if(grid[x+1][y-1]->IsPrey())
    {
        array[i] = 2;
        i++;
    }
    if(grid[x-1][y]->IsPrey())
    {
        array[i] = 3;
        i++;
    }
    if(grid[x+1][y]->IsPrey())
    {
        array[i] = 4;
        i++;
    }
    if(grid[x-1][y+1]->IsPrey())
    {
        array[i] = 5;
        i++;
    }
    if(grid[x][y+1]->IsPrey())
    {
        array[i] = 6;
        i++;
    }
    if(grid[x+1][y+1]->IsPrey())
    {
        array[i] = 7;
        i++;
    }
    array[i] = -1;
    return array;
}

void Hunter::Show(ostream& out)
{
    out<<"H";
}
