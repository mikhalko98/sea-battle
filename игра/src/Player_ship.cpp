#include "Player_ship.h"
#include <iostream>
using namespace std;
Player_ship::Player_ship():s(10),c(10)
{
}
void Player_ship::init_pl_ships()
{
    for(int i = 0 ; i < s ; i++)
    {
        for(int j = 0 ; j < c ; j++)
        {
            pl_ships[i][j]=' ';
        }
    }
                          set(pl_ships,four._deck(),four._symbol());
    for(int i=0;i<2;i++)  set(pl_ships,three[i]._deck(),three[i]._symbol());
    for(int i=0;i<3;i++)  set(pl_ships,two[i]._deck(),two[i]._symbol());
    for(int i=0;i<4;i++)  set(pl_ships,one[i]._deck(),one[i]._symbol());
}
void Player_ship::mark(int x, int y)
{
    if(pl_ships[x][y]=='K') pl_ships[x][y]='X';
    if(pl_ships[x][y]==' ') pl_ships[x][y]='O';
}
Player_ship::~Player_ship()
{
}
