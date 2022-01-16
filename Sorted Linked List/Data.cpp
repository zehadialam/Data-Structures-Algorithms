#include "Data.h"

// Default constructor that initializes the value data member
Data::Data() {
    initialize(0);
}

// Return the value of Data object
int Data::getValue() const {
    return value;
}

// Initialize the value of Data object
void Data::initialize(int num) {
    value = num;
}