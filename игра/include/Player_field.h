#ifndef PLAYER_FIELD_H
#define PLAYER_FIELD_H
#include "Player_ship.h"
#include <string>
using namespace std;

class Player_field
{
public:
    Player_field();
    virtual ~Player_field();
    void show();
    void map_init();
    int chek();
    void mark(int x, int y);
    char getp(int _i, int _j){ return ship.get_ships(_i,_j);}
    char get_map(int x, int y){return map[x][y];}

private:
    void cin_playerField(const char *fname);
    string map[13];
    Player_ship ship;
    int const s,c;
};

#endif // PLAYER_FIELD_H
