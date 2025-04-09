#include <iostream>
#include "LinkedList.h"
#include "Part.h"

int main() {
    LinkedList<Part> list;

    int choice;
    bool keep_running = true;

    while (keep_running) {


        cout << "\nPress 1 to Add an Item.\n"
            << "Press 2 to Get an Item.\n"
            << "Press 3 to Check if an Item is in the list.\n"
            << "Press 4 to See the size of the list.\n"
            << "Press 5 to See the Next item in the list.\n"
            << "Press 6 to See the Previous item in the list.\n"
            << "Press 7 to See an Item at a specific location.\n"
            << "Press 8 to Reset the Viewing location.\n"
            << "Press 9 to View the List of Items.\n"
            << "Press 0 to Quit\n"
            << "Choice: ";

        cin >> choice;

        switch (choice) {

        case 1: {

            int SKU;
            string Description;
            double Price;
            string UOM;
            char Option;
            int QuantityOnHand;

            while (true) {
                cout << "\nEnter a SKU: ";
                cin >> SKU;

                Part check_sku(SKU, " ", 0.0, " ");

                if (list.IsInList(check_sku)) {
                    cout << "\n!SKU Exists. Enter New SKU!" << endl;
                }
                else {
                    break;
                }
            }

            cout << "\nEnter a Description: ";
            cin >> Description;
            cout << "\nEnter a Price: $";
            cin >> Price;
            cout << "\nEnter a UOM: ";
            cin >> UOM;

            cout << "\nWould you like to add a Quantity On Hand Value? (y/n): ";
            cin >> Option;

            if (Option == 'y') {
                cout << "\nEnter a value for Quantity On Hand: ";
                cin >> QuantityOnHand;

                list.AddItem(Part(SKU, Description, Price, UOM, QuantityOnHand));
            }
            else {
                list.AddItem(Part(SKU, Description, Price, UOM));
            }

            break;
        }

        case 2: {
            int SKU;
            bool keep_asking = true;

            if (list.IsEmpty()) {
                cout << "\nList is Empty. Add an Item before removing.\n";
                break;
            }

            while (keep_asking) {
                cout << "\nEnter the SKU of the item you want to remove: ";
                cin >> SKU;

                Part check_sku(SKU, " ", 0.0, " ");

                if (list.IsInList(check_sku)) {
                    cout << "\nThe follwoing item was removed: " << list.GetItem(check_sku)->data << "\n";
                    keep_asking = false;
                }
                else {
                    cout << "\nSKU does not exist.Try Again.\n";
                }
            }
                break;
            }

        case 3: {
            int SKU;

            cout << "\nEnter a SKU: ";
            cin >> SKU;

            Part check_sku(SKU, " ", 0.0, " ");

            if (list.IsInList(check_sku)) {
                cout << "\nItem Exists in List!" << endl;
            }
            else {
                cout << "\nItem Does Not Exist!" << endl;
            }

            break;
        }
        case 4: {
            cout << "\nSize: " << list.Size() << endl;
            break;
        }
        case 5: {
            if (list.IsEmpty()) {
                cout << "\nList is empty.";
                break;
            }

            Node<Part>* next_item = list.SeeNext();

            if (next_item != nullptr) {
                cout << "\nNext Item: " << next_item->data;
            }
            else {
                cout << "\nYou have reached the end of the list. Resetting to First Item." << endl;
            }

            break;
        }
        case 6: {
            if (list.IsEmpty()) {
                cout << "\nList is empty.";
                break;
            }

            Node<Part>* prev_item = list.SeePrev();

            if (prev_item != nullptr) {
                cout << "\nPrevious Item: " << prev_item->data;
            }
            else {
                cout << "\nYou have reached the beginning of the list." << endl;
            }

            break;
        }
        case 7: {
            int index = -1;

            while (index < 0 || index > list.Size() - 1) {
                cout << "\nEnter an index (0-" << list.Size()-1 << "): ";
                cin >> index;
            }

            cout << "\n" << list.SeeAt(index)->data << " at index " << index << "\n";

            break;
        }
        case 8: {
            list.Reset();
            cout << "\nList Viewing Position Reset.\n";
            break;
        } 
        case 9: {
            if (list.IsEmpty()) {
                cout << "\nList is Empty." << endl;
                break;
            }
            cout << "+-------------+ List Of Items +-------------+\n";
            list.PrintList();
            break;
        }
        case 0: {
            return 0;
        }
        default: {
            cout << "\nEnter a Valid Choice.\n";
            break;
        }
        }
    }

    return 0;
}

