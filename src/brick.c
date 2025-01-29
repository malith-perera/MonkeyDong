#include "brick.h"

ECEntity brick;

SpriteImages *brick_sprites;

void
Brick_Init_Spritesheet(char *image)
{
    SpriteSheet *spritesheet = Engine_Create_Spritesheet(image, renderer);

    /* image , renderer, src_x, src_y, src_w, src_h, scale, nRows, nColumns, nSprite images in the sprite sheet, sprites per second */
    brick_sprites  = Engine_New_Sprite(
            spritesheet,   // sprite image                    
            renderer,      // renderer                           
            0, 0,          // src_x, src_y                             
            4, 4,          // src_w, src_h                         
            1,             // scale                                    
            1, 8,          // nRows, nColumns                      
            8, 4);         // nSprites, sprites per second     
}

void
Brick_Init (
    int entity_id,
    int pos_x, int pos_y,
    int vel_x, int vel_y,
    float scale
)
{

    /* int entity_id, SpriteImage* sprite images, float scale */
    Engine_Assign_Sprite(entity_id, brick_sprites);

    /* entity_id, pos_x, pos_y, vel_x, vel_y, initial_scale */
    Engine_Entity_Init(entity_id, pos_x, pos_y, vel_x, vel_y, 1);
}

void
Brick_Free ()
{
    free (brick_sprites);
}

void
Brick_Update ()
{
    for (int brick_id = brick.I; brick_id < brick.n; brick_id++)
    {
        Engine_Render (brick_id, renderer);

        Brick_Move(brick_id);
        Engine_Sprite_Simple_Triger(&triger8, &sprite[brick_id]);
        /*Engine_Sprite_Triger (triger8, &sprite[brick_id]);*/
        Engine_Update_Sprite (&sprite[brick_id]);
    }
}

void
Brick_Render ()
{

}

void
Brick_Move (int brick_id)
{
    if (player_move_right) {
        *position[brick_id].x += velocity[brick_id].x;
        *position[brick_id].y += velocity[brick_id].y;
    }
    else {
        *position[brick_id].x += velocity[brick_id].x;
        *position[brick_id].y += velocity[brick_id].y;
    }


    if (*position[brick_id].x <= 0 || *position[brick_id].x >= engine_width * engine_scale)
    {
        velocity[brick_id].x = -1 * velocity[brick_id].x; 
    }

    if (*position[brick_id].y <= 0 || *position[brick_id].y >= engine_height * engine_scale)
    {
        velocity[brick_id].y = -1 * velocity[brick_id].y; 
    }
}
