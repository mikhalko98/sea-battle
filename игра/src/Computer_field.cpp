#include "Computer_field.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
ifstream din("map.txt");
Computer_field::Computer_field(): s(13),c(13)
{
}
void Computer_field::map_init()
{
    for(int i=0; i<s; i++)
    {
        getline(din, map[i]);
    }
    ship.init_comp_ships();
    for (int i=0; i < s-3; i++)
    {
        for (int j=0; j < c-3; j++)
        {
            map[i+2][j+2] = ship.get_ships(i,j);
        }
    }
}
int Computer_field::get(int _i, int _j)
{
    ship.mark(_i,_j);
    mark(_i+2,_j+2);
    if(ship.get_ships(_i,_j)=='O') return 10;
    if(ship.get_ships(_i,_j)=='X'&&ship.get_ships(_i,_j+1)=='X'&&
       ship.get_ships(_i,_j+2)=='X'&&ship.get_ships(_i,_j+3)=='X')
        return 4;
    if(ship.get_ships(_i,_j)=='X'&&ship.get_ships(_i,_j-1)=='X'&&
       ship.get_ships(_i,_j-2)=='X'&&ship.get_ships(_i,_j-3)=='X')
        return -4;
    if(ship.get_ships(_i,_j)=='X' && ship.get_ships(_i,_j+1)=='X'&&
       ship.get_ships(_i,_j+2)=='X'&&ship.get_ships(_i,_j-1)!='X'&&
       ship.get_ships(_i,_j-1)!='K'&&ship.get_ships(_i,_j+3)!='X'&&
       ship.get_ships(_i,_j+3)!='K' )
        return 3;
    if(ship.get_ships(_i,_j)=='X'&&ship.get_ships(_i,_j-1)=='X'&&
       ship.get_ships(_i,_j-2)=='X'&&ship.get_ships(_i,_j+1)!='X'&&
       ship.get_ships(_i,_j+1)!='K'&&ship.get_ships(_i,_j-3)!='X'&&
       ship.get_ships(_i,_j-3)!='K')
        return -3;
    if(ship.get_ships(_i,_j)=='X'&&ship.get_ships(_i,_j+1)=='X'&&
       ship.get_ships(_i,_j-1)!='X'&&ship.get_ships(_i,_j-1)!='K'&&
       ship.get_ships(_i,_j+2)!='X'&&ship.get_ships(_i,_j+2)!='K')
        return 2;
    if(ship.get_ships(_i,_j)=='X'&&ship.get_ships(_i,_j-1)=='X'&&
       ship.get_ships(_i,_j+1)!='X'&&ship.get_ships(_i,_j+1)!='K'&&
       ship.get_ships(_i,_j-2)!='X'&&ship.get_ships(_i,_j-2)!='K')
        return -2;
    if(ship.get_ships(_i,_j)=='X'&&ship.get_ships(_i,_j+1)!='X'&&
       ship.get_ships(_i,_j-1)!='X'&&ship.get_ships(_i-1,_j)!='X'&&
       ship.get_ships(_i+1,_j)!='X' && ship.get_ships(_i,_j+1)!='K'&&
       ship.get_ships(_i,_j-1)!='K'&& ship.get_ships(_i+1,_j)!='K' &&
       ship.get_ships(_i-1,_j)!='K')
        return 1;
    if(ship.get_ships(_i,_j)=='X'&&ship.get_ships(_i+1,_j)=='X'&&
       ship.get_ships(_i+2,_j)=='X'&&ship.get_ships(_i+3,_j)=='X')
        return -6;
    if(ship.get_ships(_i,_j)=='X'&&ship.get_ships(_i-1,_j)=='X'&&
       ship.get_ships(_i-2,_j)=='X'&&ship.get_ships(_i-3,_j)=='X')
        return -14;
    if(ship.get_ships(_i,_j)=='X' && ship.get_ships(_i+1,_j)=='X'&&
       ship.get_ships(_i+2,_j)=='X'&&ship.get_ships(_i-1,_j)!='X'&&
       ship.get_ships(_i+3,_j)!='X'&&ship.get_ships(_i+3,_j)!='K')
        return -7;
    if(ship.get_ships(_i,_j)=='X'&&ship.get_ships(_i-1,_j)=='X'&&
       ship.get_ships(_i-2,_j)=='X'&&ship.get_ships(_i+1,_j)!='X'&&
       ship.get_ships(_i-3,_j)!='X' && ship.get_ships(_i-3,_j)!='K')
        return -13;
    if(ship.get_ships(_i,_j)=='X' && ship.get_ships(_i+1,_j)=='X'&&
       ship.get_ships(_i-1,_j)!='X'&&ship.get_ships(_i-1,_j)!='K'&&
       ship.get_ships(_i+2,_j)!='X' && ship.get_ships(_i+2,_j)!='K')
        return -8;
    if(ship.get_ships(_i,_j)=='X' && ship.get_ships(_i-1,_j)=='X'&&
       ship.get_ships(_i+1,_j)!='X'&&ship.get_ships(_i+1,_j)!='K'&&
       ship.get_ships(_i-2,_j)!='X' && ship.get_ships(_i-2,_j)!='K')
        return -12;
    if(ship.get_ships(_i,_j)=='X') return 20;
}
void Computer_field::mark(int _i, int _j)
{
    if(map[_i][_j]=='K') map[_i][_j]='X';
    if(map[_i][_j]==' ') map[_i][_j]='O';
}
int Computer_field::chek()
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
Computer_field::~Computer_field()
{
}
