#ifndef A_STAR_TYPEDEFS_H
#define A_STAR_TYPEDEFS_H

#include <list>
#include <queue>
#include <set>
#include <utility>
#include <vector>

typedef unsigned int uint;
typedef std::vector<std::vector<uint>> nodeMap;
typedef std::pair<uint, uint> position;
typedef std::list<position> positionList;
typedef std::set<position> positionSet;
typedef std::pair<int, int> movement;

std::ostream &operator<<(std::ostream &os, const position &x) {
    return os << "(" << x.first << ", " << x.second << ")";
}

std::ostream &operator<<(std::ostream &os, const movement &x) {
    return os << "(" << x.first << ", " << x.second << ")";
}

#endif //A_STAR_TYPEDEFS_H
