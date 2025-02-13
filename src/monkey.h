#include "main.h"

#ifndef monkey_H
#define monkey_H

extern SpriteImages *monkey_run_sprites;
extern SpriteImages *monkey_jump_sprites;

extern bool *monkey_run_left; // key binding
extern bool *monkey_run_right; // key binding
extern bool *monkey_jump; // key binding
        
extern Entity *monkey;
extern EntityComponent monkeyPlace;
extern EntityComponent monkeyAction;
extern EntityComponent monkeySprite;
extern EntityComponent monkeyPosition;
extern EntityComponent monkeyVelocity;

#define Assign_Monkey()\
    Assign(monkey, action, monkeyAction);\
    Assign(monkey, place, monkeyPlace);\
    Assign(monkey, sprite, monkeySprite);\
    Assign(monkey, position, monkeyPosition);\
    Assign(monkey, velocity, monkeyVelocity)

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
MonkeyDong_Run(int monkey_id);

void
MonkeyDong_Jump(int monkey_id);

void
MonkeyDong_Stay(int monkey_id);

void
MonkeyDong_Stop(int monkey_id);
                         //
#endif //monkey_H
