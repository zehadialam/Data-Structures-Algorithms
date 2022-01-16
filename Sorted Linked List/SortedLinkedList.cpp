#include <sstream>
#include <iostream>
#include "SortedLinkedList.h"

SortedLinkedList::SortedLinkedList() {
    head = nullptr;
    currentPos = head;
    length = 0;
}

SortedLinkedList::~SortedLinkedList() {
// create two pointer variables to empty the list
    Node *temp;
    Node *temp2;
    temp2 = head; // initialize temp2 to head
    // continues to loop if temp2 is not nullptr
    while (temp2 != nullptr) {
        // clears each data one at a time
        temp = temp2;
        temp2 = temp2->next; // update position of temp2
        delete temp; // deallocate memory for temp
    }
}

int SortedLinkedList::getLength() const {
    return length;
}

void SortedLinkedList::insertData(Data data) {
    Node *temp; // declare ListNode pointer
    temp = new Node; // allocate memory for node
    temp->data = data; // set the node data member to the data to be inserted
    // handles the cases of inserting the first element or inserting in empty list
    if (head == nullptr || head->data > temp->data) {
        temp->next = head; // makes the current head the next data for the node
        head = temp; // position of head is updated
        length++; // update list length
    } else {
        currentPos = head; // initialize currentPos to head
        // continues to loop as long as the next data is not null pointer and the next data's
        // value is less than the value of the node that is to be inserted
        while (currentPos->next != nullptr && currentPos->next->data < temp->data) {
            currentPos = currentPos->next; // update currentPos
        }
        temp->next = currentPos->next; // link node to the data after currentPos
        currentPos->next = temp; // update the data after currentPos to be the inserted node
        length++; // update list length
    }
}

void SortedLinkedList::deleteData(Data data) {
    Node *previousPos = nullptr; // initialize previousPos pointer
    currentPos = head; // initialize currentPos to head
    bool notFound{true}; // boolean variable to control loop
    // Handles deleting first element case
    if (currentPos != nullptr && currentPos->data == data) {
        head = currentPos->next; // link head to the node after currentPos
        delete currentPos; // deallocate memory for currentPos
        length--; // update list length
    } else {
        while (currentPos != nullptr && notFound) {
            // searching list for the data to be deleted
            if (data != currentPos->data) {
                previousPos = currentPos;
                currentPos = currentPos->next;
            } else {
                notFound = false; // terminates loop when data is found
            }
        }
        if (previousPos != nullptr && currentPos != nullptr) {
            previousPos->next = currentPos->next; // link previousPos with node after currentPos
            delete currentPos; // deallocate memory for currentPos
            length--; // update list length
        }
    }
}

int SortedLinkedList::searchData(Data data) {
    int index{0}; // declare and initialize index tracker
    currentPos = head; // set currentPos to head
    // traverse through list until currentPos is null pointer
    while (currentPos != nullptr) {
        index++; // increment index until data is found
        if (currentPos->data == data) {
            return index - 1; // return the index when data is found
        }
        currentPos = currentPos->next; // update currentPos
    }
    return -1; // return -1 if data is not found
}

Data SortedLinkedList::getData() {
    currentPos = head; // initialize currentPos to head
    return currentPos->data; // return the data associated with currentPos
}

Data SortedLinkedList::getNextData() {
    // sets currentPos to the next data if next is not null pointer
    if (currentPos->next != nullptr) {
        currentPos = currentPos->next;
    }
    return currentPos->data; // return the data associated with currentPos
}

void SortedLinkedList::resetList() {
    currentPos = nullptr; // initialize currentPos to null pointer
}

void SortedLinkedList::makeEmpty() {
    currentPos = head; // initialize currentPos to head
    // deletes each data and updates currentPos while currentPos is not null
    while (currentPos != nullptr) {
        deleteData(currentPos->data);
        currentPos = currentPos->next;
    }
}

void SortedLinkedList::merge(SortedLinkedList &list1, const std::string &list2) {
    SortedLinkedList copyList; // holds a copy of the user-provided list
    Data data;
    bool noDuplicates{true}; // checks for the condition of entering duplicate data
    int number{0};
    std::stringstream userInputStream(list2); // used to extract each number from string
    while (!userInputStream.eof() && noDuplicates) {
        userInputStream >> number;
        data.initialize(number);
        // if a duplicate data is found in the user-provided list, then all the
        // items that have been inserted so far will be removed, such that the list
        // goes back to its original state.
        if (list1.searchData(data) != -1) {
            noDuplicates = false;
            if (copyList.getLength() != 0) {
                data = copyList.getData();
                deleteData(data);
                for (int i = 0; i < copyList.getLength() - 1; i++) {
                    data = copyList.getNextData();
                    deleteData(data);
                }
            }
            std::cout << "Sorry. You cannot insert the duplicate data." << std::endl;
        } else {
            // if the current data is not a duplicate data, it gets added to the list
            // and also added to copyList for tracking purposes.
            insertData(data);
            copyList.insertData(data);
        }
    }
}

void SortedLinkedList::deleteAlternateNodes() {
    // initialize pointers to be in correct order
    Node *previousPos = head;
    currentPos = head->next;
    while (previousPos != nullptr && currentPos != nullptr) {
        // links previousPos to the next data of currentPos
        previousPos->next = currentPos->next;
        delete currentPos; // deallocate memory for currentPos
        length--; // update length of list
        // re-adjusts the ordering to make previousPos before currentPos
        previousPos = previousPos->next;
        if (previousPos != nullptr) {
            currentPos = previousPos->next;
        } else {
            currentPos = head->next;
        }
    }
}

void SortedLinkedList::intersection(SortedLinkedList &list1, const std::string &list2) {
    Data data;
    int number{0};
    // intersectionList contains the items that are in common between the original list
    // and the user-provided list
    SortedLinkedList intersectionList;
    std::stringstream userInputStream(list2); // used to extract each number from string
    while (!userInputStream.eof()) {
        userInputStream >> number;
        data.initialize(number);
        if (list1.searchData(data) != -1) {
            // Adds the data to the intersectionList if it was found in the original list.
            intersectionList.insertData(data);
        }
    }
    makeEmpty(); // clears the list, so that the items in the intersectionList can be added
    // if the intersectionList is not empty, the items are added to the original list
    if (intersectionList.getLength() != 0) {
        currentPos = head;
        insertData(intersectionList.getData());
        for (int i = 0; i < intersectionList.getLength() - 1; i++) {
            insertData(intersectionList.getNextData());
        }
    }
}

void SortedLinkedList::printList(SortedLinkedList &list) {
// prints each item in the list if the list is not empty
    if (list.getLength() != 0) {
        std::cout << list.getData().getValue() << " ";
        for (int i = 0; i < list.getLength() - 1; i++) {
            std::cout << list.getNextData().getValue() << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << std::endl;
    }
}
