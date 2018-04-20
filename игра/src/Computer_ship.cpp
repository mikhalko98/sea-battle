#include "Computer_ship.h"
#include <iostream>
using namespace std;
Computer_ship::Computer_ship():s(10),c(10)
{
}
void Computer_ship::init_comp_ships()
{
    for(int i = 0 ; i < s ; i++)
    {
        for(int j = 0 ; j < c ; j++)
        {
            comp_ships[i][j]=' ';
        }
    }
       set(comp_ships,four._deck(),four._symbol());
    for(int i=0; i<2; i++)
        set(comp_ships,three[i]._deck(),three[i]._symbol());

    for(int i=0; i<3; i++)
        set(comp_ships,two[i]._deck(),two[i]._symbol());

    for(int i=0; i<4; i++)
        set(comp_ships,one[i]._deck(),one[i]._symbol());
}
void Computer_ship::mark(int i, int j)
{
    if(comp_ships[i][j]=='K') comp_ships[i][j]='X';
    if(comp_ships[i][j]==' ') comp_ships[i][j]='O';
}
Computer_ship::~Computer_ship()
{
}
