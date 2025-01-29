#include "monkeydong.h"

ECEntity monkeyDong; // monkeyDong entity ids

SpriteImages *monkeyDong_run_sprites;
SpriteImages *monkeyDong_jump_sprites;

bool *monkeyDong_run_left; // key binding
bool *monkeyDong_run_right; // key binding
bool *monkeyDong_jump; // key binding

void
MonkeyDong_Init_Spriteshteet(char *image)
{

    SpriteSheet *spritesheet = Engine_Create_Spritesheet(image, renderer);
    /* image , renderer, src_x, src_y, src_w, src_h, scale, nRows, nColumns, nSprite images in the sprite sheet, sprites per second */
    monkeyDong_run_sprites = Engine_New_Sprite(
            spritesheet, // sprite image                
            renderer,                        // renderer                    
            0, 0,                            // src_x, src_y                
            16, 16,                          // src_w, src_h                
            1,                               // scale                       
            1, 6,                            // nRows, nColumns             
            6, 2);                           // nSprites, sprites per second

    monkeyDong_jump_sprites = Engine_New_Sprite(
            spritesheet,
            renderer,
            0, 0,
            16, 16,
            1,
            1, 6,
            6, 2);
}


void
MonkeyDong_Init(
    int entity_id,
    int pos_x, int pos_y,
    int vel_x, int vel_y,
    float scale
)
{
    /* int entity_id, SpriteImage* sprite images */
    Engine_Assign_Sprite(entity_id, monkeyDong_run_sprites);

    /* entity_id, pos_x, pos_y, vel_x, vel_y, initial_scale */
    Engine_Entity_Init(entity_id, pos_x, pos_y, vel_x, vel_y, 1);

    place[entity_id] = ON_SKY;
}


void
MonkeyDong_Free()
{
    free(monkeyDong_run_sprites);
    free(monkeyDong_jump_sprites);
}

void
MonkeyDong_Update ()
{
    for (int monkeyDong_id = monkeyDong.I; monkeyDong_id < monkeyDong.n; monkeyDong_id++)
    {
        Engine_Render (monkeyDong_id, renderer);

        Engine_Sprite_Simple_Triger(&triger8, &sprite[monkeyDong_id]);
        /*Engine_Sprite_Triger (triger8, &sprite[monkeyDong_id]);*/

        Engine_Update_Sprite (&sprite[monkeyDong_id]);
    }

}

void
MonkeyDong_Run(int monkeyDong_id)
{
    if(place[monkeyDong_id == ON_GROUND])
        Engine_Assign_Sprite(monkeyDong_id, monkeyDong_run_sprites);

    Engine_Sprite_Triger(&triger6, &sprite[monkeyDong_id]);

    /*Engine_Update_Sprite(&sprite[monkeyDong_id]);*/

/*
    for(int ground_id = grounds.I; ground_id < grounds.n; ground_id++) {
        Engine_Ground_Move_Left(ground_id);
    }

    if (action[monkeyDong.I] == RUN_RIGHT) {
        *position[monkeyDong_id].x += velocity[monkeyDong_id].x;
        if (*position[monkeyDong_id].x > (engine_width - 16) * engine_scale) {
            *position[monkeyDong_id].x = (engine_width - 16) * engine_scale; 
        }
    }
    else if (action[monkeyDong.I] == RUN_LEFT) {
        *position[monkeyDong_id].x -= velocity[monkeyDong_id].x;
        if (*position[monkeyDong_id].x < 0) {
            *position[monkeyDong_id].x = 0; 
        }
    }
*/

}


void
MonkeyDong_Jump(int monkeyDong_id)
{
    static bool ready_play_sound = false;

/*
    if(action[monkeyDong_id] != JUMP)
        Engine_Assign_Sprite(monkeyDong_id, monkeyDong_jump_sprites);

    if(ready_play_sound == true) {
        //playSound("resources/audio/jump.wav", SDL_MIX_MAXVOLUME);
        ready_play_sound = false;
    }

    *position[monkeyDong_id].y += velocity[monkeyDong_id].y;
    velocity[monkeyDong_id].y += gravity * engine_scale * .8; // I put .8 here 
    if(*position[monkeyDong_id].y >= (engine_height - 16 ) * engine_scale) {
        place[monkeyDong_id] = ON_GROUND;
        *position[monkeyDong_id].y = (engine_height - 16) * engine_scale;
        velocity[monkeyDong_id].y = -8 * engine_scale;
        ready_play_sound = true;
    }
*/
}


void
MonkeyDong_Stop(int monkeyDong_id)
{
    Engine_Sprite_Stop_triger(&sprite[monkeyDong_id]);
}


void
MonkeyDong_Stay(int monkeyDong_id)
{
    sprite[monkeyDong_id].sprite_images = monkeyDong_run_sprites;
    sprite[monkeyDong_id].sprite_images->src.x = sprite[monkeyDong_id].sprite_images->src.w * 2;
}
