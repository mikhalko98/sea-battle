#ifndef GAME_H
#define GAME_H
#include <string>
#include "Player_field.h"
#include "Player_field_mark.h"
#include "Computer_field.h"
#include "Computer_field_mark.h"
class Game
{
public:
    Game();
    virtual ~Game();
    void start();

private:
    void show();
    void control();
    void input();
    void finish(int pl, int comp);
    Player_field pl_field;
    Player_field_mark pl_field_mark;
    Computer_field comp_field;
    Computer_field_mark comp_field_mark;
    int x,y;
    int message1;
    int message2;
};
#endif // GAME_H
