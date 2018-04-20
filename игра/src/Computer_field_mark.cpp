#include "Computer_field_mark.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;
ifstream f;
Computer_field_mark::Computer_field_mark(Player_field *s):s(13)
{
    cin_compField("map_mark.txt");
    ship=s;
    x=0;
    y=0;
    P=0;
}
void Computer_field_mark::cin_compField(const char *fname)
{
    f.open("map_mark.txt");
    for(int i=0; i<s; i++)
    {
        getline(f, map_mark[i]);
    }
}
void Computer_field_mark::shooting()
{
    iss=0;
    while(iss!=1)
    {
        if(P==0)
        {
            random();
        }
        if(ship->get_map(x+2,y+2)==' '||ship->get_map(x+2,y+2)=='K')
        {
          mark(x,y,get(x,y));
          if(map_mark[x+2][y+2]=='O' &&
            (map_mark[x+2+1][y+2]!='X' && map_mark[x+2-1][y+2]!='X'&&
             map_mark[x+2][y+2+1]!='X' && map_mark[x+2][y+2-1]!='X'))
             P=0;
         break;
        }
        else
        {
            if(map_mark[x+2][y+2]=='X')
            {
                where_to_move_vertically_forX();//Проверяем куда двигатся по вертикали
                if(iss==1) break;
                where_to_move_horizontally_forX();// Проверяем куда двигатся по горизонтали
                if(iss==1) break;
            }
            if(map_mark[x+2][y+2]=='O')
            {
                where_to_move_vertically_forO();//Проверяем куда двигатся по вертикали
                if(iss==1) break;
                where_to_move_horizontally_forO();//Проверяем куда двигатся по горизонтали
                if(iss==1) break;
            }
        }
    }
}
void Computer_field_mark::random()
{
    int is=0;
    while(is!=1)
    {
        x=rand()%10;
        y=rand()%10;
        P+=1;
        if(map_mark[x+2][y+2]!=' ') is=0;
        else break;
    }
}
void Computer_field_mark::oboznach(int _k, int _p)
{
    x+=_k;
    y+=_p;
    mark(x,y,get(x,y));
    iss=1;
    return;
}
void Computer_field_mark::where_to_move_vertically_forX()
{
    if((map_mark[x+2][y+2+1]=='O' && map_mark[x+2][y+2-1]=='O'&&
        map_mark[x+2+1][y+2]==' ') ||
        (map_mark[x+2-1][y+2]=='X' && map_mark[x+2+1][y+2]==' '))
    {
        oboznach(1,0);
        return;
    }
    if(map_mark[x+2-1][y+2]==' ' && map_mark[x+2+1][y+2]=='X')
    {
        oboznach(-1,0);
        return;
    }
    if(map_mark[x+2-1][y+2]=='X' && map_mark[x+2+1][y+2]!=' ')
    {
        if(map_mark[x+2-2][y+2]==' ')
        {
            oboznach(-2,0);
            return;
        }
        if(map_mark[x+2-2][y+2]=='X')
        {
            oboznach(-3,0);
            return;
        }
    }
}
void Computer_field_mark::where_to_move_horizontally_forX()
{
    if(map_mark[x+2][y+2+1]==' ')
    {
        oboznach(0,1);
        return;
    }
    if(map_mark[x+2][y+2+1]!=' ' && map_mark[x+2][y+2-1]!=' ')
    {
        if(map_mark[x+2+1][y+2]!=' ')
        {
            oboznach(-1,0);
            return;
        }
        else
        {
            oboznach(1,0);
            return;
        }
    }
    if(map_mark[x+2][y+2+1]!=' ' && map_mark[x+2][y+2-1]==' ')
    {
        oboznach(0,-1);
        return;
    }
    if(map_mark[x+2][y+2-1]=='X' && map_mark[x+2][y+2-2]==' '&&
       map_mark[x+2][y+2+1]=='O')
    {
        oboznach(0,-2);
        return;
    }
    if(map_mark[x+2][y+2-1]=='X' && map_mark[x+2][y+2-2]=='X'&&
       map_mark[x+2][y+2-3]==' '&& map_mark[x+2][y+2+1]!=' ')
    {
        oboznach(0,-3);
        return;
    }
}
void Computer_field_mark::where_to_move_vertically_forO()
{
    if(map_mark[x+2][y+2+1]=='X' && map_mark[x+2][y+2+2]!=' ')
    {
        oboznach(1,1);
        return;
    }
    if(map_mark[x+2-1][y+2]=='X' && map_mark[x+2-2][y+2]==' ')
    {
        oboznach(-2,0);
        return;
    }
    if(map_mark[x+2-1][y+2]=='X' && map_mark[x+2-2][y+2]=='X'&&
       map_mark[x+2-3][y+2]==' ')
    {
        oboznach(-3,0);
        return;
    }
    if(map_mark[x+2-1][y+2]=='X' && map_mark[x+2-2][y+2]=='X'&&
       map_mark[x+2-3][y+2]=='X' && map_mark[x+2-4][y+2]==' ')
    {
        oboznach(-4,0);
        return;
    }
}
void Computer_field_mark::where_to_move_horizontally_forO()
{
    if(map_mark[x+2][y+2-1]=='X' && map_mark[x+2][y+2-2]==' ')
    {
        oboznach(0,-2);
        return;
    }
    if(map_mark[x+2][y+2-1]=='X' && map_mark[x+2][y+2-2]=='X'&&
       map_mark[x+2][y+2-3]==' ')
    {
        oboznach(0,-3);
        return;
    }
    if(map_mark[x+2][y+2-1]=='X' && map_mark[x+2][y+2-2]=='X'&&
       map_mark[x+2][y+2-3]=='X' && map_mark[x+2][y+2-4]==' ')
    {
        oboznach(0,-4);
        return;
    }
    if(map_mark[x+2][y+2-1]=='X' && map_mark[x+2][y+2-2]!=' ')
    {
        if(map_mark[x+2+1][y+2-1]==' ')
        {
            oboznach(1,-1);
            return;
        }
        else
        {
            oboznach(-1,-1);
            iss=1;
            return;
        }
    }
}
int Computer_field_mark::get(int _i, int _j)
{
    ship->mark(_i,_j);
    if(ship->getp(_i,_j)=='O') return 10;
    if(ship->getp(_i,_j)=='X'&&ship->getp(_i,_j+1)=='X'&&
       ship->getp(_i,_j+2)=='X' &&ship->getp(_i,_j+3)=='X')
        return 4;
    if(ship->getp(_i,_j)=='X'&&ship->getp(_i,_j-1)=='X'&&
       ship->getp(_i,_j-2)=='X'&&ship->getp(_i,_j-3)=='X')
        return -4;
    if(ship->getp(_i,_j)=='X' && ship->getp(_i,_j+1)=='X'&&
       ship->getp(_i,_j+2)=='X'&&ship->getp(_i,_j-1)!='X'&&
       ship->getp(_i,_j-1)!='K'&& ship->getp(_i,_j+3)!='X'&&
       ship->getp(_i,_j+3)!='K')
       return 3;
    if(ship->getp(_i,_j)=='X'&&ship->getp(_i,_j-1)=='X'&&
       ship->getp(_i,_j-2)=='X'&&ship->getp(_i,_j+1)!='X'&&
       ship->getp(_i,_j+1)!='K' && ship->getp(_i,_j-3)!='X'&&
       ship->getp(_i,_j-3)!='K')
       return -3;
    if(ship->getp(_i,_j)=='X' && ship->getp(_i,_j+1)=='X'&&
       ship->getp(_i,_j-1)!='X'&&ship->getp(_i,_j-1)!='K'&&
       ship->getp(_i,_j+2)!='X' && ship->getp(_i,_j+2)!='K')
       return 2;
    if(ship->getp(_i,_j)=='X'&&ship->getp(_i,_j-1)=='X'&&
       ship->getp(_i,_j+1)!='X'&&ship->getp(_i,_j+1)!='K'&&
       ship->getp(_i,_j-2)!='X' && ship->getp(_i,_j-2)!='K')
       return -2;
    if(ship->getp(_i,_j)=='X'&&ship->getp(_i,_j+1)!='X'&&
       ship->getp(_i,_j-1)!='X'&&ship->getp(_i-1,_j)!='X'&&
       ship->getp(_i+1,_j)!='X' && ship->getp(_i,_j+1)!='K'&&
       ship->getp(_i,_j-1)!='K'&& ship->getp(_i+1,_j)!='K'&&
       ship->getp(_i-1,_j)!='K')
       return 1;
    if(ship->getp(_i,_j)=='X' && ship->getp(_i+1,_j)=='X'&&
       ship->getp(_i+2,_j)=='X'&&ship->getp(_i+3,_j)=='X')
       return -6;
    if(ship->getp(_i,_j)=='X'&&ship->getp(_i-1,_j)=='X'&&
       ship->getp(_i-2,_j)=='X' &&ship->getp(_i-3,_j)=='X')
       return -14;
    if(ship->getp(_i,_j)=='X' && ship->getp(_i+1,_j)=='X'&&
       ship->getp(_i+2,_j)=='X'&&ship->getp(_i-1,_j)!='X'&&
       ship->getp(_i-1,_j)!='K' && ship->getp(_i+3,_j)!='X'&&
       ship->getp(_i+3,_j)!='K' )
       return -7;
    if(ship->getp(_i,_j)=='X' && ship->getp(_i-1,_j)=='X'&&
       ship->getp(_i-2,_j)=='X'&&ship->getp(_i+1,_j)!='X'&&
       ship->getp(_i+1,_j)!='K' && ship->getp(_i-3,_j)!='X'&&
       ship->getp(_i-3,_j)!='K')
       return -13;
    if(ship->getp(_i,_j)=='X'&&ship->getp(_i+1,_j)=='X'&&
       ship->getp(_i-1,_j)!='X'&&ship->getp(_i-1,_j)!='K'&&
       ship->getp(_i+2,_j)!='X' && ship->getp(_i+2,_j)!='K')
       return -8;
    if(ship->getp(_i,_j)=='X' && ship->getp(_i-1,_j)=='X'&&
       ship->getp(_i+1,_j)!='X'&&ship->getp(_i+1,_j)!='K'&&
       ship->getp(_i-2,_j)!='X' && ship->getp(_i-2,_j)!='K')
       return -12;
    if(ship->getp(_i,_j)=='X') return 20;
}
void Computer_field_mark::mark(int _x, int _y, int is)
{
    _mark(_x,_y,is,map_mark);
    if(is==1)            // рисовать звёзды для однопалубного корабля
    {
        P=0;
        for(int i=-1; i<2; i++)
        {
            if(map_mark[_x+2+1][_y+2+i]!='|') map_mark[_x+2+1][_y+2+i]='*';
            if(map_mark[_x+2-1][_y+2+i]!='|') map_mark[_x+2-1][_y+2+i]='*';
        }
        if(map_mark[_x+2][_y+2+1]!='|') map_mark[_x+2][_y+2+1] ='*';
        if(map_mark[_x+2][_y+2-1]!='|') map_mark[_x+2][_y+2-1] ='*';
    }
    if(is>=-4 && is<=4)
    {
        P=0;
        draw_stars_gorizontal(_x,_y,is);
    }

    if(is>=-14 && is<=-6)
    {
        P=0;
        draw_stars_vertically(_x,_y,is);
    }

}
void Computer_field_mark::draw_stars_gorizontal(int _x, int _y, int is)
{

    int p=is/abs(is)*(-1);
    for(int i=0; i<=abs(is)+1; i++)
    {
        if(map_mark[_x+2-1][_y+2+(is)+(i*p)]!='|') map_mark[_x+2-1][_y+2+(is)+(i*p)]='*';
        if(map_mark[_x+2+1][_y+2+(is)+(i*p)]!='|') map_mark[_x+2+1][_y+2+(is)+(i*p)]='*';
    }
    if(map_mark[_x+2][_y+2+1*p]!='|') map_mark[_x+2][_y+2+1*p]='*';
    if(map_mark[_x+2][_y+2+is]!='|') map_mark[_x+2][_y+2+is]='*';
}
void Computer_field_mark::draw_stars_vertically(int _x, int _y, int is)
{
    is+=10;
    int p=is/abs(is)*(-1);
    for(int i=0; i<=abs(is)+1; i++)
    {
        if(map_mark[_x+2+(is)+(i*p)][_y+2-1]!='|') map_mark[_x+2+(is)+(i*p)][_y+2-1]='*';
        if(map_mark[_x+2+(is)+(i*p)][_y+2+1]!='|') map_mark[_x+2+(is)+(i*p)][_y+2+1]='*';
    }
    if(map_mark[_x+2+1*p][_y+2]!='|') map_mark[_x+2+1*p][_y+2]='*';
    if(map_mark[_x+2+is][_y+2]!='|') map_mark[_x+2+is][_y+2]='*';
}
Computer_field_mark::~Computer_field_mark()
{
}
