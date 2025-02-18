class Wheel {
public:
    int minValue;
    int maxValue;

    // Constructor: Set the range from 1 to 10
    Wheel() {
        minValue = 1;
        maxValue = 10;
        srand(time(0)); // Make the random numbers different every time
    }

    // Spin the wheel to get a random number
    int spin() {
        return rand() % (maxValue - minValue + 1) + minValue;
    }
};
