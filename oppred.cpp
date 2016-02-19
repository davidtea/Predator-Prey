#include "oppred.h"

OPpred::OPpred(): Creature(0, 0, 'o')
{
    starvecounter = 0;
}

OPpred::OPpred(int x, int y): Creature(x, y, 'o')
{
    starvecounter = 0;
}

void OPpred::Move(Creature* grid[][YLEN])
{
    starvecounter++;
    Eat(grid);
    int x = Xpos();
    int y = Ypos();
    int* temp = AvailSpots(grid);
    int direction = Randomize(temp);
    delete temp;
    switch(direction)
    {
    case 0:
        MoveCreature(grid, x-1, y-1);
        break;
    case 1:
        MoveCreature(grid, x, y-1);
        break;
    case 2:
        MoveCreature(grid, x+1, y-1);
        break;
    case 3:
        MoveCreature(grid, x-1, y);
        break;
    case 4:
        MoveCreature(grid, x+1, y);
        break;
    case 5:
        MoveCreature(grid, x-1, y+1);
        break;
    case 6:
        MoveCreature(grid, x, y+1);
        break;
    case 7:
        MoveCreature(grid, x+1, y+1);
        break;
    default:
        break;
    }
//    Breed(grid);
    Die(grid);
}

void OPpred::Breed(Creature* grid[][YLEN])//breeds after death 100
{
    if(BreedC() < 100)
        return;
    int x = Xpos();
    int y = Ypos();
    int* temp = AvailSpots(grid);
    int direction = Randomize(temp);
    switch(direction)
    {
    case 0:
        grid[x-1][y-1] = new OPpred(x-1, y-1);
        Creature::Breed(grid);
        break;
    case 1:
        grid[x][y-1] = new OPpred(x, y-1);
        Creature::Breed(grid);
        break;
    case 2:
        grid[x+1][y-1] = new OPpred(x+1, y-1);
        Creature::Breed(grid);
        break;
    case 3:
        grid[x-1][y] = new OPpred(x-1, y);
        Creature::Breed(grid);
        break;
    case 4:
        grid[x+1][y] = new OPpred(x+1, y);
        Creature::Breed(grid);
        break;
    case 5:
        grid[x-1][y+1] = new OPpred(x-1, y+1);
        Creature::Breed(grid);
        break;
    case 6:
        grid[x][y+1] = new OPpred(x, y+1);
        Creature::Breed(grid);
        break;
    case 7:
        grid[x+1][y+1] = new OPpred(x+1, y+1);
        Creature::Breed(grid);
        break;
    default:
        break;
    }
}

void OPpred::Die(Creature* grid[][YLEN])
{
    //dies after 100 steps
    if (starvecounter >= 50)
    {
        delete grid[Xpos()][Ypos()];
        grid[Xpos()][Ypos()] = NULL;
    }
}

void OPpred::Eat(Creature* grid[][YLEN])//eats everything around it, except for its own type
//and walls. also moves the same amount of times it eats.
{
    int x = Xpos();
    int y = Ypos();
    if(grid[x-1][y-1]->IsOPprey())
    {
        delete grid[x-1][y-1];
        grid[x-1][y-1] = NULL;
    }
    if(grid[x][y-1]->IsOPprey())
    {
        delete grid[x][y-1];
        grid[x][y-1] = NULL;
    }
    if(grid[x+1][y-1]->IsOPprey())
    {
        delete grid[x+1][y-1];
        grid[x+1][y-1] = NULL;
    }
    if(grid[x-1][y]->IsOPprey())
    {
        delete grid[x-1][y];
        grid[x-1][y] = NULL;
    }
    if(grid[x+1][y]->IsOPprey())
    {
        delete grid[x+1][y];
        grid[x+1][y] = NULL;
    }
    if(grid[x-1][y+1]->IsOPprey())
    {
        delete grid[x-1][y+1];
        grid[x-1][y+1] = NULL;
    }
    if(grid[x][y+1]->IsOPprey())
    {
        delete grid[x][y+1];
        grid[x][y+1] = NULL;
    }
    if(grid[x+1][y+1]->IsOPprey())
    {
        delete grid[x+1][y+1];
        grid[x+1][y+1] = NULL;
    }

}

int* OPpred::AvailPrey(Creature* grid[][YLEN])//like availspots for creature, except checks for prey instead
{
    int* array = new int[9];
    int x = Xpos();
    int y = Ypos();
    int i = 0;
    if(grid[x-1][y-1]->IsOPprey())
    {
        array[i] = 0;
        i++;
    }
    if(grid[x][y-1]->IsOPprey())
    {
        array[i] = 1;
        i++;
    }
    if(grid[x+1][y-1]->IsOPprey())
    {
        array[i] = 2;
        i++;
    }
    if(grid[x-1][y]->IsOPprey())
    {
        array[i] = 3;
        i++;
    }
    if(grid[x+1][y]->IsOPprey())
    {
        array[i] = 4;
        i++;
    }
    if(grid[x-1][y+1]->IsOPprey())
    {
        array[i] = 5;
        i++;
    }
    if(grid[x][y+1]->IsOPprey())
    {
        array[i] = 6;
        i++;
    }
    if(grid[x+1][y+1]->IsOPprey())
    {
        array[i] = 7;
        i++;
    }
    array[i] = -1;
    return array;
}

void OPpred::Show(ostream &out)
{
    out<<"O";
}
