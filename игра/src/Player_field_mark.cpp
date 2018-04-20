#include "Player_field_mark.h"
#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;
ifstream fit;
Player_field_mark::Player_field_mark(): s(13)
{
    cin_playerField("map_mark.txt");
}
void Player_field_mark::cin_playerField(const char *fname)
{
    fit.open("map_mark.txt");
    for(int i=0; i<s; i++)
    {
        getline(fit, map_mark[i]);
    }
    fit.close();
}
void Player_field_mark::mark(int _x,int _y, int is)
{
    _mark(_x,_y,is,map_mark);
}
int Player_field_mark::get(int x, int y)
{
    if(map_mark[x+2][y+2]==' ') return 1;
    else return 0;
}
void Player_field_mark::show()
{
    for(int i=0; i<s; i++)
    {
        cout<<map_mark[i];
        cout<<endl;
    }
}
Player_field_mark::~Player_field_mark()
{
    //dtor
}
