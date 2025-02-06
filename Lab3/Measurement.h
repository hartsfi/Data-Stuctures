#pragma once
#include <iostream>
#include <string>

using namespace std;

class Measurement {

private:
	int little;
	int lot;
	int heap;

public:
	Measurement();
	Measurement(int little, int lot, int heap);
	Measurement(int little);
	
	int getLittle() {return little;}
	int getLot() {return lot;}
	int getHeap() {return heap;}
	
	void printMeasurement();

	void setLittle(int littleNum) {little = littleNum;}
	void setLot(int lotNum) { lot = lotNum; }
	void getHeap(int heapNum) {heap = heapNum;}


};