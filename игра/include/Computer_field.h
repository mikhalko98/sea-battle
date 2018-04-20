#ifndef COMPUTER_FIELD_H
#define COMPUTER_FIELD_H
#include "Computer_ship.h"
#include <string>
using namespace std;

class Computer_field
{
public:
    Computer_field();
    virtual ~Computer_field();
    void map_init();
    int get(int _i, int _j);
    int chek();

private:
    void mark(int _i, int _j);
    int const s,c;
    string map[13];
    Computer_ship ship;
};

#endif // COMPUTER_FIELD_H
