#ifndef DATA_H
#define DATA_H

class Data {
public:
    Data();

    int getValue() const; // return value of the data member
    void initialize(int num); // initialize the value data member
    bool operator<(const Data &data) const {
        if (this->getValue() < data.getValue()) {
            return true;
        }
        return false;
    }

    bool operator>(const Data &data) const {
        if (this->getValue() > data.getValue()) {
            return true;
        }
        return false;
    }

    bool operator==(const Data &data) const {
        if (this->getValue() == data.getValue()) {
            return true;
        }
        return false;
    }

    bool operator!=(const Data &data) const {
        if (this->getValue() != data.getValue()) {
            return true;
        }
        return false;
    }

private:
    int value{};
};

#endif //DATA_H