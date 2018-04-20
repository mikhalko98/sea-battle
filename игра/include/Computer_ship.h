#ifndef COMPUTER_SHIP_H
#define COMPUTER_SHIP_H
#include<Ship_1.h>
#include<Ship_2.h>
#include<Ship_3.h>
#include<Ship_4.h>
#include "Ships.h"
class Computer_ship: public Ships
{
public:
    Computer_ship();
    virtual ~Computer_ship();
    void init_comp_ships();
    char get_ships(int i, int j){return comp_ships[i][j];}
    void mark(int i, int j);

private:
    char comp_ships[10][10];
    Ship_1 one[4];
    Ship_2 two[3];
    Ship_3 three[2];
    Ship_4 four;
    int const s,c;
};

#endif // COMPUTER_SHIP_H
