#pragma once
#include <iostream>
#include <string>

using namespace std;

class Measurement {

private:

	//Private members
	int little;
	int lot;
	int heap;

public:

	//Constuctor declarations
	Measurement();
	Measurement(int little, int lot, int heap);
	Measurement(int little);

	//Getters / Accessors
	int getLittle() { return little; }
	int getLot() { return lot; }
	int getHeap() { return heap; }

	//Setters / Mutators
	void setLittle(int littleNum) { little = littleNum; }
	void setLot(int lotNum) { lot = lotNum; }
	void setHeap(int heapNum) { heap = heapNum; }

	//Member function declarations
	int returnMeters();
	void convertToLittles();
	void convertFromLittles();
	void simplifyMeasurement();

	//Operator overload declarations
	bool operator ==(Measurement measurement);
	void operator -(Measurement measurement);
	void operator +(Measurement measurement);
	void operator *(Measurement measurement);
	void operator /(Measurement measurement);
	friend ostream& operator<<(ostream& os, const Measurement& measurement);

};
