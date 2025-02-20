#include "player.h"
#include "wheel.h"

using namespace std;

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
            int house1 = houseWheel.spin();
            int house2 = houseWheel.spin();
            cout << "House spins: " << house1 << ", " << house2 << endl;
            playerWins = !(house1 >= playerResult || house2 >= playerResult);
        } else if (wagerChoice == 'H' || wagerChoice == 'h') {
            int house1 = houseWheel.spin();
            int house2 = houseWheel.spin();
            cout << "House spins: " << house1 << ", " << house2 << endl;
            playerWins = !(house1 >= playerResult && house2 >= playerResult);
        } else {
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
