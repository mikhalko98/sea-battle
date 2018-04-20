#ifndef SHIP_2_H
#define SHIP_2_H


class Ship_2
{
    public:
        Ship_2();
        virtual ~Ship_2();
        int _deck(){ return deck ;}
        int _symbol(){ return symbol;}

    private:
        int deck;
        char symbol;
};

#endif // SHIP_2_H
