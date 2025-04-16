#include "HashTableChained.h"

// Constructor for HashTableChained
HashTableChained::HashTableChained(int size) : HashTableLinear(size) {
    // Create an array of LinkedLists, one for each index in the hash table.
    chainedTable = new LinkedList<Student>[size];
}

// Destructor for HashTableChained
HashTableChained::~HashTableChained() {
    delete[] chainedTable;
}

// Adds a new student to the hash table using chaining.
// It calculates the hash index for the student's MNumber and adds the student to the corresponding linked list.
bool HashTableChained::addItem(Student* newStudent) {
    int index = hash(newStudent->getMNumber());  // Get the hash index for the student's MNumber

    // If the student is not already in the hash table, add them to the corresponding linked list.
    if (!isInList(newStudent->getMNumber())) {
        chainedTable[index].AddItem(*newStudent);  // Add the student by value to the linked list at the calculated index
        currentSize++;  // Increment the current size of the hash table
        return true;
    }

    // If the student is already in the list, return false
    return false;
}

// Removes a student from the hash table by their MNumber.
// It searches for the student using their MNumber and deletes them from the corresponding linked list.
Student* HashTableChained::removeItem(std::string inVal) {
    int index = hash(inVal);  // Get the hash index for the MNumber to search

    // Search for the student in the corresponding linked list at that index.
    Node<Student>* result = chainedTable[index].GetItem(Student("", "", inVal, ""));
    if (result != nullptr) {
        currentSize--;  // Decrement the current size of the hash table
        Student* s = new Student(result->data);  // Create a new student object with the data found
        delete result;  // Delete the node from the linked list
        return s;  // Return the student that was removed
    }

    // If the student was not found, return nullptr.
    return nullptr;
}

// Retrieves a student from the hash table by their MNumber.
// It searches for the student in the linked list at the corresponding hash index.
Student* HashTableChained::getItem(std::string inVal) {
    int index = hash(inVal);  // Get the hash index for the MNumber

    // Start at the first node in the linked list at the computed index.
    Node<Student>* temp = chainedTable[index].SeeAt(0);
    // Traverse the linked list looking for the student.
    while (temp != nullptr) {
        if (temp->data.getMNumber() == inVal) {  // Check if the current node matches the target MNumber
            return new Student(temp->data);  // Return a copy of the student found
        }
        temp = chainedTable[index].SeeNext();  // Move to the next node in the linked list if not found
    }
    return nullptr; // Student is not there
}

// Checks if a student with the given MNumber exists in the hash table.
// It searches the linked list at the corresponding hash index for the student.
bool HashTableChained::isInList(std::string inVal) {
    int index = hash(inVal);  // Get the hash index for the MNumber

    // Start at the first node in the linked list at the computed index.
    Node<Student>* temp = chainedTable[index].SeeAt(0);
    while (temp != nullptr) {
        if (temp->data.getMNumber() == inVal) return true;  // Return true if the student is found
        temp = chainedTable[index].SeeNext();  // Move to the next node in the linked list
    }
    // Return false if the student is not found in the list.
    return false;
}
