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
    Queue(int size) : size(size), frontIndex(0), rearIndex(0) {
        items = new T*[size];
    }

    ~Queue() {
        for (int i = frontIndex; i < rearIndex; i++) {
            delete items[i % size];
        }
        delete[] items;
    }

    void enqueue(T* newItem) {
        if (isFull()) {
            throw OverflowException("Queue is Full");
        }
        items[rearIndex % size] = newItem;
        rearIndex++;
    }

    T* dequeue() {
        if (isEmpty()) {
            throw UnderflowException("Queue is Empty");
        }
        T* temp = items[frontIndex % size];
        frontIndex++;
        return temp;
    }

    T* front() {
        if (isEmpty()) {
            throw UnderflowException("Queue is Empty");
        }
        return items[frontIndex % size];
    }

    bool isEmpty() {
        return frontIndex == rearIndex;
    }

    bool isFull() {
        return (rearIndex - frontIndex) == size;
    }
};
