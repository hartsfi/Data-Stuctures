#pragma once
#include "Student.h"
#include <iostream>
#include <vector>

// Node structure for our linked list
struct Node {
    Student data;
    Node* next;

    Node(const Student& student) : data(student), next(nullptr) {}
};

// Linked list class to store Student information
class StudentLinkedList {
private:
    Node* head;
    int size;

    // Helper function to get node at specific position
    Node* getNodeAt(int position) const;

    // Sorting algorithms implementations
    // Bubble sort implementation
    void bubbleSort(bool (*compareFunc)(const Student&, const Student&));

    // Insertion sort implementation
    void insertionSort(bool (*compareFunc)(const Student&, const Student&));

    // Merge sort implementation
    Node* mergeSortHelper(Node* head, bool (*compareFunc)(const Student&, const Student&));
    Node* merge(Node* left, Node* right, bool (*compareFunc)(const Student&, const Student&));
    void mergeSort(bool (*compareFunc)(const Student&, const Student&));

    // Comparison functions for different sorting criteria
    static bool compareByFirstNameAsc(const Student& s1, const Student& s2);
    static bool compareByFirstNameDesc(const Student& s1, const Student& s2);
    static bool compareByLastNameAsc(const Student& s1, const Student& s2);
    static bool compareByLastNameDesc(const Student& s1, const Student& s2);
    static bool compareByMNumberAsc(const Student& s1, const Student& s2);
    static bool compareByMNumberDesc(const Student& s1, const Student& s2);

public:
    // Constructor and destructor
    StudentLinkedList();
    ~StudentLinkedList();

    // Basic operations
    void add(const Student& student);
    void remove(const std::string& mNumber);
    void clear();
    bool isEmpty() const;
    int getSize() const;
    void display() const;

    // Sorting methods with ascending/descending parameter
    void sortByFirstName(bool ascending = true);
    void sortByLastName(bool ascending = true);
    void sortByMNumber(bool ascending = true);
};
