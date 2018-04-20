#include <iostream>
#include "Game.h"
#include <cstdlib>
#include <ctime>
#include "Game.h"
using namespace std;

int main()
{
    srand( (time(NULL)));
    Game game;
    game.start();
    return 0;
}
