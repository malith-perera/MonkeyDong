#include "main.h"

#ifndef NEBULA_H
#define NEBULA_H

extern ECEntity nebulae;

extern SpriteImages *nebula_sprite_sprites;

void
Nebula_Init_Spritesheet(char *image);

void
Nebula_Init (
    int nebula_id,
    int pos_x, int pos_y,
    int vel_x, int vel_y,
    float scale
);

void
Nebula_Free ();

void
Nebula_Update ();

void
Nebula_Move (int nebula_id);

#endif
