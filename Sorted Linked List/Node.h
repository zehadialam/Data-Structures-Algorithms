#include "Data.h"

#ifndef NODE_H
#define NODE_H

struct Node {
    Data data;
    Node *next{};
};

#endif //NODE_H