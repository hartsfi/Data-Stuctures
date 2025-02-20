#pragma once

class Wheel {
public:
    int minValue;
    int maxValue;

    Wheel(int maxVal = 10);
    int spin();
    void increaseRange();
    void decreaseRange(int playerMax);
};
