#ifndef SHIP_1_H
#define SHIP_1_H


class Ship_1
{
    public:
        Ship_1();
        virtual ~Ship_1();
        int _deck(){ return deck ;}
        int _symbol(){ return symbol;}

    private:
        int deck;
        char symbol;
};

#endif // SHIP_1_H
