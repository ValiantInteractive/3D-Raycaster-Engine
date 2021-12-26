//
// Created by valiant on 20.8.2021.
//
#ifndef RAYCASTERENGINE_STRUCTS_H
#define RAYCASTERENGINE_STRUCTS_H

float frame1, frame2, fps;

typedef struct {
    int up, down, left, right;
} ButtonKeys;

typedef struct {
    float posX, posY, deltaX, deltaY, angle;
} Player;

__attribute__((unused)) typedef struct {
    int map[64];
} Level;

Player player;
ButtonKeys keys;

#endif //RAYCASTERENGINE_STRUCTS_H