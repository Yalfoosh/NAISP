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
