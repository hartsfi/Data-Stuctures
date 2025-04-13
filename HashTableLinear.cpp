#include "HashTableLinear.h"
#include <iostream>

HashTableLinear::HashTableLinear(int size) {
    maxSize = size;
    currentSize = 0;
    table = new Student*[maxSize];

    for (int i = 0; i < maxSize; i++) {
        table[i] = nullptr;
    }
}

// Destructor to clean up memory
HashTableLinear::~HashTableLinear() {
    for (int i = 0; i < maxSize; i++) {
        delete table[i];
    }
    delete[] table;
}

// Simple hash function based on ASCII sum
int HashTableLinear::hash(std::string key) const {
    int sum = 0;
    for (char ch : key) {
        sum += ch;
    }
    return sum % maxSize;
}

bool HashTableLinear::addItem(Student* s) {
    if (currentSize >= maxSize) return false; // table full

    int index = hash(s->getMNumber());
    int start = index;

    while (table[index] != nullptr) {
        index = (index + 1) % maxSize;
        if (index == start) return false; // looped around
    }

    table[index] = s;
    currentSize++;
    return true;
}

Student* HashTableLinear::removeItem(std::string key) {
    int index = hash(key);
    int start = index;

    while (table[index] != nullptr) {
        if (table[index]->getMNumber() == key) {
            Student* temp = table[index];
            table[index] = nullptr;
            currentSize--;
            return temp;
        }
        index = (index + 1) % maxSize;
        if (index == start) break;
    }
    return nullptr;
}

Student* HashTableLinear::getItem(std::string key) {
    int index = hash(key);
    int start = index;

    while (table[index] != nullptr) {
        if (table[index]->getMNumber() == key) {
            return table[index];
        }
        index = (index + 1) % maxSize;
        if (index == start) break;
    }
    return nullptr;
}

int HashTableLinear::getLength() const {
    return currentSize;
}