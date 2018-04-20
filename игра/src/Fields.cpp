#include "Fields.h"
#include <cmath>
Fields::Fields()
{
}
void Fields::_mark(int _x, int _y, int is, string map_mark[13])
{
    if(is==10)  map_mark[_x+2][_y+2] ='O';
    if(is==20) map_mark[_x+2][_y+2] ='X';
    if(is==1)            // рисовать звёзды для однопалубного корабля
    {
        map_mark[_x+2][_y+2] ='#';
    }
    if(is>=-4 && is<=4)
        draw_stars_gorizontal(_x,_y,is,map_mark);
    if(is>=-14 && is<=-6)
        draw_stars_vertically(_x,_y,is,map_mark);
}
void Fields::draw_stars_gorizontal(int _x, int _y, int is, string map_mark[13])
{
    int p=is/abs(is);
    for(int i=0; i<abs(is); i++)
    {
      map_mark[_x+2][_y+2+(i*p)]='#';
    }
}
void Fields::draw_stars_vertically(int _x, int _y, int is, string map_mark[13])
{
    is+=10;
    int p=is/abs(is);
    for(int i=0; i<abs(is); i++)
    {
        map_mark[_x+2+(i*p)][_y+2]='#';
    }
}
Fields::~Fields()
{
}
