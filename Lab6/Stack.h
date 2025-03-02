#pragma once
#include "StackExceptions.h"

template <typename T>
class Stack {

	private:

		int const size;
		int index = 0;
		T** items;

	public:

		Stack(int size) : size(size) {
			items = new T*[size];
		};

		~Stack() {
			delete[] items;
		}

		void push(T* newItem) {

			if (!isFull()) {
				items[index] = newItem;
				index++;
			}
			else {
				throw OverflowException("Exception: Stack is Full");
			}
		}

		T* pop() {
			if (!isEmpty()) {

				T* temp = items[index - 1];

				delete items[index - 1];

				index--;

				return temp;
			}
			
			throw UnderflowException("Exception: Stack is Empty");
		}

		T* top() {
			if (!isEmpty()) {
				return items[index - 1];
			}

			throw UnderflowException("Exception: Stack is Empty");
		}

		int length() { return index; }

		void empty() {

			for (int i = 0; i < index; i++) {
				delete items[i];
			}

			delete[] items;

			items = new T * [size];

			index = 0;
		}

		bool isEmpty() {
			return index == 0;
		}
		 
		bool isFull() {
			return index == size;
		}

};
