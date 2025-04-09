#pragma once
#include <iostream>


template <typename T>
class Node {

	public:

		T data;

		Node<T>* next;
		Node<T>* prev;

		Node(T data) : data(data), next(nullptr), prev(nullptr) {}

		Node(const Node& other) : data(other.data), next(nullptr), prev(nullptr) {}

};
