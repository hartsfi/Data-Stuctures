#pragma once
#include "EntertainmentCollectionExceptions.h"

using namespace std;

int const COLLECTION_SIZE = 10;

template <typename T>
class EntertainmentCollection{

private:

	T collection[COLLECTION_SIZE];

	int itemCount;

public:

	EntertainmentCollection() : itemCount(0) {}

	//Accepts an item of type T and adds the item to the collection. Returns Void
	void addItem(T& newItem) {
		if (itemCount != COLLECTION_SIZE) {
			for (int i = 0; i < COLLECTION_SIZE; i++) {
				if (collection[i].getTitle() == "") {
					collection[i] = newItem;
					itemCount++;
					break;
				}
			}
		}
		else {
			throw isFullException("Exception: Collection is Full!");
		}
	}
	
	//Accepts a index of the collection and removes the item at that index. Returns the T item removed
	T removeItem(int index) {
		T removedItem = collection[index];

		if (itemCount != 0) {
			collection[index] = T();
			itemCount--;
		}
		else {
			throw isEmptyException("Exception: Shelf is Empty!");
		}

		return removedItem;
	}

	//Prints the items in the collection in a formatted list with indexes. Returns void
	void printCollection() {
		if (itemCount != 0) {
			for (int i = 0; i < COLLECTION_SIZE; i++) {
				if (collection[i].getTitle() != "") {
					cout << i + 1 << ". " << collection[i].getTitle() << endl;
				}
			}
		}
		else {
			throw isEmptyException("Exception: Collection is Empty!");
		}
	}

	//Accepts an int index and verifys if it's a valid index in the collection. Returns boolean
	bool checkIfValidIndex(int index) {
		return (index > 0 && index <= COLLECTION_SIZE && collection[index-1].getTitle() != "");
	}

	//Returns the itemCount
	int getCount() { return itemCount; }

};


