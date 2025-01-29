#include "main.h"

#ifndef ARROW_H
#define ARROW_H


extern ECEntity arrow;

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
