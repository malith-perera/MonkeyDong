#include "monkey.h"

Entity *monkey;
EntityComponent(monkey, Place);
EntityComponent(monkey, Action);
EntityComponent(monkey, Sprite);
EntityComponent(monkey, Position);
EntityComponent(monkey, Velocity);

EntityList *monkey_list;

SpriteImages *monkey_run_sprites;
SpriteImages *monkey_jump_sprites;

bool *monkey_run_left; // key binding
bool *monkey_run_right; // key binding
bool *monkey_jump; // key binding

void
MonkeyDong_Init_Spriteshteet(char *image)
{
    SpriteSheet *spritesheet = Engine_Create_Spritesheet(image, renderer);
    /* image , renderer, src_x, src_y, src_w, src_h, scale, nRows, nColumns, nSprite images in the sprite sheet, sprites per second */
    monkey_run_sprites = Engine_New_Sprite(
            spritesheet, // sprite image                
            0, 0,                            // src_x, src_y                
            16, 16,                          // src_w, src_h                
            1,                               // scale                       
            1, 6,                            // nRows, nColumns             
            6, 2);                           // nSprites, sprites per second

    monkey_jump_sprites = Engine_New_Sprite(
            spritesheet,
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
    Engine_Init(monkey, entity_id);

    /* int entity_id, SpriteImage* sprite images */
    Engine_Assign_Sprite(&sprite[monkeySpriteId], monkey_run_sprites);

    /* entity_id, pos_x, pos_y, vel_x, vel_y, initial_scale */
    Engine_New_Entity_Init(monkey, entity_id, pos_x, pos_y, vel_x, vel_y, scale);
}

void
MonkeyDong_Free()
{
    free(monkey_run_sprites);
    free(monkey_jump_sprites);
}

void
MonkeyDong_Update ()
{
    int monkeyRotationId, monkeyLastRotationId, monkeySpriteId, monkeyPositionId; 

    for(int entity_id = 0; entity_id < monkey->n; entity_id++) {
        monkeySpriteId = monkeySprite.I + entity_id;
        monkeyPositionId = monkeyPosition.I + entity_id;

        Engine_Triger_Sprite(&sprite[monkeySpriteId], &triger2);

        sprite[monkeySpriteId].dst.x = position[monkeyPositionId].x;
        sprite[monkeySpriteId].dst.y = position[monkeyPositionId].y;

        Engine_Render(&sprite[monkeySpriteId], renderer);
    }
}

void
MonkeyDong_Run(int monkey_id)
{
}


void
MonkeyDong_Jump(int monkey_id)
{
    static bool ready_play_sound = false;

}


void
MonkeyDong_Stop(int monkey_id)
{
    Engine_Sprite_Stop_triger(&sprite[monkeySprite.I + monkey_id]);
}


void
MonkeyDong_Stay(int monkey_id)
{
    int monkeySpriteId = monkeySprite.I + monkey_id;

    sprite[monkeySpriteId].sprite_images = monkey_run_sprites;
    sprite[monkeySpriteId].sprite_images->src.x = sprite[monkeySpriteId].sprite_images->src.w * 2;
}
