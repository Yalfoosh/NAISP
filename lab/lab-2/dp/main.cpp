#include <chrono>
#include <cstdlib>
#include <iostream>
#include <list>

#include "src/dp.h"
#include "src/node.h"

#define WIDTH 5000
#define HEIGHT 4000
#define cTime std::chrono::high_resolution_clock::now()
#define ms std::chrono::duration_cast<std::chrono::milliseconds>

Node ***getField(uint width, uint height) {
    auto field = new Node **[height];

    for (auto i = 0; i < height; ++i)
        field[i] = new Node *[width];

    return field;
}

void deleteField(Node ***field, uint width, uint height) {
    for (auto i = 0; i < height; ++i) {
        for (auto j = 0; j < width; ++j)
            delete field[i][j];

        delete[] field[i];
    }

    delete[] field;
}

void printField(Node ***field, uint width, uint height) {
    for (auto i = 0; i < height; ++i) {
        for (auto j = 0; j < width; ++j) {
            std::cout << "[" << field[i][j]->cost << "] "
                      << field[i][j]->minCost << " ";
        }

        std::cout << std::endl;
    }
}

std::list<position> getPath(Node *node) {
    auto toReturn = std::list<position>();

    while(node->parent != nullptr){
        toReturn.emplace_back(node->pos);
        node = node->parent;
    }
    toReturn.emplace_back(node->pos);
    std::reverse(toReturn.begin(), toReturn.end());

    return toReturn;
}

int main() {
    auto field = getField(WIDTH, HEIGHT);

    for (auto i = 0; i < HEIGHT; ++i) {
        for (auto j = 0; j < WIDTH; ++j) {
            field[i][j] = new Node(rand() % 1000, i, j);
        }
    }

    auto field2 = getField(WIDTH, HEIGHT);

    for (auto i = 0; i < HEIGHT; ++i) {
        for (auto j = 0; j < WIDTH; ++j) {
            field2[i][j] = new Node(field[i][j]->cost, i, j);
        }
    }

    std::cout << "Calculating..." << std::endl;
    auto start = cTime;
    auto goal = solve(field, WIDTH, HEIGHT);
    auto end = cTime;

    std::cout << "Calculated in " << ms(end - start).count() << " ms"
              << std::endl;
    std::cout << "Cost: " << goal->minCost << std::endl;



    std::cout << std::endl << "Calculating 2nd..." << std::endl;
    start = cTime;
    goal = solve(field2, WIDTH, HEIGHT, 10);
    end = cTime;

    std::cout << "Calculated 2nd in " << ms(end - start).count() << " ms"
              << std::endl;
    std::cout << "Cost: " << goal->minCost << std::endl;

    deleteField(field, WIDTH, HEIGHT);
    deleteField(field2, WIDTH, HEIGHT);
    return 0;
}
