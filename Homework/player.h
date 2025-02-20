#pragma once
#include "wheel.h"
#include "Player.h"
#include <string>
#include <iostream>

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
