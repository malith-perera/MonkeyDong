#include "main.h"

#ifndef COPONENT_H
#define COPONENT_H

typedef enum {ON_SKY, ON_GROUND} Place;
typedef enum {IDLE, MOVE, MOVE_LEFT, MOVE_RIGHT, JUMP, JUMP_LEFT, JUMP_RIGHT, TURN, TURN_LEFT, TURN_RIGHT, STOP} Action;

extern Place* place;
extern Action* action;
extern int* player_arrow_id;

void
Create_Components();

void
Assign_Components();

void
Free_Components();

#endif
