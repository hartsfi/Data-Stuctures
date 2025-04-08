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
        void Insert(TreeNode<T> *&node,T target);

    public:
        T Remove(TreeNode<T> *&node, T target);
        T Find(TreeNode<T> *node, T target); // Returns data val when found, throws exception if not.
        void Insert(T target) { // Create a user friendly version of insert where they don't need the node.
            Insert(root,target);
        };


        int getHeight(TreeNode<T>* node);
        int Size(TreeNode<T>* currentNode);
        TreeNode<T> GetAllAscending(TreeNode<T> nodeArray, TreeNode<T>* currentNode, int& index);
        TreeNode<T> GetAllDescending(TreeNode<T> nodeArray, TreeNode<T>* currentNode, int& index);
        void EmptyTree(TreeNode<T>* currentNode);

        BinarySearchTree() : root(nullptr) {};
        ~BinarySearchTree() {
            EmptyTree(root);
        };


};

template <typename T>
T BinarySearchTree<T>::Find(TreeNode<T>* node,const T target) {
    if (node == nullptr) { // If the node gets to this point, it does not exist
        throw notFoundException("Target not found");
    }
    if (node->data == target) { // Case for the node data matching target
        return node->data;
    }
    if (target < node->data) { // Case to indicate moving to the right
        return Find(node->right,target);
    }
    else { // If it doesn't move to the right it must go left
        return Find(node->left,target);
    }
}

template <typename T>
// No return (Tree modification) // Pass in pointer to node (root) and target insert data value // Node will be updated every call
void BinarySearchTree<T>::Insert(TreeNode<T>*& node, const T target) {
    // Case for creating root
    if (node == nullptr) {
        node = new TreeNode<T>(target); // New node instance with target val
        root = node;
    }
    if (target < node->data) {
        // Spot is open for data to be inserted left
        if (node->left == nullptr) {
            node->left = new TreeNode<T>(target); // New node instance with target val
        }
        else { // There is no spot open for insert
            Insert(node->left,target);
        }
    }
    else if (target > node->data) {
        if (node->right == nullptr) { // Spot is open for data to be inserted right
            node->right = new TreeNode<T>(target); // New node instance with target val
        }
        else { // There is no spot open for insert
            Insert(node->right,target);
        }
    }
    else { // If there is a duplicate, insert to the right of it
        if (node->right == nullptr) { // There is a spot open for insertion
            node->right = new TreeNode<T>(target);
        }
        else { // There is no spot open for insertion
            Insert(node->right,target);
        }
    }

    updateHeight(node); // Add height to the node since it has a child post-insert

    int nodeBalance = balanceCalculation(node); // Get balance of the node post insert

    // If the new insert takes place at the far left of the left subtree
    // The balance indicates that there is an unbalance on said left subtree
    // Rotate main node of the subtree to the right to distribute node load
    //              30      -->         20
    //          20          -->     10      30
    //      10              -->
    if (nodeBalance > 1 && target < node->left->data)
        RotateRight(node);

    // If the new insert takes place at the far right of the right subtree
    // The balance indicates that there is an unbalance on said right subtree
    // Rotate the main node of the subtree to the left to distribute node load
    //      10              -->         20
    //          20          -->     10      30
    //              30      -->
    if (nodeBalance < -1 && target > node->right->data)
        RotateLeft(node);

    // If the new child is inserted to the right of the left child
    // The balance indicates that there is an imbalance on said left subtree
    // Rotate the left child to the left (Get that left child far left to straighten it out)
    // Rotate the main node to the right (Get that main node to the right to distribute the load)
    //      30  -->             30      -->         20
    //  10      -->         20          -->     10      30
    //      20  -->     10              -->
    if (nodeBalance > 1 && target > node->left->data) {
        RotateLeft(node->left);
        RotateRight(node);
    }

    // If the new child is inserted to the left of the right child
    // The balance indicates that there is an imbalance on the right subtree
    // Rotate the right child to the right (Get that right child far right to straighten it out)
    // Rotate the main node to the right (Get that main node to the left to distribute the load)
    //  10      -->     10              -->         20
    //      30  -->         20          -->     10      30
    //  20      -->             30      -->
    if (nodeBalance < -1 && target < node->right->data) {
        RotateRight(node->right);
        RotateLeft(node);
    }
}

