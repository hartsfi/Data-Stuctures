#include "Shelf.h"
#include "ShelfExceptions.h"

//Constructor implementation
Shelf::Shelf() : movieCount(0) {}

//Accepts a Movie object and adds it to the shelf. Returns void.
void Shelf::addMovie(Movie& newMovie) {

	if (movieCount != MOVIE_SHELF_LENGTH) {
		for (int i = 0; i < MOVIE_SHELF_LENGTH; i++) {
			if (movieShelf[i].getTitle() == "") {
				movieShelf[i] = newMovie;
				movieCount++;
				break;
			}
		}
	}
	else {
		throw isFullException("Exception: Shelf is Full!");
	}
}

//Accepts an int index that specifies which Movie to remove from the shelf. Returns the Movie object you removed.
Movie Shelf::removeMovie(int index) {

	Movie removedMovie = movieShelf[index];


	if (movieCount != 0) {
		movieShelf[index] = Movie();
		movieCount--;
	}
	else {
		throw isEmptyException("Execption: Shelf is Empty!");
	}
	

	return removedMovie;
}

//Prints the shelfs contents in a formatted list with indexes. Returns void.
void Shelf::printShelf() {

	if (movieCount != 0) {
		for (int i = 0; i < MOVIE_SHELF_LENGTH; i++) {
			if (movieShelf[i].getTitle() != "") {
				cout << i + 1 << ". " << movieShelf[i].getTitle() << endl;
			}
		}
	}
	else {
		throw isEmptyException("Exception: Shelf is Empty!");
	}
}

//Accepts an int index and determines whether it's a valid index in the shelf. Returns a boolean. 
bool Shelf::checkIfValidIndex(int index) {
	if (movieShelf[index - 1].getTitle() != "") {
		return true;
	}
	else {
		return false;
	}
}
