#pragma once
#include <iostream>
#include <stdexcept>

using namespace std;

/*
    TreeNode Struct:
        - data: The value stored in the node
        - height: The height of the node in the tree
        - amount: Count of duplicate elements
        - left: Pointer to the left child
        - right: Pointer to the right child
*/
template <typename T>
struct TreeNode {
    T data;
    int height;
    int amount;
    TreeNode* left;
    TreeNode* right;

    TreeNode(T val) : data(val), height(1), amount(1), left(nullptr), right(nullptr) {}
};

/*
    notFoundException Class:
        - Custom exception class for tree operations
        - Provides meaningful error messages when an item is not found
*/
class notFoundException : public std::exception {
public:
    const char* getErrorMessage() const noexcept {
        return "Item not found in the tree.";
    }

    notFoundException(const char* message) : msg(message) {}
    const char* what() const noexcept override {
        return msg;
    }

private:
    const char* msg;
};

// BinarySearchTree class with templated type T
template <typename T>
class BinarySearchTree {
public:
    BinarySearchTree() : root(nullptr), treeSize(0) {}

    ~BinarySearchTree() {
        EmptyTree(root);
    }

    /*
        GetBalance(TreeNode<T>* node) const -
        Returns: int
        Function: Computes and returns the balance factor of the given node
    */
    int GetBalance(TreeNode<T>* node) const {
        return balanceCalculation(node);
    }

    /*
        Insert(T value) -
        Returns: void
        Function: Public interface to insert a value into the tree
    */
    void Insert(T value) {
        Insert(root, value);
    }

    /*
        EmptyTree() -
        Returns: void
        Function: Public interface to empty (delete) the entire tree
    */
    void EmptyTree() {
        EmptyTree(root);
    }

    /*
        Size() -
        Returns: int
        Function: Returns the total number of nodes in the tree
    */
    int Size() {
        return Size(root);
    }

    /*
        Find(T searchItem) const -
        Returns: TreeNode<T>*
        Function: Takes in an item of type T and searches the tree for that item. If found, the node is returned, if not, an exception is thrown
    */
    TreeNode<T>* Find(T searchItem) const {
        return Find(root, searchItem);
    }

    /*
        GetAscending() -
        Returns: TreeNode<T>**
        Function: Returns an array of pointers to tree nodes in ascending (in-order) order
    */
    TreeNode<T>** GetAscending() {
        return GetAscending(root);
    }

    /*
        GetDescending() -
        Returns: TreeNode<T>**
        Function: Returns an array of pointers to tree nodes in descending (reverse in-order) order
    */
    TreeNode<T>** GetDescending() {
        return GetDescending(root);
    }

    /*
        Remove(const T target) -
        Returns: TreeNode<T>*
        Function: Removes the node with the given value from the tree and returns a copy of that node's data
    */
    TreeNode<T>* Remove(const T target) {
        return Remove(root, target);
    }

private:
    TreeNode<T>* root;
    int treeSize;

    // Returns the height of the node or 0 if null
    int getHeight(TreeNode<T>* node) const {
        return node ? node->height : 0;
    }

    /*
        Size(TreeNode<T>* currentNode) const -
        Returns: int
        Function: Recursively calculates the size (number of nodes) of the subtree rooted at currentNode
    */
    int Size(TreeNode<T>* currentNode) const {
        return currentNode ? 1 + Size(currentNode->left) + Size(currentNode->right) : 0;
    }

    /*
        Find(TreeNode<T>* currentNode, T searchItem) const -
        Returns: TreeNode<T>*
        Function: Takes in an item of type T and searches the tree for that item. If found, the node is returned, if not, an exception is thrown
    */
    TreeNode<T>* Find(TreeNode<T>* currentNode, T searchItem) const {
        if (currentNode == nullptr) {
            throw notFoundException("Item not found in the tree.");
        }

        if (searchItem == currentNode->data) {
            return currentNode;
        }
        else if (searchItem < currentNode->data) {
            return Find(currentNode->left, searchItem);
        }
        else {
            return Find(currentNode->right, searchItem);
        }
    }

    /*
        Insert(TreeNode<T>*& currentNode, T value) -
        Returns: void
        Function: Recursively inserts a value into the subtree rooted at currentNode while maintaining AVL balance
    */
    void Insert(TreeNode<T>*& currentNode, T value) {
        if (currentNode == nullptr) {
            currentNode = new TreeNode<T>(value);
            treeSize++;
            return;
        }

        if (value < currentNode->data) {
            Insert(currentNode->left, value);
        }
        else if (value > currentNode->data) {
            Insert(currentNode->right, value);
        }
        else {
            currentNode->amount++;
            return;
        }

        updateHeight(currentNode);
        balance(currentNode);
    }

