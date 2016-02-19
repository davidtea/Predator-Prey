#ifndef WALL_H
#define WALL_H
#include "creature.h"

class Wall : public Creature
{
public:
    Wall();
    Wall(int x, int y);
    ~Wall(){};

    void Move(Creature* grid[][YLEN]);
    void Breed(Creature* grid[][YLEN]);
    void Die(Creature* grid[][YLEN]);
    void Show(ostream& out);
};

#endif // WALL_H
