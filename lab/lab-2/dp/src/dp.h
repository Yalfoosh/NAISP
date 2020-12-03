#ifndef DP_DP_H
#define DP_DP_H

#include <algorithm>
#include <cstdlib>

#include "node.h"

bool solveTwoWay(Node ***field, uint width, uint height, int addition = 1) {
    bool changed = false;

    uint hStart = 0;
    uint wStart = 0;

    if (addition < 0) {
        hStart = height - 1;
        wStart = width - 1;
    }

    uint hSecond = hStart + addition;
    uint wSecond = wStart + addition;

    for (auto i = hSecond; i >= 0 && i < height; i += addition) {
        auto proposedCost = field[i][0]->cost + field[i - addition][0]->minCost;

        if (proposedCost < field[i][0]->minCost) {
            changed = true;
            field[i][0]->minCost = proposedCost;
            field[i][0]->parent = field[i - addition][0];
        }
    }

    for (auto i = wSecond; i >= 0 && i < width; i += addition) {
        auto proposedCost = field[0][i]->cost + field[0][i - addition]->minCost;

        if (proposedCost < field[0][i]->minCost) {
            changed = true;
            field[0][i]->minCost = proposedCost;
            field[0][i]->parent = field[0][i - addition];
        }
    }

    for (auto i = hSecond; i >= 0 && i < height; i += addition) {
        for (auto j = wSecond; j >= 0 && j < width; j += addition) {
            if (field[i - addition][j]->minCost <
                field[i][j - addition]->minCost) {
                auto proposedCost =
                        field[i][j]->cost + field[i - addition][j]->minCost;

                if (proposedCost < field[i][j]->minCost) {
                    changed = true;
                    field[i][j]->minCost = proposedCost;
                    field[i][j]->parent = field[i - addition][j];
                }

            } else {
                auto proposedCost =
                        field[i][j]->cost + field[i][j - addition]->minCost;

                if (proposedCost < field[i][j]->minCost) {
                    changed = true;
                    field[i][j]->minCost = proposedCost;
                    field[i][j]->parent = field[i][j - addition];
                }
            }
        }
    }

    return changed;
}

Node *solve(Node ***field, uint width, uint height, uint maxIterations = 1) {
    field[0][0]->minCost = field[0][0]->cost;

    for (auto i = 0; i < maxIterations; ++i) {
        if (!solveTwoWay(field, width, height, i % 2 == 0 ? 1 : -1)) {
            std::cout << "Found an optimal path in " << i + 1 << " iterations"
                      << std::endl;
            break;
        }

    }

    return field[height - 1][width - 1];
}

#endif //DP_DP_H
