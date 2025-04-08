#pragma once
#include <iostream>

using namespace std;

template <typename T>
struct TreeNode {
    T data; // What data each node represents
    TreeNode* left; // Stores the pointer for the node to its left
    TreeNode* right; // Stores the pointer for the node to its right
    int height; // Stores the height of the node

    TreeNode (const T& input) {
        data = input;
        left = nullptr;
        right = nullptr;
        height = 0;
    };
};

class notFoundException {
    private:
        string errorMessage;
    public:
        explicit notFoundException(const string& errorMessage) : errorMessage(errorMessage) {}

        string getErrorMessage() const {
            return errorMessage;
        }
};


template <typename T>
class BinarySearchTree {
    private:
        TreeNode<T>* root;

        void RotateLeft(TreeNode<T>*& targetNode);
        void RotateRight(TreeNode<T>*& targetNode);
        int balanceCalculation(TreeNode<T>* node);
        void updateHeight(TreeNode<T>* node);


    public:
        T Remove(TreeNode<T> *&node, T target);
        T Find(TreeNode<T> *node, T target); 
        void Insert(TreeNode<T> *&node, T target);


        int getHeight(TreeNode<T>* node);
        int Size(TreeNode<T>* currentNode);
        TreeNode<T> GetAllAscending(TreeNode<T> nodeArray, TreeNode<T>* currentNode, int& index);
        TreeNode<T> GetAllDescending(TreeNode<T> nodeArray, TreeNode<T>* currentNode, int& index);
        void EmptyTree(TreeNode<T>* currentNode);

        BinarySearchTree() : root(nullptr) {};
        ~BinarySearchTree();


};

