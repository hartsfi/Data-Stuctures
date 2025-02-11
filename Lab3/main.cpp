#include "Measurement.h"
#include <iostream>

using namespace std;

char choice;
char operation;

int main() {			
choice = 'y'; 
while (choice == 'y' || choice == 'Y') { 

int little1, lot1, heap1;
int little2, lot2, heap2;
cout << "Enter first measurement (little lot heap): ";
cin >> little1;
cin >> lot1;
cin >> heap1;
Measurement m1(little1, lot1, heap1);


cout << "Enter second measurement (little lot heap): ";
cin >> little2;
cin >> lot2;
cin >> heap2;
Measurement m2(little2, lot2, heap2);


cout << "Enter operation (+, -, *, /, ==): ";
cin >> operation;
if (operation == '+') {
m1 + m2;
cout << "Result: ";
cout << m1;
cout << endl;
} 

else if (operation == '-') {
 m1 - m2;
cout << "Result: ";
cout << m1;
cout << endl;
} 

else if (operation == '*') {
m1 * m2;
cout << "Result: ";
cout << m1;
cout << endl;
} 

else if (operation == '/') {
if (m2.getLittle() == 0 && m2.getLot() == 0 && m2.getHeap() == 0) {
cout << "Error: Cannot divide by zero." << endl;
} else {
m1 / m2;
cout << "Result: ";
cout << m1;
cout << endl;
}
}

else if (operation == '=') {
if (m1 == m2) {
cout << "The measurements are equal." << endl;
} else {
cout << "The measurements are not equal." << endl;
}
} 
else {
cout << "That is not a valid operation." << endl;
}
cout << "Do you want to do another calculation? Enter y for yes or n for no: ";
cin >> choice;
}
if (choice == 'n' || choice == 'N') {
cout << "end" << endl;
}
else {
	
return 0;
}
}
