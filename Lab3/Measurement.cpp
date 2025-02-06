#include "Measurement.h"

using namespace std;


Measurement::Measurement() : little(0), lot(0), heap(0) {};
Measurement::Measurement(int little, int lot, int heap) : little(little), lot(lot), heap(heap) {};
Measurement::Measurement(int little) : little(little), lot(0), heap(0) {};


void Measurement::printMeasurement() {
	cout << little << " little.\n" << lot << " lot.\n" << heap << " heap.\n";
};