#ifndef DATA_H
#define DATA_H

class Data {
public:
    Data();

    int getValue() const; // return value of the data member
    void initialize(int num); // initialize the value data member

private:
    int value{};
};

#endif //DATA_H