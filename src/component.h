#include "main.h"

#ifndef COPONENT_H
#define COPONENT_H

/* Place */
typedef enum {
    ON_SKY,
    ON_GROUND
} Place;

New_Component_H(Place, place);

/* Action */
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

New_Component_H(Action, action);

/* Rotation */
typedef int Rotation;
typedef Rotation LastRotation;

New_Component_H(Rotation, rotation);

void
Free_Components();

#endif
