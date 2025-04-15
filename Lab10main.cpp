#include <iostream>
#include "HashTableLinear.h"
#include "Student.h"

using namespace std;

int main() {
    HashTableLinear studentTable;

    int choice;
    bool keep_running = true;

    while (keep_running) {


        cout << "\nPress 1 to Add an Item.\n"
            << "Press 2 to Remove an Item.\n"
            << "Press 3 to Get an Item.\n"
            << "Press 4 to See the size of the list.\n"
            << "Press 0 to Quit\n"
            << "Choice: ";

        cin >> choice;

        switch (choice) {

        case 1: {

            string first_name;
            string last_name;
            string m_number;
            string major;

            cout << "\nFirst Name: ";
            cin >> first_name;
            cout << "\nLast Name: ";
            cin >> last_name;
            cout << "\nM Number: ";
            cin >> m_number;
            cout << "\nMajor: ";
            cin >> major;

            Student* s1 = new Student(first_name, last_name, m_number, major);

            if (studentTable.addItem(s1)) {
                std::cout << "\nAdded: " << s1->toString() << std::endl;
            }

            break;
        }

        case 2: {
            string m_number;
            bool keep_asking = true;

            if (studentTable.isEmpty()) {
                cout << "\Table is Empty. Add a Student before removing.\n";
                break;
            }

            while (keep_asking) {
                cout << "\nEnter the M-Number of the Student you want to remove: ";
                cin >> m_number;

                Student* removed = studentTable.removeItem(m_number);

                if (removed) {
                    cout << "\nRemoved: " << removed->toString() << endl;
                    keep_asking = false;
                    delete removed;  // free memory
                }
                else {
                    cout << "\nM-Number does not exist.Try Again.\n";
                }
            }
            break;
        }

        case 3: {
            
            string m_number;
            cout << "\nEnter M-Number of Student you want to get: ";
            cin >> m_number;

            if (studentTable.isInList(m_number)) {
                Student* found_student = studentTable.getItem(m_number);
                cout << "Student Found: " << found_student->toString() << "\n";
            }
            else {
                cout << "\nStudent Not Found!";
            }

            break;
        }
        case 4: {
            cout << "\nSize: " << studentTable.getLength() << endl;
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