    /*
        Remove(TreeNode<T>*& node, const T target) -
        Returns: TreeNode<T>*
        Function: Recursively finds and removes a node with the given value and returns a copy of the removed node
    */
    TreeNode<T>* Remove(TreeNode<T>*& node, const T target) {
        if (node == nullptr) {
            throw notFoundException("Target value can not be found.");
        }

        if (target < node->data) {
            return Remove(node->left, target);
        }
        else if (target > node->data) {
            return Remove(node->right, target);
        }
        else {
            TreeNode<T>* removedNode = new TreeNode<T>(node->data);
            removedNode->height = node->height;
            removedNode->amount = node->amount;

            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                node = nullptr;
            }
            else if (node->left != nullptr && node->right == nullptr) {
                TreeNode<T>* temp = node;
                node = node->left;
                delete temp;
            }
            else if (node->right != nullptr && node->left == nullptr) {
                TreeNode<T>* temp = node;
                node = node->right;
                delete temp;
            }
            else {
                TreeNode<T>* temp = node->right;
                while (temp->left != nullptr) {
                    temp = temp->left;
                }
                node->data = temp->data;
                node->amount = temp->amount;
                Remove(node->right, temp->data);
            }

            treeSize--;
            return removedNode;
        }
    }

    /*
        GetAscending(TreeNode<T>* node) -
        Returns: TreeNode<T>**
        Function: Fills and returns a dynamically allocated array of TreeNode pointers in ascending order
    */
    TreeNode<T>** GetAscending(TreeNode<T>* node) {
        int size = Size(node);
        TreeNode<T>** array = new TreeNode<T>*[size];
        int index = 0;
        fillAscending(array, node, index);
        return array;
    }

    /*
        GetDescending(TreeNode<T>* node) -
        Returns: TreeNode<T>**
        Function: Fills and returns a dynamically allocated array of TreeNode pointers in descending order
    */
    TreeNode<T>** GetDescending(TreeNode<T>* node) {
        int size = Size(node);
        TreeNode<T>** array = new TreeNode<T>*[size];
        int index = 0;
        fillDescending(array, node, index);
        return array;
    }

    /*
        EmptyTree(TreeNode<T>*& currentNode) -
        Returns: void
        Function: Recursively deletes all nodes in the subtree rooted at currentNode
    */
    void EmptyTree(TreeNode<T>*& currentNode) {
        if (currentNode == nullptr) return;
        EmptyTree(currentNode->left);
        EmptyTree(currentNode->right);
        delete currentNode;
        currentNode = nullptr;
        treeSize = 0;
    }

    // Updates the height of the given node based on its children's heights
    void updateHeight(TreeNode<T>* node) {
        if (node) {
            int leftHeight = getHeight(node->left);
            int rightHeight = getHeight(node->right);
            node->height = 1 + std::max(leftHeight, rightHeight);
        }
    }

    // Performs a left rotation on the given node
    void rotateLeft(TreeNode<T>*& node) {
        TreeNode<T>* newRoot = node->right;
        node->right = newRoot->left;
        newRoot->left = node;
        updateHeight(node);
        updateHeight(newRoot);
        node = newRoot;
    }

    // Performs a right rotation on the given node
    void rotateRight(TreeNode<T>*& node) {
        TreeNode<T>* newRoot = node->left;
        node->left = newRoot->right;
        newRoot->right = node;
        updateHeight(node);
        updateHeight(newRoot);
        node = newRoot;
    }

    /*
        balance(TreeNode<T>*& node) -
        Returns: void
        Function: Applies AVL balancing logic to the node by performing appropriate rotations
    */
    void balance(TreeNode<T>*& node) {
        if (!node) return;

        updateHeight(node);
        int balanceFactor = balanceCalculation(node);

        if (balanceFactor > 1) {
            if (balanceCalculation(node->left) < 0) {
                rotateLeft(node->left);
            }
            rotateRight(node);
        }
        else if (balanceFactor < -1) {
            if (balanceCalculation(node->right) > 0) {
                rotateRight(node->right);
            }
            rotateLeft(node);
        }
    }

    // Calculates the balance factor of a node
    int balanceCalculation(const TreeNode<T>* currentNode) const {
        if (!currentNode) return 0;

        int leftHeight = (currentNode->left) ? getHeight(currentNode->left) : 0;
        int rightHeight = (currentNode->right) ? getHeight(currentNode->right) : 0;

        return leftHeight - rightHeight;
    }

    // Helper function to fill an array in ascending order using in-order traversal
    void fillAscending(TreeNode<T>** array, TreeNode<T>* node, int& index) {
        if (node == nullptr) return;
        fillAscending(array, node->left, index);
        array[index++] = node;
        fillAscending(array, node->right, index);
    }

    // Helper function to fill an array in descending order using reverse in-order traversal
    void fillDescending(TreeNode<T>** array, TreeNode<T>* node, int& index) {
        if (node == nullptr) return;
        fillDescending(array, node->right, index);
        array[index++] = node;
        fillDescending(array, node->left, index);
    }
};
