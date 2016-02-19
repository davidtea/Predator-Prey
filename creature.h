#ifndef CREATURE_H
#define CREATURE_H
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int XLEN = 300;
const int YLEN = 300;

class Creature
{
public:
    Creature();
    Creature(int x, int y, char type);
    char Face();//return face, what creature it is
    void MoveCreature(Creature *grid[][YLEN], int x, int y);
    void BreedInc();
    int BreedC();
    int Xpos();
    int Ypos();
    bool IsPrey();
    bool IsOPprey();
    bool Movedyet();//returns moved bool
    void MoveReset();//sets moved bool back to false at start of turn
    int* AvailSpots(Creature* grid[][YLEN]);//creates an array of available spots
    int Randomize(int* array);//returns randomized array
    virtual void Move(Creature* grid[][YLEN]);//increase breedcounter
    virtual void Breed(Creature* grid[][YLEN]);//resets breedcounter to 0
    virtual void Die(Creature* grid[][YLEN]);//delete creature
    virtual void Show(ostream& out);//show creature on grid

    friend ostream& operator <<(ostream& out, Creature& C);

private:
    int breedcounter;//3 for prey, 8 for hunter
    int xpos;
    int ypos;
    char face;//h for hunter, p for prey, w for wall
    bool moved;
};

#endif // CREATURE_H
