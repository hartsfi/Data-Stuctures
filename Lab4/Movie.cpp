#include "Movie.h"

//Constructor initialization
Movie::Movie(string title, string description, double rating)
	: Show(title, description), Rating(rating) {}

Movie::Movie()
	: Show("", ""), Rating(0) {}

//Overriden Play function - Outputs the Rating of the Movie instance
void Movie::Play() {

	cout << "Rating: " << Rating << endl;

}
