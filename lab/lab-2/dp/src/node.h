#ifndef DP_NODE_H
#define DP_NODE_H

#include <climits>

typedef std::pair<uint, uint> position;

class Node{
public:
    uint cost;
    uint minCost;
    position pos;
    Node* parent;

    Node(uint cost, position pos){
        this->cost = cost;
        this->minCost = UINT_MAX;
        this->pos = pos;
        this->parent = nullptr;
    }

    Node(uint cost, uint i, uint j){
        this->cost = cost;
        this->minCost = UINT_MAX;
        this->pos = position(i, j);
        this->parent = nullptr;
    }
};

#endif //DP_NODE_H
