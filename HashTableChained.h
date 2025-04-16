#pragma once

#include "HashTableLinear.h"
#include "LinkedList.h"
#include "Student.h"

// This class extends HashTableLinear to use linked lists
class HashTableChained : public HashTableLinear {
private:
    LinkedList<Student>* chainedTable; // array of linked lists of students

public:
    // Constructor to initialize hash table of a given size
    HashTableChained(int size);

    // Destructor to clean up dynamic memory
    ~HashTableChained();

    // Add a student to the hash table (by value)
    bool addItem(Student* s);

    // Remove a student by their M-number (returns pointer to removed student)
    Student* removeItem(std::string inVal);

    // Get a student by M-number (returns copy)
    Student* getItem(std::string inVal);

    // Check if a student with this M-number is in the table
    bool isInList(std::string inVal);
};
