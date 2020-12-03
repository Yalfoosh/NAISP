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

#ifndef A_STAR_CONSTANTS_H
#define A_STAR_CONSTANTS_H

#include <vector>

#include "typedefs.h"

const auto MOVE_UP = movement(-1, 0);
const auto MOVE_DOWN = movement(1, 0);
const auto MOVE_LEFT = movement(0, -1);
const auto MOVE_RIGHT = movement(0, 1);

const auto DEFAULT_MOVEMENT = std::vector<movement>({
                                                            MOVE_UP, MOVE_DOWN,
                                                            MOVE_LEFT,
                                                            MOVE_RIGHT
                                                    });

const auto DEFAULT_STARTING_POINT = position(0, 0);

#endif //A_STAR_CONSTANTS_H
