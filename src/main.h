#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "engine.h"

#include "component.h"
#include "menu.h"
#include "player.h"
#include "arrow.h"
#include "monkeydong.h"
#include "nebula.h"
#include "brick.h"
#include "ground.h"

#include "system.h"
#include "mission1.h"

#define PI 3.14159265

extern Engine_Renderer *renderer;

/* Triger sprite images
 * Use globaly in entire game */
extern SpriteTriger triger6; /* 6 images per second */
extern SpriteTriger triger8; /* 8 images per second */

extern int gravity;

#endif
