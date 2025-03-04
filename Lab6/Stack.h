#pragma once
#include "StackExceptions.h"

template <typename T>
class Stack {

	private:

		int const size;
		int index = 0;
		T** items;

	public:

		// Default Constructor
		Stack(int size) : size(size) {
			items = new T*[size];
		};

		// Destructor
		~Stack() {
			delete[] items;
		}

		/*
			push()

			Arguments: T* newItem
			Return: void
			Function: Adds the item to the Stack
		*/

		void push(T* newItem) {
			if (!isFull()) {
				items[index] = newItem;
				index++;
			}
			else {
				throw OverflowException("Exception: Stack is Full");
			}
		}

		/*
			pop()

			Arguments: None
			Return: T*
			Function: Removes the first item in the Stack and returns it
		*/

		T* pop() {
			if (!isEmpty()) {
				index--;
				return items[index];
			}
			
			throw UnderflowException("Exception: Stack is Empty");
		}

		/*
			top()

			Arguments: None
			Return: T*
			Function: Returns the top item of the Stack
		*/

		T* top() {
			if (!isEmpty()) {
				return items[index - 1];
			}

			throw UnderflowException("Exception: Stack is Empty");
		}

		/*
			empty()

			Arguments: None
			Return: void
			Function: Empties the Stack and deallocates items memory
		*/

		void empty() {
			while (!isEmpty()) {
				T* temp = pop();
				delete temp;
			}
		}

		// True if Stack is Empty
		bool isEmpty() {
			return index == 0;
		}
		 
		// True if Stack is Full
		bool isFull() {
			return index == size;
		}

		// Returns the length of the Stack
		int length() { return index; }

};
