#pragma once
#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Node {

public:

    T data;

    Node<T>* next;
    Node<T>* prev;

    Node(T data) : data(data), next(nullptr), prev(nullptr) {}

    Node(const Node& other) : data(other.data), next(nullptr), prev(nullptr) {}

};

template <typename T>
class LinkedList {

private:
    int length;
    Node<T>* first;
    Node<T>* current;

public:
    LinkedList() : length(0), first(nullptr), current(nullptr) {}

    ~LinkedList() {
        Node<T>* temp = first;
        while (temp != nullptr) {
            Node<T>* next = temp->next;
            delete temp;
            temp = next;
        }
    }

    void AddItem(T item) {
        Node<T>* newNode = new Node<T>(item);

        if (IsEmpty()) {
            first = newNode;
        }
        else if (item < first->data) {
            newNode->next = first;
            first->prev = newNode;
            first = newNode;
        }
        else {
            Node<T>* temp = first;
            while (temp->next != nullptr && temp->next->data < item) {
                temp = temp->next;
            }

            newNode->next = temp->next;
            if (temp->next != nullptr) {
                temp->next->prev = newNode;
            }

            temp->next = newNode;
            newNode->prev = temp;
        }

        length++;
    }

    Node<T>* GetItem(T item) {
        Node<T>* temp = first;

        while (temp != nullptr) {
            if (temp->data == item) {
                if (temp == first) {
                    first = temp->next;
                    if (first != nullptr) first->prev = nullptr;
                }
                else {
                    temp->prev->next = temp->next;
                }

                if (temp->next != nullptr) {
                    temp->next->prev = temp->prev;
                }

                Node<T>* retItem = new Node<T>(temp->data);
                delete temp;
                length--;
                return retItem;
            }
            temp = temp->next;
        }
        return nullptr;
    }

    bool IsInList(T item) {
        Node<T>* temp = first;
        while (temp != nullptr) {
            if (temp->data == item) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    bool IsEmpty() {
        return length == 0;
    }

    Node<T>* SeeNext() { //Fix the brackets on these functions
        if (IsEmpty()) {
            throw runtime_error("Error: List is empty.");
        }

        if (current == nullptr) {
            current = first;
        }
        else {
            current = current->next;
        }

        return current;
    }

    Node<T>* SeePrev() {
        if (IsEmpty()) {
            throw runtime_error("Error: List is empty.");
        }

        if (current == nullptr) {
            current = first;
        }
        else {
            current = current->prev;
        }

        return current;
    }

    Node<T>* SeeAt(int index) {
        if (index >= length) throw runtime_error("Error: Invalid index.");

        current = first;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }

        return current;
    }

    void Reset() {
        current = nullptr;
    }

    int Size() {
        return length;
    }

    void PrintList() {
        if (IsEmpty()) return;

        Node<T>* temp = first;
        while (temp != nullptr) {
            std::cout << temp->data.toString() << std::endl;
            temp = temp->next;
        }
        std::cout << std::endl;
    }

};
