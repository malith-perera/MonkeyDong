#include "main.h"

#ifndef PLAYER_H
#define PLAYER_H

extern SpriteImages *player_move_images;
extern SpriteImages *player_jump_images;
extern SpriteImages *player_idle_sprites;

extern bool *player_move_left; // key binding
extern bool *player_move_right; // key binding
extern bool *player_jump; // key binding
    
// Player entity
extern Entity *player;
extern EntityComponent playerPlace;
extern EntityComponent playerAction;
extern EntityComponent playerSprite;
extern EntityComponent playerPosition;
extern EntityComponent playerVelocity;

Add_H(player, Place);

#define Assign_Player()\
    Assign(player, place, playerPlace);\
    Assign(player, action, playerAction);\
    Assign(player, sprite, playerSprite);\
    Assign(player, position, playerPosition);\
    Assign(player, velocity, playerVelocity)

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
