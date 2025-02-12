#include "main.h"

#ifndef stoneS_H
#define stoneS_H

extern Entity *stone;
extern EntityComponent stonePlace;
extern EntityComponent stoneAction;
extern EntityComponent stoneSprite;
extern EntityComponent stonePosition;
extern EntityComponent stoneVelocity;

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
