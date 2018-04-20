#include "Player_field.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

ifstream fin;
Player_field::Player_field() : s(13), c(13)
{
}
void Player_field::cin_playerField(const char *fname)
{
    fin.open("map.txt");
    for(int i=0; i<s; i++)
    {
        getline(fin, map[i]);
    }
}
int Player_field::chek()
{
    for (int i=0; i < s; i++)
    {
        for (int j=0; j < c; j++)
        {
            if(map[i][j]=='K' ) return 0;
        }
    }
    return 3;
}
void Player_field::map_init()
{
    cin_playerField("map.txt");
    ship.init_pl_ships();
    for (int i=0; i < s-3; i++)
    {
        for (int j=0; j < c-3; j++)
        {
            map[i+2][j+2] = ship.get_ships(i,j);
        }
    }
}
void Player_field::mark(int _x, int _y)
{
    ship.mark(_x,_y);
    if(ship.get_ships(_x,_y)=='O') map[_x+2][_y+2] ='O';
    if(ship.get_ships(_x,_y)=='X') map[_x+2][_y+2] ='X';
}
void Player_field::show()
{
    for(int i=0; i<s; i++)
    {
        cout<<map[i];
        cout<<endl;
    }
}
Player_field::~Player_field()
{
}
