#ifndef SORTEDLINKEDLIST_H
#define SORTEDLINKEDLIST_H

#include <string>
#include "Node.h"
#include "Data.h"

class SortedLinkedList {
public:
    SortedLinkedList();

    ~SortedLinkedList();

    int getLength() const;

    void insertData(Data data);

    void deleteData(Data data);

    int searchData(Data data);

    Data getData();

    Data getNextData();

    void resetList();

    void makeEmpty();

    void merge(SortedLinkedList &list1, const std::string &list2);

    void deleteAlternateNodes();

    void intersection(SortedLinkedList &list1, const std::string &list2);

    static void printList(SortedLinkedList &list);

private:
    Node *head;
    Node *currentPos;
    int length;
};

#endif //SORTEDLINKEDLIST_H