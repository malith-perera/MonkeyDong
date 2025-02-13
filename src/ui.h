#include "main.h"

#ifndef MENU_H
#define MENU_H

extern bool engine_quit;

typedef enum {QUIT_UI = -3, SETTINGS_UI, GAME_UI, START_UI} Ui; 


typedef struct {
    int id;
} Menu;


int
Start_Ui();


void
Menu_Play();


int
Settings_Ui();

#endif
