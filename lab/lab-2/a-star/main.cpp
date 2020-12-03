#include <iostream>

#include "src/a-star.h"

int main() {
    auto example = nodeMap({
                                   {100, 200,  1000, 0},
                                   {200, 100,  600,  0},
                                   {300, 1600, 100,  0}
                           });
    auto result = aStar(example);

    auto path = result.first;
    auto cost = result.second;

    if(path.empty()){
        std::cout << "No solution found!" << std::endl;

        return 1;
    }

    std::cout << "Path is:" << std::endl;
    for(auto x: path)
        std::cout << "\t" << x << std::endl;

    std::cout << std::endl << "Cost is: " << cost << std::endl;

    return 0;
}
