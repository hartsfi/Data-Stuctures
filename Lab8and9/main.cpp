#include "BinarySearchTree.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>
#include <iomanip>

using namespace std;

/*
     SetWordFrequency(fstream& fileData, BinarySearchTree<string>& tree) - 
     
     Returns: void

     Function: Accepts an fstream object and BinaryTree. Uses logic from Homework 1 to go word by word and 
               insert them into the Tree. It first converts the word to all lowercase then performs the insertion. 
*/
void SetWordFrequency(fstream& fileData, BinarySearchTree<string>& tree) {

    if (!fileData.is_open()) {
        cout << "File is not open!" << endl;
        return;
    }

    fileData.clear();
    fileData.seekg(0, ios::beg);

    string currentWord;
    bool countWords = false;

    while (fileData >> currentWord) {

        if (currentWord == "Contents:" || currentWord == "Contents: ") {
            countWords = true;
        }
        else if (countWords) {
            // Convert currentWord to lowercase
            transform(currentWord.begin(), currentWord.end(), currentWord.begin(),
                [](unsigned char c) { return tolower(c); });

            tree.Insert(currentWord);
        }
    }
    return;
}

int main() {

    string fileName;
    fstream fileData;
    bool isOpened = false;

    while (!isOpened) {

        cout << "Enter a file to access: ";
        cin >> fileName;

        fileData.open(fileName, ios::in);

        //Logic to ask for another .txt file if the first input fails to open
        if (fileData.fail()) {
            isOpened = false;
            cout << "File Failed To Open, Try Again.\n";
        }
        else {
            isOpened = true;
        }
    }

    BinarySearchTree<string> tree;
    SetWordFrequency(fileData, tree);
    int choice;
    bool keepRunning = true;

    while (keepRunning) {

        cout << "\n-------------------------------------------------------------"
            << "\n1. Find A Word"
            << "\n2. Size"
            << "\n3. Get All words in Ascending order"
            << "\n4. Get All words in Descending order"
            << "\n5. Empty Tree"
            << "\n6. Remove a word"
            << "\n7. Quit"
            << "\n-------------------------------------------------------------\n";
        cin >> choice;

        switch (choice) {

        case 1: {

            try {

                string search_word;
                cout << "\nEnter a word to find: ";
                cin >> search_word;

                TreeNode<string>* found_node = tree.Find(search_word);

                cout << "Word Found!"
                    << "\nCount: " << found_node->amount << "\n" << endl;
            }
            catch (const notFoundException& e) {
                cout << e.getErrorMessage() << "\n" << endl;
            }
            break;
        }

        case 2: {

            cout << "Tree size: " << tree.Size() << endl;

            break;
        }

        case 3: {

            int size = tree.Size();

            // Ascending
            TreeNode<string>** ascendingArray = tree.GetAscending();
            cout << "\nAscending order (in-order traversal):\n";
            cout << left << setw(20) << "Word"
                << setw(10) << "Height"
                << setw(10) << "Balance"
                << setw(10) << "Amount" << endl;

            cout << string(50, '-') << endl;

            for (int i = 0; i < size; i++) {
                cout << left << setw(20) << ascendingArray[i]->data
                    << setw(10) << ascendingArray[i]->height
                    << setw(10) << tree.GetBalance(ascendingArray[i])
                    << setw(10) << ascendingArray[i]->amount << endl;
            }
            delete[] ascendingArray;

            break;
        }

        case 4: {
            int size = tree.Size();
            
            // Descending
            TreeNode<string>** descendingArray = tree.GetDescending();
            cout << "\nDescending order (in-order traversal):\n";
            cout << left << setw(20) << "Word"
                << setw(10) << "Height"
                << setw(10) << "Balance"
                << setw(10) << "Amount" << endl;

            cout << string(50, '-') << endl;

            for (int i = 0; i < size; i++) {
                cout << left << setw(20) << descendingArray[i]->data
                    << setw(10) << descendingArray[i]->height
                    << setw(10) << tree.GetBalance(descendingArray[i])
                    << setw(10) << descendingArray[i]->amount << endl;
            }
            delete[] descendingArray;

            
            break;
        }

        case 5: {
            tree.EmptyTree();
            cout << "Tree Emptied!" << endl;

            string fileName;
            fstream fileData;
            bool isOpened = false;

            while (!isOpened) {

                cout << "Enter a different file to access: ";
                cin >> fileName;

                fileData.open(fileName, ios::in);

                if (fileData.fail()) {
                    isOpened = false;
                    cout << "File Failed To Open, Try Again.\n";
                }
                else {
                    isOpened = true;
                }
            }

            SetWordFrequency(fileData, tree);

            break;
        }

        case 6: {
            
            string remove_word;
            
            cout << "\nEnter a word to remove: ";

            cin >> remove_word;

            TreeNode<string>* removed_node = tree.Remove(remove_word);

            cout << remove_word << " was removed from the Tree!\n" << endl;

            break;
        }

        case 7: {
            keepRunning = false;
            break;
        }
        default: {
            cout << "Enter a valid choice!" << endl;
            break;
        }
        }
    }

    fileData.close();

    return 0;
}

