#pragma once
#include "Movie.h"

using namespace std;

int const MOVIE_SHELF_LENGTH = 10;

class Shelf {

	private:

		Movie movieShelf[MOVIE_SHELF_LENGTH];

		int movieCount;

	public:

		//Constructor and member function declarations
		Shelf();

		void addMovie(Movie& newMovie);

		Movie removeMovie(int index);

		int getCount() { return movieCount; }

		void printShelf();

		bool checkIfValidIndex(int index);
};
