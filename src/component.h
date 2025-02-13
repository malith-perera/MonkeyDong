#include "main.h"

#ifndef COPONENT_H
#define COPONENT_H

Engine_Components_H();

typedef enum {
    ON_SKY,
    ON_GROUND
} Place;

Component_Array_H(Place, place);

typedef enum {
    IDLE,
    MOVE,
    MOVE_LEFT,
    MOVE_RIGHT,
    JUMP,
    JUMP_LEFT,
    JUMP_RIGHT, 
    TURN,
    TURN_LEFT,
    TURN_RIGHT, 
    STOP
} Action;

Component_Array_H(Action, action);

typedef int Rotation;
Component_Array_H(Rotation, rotation);

void
Free_Components();

#endif
