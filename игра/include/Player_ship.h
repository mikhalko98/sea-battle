#ifndef PLAYER_SHIP_H
#define PLAYER_SHIP_H
#include<Ship_1.h>
#include<Ship_2.h>
#include<Ship_3.h>
#include<Ship_4.h>
#include "Ships.h"

class Player_ship: public Ships
{
public:
    Player_ship();
    virtual ~Player_ship();
    void init_pl_ships();
    char get_ships(int _i, int _j) { return pl_ships[_i][_j];}
    void mark(int x, int y);

private:
    char pl_ships[10][10];
    Ship_1 one[4];
    Ship_2 two[3];
    Ship_3 three[2];
    Ship_4 four;
    int const s,c;
};

#endif // PLAYER_SHIP_H
