#include "VideoGames.h"
#include "EntertainmentCollection.h"
#include "EntertainmentCollectionExceptions.h"


using namespace std;

int main() {

	EntertainmentCollection<VideoGames> myCollection;

	int choice;
	bool keepRunning = true;

	cout << "+------------+ Video Game Shelf +------------+" << endl;

	while (keepRunning) {

		cout << "Press 1 to add a Video Game to the shelf.\n"
			<< "Press 2 to remove a Video Game from the shelf.\n"
			<< "Press 3 to see how many Video Games are currently on the shelf.\n"
			<< "Press 4 to quit.\n\n";
		cin >> choice;

		switch (choice) {

		case 1: {

			if (myCollection.getCount() != COLLECTION_SIZE) {

				string title, description;
				int rating;

				cout << "\nEnter Video Game Title: ";
				cin.ignore();
				getline(cin, title);
				cout << "\nEnter Video Game Description: ";
				getline(cin, description);

				while (true) {

					cout << "\nEnter Video Game Rating (1-10): ";
					cin >> rating;

					if (rating >= 1 && rating <= 10) {
						break;
					}
					else {
						cout << "\nInvalid Rating!" << endl;
					}
				}

				VideoGames videoGame = VideoGames(title, description, rating);

				myCollection.addItem(videoGame);

				cout << "\nVideo Game added successfully!\n" << endl;
			}
			else {
				try {
					VideoGames temp = VideoGames();
					myCollection.addItem(temp);
				}
				catch (const isFullException& e) {
					cout << "\nException: Full Shelf! Please Remove a Video Game!\n";
				}
			}

			break;
		}

		case 2: {

			if (myCollection.getCount() != 0) {

				int index = 0;

				cout << "\nSelect a Video Game index to remove: \n\n";

				myCollection.printCollection();

				while (true) {

					cout << "\nIndex: ";
					cin >> index;

					if (myCollection.checkIfValidIndex(index)) {
						break;
					}
					else {
						cout << "\nEnter a valid index!" << endl;
					}

				}

				cout << "\n" << myCollection.removeItem(index - 1).getTitle() << " removed successfully!\n\n";
			}
			else {
				try {
					myCollection.removeItem(0);
				}
				catch (const isEmptyException& e) {
					cout << "\nException: Shelf is Empty! Please add a Video Game\n" << endl;
				}
			}

			break;
		}

		case 3: {

			cout << "\n" << myCollection.getCount() << " Video Gamea on the shelf!" << endl;

			break;

		}

		case 4: {

			keepRunning = false;

			break;

		}

		default: {

			cout << "\nInvalid Choice Try Again!\n\n";

			break;

		}

		}

	}

	return 0;
}
