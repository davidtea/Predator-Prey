#ifndef HUNTER_H
#define HUNTER_H
#include "creature.h"

class Hunter : public Creature
{
public:
    Hunter();
    Hunter(int x, int y);
    ~Hunter(){};

    void Move(Creature* grid[][YLEN]);
    void Breed(Creature* grid[][YLEN]);
    void Die(Creature* grid[][YLEN]);
    void Eat(Creature* grid[][YLEN], int direction);

    int* AvailPrey(Creature* grid[][YLEN]);//like availspots for creature, except checks for prey instead


    void Show(ostream &out);
private:
    int starvecounter;
};

#endif // HUNTER_H
