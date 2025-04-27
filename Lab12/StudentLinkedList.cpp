#include "StudentLinkedList.h"
#include <iostream>
#include <string>

// Constructor
StudentLinkedList::StudentLinkedList() : head(nullptr), size(0) {}

// Destructor
StudentLinkedList::~StudentLinkedList() {
    clear();
}

// Get node at specific position
Node* StudentLinkedList::getNodeAt(int position) const {
    if (position < 0 || position >= size) {
        return nullptr;
    }

    Node* current = head;
    for (int i = 0; i < position; i++) {
        current = current->next;
    }

    return current;
}

// Add a student to the linked list
void StudentLinkedList::add(const Student& student) {
    Node* newNode = new Node(student);

    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    size++;
}

// Remove a student by MNumber
void StudentLinkedList::remove(const std::string& mNumber) {
    if (head == nullptr) {
        return;
    }

    if (head->data.getMNumber() == mNumber) {
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
        return;
    }

    Node* current = head;
    while (current->next != nullptr && current->next->data.getMNumber() != mNumber) {
        current = current->next;
    }

    if (current->next != nullptr) {
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
        size--;
    }
}

// Clear the linked list
void StudentLinkedList::clear() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    size = 0;
}

// Check if the linked list is empty
bool StudentLinkedList::isEmpty() const {
    return head == nullptr;
}

// Get the size of the linked list
int StudentLinkedList::getSize() const {
    return size;
}

// Display all students in the linked list
void StudentLinkedList::display() const {
    if (isEmpty()) {
        std::cout << "The list is empty." << std::endl;
        return;
    }

    Node* current = head;
    int index = 1;

    while (current != nullptr) {
        std::cout << index << ". " << current->data.toString() << std::endl;
        current = current->next;
        index++;
    }
}

bool StudentLinkedList::compareByFirstNameAsc(const Student& s1, const Student& s2) {
    return s1.getFirstName() < s2.getFirstName();
}

bool StudentLinkedList::compareByFirstNameDesc(const Student& s1, const Student& s2) {
    return s1.getFirstName() > s2.getFirstName();
}

bool StudentLinkedList::compareByLastNameAsc(const Student& s1, const Student& s2) {
    return s1.getLastName() < s2.getLastName();
}

bool StudentLinkedList::compareByLastNameDesc(const Student& s1, const Student& s2) {
    return s1.getLastName() > s2.getLastName();
}

bool StudentLinkedList::compareByMNumberAsc(const Student& s1, const Student& s2) {
    return s1.getMNumber() < s2.getMNumber();
}

bool StudentLinkedList::compareByMNumberDesc(const Student& s1, const Student& s2) {
    return s1.getMNumber() > s2.getMNumber();
}

// Bubble sort implementation
void StudentLinkedList::bubbleSort(bool (*compareFunc)(const Student&, const Student&)) {
    if (size <= 1) {
        return;
    }

    bool swapped;
    Node* current;
    Node* last = nullptr;

    do {
        swapped = false;
        current = head;

        while (current->next != last) {
            if (compareFunc(current->next->data, current->data)) {
                // Swap students (we swap the data, not the nodes)
                Student temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = true;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);
}

// Insertion sort implementation
void StudentLinkedList::insertionSort(bool (*compareFunc)(const Student&, const Student&)) {
    if (size <= 1) {
        return;
    }

    Node* sorted = nullptr;
    Node* current = head;

    while (current != nullptr) {
        Node* next = current->next;

        if (sorted == nullptr || compareFunc(current->data, sorted->data)) {
            current->next = sorted;
            sorted = current;
        }
        else {
            Node* search = sorted;
            while (search->next != nullptr && !compareFunc(current->data, search->next->data)) {
                search = search->next;
            }
            current->next = search->next;
            search->next = current;
        }

        current = next;
    }

    head = sorted;
}

// Merge two sorted linked lists
Node* StudentLinkedList::merge(Node* left, Node* right, bool (*compareFunc)(const Student&, const Student&)) {
    Node dummy(Student("", "", "")); // Dummy node to simplify code
    Node* tail = &dummy;

    while (left != nullptr && right != nullptr) {
        if (compareFunc(left->data, right->data)) {
            tail->next = left;
            left = left->next;
        }
        else {
            tail->next = right;
            right = right->next;
        }
        tail = tail->next;
    }

    // Attach remaining nodes
    if (left != nullptr) {
        tail->next = left;
    }
    else {
        tail->next = right;
    }

    return dummy.next;
}

// Recursive merge sort helper
Node* StudentLinkedList::mergeSortHelper(Node* head, bool (*compareFunc)(const Student&, const Student&)) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    // Find the middle of the list
    Node* slow = head;
    Node* fast = head->next;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Split the list into two halves
    Node* right = slow->next;
    slow->next = nullptr;

    // Recursively sort both halves
    Node* leftSorted = mergeSortHelper(head, compareFunc);
    Node* rightSorted = mergeSortHelper(right, compareFunc);

    // Merge the sorted halves
    return merge(leftSorted, rightSorted, compareFunc);
}

// Merge sort public method
void StudentLinkedList::mergeSort(bool (*compareFunc)(const Student&, const Student&)) {
    if (size <= 1) {
        return;
    }

    head = mergeSortHelper(head, compareFunc);
}

// Public sorting methods
void StudentLinkedList::sortByFirstName(bool ascending) {
    if (ascending) {
        mergeSort(compareByFirstNameAsc); // Using merge sort for first name
    }
    else {
        mergeSort(compareByFirstNameDesc);
    }
}

void StudentLinkedList::sortByLastName(bool ascending) {
    if (ascending) {
        bubbleSort(compareByLastNameAsc); // Using bubble sort for last name
    }
    else {
        bubbleSort(compareByLastNameDesc);
    }
}

void StudentLinkedList::sortByMNumber(bool ascending) {
    if (ascending) {
        insertionSort(compareByMNumberAsc); // Using insertion sort for MNumber
    }
    else {
        insertionSort(compareByMNumberDesc);
    }
}

