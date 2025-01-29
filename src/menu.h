#include "main.h"

#ifndef MENU_H
#define MENU_H

typedef struct {
    int id;
} Menu;

extern int nMenu;

int
Menu_Main();


void
Menu_Play();


void
Menu_Settings();

#endif
