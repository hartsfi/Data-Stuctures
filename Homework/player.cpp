#include "player.h"

using namespace std;

Player::Player() {
    money = 1000;
    bet = 0;
}

void Player::placeBet(int amount) {
    if (amount > 0 && amount <= money) {
        bet = amount;
        money -= bet;
    } else {
        cout << "Invalid bet!" << endl;
    }
}

char Player::chooseWagerOption() {
    char choice;
    cout << "Choose: (K)eep, (D)ouble, (H)alve: ";
    cin >> choice;
    return choice;
}

void Player::adjustBet(char choice) {
    if (choice == 'D' || choice == 'd') {
        if (money >= bet) {
            money -= bet;
            bet *= 2;
        } else {
            cout << "Not enough money to double the bet!" << endl;
        }
    } else if (choice == 'H' || choice == 'h') {
        bet /= 2;
    }
}

int Player::spinWheel() {
    return wheel.spin();
}

void Player::win() {
    money += bet * 2;
    cout << "You won! New total: $" << money << endl;
}

void Player::lose() {
    cout << "You lost! Remaining money: $" << money << endl;
}
