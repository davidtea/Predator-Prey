#include "plague.h"

Plague::Plague(): Creature(0, 0, 'l')
{
    expirestep = 0;
}

Plague::Plague(int x, int y, int p): Creature(x, y, 'l')
{
    expirestep = p;
}

void Plague::Move(Creature* grid[][YLEN])//converts everything around it to plague (NW, NE, SE, SW)
{
    expirestep++;
    Die(grid);
    int x = Xpos();
    int y = Ypos();
    if(grid[x][y] == NULL)
        return;
//    if(grid[x][y+1]->Face()!='w' && grid[x][y+1]->Face()!='t' && grid[x][y+1]->Face()!='l' && grid[x][y+1]!=NULL)//bottom
//        grid[x][y+1] = new Plague(x, y+1, expirestep);
//    if(grid[x-1][y]->Face()!='w' && grid[x-1][y]->Face()!='t' && grid[x-1][y]->Face()!='l' && grid[x-1][y]!=NULL)//left
//        grid[x-1][y] = new Plague(x-1, y, expirestep);
//    if(grid[x+1][y]->Face()!='w' && grid[x+1][y]->Face()!='t' && grid[x+1][y]->Face()!='l' && grid[x-1][y]!=NULL)//right
//        grid[x+1][y] = new Plague(x+1, y, expirestep);
//    if(grid[x][y-1]->Face()!='w' && grid[x][y-1]->Face()!='t' && grid[x][y-1]->Face()!='l' && grid[x][y+1]!=NULL)//top
//        grid[x][y-1] = new Plague(x, y-1, expirestep);
//    if(grid[x-1][y+1]->Face()!='w' && grid[x-1][y+1]->Face()!='t' && grid[x-1][y+1]->Face()!='l' && grid[x-1][y+1]!=NULL)//SW
//        grid[x-1][y+1] = new Plague(x-1, y+1, expirestep);
//    if(grid[x-1][y-1]->Face()!='w' && grid[x-1][y-1]->Face()!='t' && grid[x-1][y-1]->Face()!='l' && grid[x-1][y+1]!=NULL)//NW
//        grid[x-1][y-1] = new Plague(x-1, y-1, expirestep);
//    if(grid[x+1][y+1]->Face()!='w' && grid[x+1][y+1]->Face()!='t' && grid[x+1][y+1]->Face()!='l' && grid[x-1][y+1]!=NULL)//SE
//        grid[x+1][y+1] = new Plague(x+1, y+1, expirestep);
//    if(grid[x+1][y-1]->Face()!='w' && grid[x+1][y-1]->Face()!='t' && grid[x+1][y-1]->Face()!='l' && grid[x-1][y+1]!=NULL)//NE
//        grid[x+1][y-1] = new Plague(x+1, y-1, expirestep);
//    if(grid[x][y+1]->Face()=='h' || grid[x][y+1]->Face()=='p')
//        grid[x][y+1] = new Plague(x, y+1, expirestep);
//    else if(grid[x-1][y]->Face()=='h' || grid[x-1][y]->Face()=='p')
//        grid[x-1][y] = new Plague(x-1, y, expirestep);
//    else if(grid[x+1][y]->Face()=='h' || grid[x+1][y]->Face()=='p')
//        grid[x+1][y] = new Plague(x+1, y, expirestep);
//    else if(grid[x][y-1]->Face()=='h' || grid[x][y-1]->Face()=='p')
//        grid[x][y-1] = new Plague(x, y-1, expirestep);
//    else if(grid[x-1][y+1]->Face()=='h' || grid[x-1][y+1]->Face()=='p')
//        grid[x-1][y+1] = new Plague(x-1, y+1, expirestep);
//    else if(grid[x-1][y-1]->Face()=='h' || grid[x-1][y-1]->Face()=='p')
//        grid[x-1][y-1] = new Plague(x-1, y-1, expirestep);
//    else if(grid[x+1][y+1]->Face()=='h' || grid[x+1][y+1]->Face()=='p')
//        grid[x+1][y+1] = new Plague(x+1, y+1, expirestep);
//    else if(grid[x+1][y-1]->Face()=='h' || grid[x+1][y-1]->Face()=='p')
//        grid[x+1][y-1] = new Plague(x+1, y-1, expirestep);
    int* temp = AvailPrey(grid);
    int direction = Randomize(temp);
    switch(direction)
    {
    case 0:
        delete grid[x-1][y-1];
        grid[x-1][y-1] = new Plague(x-1, y-1, expirestep);
        break;
    case 1:
        delete grid[x][y-1];
        grid[x][y-1] = new Plague(x, y-1, expirestep);
        break;
    case 2:
        delete grid[x+1][y-1];
        grid[x+1][y-1] = new Plague(x+1, y-1, expirestep);
        break;
    case 3:
        delete grid[x-1][y];
        grid[x-1][y] = new Plague(x-1, y, expirestep);
        break;
    case 4:
        delete grid[x+1][y];
        grid[x+1][y] = new Plague(x+1, y, expirestep);
        break;
    case 5:
        delete grid[x-1][y+1];
        grid[x-1][y+1] = new Plague(x-1, y+1, expirestep);
        break;
    case 6:
        delete grid[x][y+1];
        grid[x][y+1] = new Plague(x, y+1, expirestep);
        break;
    case 7:
        delete grid[x+1][y+1];
        grid[x+1][y+1] = new Plague(x+1, y+1, expirestep);
        break;
    default:
        break;
    }
}

void Plague::Breed(Creature* grid[][YLEN])//taken care of in move
{
    //blank
}

void Plague::Die(Creature* grid[][YLEN])//dies after EXPIRETIME steps
{
    if (expirestep >= 50)
    {
        delete grid[Xpos()][Ypos()];
        grid[Xpos()][Ypos()] = NULL;
    }
}

void Plague::Eat(Creature* grid[][YLEN])//not needed
{
    //blank
}

int* Plague::AvailPrey(Creature* grid[][YLEN])//checks for preys and hunters
{
    int* array = new int[9];
    int x = Xpos();
    int y = Ypos();
    int i = 0;
    if(grid[x-1][y-1]->IsPrey() || grid[x-1][y-1]->Face()=='h')
    {
        array[i] = 0;
        i++;
    }
    if(grid[x][y-1]->IsPrey() || grid[x][y-1]->Face()=='h')
    {
        array[i] = 1;
        i++;
    }
    if(grid[x+1][y-1]->IsPrey() || grid[x+1][y-1]->Face()=='h')
    {
        array[i] = 2;
        i++;
    }
    if(grid[x-1][y]->IsPrey() || grid[x-1][y]->Face()=='h')
    {
        array[i] = 3;
        i++;
    }
    if(grid[x+1][y]->IsPrey() || grid[x+1][y]->Face()=='h')
    {
        array[i] = 4;
        i++;
    }
    if(grid[x-1][y+1]->IsPrey() || grid[x-1][y+1]->Face()=='h')
    {
        array[i] = 5;
        i++;
    }
    if(grid[x][y+1]->IsPrey() || grid[x][y+1]->Face()=='h')
    {
        array[i] = 6;
        i++;
    }
    if(grid[x+1][y+1]->IsPrey() || grid[x+1][y+1]->Face()=='h')
    {
        array[i] = 7;
        i++;
    }
    array[i] = -1;
    return array;
}
