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

#ifndef A_STAR_A_STAR_H
#define A_STAR_A_STAR_H

#include <cmath>
#include <utility>
#include <set>
#include <algorithm>

#include "constants.h"
#include "node.h"
#include "typedefs.h"

nodePointerList explore(
        Node *currentNode,
        const nodeMap &field,
        const positionSet &closedNodes,
        const uint heuristicMultiplier = 1,
        const std::vector<movement> &allowedMovement = DEFAULT_MOVEMENT) {
    auto neighbours = nodePointerList();

    for (const auto &move: allowedMovement) {
        auto i = currentNode->pos.first + move.second;
        auto j = currentNode->pos.second + move.first;
        auto pos = std::make_pair(i, j);

        if (closedNodes.find(pos) == closedNodes.end() &&
            i >= 0 && i < field.size() &&
            j >= 0 && j < field[0].size()) {
            auto cost = currentNode->cost + field[i][j] - heuristicMultiplier;

            neighbours.emplace_back(new Node(cost, pos, currentNode));
        }
    }

    return neighbours;
}

uint manhattanDistance(const position &start, const position &end) {
    uint distance = 0;

    // We do this because you can't exactly do abs on uint.
    if (start.first > end.first)
        distance += start.first - end.first;
    else
        distance += end.first - start.first;

    if (start.second > end.second)
        distance += start.second - end.second;
    else
        distance += end.second - start.second;

    return distance;
}

std::pair<positionList, uint>
aStar(nodeMap field, const position &startingPoint = DEFAULT_STARTING_POINT,
      const std::vector<movement> &allowedMovement = DEFAULT_MOVEMENT) {
    // Assume ending point is the rightmost bottom field.
    auto endingPoint = position(field.size() - 1, field[0].size() - 1);

    // Initialize empty node collections.
    auto openNodes = nodeQueue();
    auto closedNodes = positionSet();

    // Find the lowest value field first.
    auto lowestValue = field[0][0];
    auto didTransform = false;

    for (const auto &row : field) {
        for (unsigned int element : row) {
            if (element < lowestValue)
                lowestValue = element;
        }
    }

    if (lowestValue == 0) {
        for (auto i = 0; i < field.size(); ++i)
            for (auto j = 0; j < field[i].size(); ++j)
                ++field[i][j];

        lowestValue = 1;

        // We remember this so we can get the true value
        // without recalculating it at the end.
        didTransform = true;
    }

    auto firstHeuristic =
            manhattanDistance(startingPoint, endingPoint) * lowestValue;
    auto firstNode = new Node(field[startingPoint.first][startingPoint.second] +
                              firstHeuristic,
                              startingPoint,
                              nullptr);

    openNodes.push(firstNode);

    // The condition is the open nodes not being empty as if
    // they become empty at any point, there is no solution.
    while (!openNodes.empty()) {
        auto openedNode = openNodes.top();
        openNodes.pop();

        // If this happened, our opened node is the goal
        if (openedNode->pos == endingPoint) {
            auto nodePath = positionList();
            auto cost = openedNode->cost;

            while (openedNode->parent != nullptr) {
                nodePath.emplace_back(openedNode->pos);
                openedNode = openedNode->parent;
            }
            nodePath.emplace_back(openedNode->pos);

            // We reverse the order since going from the
            // last node the list is reversed.
            std::reverse(nodePath.begin(), nodePath.end());

            // Remember to readjust the real cost if we had
            // to modify the field to be solvable.
            if (didTransform)
                cost -= nodePath.size();

            return make_pair(nodePath, cost);
        }

        auto nodesToExplore = explore(openedNode, field, closedNodes,
                                      lowestValue, allowedMovement);

        closedNodes.emplace(openedNode->pos);

        for (auto x: nodesToExplore) {
            openNodes.emplace(x);
        }
    }

    // In the case of no solution, return an empty position
    // list (cost doesn't matter really).
    return make_pair(positionList(), 0);
}

#endif //A_STAR_A_STAR_H
