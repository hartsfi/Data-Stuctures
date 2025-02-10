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

//Overload for == 
bool Measurement::operator ==(Measurement measurement) {

	this->convertToLittles();
	measurement.convertToLittles();

	bool isEqual = (this->little == measurement.little);

	this->convertFromLittles();
	measurement.convertFromLittles();

	return isEqual;
};

//Overload for +
void Measurement::operator +(Measurement measurement) {

	this->convertToLittles();
	measurement.convertToLittles();

	this->little += measurement.little;

	this->convertFromLittles();
	measurement.convertFromLittles();

};

//Overload for -
void Measurement::operator -(Measurement measurement) {

	this->convertToLittles();
	measurement.convertToLittles();

	this->little -= measurement.little;

	this->convertFromLittles();
	measurement.convertFromLittles();

};

//Overload for *
void Measurement::operator *(Measurement measurement) {

	this->convertToLittles();
	measurement.convertToLittles();

	this->little *= measurement.little;

	this->convertFromLittles();
	measurement.convertFromLittles();

};

//Overload for /
void Measurement::operator /(Measurement measurement) {

	this->convertToLittles();
	measurement.convertToLittles();

	this->little /= measurement.little;

	this->convertFromLittles();
	measurement.convertFromLittles();

};

//Overload for cout << to print the measurements values
ostream& operator<<(ostream& os, const Measurement& measurement) {

	Measurement temp = measurement;

	temp.simplifyMeasurement(); 

	os << temp.little << " littles, " << temp.lot << " lots, " << temp.heap << " heaps";

	return os;

}


