#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
        Player player;
        int betAmount;
        char playAgain;
    
        do {
            // Check if player has money left
            if (player.money <= 0) {
                cout << "You're out of money! Game over." << endl;
                break;
            }
    
            // Ask for a bet
            cout << "You have $" << player.money << ". Enter your bet: ";
            cin >> betAmount;
            player.placeBet(betAmount);
    
            // Spin the player's wheel
            int playerResult = player.spinWheel();
            cout << "Your wheel landed on: " << playerResult << endl;
    
            // For now, house spins once (we'll add more logic later)
            Wheel houseWheel;
            int houseResult = houseWheel.spin();
            cout << "House wheel landed on: " << houseResult << endl;
    
            // Compare results
            if (playerResult > houseResult) {
                player.win();
            } else {
                player.lose();
            }
    
            // Ask if the player wants to play again
            cout << "Play again? (y/n): ";
            cin >> playAgain;
    
        } while (playAgain == 'y' || playAgain == 'Y');
    
        cout << "Thanks for playing!" << endl;
        return 0;
    }    
