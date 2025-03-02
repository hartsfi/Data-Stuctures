#pragma once
#include <string>
#include <iostream>

using namespace std;

class OverflowException {

	private:

		string message;

	public:

		explicit OverflowException(const string& msg) : message(msg) {}

		string getMessage() const { return message; }

};

class UnderflowException {
	private:

		string message;

	public:

		explicit UnderflowException(const string& msg) : message(msg) {}

		string getMessage() const { return message; }
};
