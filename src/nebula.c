#include "nebula.h"

ECEntity nebulae;

SpriteImages *nebula_sprites;

void
Nebula_Init_Spritesheet(char *image)
{
    SpriteSheet *spritesheet = Engine_Create_Spritesheet(image, renderer);

    /* image , renderer, src_x, src_y, src_w, src_h, scale, nRows, nColumns, nSprite images in the sprite sheet, sprites per second */
    nebula_sprites  = Engine_New_Sprite(
            spritesheet,   // sprite image                    
            renderer,      // renderer                           
            0, 0,          // src_x, src_y                             
            16, 16,        // src_w, src_h                         
            1,             // scale                                    
            8, 8,          // nRows, nColumns                      
            61, 6);        // nSprites, sprites per second     
}

void
Nebula_Init (
    int entity_id,
    int pos_x, int pos_y,
    int vel_x, int vel_y,
    float scale
)
{

    /* int entity_id, SpriteImage* sprite images, float scale */
    Engine_Assign_Sprite(entity_id, nebula_sprites);

    /* entity_id, pos_x, pos_y, vel_x, vel_y, initial_scale */
    Engine_Entity_Init(entity_id, pos_x, pos_y, vel_x, vel_y, 1);
}

void
Nebula_Free ()
{
    free (nebula_sprites);
}

void
Nebula_Update ()
{
    for (int nebula_id = nebulae.I; nebula_id < nebulae.n; nebula_id++)
    {
        Engine_Render (nebula_id, renderer);

        Nebula_Move(nebula_id);
        Engine_Sprite_Simple_Triger(&triger8, &sprite[nebula_id]);
        /*Engine_Sprite_Triger (triger8, &sprite[nebula_id]);*/
        Engine_Update_Sprite (&sprite[nebula_id]);
    }
}

void
Nebula_Render ()
{

}

void
Nebula_Move (int nebula_id)
{
    if (player_move_right) {
        *position[nebula_id].x += velocity[nebula_id].x * 2; // *** I simply double the velocity. need to add the player velocity (background velocity)
    }
    else {
        *position[nebula_id].x += velocity[nebula_id].x;
    }


    if (*position[nebula_id].x < -100 * engine_scale)
    {
        *position[nebula_id].x = 2000 * engine_scale;
    }
}
