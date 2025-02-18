class Player {
    public:
        int money;
        int bet;
        Wheel wheel; // The player has a wheel
    
        // Constructor: Start with some money
        Player() {
            money = 1000; // Start with $1000
            bet = 0;
        }
    
        // Place a bet
        void placeBet(int amount) {
            if (amount > 0 && amount <= money) {
                bet = amount;
                money -= bet;
                cout << "You bet: " << bet << endl;
            } else {
                cout << "Invalid bet!" << endl;
            }
        }
    
        // Spin the player's wheel
        int spinWheel() {
            return wheel.spin();
        }
    
        // Win the bet (get double the bet back)
        void win() {
            money += bet * 2;
            cout << "You won! New total: " << money << endl;
        }
    
        // Lose the bet (bet is already taken out)
        void lose() {
            cout << "You lost! Remaining money: " << money << endl;
        }
    };
