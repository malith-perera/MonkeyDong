#include "main.h"

#ifndef stoneS_H
#define stoneS_H

extern Entity *stone;
EntityComponent_H(stone, Place);
EntityComponent_H(stone, Action);
EntityComponent_H(stone, Sprite);
EntityComponent_H(stone, Position);
EntityComponent_H(stone, Velocity);

extern EntityList *stone_list;

#define Assign_Stone()\
    Assign(stone, action, stoneAction);\
    Assign(stone, place, stonePlace);\
    Assign(stone, sprite, stoneSprite);\
    Assign(stone, position, stonePosition);\
    Assign(stone, velocity, stoneVelocity)

void
Stone_Init_Spritesheet(char *image);

void
Stone_Init (
    int stone_id,
    int pos_x, int pos_y,
    int vel_x, int vel_y,
    float scale
);

void
Stone_Free ();

void
Stone_Update ();

void
Stone_Move (int stone_id);

#endif
