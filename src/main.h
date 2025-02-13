#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "ec.h"
#include "engine.h"

#include "time.h"
#include "component.h"
#include "ui.h"
#include "player.h"
#include "arrow.h"
#include "monkey.h"
#include "stone.h"
#include "ground.h"

#include "system.h"
#include "mission1.h"

#define PI 3.14159265

extern Engine_Renderer *renderer;
extern Engine_Renderer *engine_renderer;

extern int gravity;

// defined in time.h
extern TimeTriger triger1; /* 1 sprite image per second */
extern TimeTriger triger2; /* 2 sprite images per second */
extern TimeTriger triger4; /* 4 sprite images per second */
extern TimeTriger triger6; /* 6 sprite images per second */
extern TimeTriger triger8; /* 8 sprite images per second */

#endif
