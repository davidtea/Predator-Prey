#ifndef PREY_H
#define PREY_H
#include "creature.h"

class Prey : public Creature
{
public:
    Prey();
    Prey(int x, int y);
    ~Prey(){};

    void Move(Creature* grid[][YLEN]);
    void Breed(Creature* grid[][YLEN]);
    void Die(Creature* grid[][YLEN]);
    void Show(ostream& out);
};

#endif // PREY_H
