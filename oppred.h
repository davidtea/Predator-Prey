#ifndef OPPRED_H
#define OPPRED_H
#include "creature.h"

class OPpred : public Creature
{
public:
    OPpred();
    OPpred(int x, int y);
    ~OPpred(){};

    void Move(Creature* grid[][YLEN]);
    void Breed(Creature* grid[][YLEN]);
    void Die(Creature* grid[][YLEN]);
    void Eat(Creature* grid[][YLEN]);//eats everything around it, except for its own type, teleports,
    //and walls. Doesn't breed, only spawns from teleport, lasts 50 steps.

    int* AvailPrey(Creature* grid[][YLEN]);//like availspots for creature, except checks for prey instead
    void Show(ostream &out);

private:
    int starvecounter;
};

#endif // OPPRED_H
