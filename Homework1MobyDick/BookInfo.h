#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

struct BookInfo {

    //Member Variables
    string title;
    string authorFirst;
    string authorLast;
    int wordCount;
    double letterFrequency[26] = { 0 };
    int lineCount;

    //Member Fucntion Declarations
    void printLetterFrequency() const;
    void saveToCatalog() const;

};

//Function declarations
int getWordCount(fstream& fileData);

void getCharFrequency(fstream& fileData, BookInfo& book);

int getLineCount(fstream& fileData);

bool getYesOrNoResponse(const string& prompt);


