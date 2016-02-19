#include "prey.h"

Prey::Prey(): Creature(0,0,'p')
{
    //intentionally left blank
}

Prey::Prey(int x, int y): Creature(x,y,'p')
{
    //intentionally left blank
}

void Prey::Move(Creature *grid[][YLEN])
{
    int* temp = AvailSpots(grid);
    int direction = Randomize(temp);
    int x = Xpos();
    int y = Ypos();
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
    delete temp;
    Breed(grid);
}

void Prey::Breed(Creature* grid[][YLEN])
{
    if(BreedC() >= 3)
        {
            int x = Xpos();
            int y = Ypos();
            int* temp = AvailSpots(grid);
            int direction = Randomize(temp);
            switch(direction)
            {
            case 0:
                grid[x-1][y-1] = new Prey(x-1, y-1);
                Creature::Breed(grid);
                break;
            case 1:
                grid[x][y-1] = new Prey(x, y-1);
                Creature::Breed(grid);
                break;
            case 2:
                grid[x+1][y-1] = new Prey(x+1, y-1);
                Creature::Breed(grid);
                break;
            case 3:
                grid[x-1][y] = new Prey(x-1, y);
                Creature::Breed(grid);
                break;
            case 4:
                grid[x+1][y] = new Prey(x+1, y);
                Creature::Breed(grid);
                break;
            case 5:
                grid[x-1][y+1] = new Prey(x-1, y+1);
                Creature::Breed(grid);
                break;
            case 6:
                grid[x][y+1] = new Prey(x, y+1);
                Creature::Breed(grid);
                break;
            case 7:
                grid[x+1][y+1] = new Prey(x+1, y+1);
                Creature::Breed(grid);
                break;
            default:
                break;
            }
        }
//    if(BreedC() >= 3)
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
//                grid[tempx][tempy] = new Prey(tempx, tempy);
//                Creature::Breed(grid);
//                return;
//            }
//        }
//    }
}

void Prey::Die(Creature* grid[][YLEN])
{
    //blank
}

void Prey::Show(ostream& out)
{
    out<<"P";
}
