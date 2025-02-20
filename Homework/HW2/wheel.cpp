#include "Wheel.h"
#include <cstdlib>
#include <ctime>

Wheel::Wheel(int maxVal) {
    minValue = 1;
    maxValue = maxVal;
    srand(time(0));
}

int Wheel::spin() {
    return rand() % (maxValue - minValue + 1) + minValue;
}

void Wheel::increaseRange() {
    if (maxValue < 20) maxValue++;
}

void Wheel::decreaseRange(int playerMax) {
    if (maxValue > playerMax) maxValue--;
}
