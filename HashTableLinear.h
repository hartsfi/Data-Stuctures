#include"Student.h"
#pragma once

class HashTableLinear {
private:
    Student** table;//array of poiters to student 
    int maxSize;
    int currentSize;
    // Hash function that adds ASCII values of charachters and mods by table size
    int hash(std::string key) const;

public:
    HashTableLinear(int size = 100);
    ~HashTableLinear(); // Destructor

    bool addItem(Student* s);
    Student* removeItem(std::string key); // remove item
    Student* getItem(std::string key);//get item without removing
    int getLength() const; // current number of items
    bool isEmpty(); // returns true if table is empty
    bool isInList(std::string key);
};
