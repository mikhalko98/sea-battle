#ifndef FIELDS_H
#define FIELDS_H
#include <string>
using namespace std;

class Fields
{
public:
    Fields();
    virtual ~Fields();
    void _mark(int _x,int _y, int is, string map_mark[13]);
    void draw_stars_vertically(int _x, int _y, int is, string map_mark[13]);
    void draw_stars_gorizontal(int _x, int _y, int is, string map_mark[13]);

private:
    int x,y;
    string map_mark[13];
};

#endif // FIELDS_H
