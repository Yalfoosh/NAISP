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
