#pragma once
#include "StackExceptions.h"

template <typename T>
class Queue {

    private:

        int size;
        int frontIndex;
        int rearIndex;
        T** items;

    public:

        // Default constructor
        Queue(int size) : size(size), frontIndex(0), rearIndex(0) {
            items = new T*[size];
        }
         
        // Destructor
        ~Queue() {
            for (int i = frontIndex; i < rearIndex; i++) {
                delete items[i % size];
            }
            delete[] items;
        }

        /*
            enqueue()

            Arguments: T* newItem
            Return: void
            Function: Adds the item to the Queue
        */

        void enqueue(T* newItem) {
            if (isFull()) {
                throw OverflowException("Queue is Full");
            }
            items[rearIndex % size] = newItem;
            rearIndex++;
        }

        /*
            dequeue()

            Arguments: T* newItem
            Return: T* 
            Function: Removes first item from the Queue and returns it
        */

        T* dequeue() {
            if (isEmpty()) {
                throw UnderflowException("Queue is Empty");
            }
            T* temp = items[frontIndex % size];
            frontIndex++;
            return temp;
        }

        /*
            front()

            Arguments: None
            Return: T*
            Function: Returns the first item in the Queue
        */

        T* front() {
            if (isEmpty()) {
                throw UnderflowException("Queue is Empty");
            }
            return items[frontIndex % size];
        }

        /*
            empty()

            Arguments: None
            Return: void
            Function: Empties the Queue by deleting all the allocated memory for the items
        */

        void empty() {
            while (!isEmpty()) {
                T* temp = dequeue(); 
                delete temp;  
            }
        }

        // True if Queue is Empty
        bool isEmpty() {
            return frontIndex == rearIndex;
        }

        // True if Queue is Full
        bool isFull() {
            return (rearIndex - frontIndex) == size;
        }
};
