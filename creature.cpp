#include "creature.h"

Creature::Creature()
{
    breedcounter = 0;
    xpos = 0;
    ypos = 0;
    face = 'c';
    moved = true;
}

Creature::Creature(int x, int y, char type)
{
    breedcounter = 0;
    xpos = x;
    ypos = y;
    face = type;
    moved = true;
}

void Creature::MoveCreature(Creature* grid[][YLEN], int x, int y)
{
    if(!moved && grid[x][y] == NULL)
    {
        grid[x][y] = grid[xpos][ypos];
        grid[xpos][ypos] = NULL;
        xpos = x;
        ypos = y;
        breedcounter++;
    }
    moved = true;
}

int* Creature::AvailSpots(Creature* grid[][YLEN])//creates an array of available spots
{
    int* array = new int[9];
    int x = xpos;
    int y = ypos;
    int i=0;
    if(grid[x-1][y-1] == NULL)
    {
        array[i] = 0;
        i++;
    }
    if(grid[x][y-1] == NULL)
    {
        array[i] = 1;
        i++;
    }
    if(grid[x+1][y-1] == NULL)
    {
        array[i] = 2;
        i++;
    }
    if(grid[x-1][y] == NULL)
    {
        array[i] = 3;
        i++;
    }
    if(grid[x+1][y] == NULL)
    {
        array[i] = 4;
        i++;
    }
    if(grid[x-1][y+1] == NULL)
    {
        array[i] = 5;
        i++;
    }
    if(grid[x][y+1] == NULL)
    {
        array[i] = 6;
        i++;
    }
    if(grid[x+1][y+1] == NULL)
    {
        array[i] = 7;
        i++;
    }
    array[i] = -1;
    return array;
}

int Creature::Randomize(int* array)//returns random number (position to move to)
{
    int i=0;
    while(array[i] != -1)
    {
        i++;//size of array
    }
    if(i == 0)
        return -1;
    int rnum = rand()%i;
    int temp = array[rnum];
    delete[] array;
    return temp;
}

int Creature::BreedC()
{
    return breedcounter;
}

void Creature::BreedInc()
{
    breedcounter++;
}

char Creature::Face()
{
    if (this == NULL)
        return 'n';
    else
        return face;
}

int Creature::Xpos()
{
    return xpos;
}

int Creature::Ypos()
{
    return ypos;
}

bool Creature::IsPrey()
{
    if(this == NULL)
        return false;
    else if(face == 'p')
        return true;
    else
        return false;
}

bool Creature::IsOPprey()
{
    if(this == NULL)
        return false;
    else if(face == 'p' || face == 'h')
        return true;
    else
        return false;
}

bool Creature::Movedyet()
{
    return moved;
}

void Creature::MoveReset()
{
    moved = false;
}

void Creature::Move(Creature *grid[][YLEN])
{
    //blank
}

void Creature::Breed(Creature* grid[][YLEN])
{
    breedcounter = 0;
}

void Creature::Die(Creature* grid[][YLEN])
{
    grid[xpos][ypos] = NULL;
}
void Creature::Show(ostream& out)
{
    out<<"X";
}

ostream& operator <<(ostream& out, Creature& C)
{
    C.Show(out);
    return out;
}
