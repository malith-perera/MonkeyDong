#include "main.h"

#ifndef BRICKS_H
#define BRICKS_H

extern ECEntity brick;

extern SpriteImages *brick_sprite_sprites;

void
Brick_Init_Spritesheet(char *image);

void
Brick_Init (
    int brick_id,
    int pos_x, int pos_y,
    int vel_x, int vel_y,
    float scale
);

void
Brick_Free ();

void
Brick_Update ();

void
Brick_Move (int brick_id);

#endif
