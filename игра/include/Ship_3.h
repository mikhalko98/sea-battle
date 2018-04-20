#ifndef SHIP_3_H
#define SHIP_3_H


class Ship_3
{
    public:
        Ship_3();
        virtual ~Ship_3();
        int _deck(){ return deck ;}
        int _symbol(){ return symbol;}

    private:
        int deck;
        char symbol;
};

#endif // SHIP_3_H
