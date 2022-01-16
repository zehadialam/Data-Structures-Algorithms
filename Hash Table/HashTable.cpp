#include <iostream>
#include "HashTable.h"

HashTable::HashTable() = default;

void HashTable::insertData(Data data) {
    int index = HashTable::hash(data.getValue());
    hashTable[index] = data;
}

int HashTable::retrieveData(Data data) {
    int index = HashTable::hash(data.getValue());
    return hashTable[index].getValue();
}

void HashTable::printHashTable() {
    for (Data data: hashTable) {
        std::cout << data.getValue() << std::endl;
    }
}

int HashTable::hash(int value) {
    return value % SIZE;
}
