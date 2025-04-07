#include "BookInfo.h"
using namespace std;

//Member function that outputs the BookInfo objects letter frequency
void BookInfo::printLetterFrequency() const {

	cout << title << " letter frequency:" << endl;
	cout << fixed << setprecision(4);

	for (int i = 0; i < 26; i++) {
		char currentChar = 'a' + i;
		cout << currentChar << ": " << letterFrequency[i] << "%" << endl;
	}
}

//Member function that outputs the BookInfo objects data to the CardCatalog.txt file
void BookInfo::saveToCatalog() const {

	ofstream catalogFile("CardCatalog.txt", ios::app);

	if (catalogFile.is_open()) {

		catalogFile << "Title: " << title << endl;
		catalogFile << "Full Author Name: " << authorFirst << " " << authorLast << endl;
		catalogFile << "Author First Name: " << authorFirst << endl;
		catalogFile << "Author Last Name: " << authorLast << endl;
		catalogFile << "Word Count: " << wordCount << endl;
		catalogFile << "Line Count: " << lineCount << endl;
		catalogFile << endl;
		catalogFile.close();

		cout << "Book Information was catalogged successfully!" << endl;
	}
	else {
		cout << "Error: Unable to open CardCatalog.txt" << endl;
	}
}

//Function that returns the number of words in a given .txt file
int getWordCount(fstream& fileData) {

	fileData.clear();
	fileData.seekg(0, ios::beg);

	string currentWord;
	bool countWords = false;
	int wordCount = 0;

	while (fileData >> currentWord) {

		if (currentWord == "Contents:" || currentWord == "Contents: ") {
			countWords = true;
		}
		else if (countWords) {
			wordCount++;
		}

	}
	return wordCount;
}

//Function that stores the character frequencies of a given .txt file and stores them in the BookInfo object
void getCharFrequency(fstream& fileData, BookInfo& book) {

	fileData.clear();
	fileData.seekg(0, ios::beg);

	int letterCount = 0;
	double charFrequencies[26] = { 0 };
	char letter;

	while (fileData.get(letter)) {

		if (isalpha(letter)) {
			letter = tolower(letter);
			charFrequencies[letter - 'a']++;
			letterCount++;
		}
	}

	if (letterCount > 0) {

		for (int i = 0; i < 26; i++) {
			book.letterFrequency[i] = (charFrequencies[i] / letterCount) * 100;
		}
	}
}

//Function that returns the number of lines in a given .txt file
int getLineCount(fstream& fileData) {

	fileData.clear();
	fileData.seekg(0, ios::beg);

	string tempLine;
	int lineCount = 0;
	bool countBlankLine = false;

	while (getline(fileData, tempLine)) {

		if (!countBlankLine) {
			if (tempLine == "Contents: " || tempLine == "Contents:") {
				countBlankLine = true;
			}
		}
		else {
			lineCount++;
		}
	}

	return lineCount;
};

//Function that returns true if the user inputs "Y" and false if the user inputs "N"
bool getYesOrNoResponse(const string& prompt) {

	string response;

	while (true) {

		cout << prompt << " (Y/N): ";
		cin >> response;

		if (response == "Y" || response == "y") {
			return true;
		}
		if (response == "N" || response == "n") {
			return false;
		}

		cout << "Invalid input. Please enter Y or N.\n";
	}
}
