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
