#include "Measurement.h"

using namespace std;

Measurement::Measurement() : little(0), lot(0), heap(0) {}

Measurement::Measurement(int little, int lot, int heap) : little(little), lot(lot), heap(heap) {}

Measurement::Measurement(int little) : little(little), lot(0), heap(0) {}

//Converts all values into littles (easier to compare and perform arithmatic)
void Measurement::convertFromLittles() {

	heap = (little / 7) / 23;

	lot = (little / 7) % 23;

	little = little % 7;

};

//Converts all the littles back into the simplified forms (I wrote a new simplitfy function that works better than this but ill leave it here)
void Measurement::convertToLittles() {

	little += (lot * 7) + (heap * 23 * 7);

	lot = 0;

	heap = 0;

};

//Converts the measurement values to the simplified versions (Ex. (249, 2, 3) -> (4, 14, 4))
void Measurement::simplifyMeasurement() {

	convertToLittles();
	convertFromLittles();

};

//Overload for == to check if measurement instances are equal
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

//Overload for += to add two measurement instances (I wasn't sure if wwe should be using + or += versions of operators so theyll all use += for now)
void Measurement::operator +=(Measurement measurement) {
	
	this->little += measurement.little;
	this->lot += measurement.lot;
	this->heap += measurement.heap;

	simplifyMeasurement();

};

//Overload for -=
void Measurement::operator -=(Measurement measurement) {

	this->convertToLittles();
	measurement.convertToLittles();

	this->little -= measurement.little;

	this->convertFromLittles();
	measurement.convertFromLittles();

};

//Over load for cout << to print the measurements values
ostream& operator<<(ostream& os, const Measurement& measurement) {

	Measurement temp = measurement;

	temp.simplifyMeasurement(); 

	os << temp.little << " littles, " << temp.lot << " lots, " << temp.heap << " heaps";

	return os;

}


