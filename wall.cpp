#include "wall.h"

Wall::Wall(): Creature(0,0,'w')
{
    //intentionally left blank
}

Wall::Wall(int x, int y): Creature(x,y,'w')
{
    //intentionally left blank
}

void Wall::Move(Creature *grid[][YLEN])
{
    //do nothing, its a wall
}

void Wall::Breed(Creature* grid[][YLEN])
{
    //do nothing, its a wall
}

void Wall::Die(Creature* grid[][YLEN])
{
    //do nothing, its a wall
}

void Wall::Show(ostream &out)
{
    out<<"/";
}