template <typename T>
// Return data type T from target node // Pass in pointer to node and target data value // Node will be updated every call
T BinarySearchTree<T>::Remove (TreeNode<T>*& node,const T target) {
    if (node == nullptr) { // Case for target value not found
        throw notFoundException("Target value can not be found.");
    }
    if (target < node->data) { // If the target is less than the current node data (It has to be on left)
        Remove(node->left,target); // Call function to the left another position
    }
    else if (target > node->data) { // If the target is more than the current node data (It has to be on right)
        Remove(node->right,target); // Call function to the right another position
    }
    else { // The target == node->data
        T retVal = node->data;
        // Next we will have to handle cases of children
        // Node has no children // Can be deleted and node set to null (prevent memory leak) with no further action
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            node = nullptr;
        } // Node has one child that's on the left
        else if (node->left != nullptr && node->right == nullptr) {
            TreeNode<T>* temp = node; // Holds original node
            node = node->left; // Replace node with child
            delete temp; // Delete old node
        } // Node has one child that's on the right
        else if (node->right != nullptr && node->left == nullptr) {
            TreeNode<T>* temp = node; // Holds original node
            node = node->right; // Replace old node with child
            delete temp; // Delete old node
        } // Node has two children
        else {
            TreeNode<T>* temp = node->right; // Replacement node will be from right side
            // We want to use the far right->left value as the replacement node as it would not disrupt the order of the tree
            // temp->right->left is by default bigger than node->left, and temp->right->right would still be bigger without change
            // Once this while loop is done, we expect to have a temp->right->left nested value to act as a replacement
            // Obviously, if there is no left child, the tree will just be shifted left to fill the vacant spot
            while (temp->left != nullptr) {
                temp = temp->left;
            }
            // Overwrite the original node's data with our temp data while preserving its children and connections
            node->data = temp->data;
            // Remove the temp data value starting from the right of the node (So the replacement we just did isn't deleted)
            remove(node->right, temp->data);
        }
        return retVal;
    }
}

template <typename T>
int BinarySearchTree<T>::getHeight(TreeNode<T>* node) {
    if (node == nullptr)
        return -1; // No node exists
    else
        return node->height;
}


template <typename T>
int BinarySearchTree<T>::balanceCalculation(TreeNode<T>* node) {
    if (node == nullptr) //
        return 0;
    else
        return getHeight(node->left) - getHeight(node->right); // Left side - Right side // Why negative == right unbalanced
}

template <typename T>
void BinarySearchTree<T>::updateHeight(TreeNode<T>* node) {
    if (node == nullptr) return;

    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);

    // Since we take the heights of the left and right children, whatever that comes back to (+1) would be our height
    // We take the max of the two heights because if one child's subtree goes deeper that the other child, we need to account for that.
    // And if there would be no children, it would be max(-1,-1) which would evaluate fully to 0 which would be root or leaf.
    node->height = 1 + std::max(leftHeight, rightHeight);
}


template <typename T>
void BinarySearchTree<T>::RotateRight(TreeNode<T>*& targetNode) {
    // Node 1 is the left child of the original target node
    TreeNode<T>* node1 = targetNode->left;
    // Node 2 is the right child of node 1 (targetNode->left->right)
    TreeNode<T>* node2 = node1->right;

    // In a right rotation, we need target node now to the right of it's left child
    node1->right = targetNode;
    // If the left child already has a child in the right slot, we need to preserve it
    // Move the pre-existing child into the slot we just opened up on the target node
    targetNode->left = node2;

    targetNode = node1;

    updateHeight(targetNode);
    updateHeight(node1);
}

template <typename T>
void BinarySearchTree<T>::RotateLeft(TreeNode<T>*& targetNode) {
    // Node 1 is the right child of the original target node
    TreeNode<T>* node1 = targetNode->right;
    // Node 2 is the left child of node 1 (targetNode->right->left)
    TreeNode<T>* node2 = node1->left;

    // In a right rotation, we need target node now to the right of it's left child
    node1->left = targetNode;
    // If the right child already has a child in the left slot, we need to preserve it
    // Move the pre-existing child into the slot we just opened up on the target node
    targetNode->right = node2;

    targetNode = node1;

    updateHeight(targetNode);
    updateHeight(node1);
}

template <typename T>
void BinarySearchTree<T>::EmptyTree(TreeNode<T>* currentNode) {
    if (currentNode == nullptr) { // Case where we reach the end of a path (Start returning back up tree)
        return;
    }
    EmptyTree(currentNode->left); // Goes down the left subtree first
    EmptyTree(currentNode->right); // Goes down right subtree second

    // Once the function can't go down farther, it will reach here where it will delete the node
    // Then set the node to a nullptr so there are no memory leaks
    delete currentNode;
    currentNode = nullptr;
};

template <typename T>
int BinarySearchTree<T>::Size(TreeNode<T>* currentNode) {
    if (currentNode == nullptr) { // Case where we reach the end of a path (Start returning back up tree)
        return 0; // Return 0 since we don't want it counting towards size
    }
    // Incrementally add the size from each function call
    // If we get to this return it's atleast 1 even ->left and -> right don't return anything as we got past the first condition
    // This will go down the left subtree then the right subtree, tallying up
    return 1 + Size(currentNode->left) + Size(currentNode->right);
};

template <typename T>
TreeNode<T> BinarySearchTree<T>::GetAllAscending(TreeNode<T> nodeArray, TreeNode<T>* currentNode, int& index) {

};

// Practically just the inverse of the ascending function
template <typename T>
TreeNode<T> BinarySearchTree<T>::GetAllDescending(TreeNode<T> nodeArray, TreeNode<T>* currentNode, int& index) {

};





