#include "Measurement.h"
#include <iostream>

using namespace std;

int main() {

	char choice;
	string operation;
	int little1, lot1, heap1;
	int little2, lot2, heap2;
	cout << "+-----------------------------------------------+" << endl;
	choice = 'y';

	while (choice == 'y' || choice == 'Y') {

		cout << "\nEnter first measurement (little lot heap): " << endl;
		cin >> little1;
		cin >> lot1;
		cin >> heap1;
		cout << "\n+-----------------------------------------------+\n" << endl;
		Measurement m1(little1, lot1, heap1);

		cout << "Enter operation (+, -, *, /, ==): \n";
		cin >> operation;
		cout << "\n+-----------------------------------------------+\n" << endl;


		cout << "Enter second measurement (little lot heap): " << endl;
		cin >> little2;
		cin >> lot2;
		cin >> heap2;
		cout << "\n+-----------------------------------------------+\n" << endl;
		Measurement m2(little2, lot2, heap2);

		if (operation == "+") {
			m1 + m2;
			cout << "\nResult: (" << m1 << ") " << endl;
		}

		else if (operation == "-") {
			m1 - m2;
			cout << "\nResult: (" << m1 << ") " << endl;
		}

		else if (operation == "*") {
			m1* m2;
			cout << "\nResult: (" << m1 << ") " << endl;
		}

		else if (operation == "/") {
			if (m2.getLittle() == 0 && m2.getLot() == 0 && m2.getHeap() == 0) {
				cout << "Error: Cannot divide by zero." << endl;
			}
			else {
				m1 / m2;
				cout << "\nResult: (" << m1 << ") " << endl;
			}
		}

		else if (operation == "==") {
			if (m1 == m2) {
				cout << "The measurements are equal." << endl;
			}
			else {
				cout << "The measurements are not equal." << endl;
			}
		}
		else {
			cout << "That is not a valid operation." << endl;
		}

		m1.convertToLittles();
		m2.convertToLittles();

		cout << "\nMeasurement One converted to meters: " << m1.getLittle() << "m" << endl;

		cout << "\nMeasurement Two converted to meters: " << m2.getLittle() << "m" << endl;

		cout << "\nDo you want to do another calculation? (Y/N): ";
		cin >> choice;
		cout << "\n+-----------------------------------------------+" << endl;
	}
	if (choice == 'n' || choice == 'N') {
		cout << "End" << endl;
	}
	else {

		return 0;
	}
}
