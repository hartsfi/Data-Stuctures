#pragma once
#include <iostream>
#include <ctime>

using namespace std;

class Part {

private:
	
	int SKU;
	string Description;
	double Price;
	string UOM;
	int QuantityOnHand;
	int LeadTime;

public:

	Part(int sku, string desc, double price, string uom, int qtyOnHand = 0, int leadTime = 7)
		: SKU(sku), Description(desc), Price(price), UOM(uom), QuantityOnHand(qtyOnHand), LeadTime(leadTime) {}

	string GetPartInfo() {
		return to_string(SKU) + " - " + Description;
	}

	void PrintPartInfo() {
		cout << "\n+----------------------------+" << endl;
		cout << "| SKU: " << SKU << "\t\t|" << endl;
		cout << "| Desc: " << Description << "\t\t|" << endl;
		cout << "| Price: $" << Price << "\t\t|" << endl;
		cout << "| UOM: " << UOM << "\t\t|" << endl;
		cout << "| Quantity: " << QuantityOnHand << "\t\t|" << endl;
		cout << "| Lead Time: " << LeadTime << " days\t|" << endl;
		cout << "+----------------------------+" << endl;
	}

	double GetPrice() {
		return Price;
	}

	bool InStock() {
		return QuantityOnHand > 0;
	}

	bool Available(time_t date) {
		if (InStock()) return true;

		time_t currentTime = time(nullptr);
		time_t availableDate = currentTime + (LeadTime * 86400);

		return date >= availableDate;
	}

	bool operator>(const Part& other) const {
		return SKU > other.SKU;
	}

	bool operator<(const Part& other) const {
		return SKU < other.SKU;
	}

	bool operator==(const Part& other) const {
		return SKU == other.SKU;
	}

	friend ostream& operator<<(ostream& os, Part& part) {
		os << part.GetPartInfo();
		return os;
	}
};
