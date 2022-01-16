// Program reads from text file and creates a sorted linked list from the values.
// Program provides a menu for carrying out various list operations, such as
// inserting, deleting, and searching items in the list.
#include <iostream>
#include <fstream>
#include "Data.h" // include definition of class Data
#include "SortedLinkedList.h" // include definition of class SortedLinkedList

using namespace std;

int main(int argc, char **argv) {
    if (argc != 2) { // checking for number of command line arguments.
        cout << "Error: invalid number of command line arguments. Please use the following syntax." << endl;
        cout << "./main filename.txt" << endl;
        exit(EXIT_FAILURE);
    }
    string arg1 = argv[1];
    ifstream input(arg1);
    SortedLinkedList list;
    Data data;
    int number{0};
    while (input >> number) {
        data.initialize(number);
        list.insertData(data);
    }
    cout << "Commands:" << endl;
    cout << "(i) - Insert value" << endl;
    cout << "(d) - Delete value" << endl;
    cout << "(s) - Search value" << endl;
    cout << "(n) - Print next iterator value" << endl;
    cout << "(r) - Reset iterator" << endl;
    cout << "(a) - Delete alternate nodes" << endl;
    cout << "(m) - Merge two lists" << endl;
    cout << "(t) - Intersection" << endl;
    cout << "(p) - Print list" << endl;
    cout << "(l) - Print length" << endl;
    cout << "(q) - Quit program" << endl;
    string userInput;
    bool continueLoop{true};
    cout << "Enter a command: ";
    cin >> userInput;
    while (continueLoop) {
        if (userInput == "i") {
            string insert{};
            SortedLinkedList::printList(list);
            cout << "Enter number: ";
            cin >> insert;
            data.initialize(stoi(insert));
            if (list.searchData(data) == -1) {
                list.insertData(data);
            } else {
                cout << "Sorry. You cannot insert the duplicate data." << endl;
            }
            SortedLinkedList::printList(list);
            cout << "Enter a command: ";
            cin >> userInput;
        } else if (userInput == "d") {
            string remove{};
            SortedLinkedList::printList(list);
            cout << "Enter value to delete: ";
            cin >> remove;
            data.initialize(stoi(remove));
            if (list.getLength() == 0) {
                cout << "You cannot delete from an empty list.";
            } else {
                if (list.searchData(data) == -1) {
                    cout << "Item not found." << endl;
                } else {
                    list.deleteData(data);
                }
            }
            SortedLinkedList::printList(list);
            cout << "Enter a command: ";
            cin >> userInput;
        } else if (userInput == "s") {
            string search{};
            cout << "Enter a value to search: ";
            cin >> search;
            data.initialize(stoi(search));
            if (list.searchData(data) == -1) {
                cout << "Item not found." << endl;
            } else {
                cout << "Index " << list.searchData(data) << endl;
            }
            cout << "Enter a command: ";
            cin >> userInput;
        } else if (userInput == "n") {
            string iterate;
            int count{0};
            bool loop{true};
            if (list.getLength() != 0) {
                cout << list.getData().getValue() << endl;
                count++;
                cout << "Enter a command: ";
                cin >> iterate;
                while (loop) {
                    if (count == list.getLength()) {
                        cout << "The end of the list has been reached" << endl;
                        loop = false;
                        cout << "Enter a command: ";
                        cin >> userInput;
                    } else {
                        if (iterate != "n") {
                            userInput = iterate;
                            loop = false;
                        } else {
                            cout << list.getNextData().getValue() << endl;
                            count++;
                            cout << "Enter a command: ";
                            cin >> iterate;
                            if (iterate != "n") {
                                userInput = iterate;
                                loop = false;
                            }
                        }
                    }
                }
            } else {
                cout << "List is empty" << endl;
                cout << "Enter a command: ";
                cin >> userInput;
            }
        } else if (userInput == "r") {
            list.resetList();
            cout << "Iterator reset." << endl;
            cout << "Enter a command: ";
            cin >> userInput;
        } else if (userInput == "a") {
            cout << "List before alternate delete: ";
            SortedLinkedList::printList(list);
            cout << "List after alternate delete: ";
            list.deleteAlternateNodes();
            SortedLinkedList::printList(list);
            cout << "Enter a command: ";
            cin >> userInput;
        } else if (userInput == "m") {
            string listLength{};
            string elements{};
            cout << "Length of list to merge: ";
            cin >> listLength;
            cout << "List elements separated by spaces in order: ";
            cin.ignore();
            getline(cin, elements);
            cout << "List 1: ";
            SortedLinkedList::printList(list);
            cout << "List 2: " << elements << endl;
            list.merge(list, elements);
            SortedLinkedList::printList(list);
            cout << "Enter a command: ";
            cin >> userInput;
        } else if (userInput == "t") {
            string listLength{};
            string elements{};
            cout << "Length of list to find intersection: ";
            cin >> listLength;
            cout << "List elements separated by spaces in order: ";
            cin.ignore();
            getline(cin, elements);
            cout << "List 1: ";
            SortedLinkedList::printList(list);
            cout << "List 2: " << elements << endl;
            list.intersection(list, elements);
            cout << "Intersection: ";
            SortedLinkedList::printList(list);
            cout << "Enter a command: ";
            cin >> userInput;
        } else if (userInput == "p") {
            SortedLinkedList::printList(list);
            cout << "Enter a command: ";
            cin >> userInput;
        } else if (userInput == "l") {
            cout << "List Length is " << list.getLength() << endl;
            cout << "Enter a command: ";
            cin >> userInput;
        } else if (userInput == "q") {
            cout << "Quitting program..." << endl;
            continueLoop = false;
        } else {
            cout << "Invalid command, try again!" << endl;
            cout << "Enter a command: ";
            cin >> userInput;
        }
    }
    return EXIT_SUCCESS;
}
