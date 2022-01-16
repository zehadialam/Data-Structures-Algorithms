#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "Data.h"

static const int SIZE = 101;

class HashTable {
public:
    HashTable();

    void insertData(Data data);

    int retrieveData(Data data);

    void printHashTable();

private:
    Data hashTable[SIZE];

    static int hash(int value);
};

#endif //HASHTABLE_H
