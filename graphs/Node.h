#ifndef NODE_H
#define NODE_H
#include <vector>

// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

#endif