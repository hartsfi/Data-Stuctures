#pragma once
#include <string>
#include <iostream>

using namespace std;

class VideoGames {

private:

	string title;
	string description;
	int rating;

public:

	//Default and overloaded constructor declarations
	VideoGames();
	VideoGames(string title, string description, int rating);

	//Returns the title of the Video Game
	string getTitle() { return title; }

};
