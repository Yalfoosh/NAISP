#ifndef A_STAR_NODE_H
#define A_STAR_NODE_H

#include <utility>

#include "typedefs.h"

class Node {
public:
    long long cost = 0;
    position pos = std::make_pair(0, 0);
    Node *parent = nullptr;

    Node(const long long &cost, const position &pos, Node *parent) {
        this->cost = cost;
        this->pos = pos;
        this->parent = parent;
    }

    bool operator<(const Node &other) const {
        return cost < other.cost;
    }

    bool operator>(const Node &other) const {
        return cost > other.cost;
    }
};

class NodePointerGreater {
public:
    bool operator()(Node *lhs, Node *rhs) {
        return *lhs > *rhs;
    }
};

std::ostream &operator<<(std::ostream &os, const Node &node) {
    return os << "[" << node.cost << "]  (" << node.pos.first << ", "
              << node.pos.second
              << ")  <" << node.parent << ">";
}

typedef std::list<Node *> nodePointerList;
typedef std::priority_queue<Node *, std::vector<Node *>, NodePointerGreater> nodeQueue;

#endif //A_STAR_NODE_H
