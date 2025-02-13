#include "main.h"

#ifndef BACKGROUND_H
#define BACKGROUND_H


extern int far_ground_id, back_ground_id, fore_ground_id;

extern SpriteImages ground_sprite_sprites[3];

extern SpriteImages *far_ground_sprites;
extern SpriteImages *back_ground_sprites;
extern SpriteImages *fore_ground_sprites;

void
Ground_Free();

void
Ground_Init();

void
Ground_Update();

#endif
