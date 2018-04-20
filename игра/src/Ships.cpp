#include "Ships.h"
#include <cstdlib>
#include <iostream>
using namespace std;
Ships::Ships()
{
    //ctor
}
void Ships::set(char ships[10][10], int deck, char sign)
{
    bool isset=0;
    int dir;
    int kor_i, kor_j;
    while(isset==0)
    {
        dir=rand()%2+1;
        kor_i=rand()%10;
        kor_j=rand()%10;
        int e=0;
        switch(dir)
        {
        case 1: // 1 это горизонтально размещение корабля
            if(ships[kor_i][kor_j]==' ')
            {
                e=place_ships(ships,kor_i,kor_j,dir,deck);
                if(e==0)
                {
                    for(int i=0; i<deck; i++)
                    {
                        ships[kor_i][kor_j+i]=sign;
                    }
                    isset=1;
                }

            }
            break;
        case 2:
            if(ships[kor_i][kor_j]==' ')
            {
                e=place_ships(ships,kor_i,kor_j,dir,deck);
                if(e==0)
                {
                    for(int i=0; i<deck; i++)
                    {
                        ships[kor_i+i][kor_j]=sign;
                    }
                    isset=1;
                }

            }
            break;
        }
    }
}
int Ships::place_ships(char ships[10][10],int kor_i, int kor_j, int dir, int deck)
{
    int e=0;
    switch(dir)
    {
    case 1:// если горизонтально
        if(kor_j+(deck-1)>=10) e=1;
        if(ships[kor_i-1][kor_j-1]!=' ') e=1;
        if(ships[kor_i+1][kor_j-1]!=' ') e=1;
        if(ships[kor_i][kor_j-1]!=' ') e=1;
        if(ships[kor_i-1][kor_j+deck]!=' ') e=1;
        if(ships[kor_i+1][kor_j+deck]!=' ') e=1;
        if(ships[kor_i][kor_j+deck]!=' ') e=1;
        for(int i=0; i<deck; i++)
        {
            if(ships[kor_i-1][kor_j+i]!=' ') e=1;
            if(ships[kor_i+1][kor_j+i]!=' ') e=1;
            if(ships[kor_i][kor_j+i]!=' ') e=1;
        }
        break;

    case 2: // если вертикально
        if(kor_i+(deck-1)>=10) e=1;
        if(ships[kor_i-1][kor_j-1]!=' ') e=1;
        if(ships[kor_i-1][kor_j+1]!=' ') e=1;
        if(ships[kor_i-1][kor_j]!=' ') e=1;
        if(ships[kor_i+deck][kor_j-1]!=' ') e=1;
        if(ships[kor_i+deck][kor_j+1]!=' ') e=1;
        if(ships[kor_i+deck][kor_j]!=' ') e=1;
        for(int i=0; i<deck; i++)
        {
            if(ships[kor_i+i][kor_j-1]!=' ') e=1;
            if(ships[kor_i+i][kor_j+1]!=' ') e=1;
            if(ships[kor_i+i][kor_j]!=' ') e=1;
        }
        break;
    }
    return e;
}
Ships::~Ships()
{
    //dtor
}
