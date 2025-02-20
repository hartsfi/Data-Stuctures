#ifndef WHEEL_H
#define WHEEL_H

class Wheel {
public:
    int minValue;
    int maxValue;

    Wheel(int maxVal = 10);
    int spin();
    void increaseRange();
    void decreaseRange(int playerMax);
};

#endif
