#ifndef TELEPORT_H
#define TELEPORT_H
#include "creature.h"
#include "oppred.h"

class Teleport : public Creature
{
public:
    Teleport();
    Teleport(int x, int y);//teleports around and spawns OPpreds all around, only in NULL spots
    ~Teleport(){};

    void Move(Creature* grid[][YLEN]);
    void Breed(Creature* grid[][YLEN]);
    void Die(Creature* grid[][YLEN]);
    void Show(ostream& out);

    void Spawn(Creature* grid[][YLEN]);

private:
    int spawncount;
    int starve;
};

#endif // TELEPORT_H
