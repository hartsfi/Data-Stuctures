#pragma once
#include <iostream>
#include <vector>
using namespace std;

// Node to hold any data type
template <typename T>
struct TreeNode {
    T data;
    TreeNode* left;
    TreeNode* right;
    int height;

    TreeNode(const T& value) {
        data = value;
        left = right = nullptr;
        height = 1;
    }
};

// AVL Tree class
template <typename T>
class AVLTree {
public:
    AVLTree();                      // Constructor
    ~AVLTree();                     // Destructor
    void Insert(const T& value);    // Insert value
    TreeNode<T>* Find(const T& value); // Find value
    int Size();                     // Return total nodes
    vector<TreeNode<T>*> GetAllAscending(); // In-order (A-Z)

private:
    TreeNode<T>* root;              // Top of tree
    int size;

    // Recursive helper functions
    TreeNode<T>* insert(TreeNode<T>* node, const T& value);
    TreeNode<T>* find(TreeNode<T>* node, const T& value);
    void inOrder(TreeNode<T>* node, vector<TreeNode<T>*>& result);

    // AVL balancing
    int getHeight(TreeNode<T>* node);
    int getBalance(TreeNode<T>* node);
    TreeNode<T>* rotateLeft(TreeNode<T>* node);
    TreeNode<T>* rotateRight(TreeNode<T>* node);
    TreeNode<T>* rebalance(TreeNode<T>* node);

    // Destructor
    void destroyTree(TreeNode<T>* node);
};
