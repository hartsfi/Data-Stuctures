#pragma once
#include <string>
#include <iostream>

using namespace std;

class Movie {

	private:

		string title;
		string description;
		int rating;

	public:

		//Default and overloaded constructor declarations
		Movie();
		Movie(string title, string description, int rating);

		//Member function that returns the Movie instance's title
		string getTitle() { return title; }

};
