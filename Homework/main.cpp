#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Wheel {
public:
    int minValue;
    int maxValue;

    // Constructor: Default range 1-10
    Wheel(int maxVal = 10) {
        minValue = 1;
        maxValue = maxVal;
        srand(time(0)); 
    }

    // Spin the wheel
    int spin() {
        return rand() % (maxValue - minValue + 1) + minValue;
    }

    // Adjust range for hard mode
    void increaseRange() {
        if (maxValue < 20) maxValue++;
    }
    void decreaseRange(int playerMax) {
        if (maxValue > playerMax) maxValue--;
    }
};

class Player {
public:
    int money;
    int bet;
    Wheel wheel;

    Player() {
        money = 1000;
        bet = 0;
    }

    // Place a bet
    void placeBet(int amount) {
        if (amount > 0 && amount <= money) {
            bet = amount;
            money -= bet;
        } else {
            cout << "Invalid bet!" << endl;
        }
    }

    // Choose wager option
    char chooseWagerOption() {
        char choice;
        cout << "Choose: (K)eep, (D)ouble, (H)alve: ";
        cin >> choice;
        return choice;
    }

    // Adjust bet
    void adjustBet(char choice) {
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

    int spinWheel() {
        return wheel.spin();
    }

    void win() {
        money += bet * 2;
        cout << "You won! New total: $" << money << endl;
    }

    void lose() {
        cout << "You lost! Remaining money: $" << money << endl;
    }
};

int main() {
    Player player;
    Wheel houseWheel;
    int betAmount;
    char playAgain, wagerChoice, hardMode;
    bool isHardMode = false;
    int houseWinStreak = 0;

    cout << "Enable hard mode? (y/n): ";
    cin >> hardMode;
    if (hardMode == 'y' || hardMode == 'Y') {
        isHardMode = true;
    }

    do {
        if (player.money <= 0) {
            cout << "You're out of money! Game over." << endl;
            break;
        }

        cout << "You have $" << player.money << ". Enter your bet: ";
        cin >> betAmount;
        player.placeBet(betAmount);

        int playerResult = player.spinWheel();
        cout << "Your wheel landed on: " << playerResult << endl;

        wagerChoice = player.chooseWagerOption();
        player.adjustBet(wagerChoice);

        bool playerWins = false;

        if (wagerChoice == 'D' || wagerChoice == 'd') {
            // House gets two chances
            int house1 = houseWheel.spin();
            int house2 = houseWheel.spin();
            cout << "House spins: " << house1 << ", " << house2 << endl;
            if (house1 >= playerResult || house2 >= playerResult) {
                playerWins = false;
            } else {
                playerWins = true;
            }
        } else if (wagerChoice == 'H' || wagerChoice == 'h') {
            // House must win both
            int house1 = houseWheel.spin();
            int house2 = houseWheel.spin();
            cout << "House spins: " << house1 << ", " << house2 << endl;
            if (house1 >= playerResult && house2 >= playerResult) {
                playerWins = false;
            } else {
                playerWins = true;
            }
        } else {
            // Normal case (one spin)
            int houseResult = houseWheel.spin();
            cout << "House wheel landed on: " << houseResult << endl;
            playerWins = playerResult > houseResult;
        }

        if (playerWins) {
            player.win();
            houseWinStreak = 0;
        } else {
            player.lose();
            houseWinStreak++;
        }

        // Hard mode logic
        if (isHardMode) {
            if (houseWinStreak >= 2) {
                houseWheel.increaseRange();
                houseWinStreak = 0;
            } else {
                houseWheel.decreaseRange(player.wheel.maxValue);
            }
        }

        cout << "Play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing!" << endl;
    return 0;
}
