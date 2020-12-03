/*
 *  Copyright 2020 Yalfoosh
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

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
