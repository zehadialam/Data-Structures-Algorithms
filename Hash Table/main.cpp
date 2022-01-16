#include <iostream>
#include <fstream>
#include "Data.h" // include definition of class Data
#include "HashTable.h" // include definition of class SortedLinkedList

using namespace std;

int main(int argc, char **argv) {
    if (argc != 2) { // checking for number of command line arguments.
        cout << "Error: invalid number of command line arguments. Please use the following syntax." << endl;
        cout << "./main filename.txt" << endl;
        exit(EXIT_FAILURE);
    }
    string arg1 = argv[1];
    ifstream input(arg1);
    HashTable hashTable;
    Data data;
    int number{0};
    while (input >> number) {
        data.initialize(number);
        hashTable.insertData(data);
    }
    data.initialize(3);
    hashTable.retrieveData(data);
    hashTable.printHashTable();
    return EXIT_SUCCESS;
}

