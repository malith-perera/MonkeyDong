#include "main.h"

#ifndef monkeyDong_H
#define monkeyDong_H

extern ECEntity monkeyDong; // monkeyDong entity ids

extern SpriteImages *monkeyDong_run_sprites;
extern SpriteImages *monkeyDong_jump_sprites;

extern bool *monkeyDong_run_left; // key binding
extern bool *monkeyDong_run_right; // key binding
extern bool *monkeyDong_jump; // key binding
        
void
MonkeyDong_Init_Spriteshteet(char *image);

void
MonkeyDong_Init(
    int entity_id,
    int pos_x, int pos_y,
    int vel_x, int vel_y,
    float scale
);

void
MonkeyDong_Free();

void
MonkeyDong_Update();

void
MonkeyDong_Run(int monkeyDong_id);

void
MonkeyDong_Jump(int monkeyDong_id);

void
MonkeyDong_Stay(int monkeyDong_id);

void
MonkeyDong_Stop(int monkeyDong_id);
                         //
#endif //monkeyDong_H
