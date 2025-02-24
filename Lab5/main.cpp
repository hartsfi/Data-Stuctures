#include "Shelf.h"
#include "Movie.h"
#include "ShelfExceptions.h"

using namespace std;

int main() {

	Shelf myShelf = Shelf();

	int choice;
	bool keepRunning = true;

	cout << "+------------+ Movie Shelf +------------+" << endl;
	
	while (keepRunning) {

		cout << "\nPress 1 to add a movie to the shelf.\n"
			<< "Press 2 to remove a movie from the shelf.\n"
			<< "Press 3 to see how many movies are currently on the shelf.\n"
			<< "Press 4 to quit.\n\n";
		cin >> choice;

		switch (choice) {

		case 1: {

			if (myShelf.getCount() != MOVIE_SHELF_LENGTH) {

				string title, description;
				int rating;

				cout << "\nEnter Movie Title: ";
				cin.ignore();
				getline(cin, title);
				cout << "\nEnter Movie Description: ";
				getline(cin, description);

				while (true) {

					cout << "\nEnter Movie Rating (1-10): ";
					cin >> rating;

					if (rating >= 1 && rating <= 10) {
						break;
					}
					else {
						cout << "\nInvalid Rating!" << endl;
					}
				}

				Movie movie = Movie(title, description, rating);

				myShelf.addMovie(movie);

				cout << "\nMovie added successfully!" << endl;
			}
			else {
				try {
					Movie temp = Movie();
					myShelf.addMovie(temp);
				}
				catch (const isFullException& e) {
					cout << "\nException: Full Shelf! Please Remove a Movie!\n";
				}
			}

			break;
		}

		case 2: {

			if (myShelf.getCount() != 0) {

				int index = 0;

				cout << "\nSelect a Movie index to remove: \n\n";

				myShelf.printShelf();

				while (true) {

					cout << "\nIndex: ";
					cin >> index;

					if (myShelf.checkIfValidIndex(index)) {
						break;
					}
					else {
						cout << "\nEnter a valid index!" << endl;
					}

				}

				cout << "\n" << myShelf.removeMovie(index - 1).getTitle() << " removed successfully!\n";
			}
			else {
				try {
					myShelf.removeMovie(0);
				}
				catch (const isEmptyException& e) {
					cout << "\nException: Shelf is Empty! Please add a Movie\n" << endl;
				}
			}

			break;
		}

		case 3: {

			cout << "\n" << myShelf.getCount() << " movies on the shelf!" << endl;

			break;

		}
		
		case 4: {

			keepRunning = false;

			break;

		}

		default: {

			cout << "Invalid Choice Try Again!";

			break;

		}

		}

	}

	return 0;
}
