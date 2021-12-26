//
// Created by valiant on 19.8.2021.
//

#ifndef RAYCASTERENGINE_MAPS_H
#define RAYCASTERENGINE_MAPS_H

#include "structs.h"

static int mapX = 8, mapY = 8, mapS = 64; // X-coordinate, Y-coordinate, Size

// Default map:
static int map[] = {
        1, 1, 1, 1, 1, 1, 1, 1,
        1, 0, 0, 0, 0, 1, 0, 1,
        1, 1, 1, 1, 0, 1, 0, 1,
        1, 0, 0, 1, 0, 1, 0, 1,
        1, 0, 0, 1, 0, 0, 0, 1,
        1, 0, 0, 1, 0, 1, 1, 1,
        1, 0, 0, 0, 0, 0, 0, 1,
        1, 1, 1, 1, 1, 1, 1, 1
};

#endif //RAYCASTERENGINE_MAPS_H