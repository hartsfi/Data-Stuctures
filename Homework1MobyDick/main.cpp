#include "BookInfo.h"
using namespace std;

int main() {

	bool readAnotherBook = true;

	//Logic to read another book to the Catalog
	while (readAnotherBook) {

		string fileName;
		fstream fileData;
		bool isOpened = false;

		while (!isOpened) {

			cout << "Enter a file to access: ";
			cin >> fileName;

			fileData.open(fileName, ios::in);

			//Logic to ask for another .txt file if the first input fails to open
			if (fileData.fail()) {
				isOpened = false;
				cout << "File Failed To Open, Try Again.\n";
			}
			else {
				isOpened = true;
			}
		}

		//BookInfo object declaration and instantiation
		BookInfo bookOne;

		getline(fileData, bookOne.title);
		fileData >> bookOne.authorFirst;
		fileData >> bookOne.authorLast;
		bookOne.wordCount = getWordCount(fileData);
		bookOne.lineCount = getLineCount(fileData);
		getCharFrequency(fileData, bookOne);

		bookOne.saveToCatalog();

		fileData.close();

		//Asks users for letter frequency and to process another book
		if (getYesOrNoResponse("Would you like to see the letter frequency?")) {
			bookOne.printLetterFrequency();
		}

		if (!getYesOrNoResponse("Would you like to process another book?")) {
			break;
		}

	}

	return 0;

}
