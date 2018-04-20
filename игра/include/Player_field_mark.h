#ifndef PLAYER_FIELD_MARK_H
#define PLAYER_FIELD_MARK_H
#include <string>
#include "Fields.h"
using namespace std;
class Player_field_mark:public Fields
{
    public:
        Player_field_mark();
        virtual ~Player_field_mark();
        void show();
        void mark(int _x,int _y, int is);
        int get(int x, int y);

    private:
        void cin_playerField(const char *fname);
        string map_mark[13];
        int const s;
};

#endif // PLAYER_FIELD_MARK_H
