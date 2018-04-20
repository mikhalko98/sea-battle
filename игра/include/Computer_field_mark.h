#ifndef COMPUTER_FIELD_MARK_H
#define COMPUTER_FIELD_MARK_H
#include <string>
#include "Player_field.h"
#include "Fields.h"
using namespace std;
class Computer_field_mark:public Fields
{
public:
    Computer_field_mark(Player_field *s);
    virtual ~Computer_field_mark();
    void cin_compField(const char *fname);
    void shooting();

private:
    int get(int _i, int _j);
    void mark(int _x, int _y, int is);
    void draw_stars_vertically(int _x, int _y, int is);
    void draw_stars_gorizontal(int _x, int _y, int is);
    void random();
    void where_to_move_vertically_forX();
    void where_to_move_horizontally_forX();
    void where_to_move_vertically_forO();
    void where_to_move_horizontally_forO();
    void oboznach(int _k, int _p);
    Player_field *ship;
    string map_mark[13];
    int const s;
    int x, y;
    int iss;
    int P;
};

#endif
