#pragma once
#include <string>
#include <iostream>

using namespace std;

//Exception class for when the collection is full
class isFullException {
private:

    string message;

public:

    explicit isFullException(const string& msg) : message(msg) {}

    string getMessage() const {
        return message;
    }
};

//Exception class for when the collection is empty
class isEmptyException {
private:

    string message;

public:

    explicit isEmptyException(const string msg) : message(msg) {}

    string getMessage() const {
        return message;
    }
};


