#ifndef PLAGUE_H
#define PLAGUE_H
#include "creature.h"

const int EXPIRETIME = 5;//number of steps before plague dies out

class Plague : public Creature
{
public:
    Plague();
    Plague(int x, int y, int p);//spawns in a random place, converts everything around it into plague
    //and spreads outward. dies off after a certain amount of steps
    ~Plague(){};

    void Move(Creature* grid[][YLEN]);
    void Breed(Creature* grid[][YLEN]);
    void Die(Creature* grid[][YLEN]);
    void Eat(Creature* grid[][YLEN]);

    int* AvailPrey(Creature* grid[][YLEN]);//checks for preys and hunters


private:
    int expirestep;
};

#endif // PLAGUE_H
