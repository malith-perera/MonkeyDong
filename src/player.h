#include "main.h"

#ifndef PLAYER_H
#define PLAYER_H

extern ECEntity players; // player entity ids

extern SpriteImages *player_move_images;
extern SpriteImages *player_jump_images;
extern SpriteImages *player_idle_sprites;

extern bool *player_move_left; // key binding
extern bool *player_move_right; // key binding
extern bool *player_jump; // key binding

void
Player_Init(
    int player_id,
    int pos_x, int pos_y,
    int vel_x, int vel_y,
    float scale
);

void
Player_Init_SpriteSheet(char *image);

void
Player_Free();

void
Player_Update();

void
Player_Move(int player_id);

void
Player_Jump(int player_id);

void
Player_Jump_Left(int player_id);

void
Player_Jump_Right(int player_id);

void
Player_Idle(int player_id);

void
Player_Stop(int player_id);

#endif
