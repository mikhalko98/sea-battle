#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
Game::Game():comp_field_mark(&pl_field)
{
    message1=0;
    message2=0;
    x=0;
    y=0;
}
void Game::start()
{
    pl_field.map_init();
    comp_field.map_init();
    control();
    finish(message1,message2);
}
void Game::show()
{
    system("cls");
    pl_field.show();
    pl_field_mark.show();
}
void Game::control()
{
    while(message2!=2)
    {
        show();
        input();
        pl_field_mark.mark(x,y,comp_field.get(x,y));
        comp_field_mark.shooting();
        message1=pl_field.chek();
        message2=comp_field.chek();
        if(message2==3)break;
    }
}
void Game::input()
{
    bool is=false;
    int is2=5;
    while(is==false)
    {
        if(is2==0) cout<<"***You entered the wrong coordinates!***"<<endl;
        cout<<"Enter gorizont-";
        cin>>x;
        cout<<"Enter vertical-";
        cin>>y;
        cout<<endl;
        if(x<10 && y<10 && pl_field_mark.get(x,y)==1)
        {
            is=true;
        }
        else is2=0;
        show();
    }
}
void Game::finish(int pl, int comp)
{
    system("cls");
    cout<<"\n\n"<<"GAME OVER"<<endl<<endl;
    comp=message1;
    pl=message2;
    if(pl==3)
    {
        cout<<"\n"<<"***!!!This game is yours!!!***";
    }
    if(comp==2)
    {
        cout<<"\n"<<"***!!!You lose!!!***";
    }
}
Game::~Game()
{
}
