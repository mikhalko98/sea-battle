#ifndef SHIP_4_H
#define SHIP_4_H


class Ship_4
{
    public:
        Ship_4();
        virtual ~Ship_4();
        int _deck(){ return deck ;}
        int _symbol(){ return symbol;}

    private:
        int deck;
        char symbol;
};

#endif // SHIP_4_H
