#include "main.h"

#ifndef ARROW_H
#define ARROW_H

extern Entity *arrow;
EntityComponent_H(arrow, Action);
EntityComponent_H(arrow, Sprite);
EntityComponent_H(arrow, Position);
EntityComponent_H(arrow, Velocity);
EntityComponent_H(arrow, Rotation);
EntityComponent_H(arrow, LastRotation);

extern EntityList *arrow_list;

extern int arrow_rotation; // arrow component

#define Assign_Arrow()\
    Assign(arrow, action, arrowAction);\
    Assign(arrow, rotation, arrowRotation);\
    Assign(arrow, rotation, arrowLastRotation);\
    Assign(arrow, sprite, arrowSprite);\
    Assign(arrow, position, arrowPosition);\
    Assign(arrow, velocity, arrowVelocity)


extern bool *arrow_turn_left; // key binding
extern bool *arrow_turn_right; // key binding

void
Arrow_Init_Spritesheet(char *image);

void
Arrow_Init(
    int arrow_id,
    int pos_x, int pos_y,
    int vel_x, int vel_y,
    float scale
);

void
Arrow_Free();

void
Arrow_Update();

#endif // ARROW_H 
