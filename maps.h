//
// Created by valiant on 19.8.2021.
//

#ifndef RAYCASTERENGINE_MAPS_H
#define RAYCASTERENGINE_MAPS_H

#include "structs.h"

int mapX = 8, mapY = 8, mapS = 64; // X-coordinate, Y-coordinate, Size

// Default map:
int map[] = {
        1, 1, 1, 1, 1, 1, 1, 1,
        1, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 1,
        1, 1, 1, 1, 1, 1, 1, 1
};

Level level1 = {
        1, 1, 1, 1, 1, 1, 1, 1,
        1, 0, 0, 0, 0, 1, 0, 1,
        1, 1, 1, 1, 0, 1, 0, 1,
        1, 0, 0, 1, 0, 1, 0, 1,
        1, 0, 0, 1, 0, 0, 0, 1,
        1, 0, 0, 1, 0, 1, 1, 1,
        1, 0, 0, 0, 0, 0, 0, 1,
        1, 1, 1, 1, 1, 1, 1, 1
};

Level level2 = {
        1, 1, 1, 1, 1, 1, 1, 1,
        1, 0, 0, 0, 0, 1, 0, 1,
        1, 1, 1, 1, 0, 1, 0, 1,
        1, 0, 0, 0, 0, 1, 0, 1,
        1, 0, 1, 1, 0, 1, 0, 1,
        1, 0, 1, 1, 0, 1, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 1,
        1, 1, 1, 1, 1, 1, 1, 1
};

Level level3 = {
        1, 1, 1, 1, 1, 1, 1, 1,
        1, 0, 0, 0, 0, 0, 0, 1,
        1, 1, 1, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 1, 1, 0, 1,
        1, 0, 1, 1, 1, 0, 0, 1,
        1, 0, 0, 0, 1, 0, 0, 1,
        1, 0, 0, 0, 1, 0, 0, 1,
        1, 1, 1, 1, 1, 1, 1, 1,
};

#endif //RAYCASTERENGINE_MAPS_H