#ifndef PLAYER_H
#define PLAYER_H

#include "Wheel.h"

class Player {
public:
    int money;
    int bet;
    Wheel wheel;

    Player();
    void placeBet(int amount);
    char chooseWagerOption();
    void adjustBet(char choice);
    int spinWheel();
    void win();
    void lose();
};

#endif
