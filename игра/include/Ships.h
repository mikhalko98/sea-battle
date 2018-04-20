#ifndef SHIPS_H
#define SHIPS_H

class Ships
{
public:
    Ships();
    virtual ~Ships();
    void set(char ships[10][10],int deck, char sign);
    int place_ships(char ships[10][10],int kor_i, int kor_j, int dir, int deck);

private:
    int deck;

};

#endif // SHIPS_H
