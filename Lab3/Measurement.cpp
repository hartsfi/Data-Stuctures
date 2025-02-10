#include "Measurement.h"

using namespace std;

Measurement::Measurement() : little(0), lot(0), heap(0) {}

Measurement::Measurement(int little, int lot, int heap) : little(little), lot(lot), heap(heap) {}

Measurement::Measurement(int little) : little(little), lot(0), heap(0) {}

void Measurement::convertFromLittles() {

	heap = (little / 7) / 23;

	lot = (little / 7) % 23;

	little = little % 7;

};

void Measurement::convertToLittles() {

	little += (lot * 7) + (heap * 23 * 7);

	lot = 0;

	heap = 0;

};

void Measurement::simplifyMeasurement() {

	convertToLittles();
	convertFromLittles();

};

bool Measurement::operator ==(Measurement measurement) {

	Measurement tempL = *this;
	Measurement tempR = measurement;

	tempL.convertToLittles();
	tempR.convertToLittles();

	bool isEqual = (tempL.little == tempR.little);

	tempL.convertFromLittles();
	tempR.convertFromLittles();

	return isEqual;
};

void Measurement::operator +=(Measurement measurement) {
	
	this->little += measurement.little;
	this->lot += measurement.lot;
	this->heap += measurement.heap;

	simplifyMeasurement();

};

void Measurement::operator -=(Measurement measurement) {

	this->convertToLittles();
	measurement.convertToLittles();

	this->little -= measurement.little;

	this->convertFromLittles();
	measurement.convertFromLittles();

};

void Measurement::operator <<(Measurement measurement) {

	measurement.simplifyMeasurement();
	
	measurement.printMeasurement();

}

ostream& operator<<(ostream& os, const Measurement& measurement) {

	Measurement temp = measurement;

	temp.simplifyMeasurement(); 

	os << temp.little << " littles, " << temp.lot << " lots, " << temp.heap << " heaps";

	return os;

}


