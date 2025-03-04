#include "Stack.h"
#include "Queue.h"
#include "StackExceptions.h"
#include <iostream>
#include <fstream>

using namespace std;

// Function Declarations
string reverseWordsInSameOrder(const string& input);

void getConsoleInput();

void getFileInput();


int main() {

	while (true) {
		int choice;

		cout << "Choose input method: \n"
			<< "1. Console\n"
			<< "2. File\n"
			<< "3. Quit\n"
			<< "\nChoice: ";
		cin >> choice;

		switch (choice) {
			case 1: {
				getConsoleInput();

				break;
			}
			case 2: {
				getFileInput();

				break;
			}
			case 3: {
				return 0;

			}
			default: {
				cout << "\nInvalid Choice! Try Again!\n" << endl;
				break;
			}
		}
	}

	return 0;
}

/*
	reverseWordsInSameOrder()

	Arguments: const string& input
	Return: String
	Function: Handles all the logic needed to process a string, reverse
	its contents, and return it in the same word order. 
*/

string reverseWordsInSameOrder(const string& input) {

	int n = input.length();

	Stack<char> charStack(n);
	Queue<char> charQueue(n);

	try {
		for (char ch : input) {
			if (ch != ' ') {
				charStack.push(new char(ch));
			}
			else {
				while (!charStack.isEmpty()) {
					charQueue.enqueue(charStack.pop());
				}

				charQueue.enqueue(new char(' '));
			}
		}

		while (!charStack.isEmpty()) {
			charQueue.enqueue(charStack.pop());
		}
	}
	catch (const OverflowException& e) {
		cout << "\nException: Overflow Error" << endl;
	}

	string result;

	try {
		while (!charQueue.isEmpty()) {
			char* frontChar = charQueue.dequeue();
			result += *frontChar;
			delete frontChar;
		}
	}
	catch (const UnderflowException& e) {
		cout << "\nException: Underflow Error" << endl;
	}

	return result;

}

/*
	getConsoleInput()

	Arguments: none
	Return: void
	Function: Handles console input from the user calling the reverseWordsInSameOrder() function, 
	and outputs the results to the console.
*/

void getConsoleInput() {

	cout << "\nEnter a sentence: ";

	cin.ignore();
	string input;
	getline(cin, input);

	cout << "\nProcessed sentence: " << reverseWordsInSameOrder(input) << "\n" << endl;
	
}

/*
	getFileInput()

	Arguments: none
	Return: void
	Function: Handles getting a filename from the user, processing the contents, and outputting the
	resulting reversed text to the console
*/

void getFileInput() {

	string fileName;
	ifstream file;

	while (true) {
		cout << "\nEnter a Filename: ";
		cin >> fileName;
		file.open(fileName);

		if (file.is_open()) {
			break;
		}
		else {
			cout << "\nCould not open file. Try Again.\n" << endl;
		}
	}

	string line;
	while (getline(file, line)) {
		cout << "\n" << reverseWordsInSameOrder(line) << "\n" << endl;
	}

	file.close();
}
